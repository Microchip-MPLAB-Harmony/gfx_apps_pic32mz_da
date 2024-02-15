/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "app_qspi.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define NUM_COUNT_SEC_TICK (100)

uint8_t CACHE_ALIGN cdcReadBuffer[APP_READ_BUFFER_SIZE*2];
uint8_t CACHE_ALIGN cdcWriteBuffer[APP_READ_BUFFER_SIZE];

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA CACHE_ALIGN appData;
APP_QSPI_DATA CACHE_ALIGN qspiData;
static char charBuff[32] = {0};
volatile unsigned int tick_count = 0;
unsigned int tick_count_last = 0;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;
static bool timerNotRunning = true;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

leResult leApplication_MediaOpenRequest(leStream* stream)
{
    uint8_t currentConfiguration = true;
    
    stream->flags |= SF_BLOCKING;
       
    if (currentConfiguration)
    {
        APP_WaitUntilTransferDone();
        return LE_SUCCESS;
    }

    return LE_FAILURE;
}

leResult leApplication_MediaReadRequest(leStream* stream, // stream reader
                                        uint32_t address,  // address
                                        uint32_t readSize,  // dest size
                                        uint8_t* destBuffer)
{
    
    if(stream->desc->location != LE_STREAM_LOCATION_ID_SQI)
    {
         // failure tells the decoder to abort and move on
        return LE_FAILURE;
    }
    
    APP_Read((uint32_t *)destBuffer, readSize, address);
    APP_WaitUntilTransferDone();   
    leStream_DataReady(stream);    
    return LE_SUCCESS;
}

void leApplication_MediaCloseRequest(leStream* stream)
{
}

static void Timer_Callback ( uintptr_t context)
{
    tick_count++;
}

void APP_StartDownload (void)
{
    appData.event = APP_IMGFLASH_EVENT_START_FLASH;
}

void APP_StopDownload (void)
{
    appData.event = APP_IMGFLASH_EVENT_EXIT;
}

/*******************************************************
 * USB CDC Device Events - Application Event Handler
 *******************************************************/

USB_DEVICE_CDC_EVENT_RESPONSE APP_USBDeviceCDCEventHandler
(
    USB_DEVICE_CDC_INDEX index,
    USB_DEVICE_CDC_EVENT event,
    void * pData,
    uintptr_t userData
)
{
    APP_DATA * appDataObject;
    USB_CDC_CONTROL_LINE_STATE * controlLineStateData;
    USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE * eventDataRead;
    
    appDataObject = (APP_DATA *)userData;

    switch(event)
    {
        case USB_DEVICE_CDC_EVENT_GET_LINE_CODING:

            /* This means the host wants to know the current line
             * coding. This is a control transfer request. Use the
             * USB_DEVICE_ControlSend() function to send the data to
             * host.  */

            USB_DEVICE_ControlSend(appDataObject->deviceHandle,
                    &appDataObject->getLineCodingData, sizeof(USB_CDC_LINE_CODING));

            break;

        case USB_DEVICE_CDC_EVENT_SET_LINE_CODING:

            /* This means the host wants to set the line coding.
             * This is a control transfer request. Use the
             * USB_DEVICE_ControlReceive() function to receive the
             * data from the host */

            USB_DEVICE_ControlReceive(appDataObject->deviceHandle,
                    &appDataObject->setLineCodingData, sizeof(USB_CDC_LINE_CODING));

            break;

        case USB_DEVICE_CDC_EVENT_SET_CONTROL_LINE_STATE:

            /* This means the host is setting the control line state.
             * Read the control line state. We will accept this request
             * for now. */

            controlLineStateData = (USB_CDC_CONTROL_LINE_STATE *)pData;
            appDataObject->controlLineStateData.dtr = controlLineStateData->dtr;
            appDataObject->controlLineStateData.carrier = controlLineStateData->carrier;

            USB_DEVICE_ControlStatus(appDataObject->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);

            break;

        case USB_DEVICE_CDC_EVENT_SEND_BREAK:

            /* This means that the host is requesting that a break of the
             * specified duration be sent. Read the break duration */

            appDataObject->breakData = ((USB_DEVICE_CDC_EVENT_DATA_SEND_BREAK *)pData)->breakDuration;
            
            /* Complete the control transfer by sending a ZLP  */
            USB_DEVICE_ControlStatus(appDataObject->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);
            
            break;

        case USB_DEVICE_CDC_EVENT_READ_COMPLETE:

            /* This means that the host has sent some data*/
            eventDataRead = (USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE *)pData;
            
            if(eventDataRead->status != USB_DEVICE_CDC_RESULT_ERROR)
            {
                appDataObject->isReadComplete = true;
                
                appDataObject->numBytesRead = eventDataRead->length; 
            }
            break;

        case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_RECEIVED:

            /* The data stage of the last control transfer is
             * complete. For now we accept all the data */

            USB_DEVICE_ControlStatus(appDataObject->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);
            break;

        case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_SENT:

            /* This means the GET LINE CODING function data is valid. We don't
             * do much with this data in this demo. */
            break;

        case USB_DEVICE_CDC_EVENT_WRITE_COMPLETE:

            /* This means that the data write got completed. We can schedule
             * the next read. */

            appDataObject->isWriteComplete = true;
            break;

        default:
            break;
    }

    return USB_DEVICE_CDC_EVENT_RESPONSE_NONE;
}

/***********************************************
 * Application USB Device Layer Event Handler.
 ***********************************************/
void APP_USBDeviceEventHandler 
(
    USB_DEVICE_EVENT event, 
    void * eventData, 
    uintptr_t context 
)
{
    USB_DEVICE_EVENT_DATA_CONFIGURED *configuredEventData;

    switch(event)
    {
        case USB_DEVICE_EVENT_SOF:

            /* This event is used for switch debounce. This flag is reset
             * by the switch process routine. */
            appData.sofEventHasOccurred = true;
            
            break;

        case USB_DEVICE_EVENT_RESET:

            /* Update LED to show reset state */
            BLUE_LED_OFF();

            appData.isConfigured = false;

            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            /* Check the configuration. We only support configuration 1 */
            configuredEventData = (USB_DEVICE_EVENT_DATA_CONFIGURED*)eventData;
            
            if ( configuredEventData->configurationValue == 1)
            {
                /* Update LED to show configured state */
                BLUE_LED_ON();
                
                /* Register the CDC Device application event handler here.
                 * Note how the appData object pointer is passed as the
                 * user data */

                USB_DEVICE_CDC_EventHandlerSet(USB_DEVICE_CDC_INDEX_0, APP_USBDeviceCDCEventHandler, (uintptr_t)&appData);

                /* Mark that the device is now configured */
                appData.isConfigured = true;
            }
            
            break;

        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS was detected. We can attach the device */
            USB_DEVICE_Attach(appData.deviceHandle);
            
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:
            
            /* VBUS is not available. We can detach the device */
            USB_DEVICE_Detach(appData.deviceHandle);
            
            appData.isConfigured = false;
            
            BLUE_LED_OFF();
            
            break;

        case USB_DEVICE_EVENT_SUSPENDED:

            /* Switch LED to show suspended state */
            BLUE_LED_OFF();
            
            break;

        case USB_DEVICE_EVENT_RESUMED:
        
            if(appData.isConfigured == true)
            {
                BLUE_LED_ON ();
            }
            break;
        case USB_DEVICE_EVENT_ERROR:
        default:
            
            break;
    }
}

//SQI FUNCTIONS
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

void APP_ProcessSwitchPress(void)
{
    /* This function checks if the switch is pressed and then
     * debounces the switch press*/
    
    if(SWITCH1_STATE_PRESSED == (SWITCH1_Get()))
    {
        if(appData.ignoreSwitchPress)
        {
            /* This means the key press is in progress */
            if(appData.sofEventHasOccurred)
            {
                /* A timer event has occurred. Update the debounce timer */
                appData.switchDebounceTimer ++;
                appData.sofEventHasOccurred = false;
                
                if (USB_DEVICE_ActiveSpeedGet(appData.deviceHandle) == USB_SPEED_FULL)
                {
                    appData.debounceCount = APP_USB_SWITCH_DEBOUNCE_COUNT_FS;
                }
                else if (USB_DEVICE_ActiveSpeedGet(appData.deviceHandle) == USB_SPEED_HIGH)
                {
                    appData.debounceCount = APP_USB_SWITCH_DEBOUNCE_COUNT_HS;
                }
                if(appData.switchDebounceTimer == appData.debounceCount)
                {
                    /* Indicate that we have valid switch press. The switch is
                     * pressed flag will be cleared by the application tasks
                     * routine. We should be ready for the next key press.*/
                    appData.isSwitchPressed = true;
                    appData.switchDebounceTimer = 0;
                    appData.ignoreSwitchPress = false;
                }
            }
        }
        else
        {
            /* We have a fresh key press */
            appData.ignoreSwitchPress = true;
            appData.switchDebounceTimer = 0;
        }
    }
    else
    {
        /* No key press. Reset all the indicators. */
        appData.ignoreSwitchPress = false;
        appData.switchDebounceTimer = 0;
        appData.sofEventHasOccurred = false;
    }
}

/*****************************************************
 * This function is called in every step of the
 * application state machine.
 *****************************************************/

bool APP_StateReset(void)
{
    /* This function returns true if the device
     * was reset  */

    bool retVal;

    if(appData.isConfigured == false)
    {
        appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
        appData.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
        appData.writeTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
        appData.isReadComplete = true;
        appData.isWriteComplete = true;
        retVal = true;
    }
    else
    {
        retVal = false;
    }

    return(retVal);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize(void)

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize(void)
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    
    /* Device Layer Handle  */
    appData.deviceHandle = USB_DEVICE_HANDLE_INVALID ;

    /* Device configured status */
    appData.isConfigured = false;

    /* Initial get line coding state */
    appData.getLineCodingData.dwDTERate = 9600;
    appData.getLineCodingData.bParityType = 0;
    appData.getLineCodingData.bCharFormat= 0; 
    appData.getLineCodingData.bDataBits = 8;

    /* Read Transfer Handle */
    appData.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

    /* Write Transfer Handle */
    appData.writeTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

    /* Initialize the read complete flag */
    appData.isReadComplete = true;

    /*Initialize the write complete flag*/
    appData.isWriteComplete = true;

    /* Initialize Ignore switch flag */
    appData.ignoreSwitchPress = false;

    /* Reset the switch debounce counter */
    appData.switchDebounceTimer = 0;

    /* Reset other flags */
    appData.sofEventHasOccurred = false;
    
    /* To know status of Switch */
    appData.isSwitchPressed = false;

    /* Set up the read buffer */
    appData.cdcReadBuffer = &cdcReadBuffer[0];

    /* Set up the read buffer */
    appData.cdcWriteBuffer = &cdcWriteBuffer[0];
    
    appData.totalBytesWrite = 0;

    APP_QSPI_Initialize ();
    
    timerNotRunning = true;
    
    SUCCESS_LED_OFF();
    BLUE_LED_OFF();
    RED_LED_OFF();

}


/******************************************************************************
  Function:
    void APP_Tasks(void)

  Remarks:
    See prototype in app.h.
 */
void APP_Tasks(void)
{
    /* Update the application state machine based
     * on the current state */
    static uint32_t  *cdcReadAddress = NULL;
    static uint32_t  *sqiReadBuffAddress = NULL;

    static uint32_t sqiWriteAddress = 0;
     
    switch(appData.state)
    {
        case APP_STATE_INIT:
        {
            
            timer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, CLOCK_TICK_TIMER_PERIOD_MS, SYS_TIME_PERIODIC);
            
            /* Open the device layer */
            appData.deviceHandle = USB_DEVICE_Open( USB_DEVICE_INDEX_0, DRV_IO_INTENT_READWRITE );

            if(appData.deviceHandle != USB_DEVICE_HANDLE_INVALID)
            {
                /* Register a callback with device layer to get event notification (for end point 0) */
                USB_DEVICE_EventHandlerSet(appData.deviceHandle, APP_USBDeviceEventHandler, 0);
                
                appData.state = APP_STATE_QSPI_RESET;
            }
            else
            {
                /* The Device Layer is not ready to be opened. We should try
                 * again later. */
            }

            break;
        }
        case APP_STATE_QSPI_RESET:
        {
            APP_ResetFlash();
            appData.state = APP_STATE_QSPI_ENABLE_QUADIO;
            
            break;
        }
        case APP_STATE_QSPI_ENABLE_QUADIO:
        {
            APP_EnableQuadIO();
            appData.state = APP_STATE_QSPI_UNLOCK;
            
            break;
        }
        case APP_STATE_QSPI_UNLOCK:
        {
            APP_UnlockFlash();
            appData.state = APP_STATE_QSPI_READ_JEDECID;           
            
            break;
        }
        case APP_STATE_QSPI_READ_JEDECID:
        {
            APP_ReadJedecId(&qspiData.jedec_id);

            if (qspiData.jedec_id != SST26VF032B_JEDEC_ID)
            {
                appData.state = APP_STATE_ERROR;
                break;
            }
            appData.state = APP_STATE_IDLE;
            
            break;
        }
        case APP_STATE_IDLE:
        {
            switch (appData.event)
            {
                case APP_IMGFLASH_EVENT_START_FLASH:
                {
                    appData.event = APP_IMGFLASH_EVENT_NONE;
                    
                    appData.state = APP_STATE_USB_START_DOWNLOAD;

                    break;
                }
                default:
                    break;
            }
            
            break;
        }            
        case APP_STATE_USB_START_DOWNLOAD:
        {
            if (appData.isConfigured)
            {
                appData.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
                appData.writeTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
                appData.isReadComplete = true;
                appData.isWriteComplete = true;
                appData.totalBytesRead = 0;
                appData.numBytesRead = 0;
                appData.bytesToRead = APP_READ_BUFFER_SIZE/2;
                appData.totalBytesCopied = 0;
                appData.totalBytesWrite = 0;
                qspiData.writeOffset = 0;                
                appData.state = APP_STATE_QSPI_ERASE;                

                APP_ShowSQIUpdateLog("Ready.\nPlease send BIN file via USB.");
            }
            else
            {
                APP_ShowSQIUpdateLog("USB not ready. Please connect to PC.");
                appData.state = APP_STATE_IDLE;
            }
            
            break;
        }
        case APP_STATE_QSPI_ERASE:
        {
            APP_ChipErase();
            
            appData.state = APP_STATE_QSPI_ERASE_WAIT;
            
            break;
        }
        case APP_STATE_QSPI_ERASE_WAIT:
        {
            APP_WaitUntilTransferDone();
            
            appData.state = APP_STATE_USB_DOWNLOAD;            

            break;
        }
        case APP_STATE_WAIT_FOR_CONFIGURATION:
        {
            /* Check if the device was configured */
            if(appData.isConfigured)
            {
                appData.state = APP_STATE_USB_DOWNLOAD;             
            }
            
            break;
        }
        case APP_STATE_USB_PREP_DOWNLOAD:
        {
            if (appData.totalBytesRead > 0)
            {                
                // shift remainder of unwritten data in cdcReadBuffer
                // to the front buffer
                memcpy(&appData.cdcReadBuffer[0], 
                       &appData.cdcReadBuffer[APP_READ_BUFFER_SIZE],
                       appData.totalBytesRead);
                
            }
            appData.state = APP_STATE_USB_DOWNLOAD;
            
            break;
        }            
        case APP_STATE_USB_DOWNLOAD:
        {
            if(APP_StateReset())
            {
                break;
            }
            appData.state = APP_STATE_USB_DOWNLOAD_WAIT;
            
            if(appData.isReadComplete == true)
            {
                appData.isReadComplete = false;
                appData.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

                
                USB_DEVICE_CDC_Read (USB_DEVICE_CDC_INDEX_0,
                        &appData.readTransferHandle,
                        &appData.cdcReadBuffer[appData.totalBytesRead],
                        APP_READ_BUFFER_SIZE);
                
                if(appData.readTransferHandle == USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID)
                    appData.state = APP_STATE_ERROR;
                
            }
            
            break;
        }            
        case APP_STATE_USB_DOWNLOAD_WAIT:
        {
            if(APP_StateReset())
            {
                break;
            }

            if(appData.isReadComplete)
            {
                if(appData.numBytesRead > 0)
                {
                    appData.totalBytesRead += appData.numBytesRead;
                    appData.totalBytesCopied += appData.numBytesRead;
                                       
                    if(appData.totalBytesRead < APP_READ_BUFFER_SIZE)
                    {
                        appData.state = APP_STATE_USB_DOWNLOAD;
                    }
                    else
                    {
                        appData.totalBytesRead %= APP_READ_BUFFER_SIZE;
                        appData.state = APP_STATE_QSPI_WRITE;
                    }
                }
            }            
            
            /* Process events */
            switch (appData.event)
            {
                case APP_IMGFLASH_EVENT_EXIT:
                {
                    appData.event = APP_IMGFLASH_EVENT_NONE;
                    appData.state = APP_STATE_QSPI_FINAL_WRITE;
                    
                    break;
                }
                default:
                    break;
            }
            
            /* handle progress */
            if (appData.totalBytesCopied && (tick_count > tick_count_last))
            {
                if (tick_count - tick_count_last > NUM_COUNT_SEC_TICK)
                {
                    sprintf(charBuff, "Downloading %7u kb", (unsigned int) (appData.totalBytesCopied/1024));
                    APP_ShowSQIUpdateLog(charBuff);
                    
                    tick_count_last = tick_count;
                }
            }
            else
            {
                tick_count_last = tick_count;
            }
            break;
        }
        
        case APP_STATE_QSPI_WRITE:
        {
            cdcReadAddress = (uint32_t *)&appData.cdcReadBuffer[qspiData.writeOffset];
            sqiWriteAddress = (MEM_START_ADDRESS + appData.totalBytesWrite);
                        
            APP_PageWrite(cdcReadAddress, sqiWriteAddress);
                                    
            appData.state = APP_STATE_QSPI_WRITE_WAIT;
            
            break;
        }
        case APP_STATE_QSPI_WRITE_WAIT:
        {
            APP_WaitUntilTransferDone();
            appData.state = APP_STATE_QSPI_READ;
            
            break;            
        }
        case APP_STATE_QSPI_READ:
        {
            sqiReadBuffAddress = (uint32_t *)qspiData.readBuffer;
            APP_Read(sqiReadBuffAddress, PAGE_SIZE, sqiWriteAddress);
            
            appData.state = APP_STATE_QSPI_VERIFY;
            
            break;
        }
        case APP_STATE_QSPI_VERIFY:
        {
            APP_WaitUntilTransferDone();
             
            if (!memcmp(cdcReadAddress, sqiReadBuffAddress, PAGE_SIZE))
            {
                appData.totalBytesWrite += PAGE_SIZE;
                
                if(qspiData.writeOffset == 0)
                {
                    // write the second page
                    qspiData.writeOffset = PAGE_SIZE;
                    appData.state = APP_STATE_QSPI_WRITE;
                }
                else
                {
                    qspiData.writeOffset = 0;
                    appData.state = APP_STATE_USB_PREP_DOWNLOAD;
                }
                SUCCESS_LED_ON();
            }
            else
            {
                appData.state = APP_STATE_ERROR;
            }

            break;
        }
        case APP_STATE_QSPI_FINAL_WRITE:
        {
            static uint32_t executedCount = 0;
            static int numOfWriteBytes = 0;
            static uint8_t *writeBufferAddress = NULL;
            
            APP_WaitUntilTransferDone();
            
            if (executedCount == 0)
            {
                
                numOfWriteBytes = appData.totalBytesRead;
                
                memcpy(qspiData.writeBuffer,
                        (uint32_t *)&appData.cdcReadBuffer[0],
                        numOfWriteBytes);
            }
            
            if (numOfWriteBytes > 0)
            {
                writeBufferAddress = &qspiData.writeBuffer[PAGE_SIZE*executedCount];            
                APP_PageWrite(writeBufferAddress, 
                    (MEM_START_ADDRESS + appData.totalBytesWrite));
                appData.totalBytesWrite += PAGE_SIZE;
                numOfWriteBytes -= PAGE_SIZE;
                executedCount++;
            }
            else
            {
                appData.state = APP_STATE_IDLE;
                sprintf(charBuff, "update complete");
                APP_ShowSQIUpdateLog(charBuff);

            }

            break;            
        }
        case APP_STATE_ERROR:
        {            
            sprintf(charBuff, "error");
            APP_ShowSQIUpdateLog(charBuff);
            SYS_TIME_TimerStop(timer);
            SUCCESS_LED_OFF();
            BLUE_LED_OFF();
            RED_LED_ON();    
            break;
        }
        default:
            
            break;
    }
}

/*******************************************************************************
 End of File
 */
