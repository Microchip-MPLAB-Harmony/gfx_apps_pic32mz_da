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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <string.h>
#include "app.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

SYS_FS_HANDLE usb_fileHandle;
SYS_FS_HANDLE jpeg_fileHandle;
SYS_FS_HANDLE png_fileHandle;

long          fileSize;

int32_t       usbDeviceConnected;
int32_t       sdcardDeviceConnected;

#define ASSET_BIN_FILENAME     "/Assets.bin"
#define JPEG_FILENAME        "/MHGS_logo_small_jpeg.jpg"
#define PNG_FILENAME         "/MHGS_logo_small_png.png"

#if SYS_FS_AUTOMOUNT_ENABLE == true
#define USB_MOUNT_NAME       SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0
#define SDCARD_MOUNT_NAME    SYS_FS_MEDIA_IDX1_MOUNT_NAME_VOLUME_IDX0
#else
#define USB_ID      0
#define SDCARD_ID   1

#define USB_MOUNT_NAME       "/mnt/usb"
#define USB_DEV_NAME         "/dev/sda1"
#define SDCARD_MOUNT_NAME       "/mnt/myDrive1"
#define SDCARD_DEV_NAME         "/dev/mmcblka1"
#endif

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

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

SYS_FS_HANDLE APP_GetFileHandle( uint32_t dataLocation )
{
    SYS_FS_HANDLE handle = SYS_FS_HANDLE_INVALID;
    
    switch(dataLocation)
    {
        case LE_STREAM_LOCATION_ID_JPEG_IMG0:
        {
            handle = jpeg_fileHandle;
            break;
        }
        case LE_STREAM_LOCATION_ID_PNG_IMG0:
        {
            handle = png_fileHandle;
            break;
        }
        case LE_STREAM_LOCATION_ID_USB_BIN:
        {
            handle = usb_fileHandle;
            break;
        }
        default:
            break;
    }
    
    return handle;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Legato Media Callback Functions
// *****************************************************************************
// *****************************************************************************

leResult leApplication_MediaOpenRequest(leStream* stream)
{
    if ( (usbDeviceConnected == 0 && sdcardDeviceConnected == 0)
            || stream->desc->location == LE_STREAM_LOCATION_ID_INTERNAL 
            || appData.state == APP_STATE_ERROR)
        return LE_FAILURE;

    appData.mediaStream = stream;
    appData.assetFileHandle = APP_GetFileHandle(appData.mediaStream->desc->location);

    if(SYS_FS_FileEOF(appData.assetFileHandle) == true)
    {
        if (SYS_FS_FileSeek(appData.assetFileHandle, (int32_t)0, SYS_FS_SEEK_SET) == -1)
        {
#ifdef RGB_LED_R_On
            RGB_LED_R_On();
#else
            LED2_On();
#endif
            return LE_FAILURE;
        }
    }
    
#ifdef RGB_LED_R_Off
        RGB_LED_R_Off();
#else
        LED2_Off();
#endif
    return LE_SUCCESS;
}

leResult leApplication_MediaReadRequest(leStream* stream, // stream reader
                                        uint32_t address,  // address
                                        uint32_t readSize,  // dest size
                                        uint8_t* destBuffer)
{
    if (SYS_FS_FileSeek(appData.assetFileHandle, (int32_t)address, SYS_FS_SEEK_SET) == -1)
    {
#ifdef RGB_LED_R_On
            RGB_LED_R_On();
#else
            LED2_On();
#endif
        return LE_FAILURE;
    }

    if (SYS_FS_FileRead(appData.assetFileHandle, (void*)destBuffer, readSize) <= 0)
    {
#ifdef RGB_LED_R_On
            RGB_LED_R_On();
#else
            LED2_On();
#endif
        return LE_FAILURE;
    }
    
    leStream_DataReady(appData.mediaStream);
    
    return LE_SUCCESS; // success tells the decoder to keep going
}

void leApplication_MediaCloseRequest(leStream* stream)
{
    
}

void event_Main_LogoButton_OnReleased(leButtonWidget* btn)
{
    if (leGetStringLanguage() == language_English)
    {
        leSetStringLanguage(language_Chinese);
    }
    else
    {
        leSetStringLanguage(language_English);
    }
}

void event_Main_SloganButton_OnReleased(leButtonWidget* btn)
{
    if (Main_LogoButton->releasedImage == &MHGS_logo_small_compressed)
    {
        //Show the next message
        leTableString_Constructor(&string_DrawRLE, stringID_DrawRLE); 
        Main_SloganButton->fn->setString(Main_SloganButton, (leString*)&string_DrawRLE);

        //Draw the intended from the previous message
        Main_LogoButton->fn->setPressedImage(Main_LogoButton, &MHGS_logo_small_raw);
        Main_LogoButton->fn->setReleasedImage(Main_LogoButton, &MHGS_logo_small_raw);
        
        leTableString_Constructor(&string_ImageIsRaw, stringID_ImageIsRaw); 
        Main_ImageTypeLabelWidget->fn->setString(Main_ImageTypeLabelWidget, (leString*)&string_ImageIsRaw);
    }
    else if (Main_LogoButton->releasedImage == &MHGS_logo_small_raw)
    {
        //Show the next message
        leTableString_Constructor(&string_DrawPNG, stringID_DrawPNG); 
        Main_SloganButton->fn->setString(Main_SloganButton, (leString*)&string_DrawPNG);

        //Draw the intended from the previous message
        Main_LogoButton->fn->setPressedImage(Main_LogoButton, &MHGS_logo_small_rle);
        Main_LogoButton->fn->setReleasedImage(Main_LogoButton, &MHGS_logo_small_rle);

        leTableString_Constructor(&string_ImageIsRLE, stringID_ImageIsRLE); 
        Main_ImageTypeLabelWidget->fn->setString(Main_ImageTypeLabelWidget, (leString*)&string_ImageIsRLE);
    }
    else if (Main_LogoButton->releasedImage == &MHGS_logo_small_rle)
    {
        //Show the next message
        leTableString_Constructor(&string_DrawJpeg, stringID_DrawJpeg); 
        Main_SloganButton->fn->setString(Main_SloganButton, (leString*)&string_DrawJpeg);

        //Draw the intended from the previous message
        Main_LogoButton->fn->setPressedImage(Main_LogoButton, &MHGS_logo_small_png);
        Main_LogoButton->fn->setReleasedImage(Main_LogoButton, &MHGS_logo_small_png);

        leTableString_Constructor(&string_ImageIsPNG, stringID_ImageIsPNG); 
        Main_ImageTypeLabelWidget->fn->setString(Main_ImageTypeLabelWidget, (leString*)&string_ImageIsPNG);
    }
    else if (Main_LogoButton->releasedImage == &MHGS_logo_small_png)
    {
        //Show the next message
        leTableString_Constructor(&string_DrawPaletteCompressed, stringID_DrawPaletteCompressed); 
        Main_SloganButton->fn->setString(Main_SloganButton, (leString*)&string_DrawPaletteCompressed);

        //Draw the intended from the previous message
        Main_LogoButton->fn->setPressedImage(Main_LogoButton, &MHGS_logo_small_jpeg);
        Main_LogoButton->fn->setReleasedImage(Main_LogoButton, &MHGS_logo_small_jpeg);

        leTableString_Constructor(&string_ImageIsJPEG, stringID_ImageIsJPEG); 
        Main_ImageTypeLabelWidget->fn->setString(Main_ImageTypeLabelWidget, (leString*)&string_ImageIsJPEG);
    }
    else if (Main_LogoButton->releasedImage == &MHGS_logo_small_jpeg)
    {
        //Show the next message
        leTableString_Constructor(&string_DrawRaw, stringID_DrawRaw); 
        Main_SloganButton->fn->setString(Main_SloganButton, (leString*)&string_DrawRaw);

        //Draw the intended from the previous message
        Main_LogoButton->fn->setPressedImage(Main_LogoButton, &MHGS_logo_small_compressed);
        Main_LogoButton->fn->setReleasedImage(Main_LogoButton, &MHGS_logo_small_compressed);

        leTableString_Constructor(&string_ImageIsPaletteCompressed, stringID_ImageIsPaletteCompressed); 
        Main_ImageTypeLabelWidget->fn->setString(Main_ImageTypeLabelWidget, (leString*)&string_ImageIsPaletteCompressed);
    }
}

void event_Launch_ButtonWidget_LaunchLabel_OnReleased(leButtonWidget* btn)
{
    if (leGetStringLanguage() == language_Chinese)
    {
        leSetStringLanguage(language_English);
    }
    else
    {
        leSetStringLanguage(language_Chinese);
    }
}

void event_Launch_ButtonWidget_GoToMain_OnReleased(leButtonWidget* btn)
{
    legato_showScreen(screenID_Main);   
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Legato USB Callback Functions
// *****************************************************************************
// *****************************************************************************

USB_HOST_EVENT_RESPONSE APP_USBHostEventHandler (USB_HOST_EVENT event,
                                                 void* eventData,
                                                 uintptr_t context)
{
    switch (event)
    {
        case USB_HOST_EVENT_DEVICE_UNSUPPORTED:
            break;
        default:
            break;
    }
    
    return(USB_HOST_EVENT_RESPONSE_NONE);
}

#if SYS_FS_AUTOMOUNT_ENABLE == true

void APP_SYSFSEventHandler(SYS_FS_EVENT event,
                           void* eventData,
                           uintptr_t context)
{
    switch(event)
    {
        case SYS_FS_EVENT_MOUNT:
        {
            if(strcmp((const char *)eventData, USB_MOUNT_NAME) == 0)
            {
                usbDeviceConnected = 1;
                appData.state = APP_OPEN_FILES;
            }
            
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                sdcardDeviceConnected = 1;
                appData.state = APP_OPEN_FILES;
            }
            
            break;
        }    
        case SYS_FS_EVENT_UNMOUNT:
        {
            if(strcmp((const char *)eventData, USB_MOUNT_NAME) == 0)
            {
                usbDeviceConnected = 0;
                appData.state = APP_STATE_IDLE;
            }
            
            if(strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                sdcardDeviceConnected = 0;
                appData.state = APP_STATE_IDLE;
            }
            
            break;
        }
        default:
            break;
    }
}

#endif

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    usbDeviceConnected = 0;    
    sdcardDeviceConnected = 0;

#ifdef RGB_LED_R_Off
        RGB_LED_B_Off();
        RGB_LED_G_Off();
        RGB_LED_R_Off();
#else
        LED1_Off();
        LED2_Off();
        LED3_Off();
#endif
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            appData.state = APP_STATE_BUS_ENABLE;
            break;
        }
        
        case APP_STATE_BUS_ENABLE:
        {
            // set the event handler and enable the bus
#if SYS_FS_AUTOMOUNT_ENABLE == true
            SYS_FS_EventHandlerSet(&APP_SYSFSEventHandler, (uintptr_t)NULL);
#endif
            USB_HOST_EventHandlerSet(&APP_USBHostEventHandler, 0);
            USB_HOST_BusEnable(0);
            
            appData.state = APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE;
            break;
        }
		
        case APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE:
        {
            if(USB_HOST_BusIsEnabled(0))
            {
#if SYS_FS_AUTOMOUNT_ENABLE == true
                appData.state = APP_STATE_IDLE;
#else
                appData.state = APP_MOUNT_DRIVE;
#endif
            }
            break;
        }
        
#if SYS_FS_AUTOMOUNT_ENABLE == false
        case APP_MOUNT_DRIVE:
        {
            if( SYS_FS_Mount( USB_DEV_NAME, USB_MOUNT_NAME, FAT, USB_ID, NULL) == SYS_FS_RES_SUCCESS )
            {
                if(SYS_FS_CurrentDriveSet(USB_MOUNT_NAME) == SYS_FS_RES_SUCCESS)
                {
                    usbDeviceConnected = 1;
                    appData.state = APP_OPEN_FILES;

#ifdef RGB_LED_G_On
                    RGB_LED_G_On();
#else
                    LED1_On();
#endif
                    break;
                }
            }

            if( SYS_FS_Mount( SDCARD_DEV_NAME, SDCARD_MOUNT_NAME, FAT, SDCARD_ID, NULL) == SYS_FS_RES_SUCCESS )
            {
                if(SYS_FS_CurrentDriveSet(SDCARD_MOUNT_NAME) == SYS_FS_RES_SUCCESS)
                {
                    sdcardDeviceConnected = 1;
                    appData.state = APP_OPEN_FILES;

#ifdef RGB_LED_G_On
                    RGB_LED_G_On();
#else
                    LED1_On();
#endif
                    break;
                }
            }
            break;            
        }
#endif //SYS_FS_AUTOMOUNT_ENABLE == false
		
		case APP_OPEN_FILES:
		{
            
			usb_fileHandle  = SYS_FS_FileOpen( ASSET_BIN_FILENAME, SYS_FS_FILE_OPEN_READ);
			jpeg_fileHandle = SYS_FS_FileOpen( JPEG_FILENAME, SYS_FS_FILE_OPEN_READ);
			png_fileHandle  = SYS_FS_FileOpen( PNG_FILENAME, SYS_FS_FILE_OPEN_READ);

			if (usb_fileHandle == SYS_FS_HANDLE_INVALID
                    || jpeg_fileHandle == SYS_FS_HANDLE_INVALID
                    || png_fileHandle == SYS_FS_HANDLE_INVALID)
			{
				appData.state = APP_FILE_NOT_FOUND;
			}
			else
			{
				appData.state = APP_VALIDATE_FILE;
			}
            break;
        }

		case APP_FILE_NOT_FOUND:
		{
            SYS_FS_FileClose(usb_fileHandle);
            SYS_FS_FileClose(jpeg_fileHandle);
            SYS_FS_FileClose(png_fileHandle);

            if (usbDeviceConnected == 1)
            {
            SYS_FS_Unmount(USB_MOUNT_NAME);
                usbDeviceConnected = 0;
            }

            if (sdcardDeviceConnected == 1)
            {
                SYS_FS_Unmount(SDCARD_MOUNT_NAME);
                sdcardDeviceConnected = 0;
            }

			appData.state = APP_MOUNT_DRIVE;
            break;
        }

		case APP_VALIDATE_FILE:
        {
			fileSize = SYS_FS_FileSize(usb_fileHandle);
			fileSize |= SYS_FS_FileSize(jpeg_fileHandle);
			fileSize |= SYS_FS_FileSize(png_fileHandle);

			if (fileSize <= 0)
			{
				appData.state = APP_FILE_NOT_FOUND;
			}
			else
			{
                if (legato_getCurrentScreen() == screenID_Launch)
                {
                    Launch_ButtonWidget_GoToMain->fn->setEnabled(Launch_ButtonWidget_GoToMain, LE_TRUE);
                    Launch_ButtonWidget_GoToMain->fn->setVisible(Launch_ButtonWidget_GoToMain, LE_TRUE);
                    
    				appData.state = APP_STATE_IDLE;
                }
			}
		}

		case APP_STATE_ERROR:
        {
#ifdef RGB_LED_R_On
            RGB_LED_R_On();
#else
            LED2_On();
#endif
            break;
        }
        
		case APP_STATE_IDLE:
        default:
		{
            break;
		}
    }
}


/*******************************************************************************
 End of File
 */
