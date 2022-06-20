/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_reader.c

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

#include "app_reader.h"
#include "gfx/legato/generated/le_gen_assets.h"
#include "gfx/legato/generated/screen/le_gen_screen_default.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_READER_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

static leTableString tableString_DrawRLE;
static leTableString tableString_DrawPaletteCompressed;
static leTableString tableString_DrawRaw;
static leTableString tableString_DrawJpeg;
static leTableString tableString_DrawPNG;

static leTableString tableString_ImageIsPaletteCompressed;
static leTableString tableString_ImageIsRaw;
static leTableString tableString_ImageIsRLE;
static leTableString tableString_ImageIsPNG;
static leTableString tableString_ImageIsJPEG;

APP_READER_DATA CACHE_ALIGN appData;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

leResult leApplication_MediaOpenRequest(leStream* stream)
{
    appData.transferStatus = DRV_SST26_TransferStatusGet(appData.handle);
    
    if (appData.handle != DRV_HANDLE_INVALID
            && appData.transferStatus == DRV_SST26_TRANSFER_COMPLETED)
        return LE_SUCCESS;
    
    return LE_FAILURE;
}

leResult leApplication_MediaReadRequest(leStream* stream, // stream reader
                                        uint32_t address,  // address
                                        uint32_t readSize,  // dest size
                                        uint8_t* destBuffer)
{
    uint32_t total, rem, sz;
    uint8_t* ptr;
       
    if(stream->desc->location != LE_STREAM_LOCATION_ID_SQI)
    {
        // failure tells the decoder to abort and move on
        return LE_FAILURE;
    }
    
    if (DRV_SST26_Status(DRV_SST26_INDEX) != SYS_STATUS_READY)
    {
         // failure tells the decoder to abort and move on
        return LE_FAILURE;
    }
    
    appData.mediaStream = stream;
    appData.destBuffer = destBuffer;
    appData.readSize = readSize;
    appData.readAddress = (void*)address;
    
    rem = readSize;
    ptr = (uint8_t*)appData.destBuffer;
    total = 0;
    
    while(rem > 0)
    {
        sz = rem;
        
        if(sz > DRV_SST26_PAGE_SIZE * DRV_SST26_BUFF_DESC_NUMBER)
        {
            sz = DRV_SST26_PAGE_SIZE * DRV_SST26_BUFF_DESC_NUMBER;
        }
        
        DRV_SST26_Read(appData.handle,
                       ptr,
                       sz,
                       (uint32_t)appData.readAddress + total);
        
        while(DRV_SST26_TransferStatusGet(appData.handle) != DRV_SST26_TRANSFER_COMPLETED)
        { }
         
        ptr += sz;
        rem -= sz;
        total += sz;
    }
    
    leStream_DataReady(appData.mediaStream);
    
    return LE_SUCCESS; // success tells the decoder to keep going
}

void leApplication_MediaCloseRequest(leStream* stream)
{
}

void event_default_LogoButton_OnReleased(leButtonWidget* btn)
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

void event_default_SloganButton_OnReleased(leButtonWidget* btn)
{
    if (default_LogoButton->releasedImage == &MHGS_logo_small_compressed)
    {
        //Show the next message
        leTableString_Constructor(&tableString_DrawRLE, stringID_DrawRLE); 
        default_SloganButton->fn->setString(default_SloganButton, (leString*)&tableString_DrawRLE);

        //Draw the intended from the previous message
        default_LogoButton->fn->setPressedImage(default_LogoButton, &MHGS_logo_small_raw);
        default_LogoButton->fn->setReleasedImage(default_LogoButton, &MHGS_logo_small_raw);
        
        leTableString_Constructor(&tableString_ImageIsRaw, stringID_ImageIsRaw); 
        default_ImageTypeLabelWidget->fn->setString(default_ImageTypeLabelWidget, (leString*)&tableString_ImageIsRaw);
    }
    else if (default_LogoButton->releasedImage == &MHGS_logo_small_raw)
    {
        //Show the next message
        leTableString_Constructor(&tableString_DrawPNG, stringID_DrawPNG); 
        default_SloganButton->fn->setString(default_SloganButton, (leString*)&tableString_DrawPNG);

        //Draw the intended from the previous message
        default_LogoButton->fn->setPressedImage(default_LogoButton, &MHGS_logo_small_rle);
        default_LogoButton->fn->setReleasedImage(default_LogoButton, &MHGS_logo_small_rle);

        leTableString_Constructor(&tableString_ImageIsRLE, stringID_ImageIsRLE); 
        default_ImageTypeLabelWidget->fn->setString(default_ImageTypeLabelWidget, (leString*)&tableString_ImageIsRLE);
    }
    else if (default_LogoButton->releasedImage == &MHGS_logo_small_rle)
    {
        //Show the next message
        leTableString_Constructor(&tableString_DrawJpeg, stringID_DrawJpeg); 
        default_SloganButton->fn->setString(default_SloganButton, (leString*)&tableString_DrawJpeg);

        //Draw the intended from the previous message
        default_LogoButton->fn->setPressedImage(default_LogoButton, &MHGS_logo_small_png);
        default_LogoButton->fn->setReleasedImage(default_LogoButton, &MHGS_logo_small_png);

        leTableString_Constructor(&tableString_ImageIsPNG, stringID_ImageIsPNG); 
        default_ImageTypeLabelWidget->fn->setString(default_ImageTypeLabelWidget, (leString*)&tableString_ImageIsPNG);
    }
    else if (default_LogoButton->releasedImage == &MHGS_logo_small_png)
    {
        //Show the next message
        leTableString_Constructor(&tableString_DrawPaletteCompressed, stringID_DrawPaletteCompressed); 
        default_SloganButton->fn->setString(default_SloganButton, (leString*)&tableString_DrawPaletteCompressed);

        //Draw the intended from the previous message
        default_LogoButton->fn->setPressedImage(default_LogoButton, &MHGS_logo_small_jpeg);
        default_LogoButton->fn->setReleasedImage(default_LogoButton, &MHGS_logo_small_jpeg);

        leTableString_Constructor(&tableString_ImageIsJPEG, stringID_ImageIsJPEG); 
        default_ImageTypeLabelWidget->fn->setString(default_ImageTypeLabelWidget, (leString*)&tableString_ImageIsJPEG);
    }
    else if (default_LogoButton->releasedImage == &MHGS_logo_small_jpeg)
    {
        //Show the next message
        leTableString_Constructor(&tableString_DrawRaw, stringID_DrawRaw); 
        default_SloganButton->fn->setString(default_SloganButton, (leString*)&tableString_DrawRaw);

        //Draw the intended from the previous message
        default_LogoButton->fn->setPressedImage(default_LogoButton, &MHGS_logo_small_compressed);
        default_LogoButton->fn->setReleasedImage(default_LogoButton, &MHGS_logo_small_compressed);

        leTableString_Constructor(&tableString_ImageIsPaletteCompressed, stringID_ImageIsPaletteCompressed); 
        default_ImageTypeLabelWidget->fn->setString(default_ImageTypeLabelWidget, (leString*)&tableString_ImageIsPaletteCompressed);
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_READER_Initialize ( void )

  Remarks:
    See prototype in app_reader.h.
 */

//static CACHE_ALIGN uint8_t testData[32];

void APP_READER_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

//    while(DRV_SST26_Status(DRV_SST26_INDEX) != SYS_STATUS_READY)
//    { }
//    
//respin:        
//    appData.handle = DRV_SST26_Open(DRV_SST26_INDEX, DRV_IO_INTENT_READ);
//
//    if (appData.handle == DRV_HANDLE_INVALID)
//    {
//        goto respin;
//    }
//    
//    appData.state = APP_STATE_IDLE;
//    
//    DRV_SST26_Read(appData.handle,
//                   testData,
//                   32,
//                   (uint32_t)0x18D4A0);
//    
//    while(DRV_SST26_TransferStatusGet(appData.handle) != DRV_SST26_TRANSFER_COMPLETED)
//    { }
}


/******************************************************************************
  Function:
    void APP_READER_Tasks ( void )

  Remarks:
    See prototype in app_reader.h.
 */

void APP_READER_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
			appData.transferStatus = DRV_SST26_TransferStatusGet(appData.handle);

			if (appData.transferStatus == DRV_SST26_TRANSFER_COMPLETED)
            {
                // indicate that the data buffer is ready
                leStream_DataReady(appData.mediaStream);

				appData.state = APP_STATE_IDLE;
			}

            break;
        }

        case APP_STATE_IDLE:
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
