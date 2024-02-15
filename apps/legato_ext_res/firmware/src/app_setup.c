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

#include "app.h"
#include "definitions.h"
#include "gfx/legato/generated/le_gen_assets.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define SQI_LOG_STR_SIZE 64
#define TIMESTAMP_STR_SIZE 36

typedef enum
{
    SCRN_STATE_INIT,
    SCRN_STATE_IDLE,
    SCRN_STATE_EXIT,
} SETTINGS_SCRN_STATE;

typedef enum
{
    SCRN_EVENT_NONE,
    SCRN_EVENT_START_UPDATE,
    SCRN_EVENT_CONTINUE_UPDATE,
    SCRN_EVENT_CANCEL_UPDATE,
    SCRN_EVENT_ABORT_UPDATE,
    SCRN_EVENT_EXIT,
    SCRN_EVENT_SHOW_LOG,
    SCRN_EVENT_RESTART,
} SETTINGS_SCRN_EVENT;

static char timeStampStrBuff[TIMESTAMP_STR_SIZE];

static leChar timeStampStrCharBuff[TIMESTAMP_STR_SIZE] = {0};
static leFixedString timeStampStr;
static leFixedString sqiUpdateStr;
static leChar sqiUpdateStrBuff[SQI_LOG_STR_SIZE] = {0};
static SETTINGS_SCRN_STATE app_scrn_state;
static SETTINGS_SCRN_EVENT app_scrn_event;
static char charBuff[SQI_LOG_STR_SIZE];








void APP_ShowSQIUpdateLog(char * str)
{
    memcpy(charBuff, str, SQI_LOG_STR_SIZE - 1);
    charBuff[SQI_LOG_STR_SIZE - 1] = '\0';
    app_scrn_event = SCRN_EVENT_SHOW_LOG;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
void event_IntroScreen_SetupButton_OnReleased(leButtonWidget* btn)
{
    legato_showScreen(screenID_SetupScreen);
}
void event_IntroScreen_ApplicationButton_OnReleased(leButtonWidget* btn)
{
    legato_showScreen(screenID_ApplicationScreen);
}
void event_ApplicationScreen_SloganButton_OnReleased(leButtonWidget* btn)
{
    if (ApplicationScreen_LogoButton->releasedImage == &MHGS_logo_small_compressed)
    {
        //Show the next message
        leTableString_Constructor(&string_DrawPNG, stringID_DrawPNG); 
        ApplicationScreen_SloganButton->fn->setString(ApplicationScreen_SloganButton, (leString*)&string_DrawPNG);

        //Draw the intended from the previous message
        ApplicationScreen_LogoButton->fn->setPressedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_raw);
        ApplicationScreen_LogoButton->fn->setReleasedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_raw);
        
        leTableString_Constructor(&string_ImageIsRaw, stringID_ImageIsRaw); 
        ApplicationScreen_ImageTypeLabelWidget->fn->setString(ApplicationScreen_ImageTypeLabelWidget, (leString*)&string_ImageIsRaw);
    }
    else if (ApplicationScreen_LogoButton->releasedImage == &MHGS_logo_small_raw)
    {
        //Show the next message
        leTableString_Constructor(&string_DrawJpeg, stringID_DrawJpeg); 
        ApplicationScreen_SloganButton->fn->setString(ApplicationScreen_SloganButton, (leString*)&string_DrawJpeg);

        //Draw the intended from the previous message
        ApplicationScreen_LogoButton->fn->setPressedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_png);
        ApplicationScreen_LogoButton->fn->setReleasedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_png);

        leTableString_Constructor(&string_ImageIsPNG, stringID_ImageIsPNG); 
        ApplicationScreen_ImageTypeLabelWidget->fn->setString(ApplicationScreen_ImageTypeLabelWidget, (leString*)&string_ImageIsPNG);
    }
    else if (ApplicationScreen_LogoButton->releasedImage == &MHGS_logo_small_png)
    {        
        //Show the next message
        leTableString_Constructor(&string_DrawRLE, stringID_DrawRLE); 
        ApplicationScreen_SloganButton->fn->setString(ApplicationScreen_SloganButton, (leString*)&string_DrawRLE);

        //Draw the intended from the previous message
        ApplicationScreen_LogoButton->fn->setPressedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_jpeg);
        ApplicationScreen_LogoButton->fn->setReleasedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_jpeg);

        leTableString_Constructor(&string_ImageIsJPEG, stringID_ImageIsJPEG); 
        ApplicationScreen_ImageTypeLabelWidget->fn->setString(ApplicationScreen_ImageTypeLabelWidget, (leString*)&string_ImageIsJPEG);      
    }
    else if (ApplicationScreen_LogoButton->releasedImage == &MHGS_logo_small_jpeg)
    {
        //Show the next message
        leTableString_Constructor(&string_DrawPaletteCompressed, stringID_DrawPaletteCompressed); 
        ApplicationScreen_SloganButton->fn->setString(ApplicationScreen_SloganButton, (leString*)&string_DrawPaletteCompressed);

        //Draw the intended from the previous message
        ApplicationScreen_LogoButton->fn->setPressedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_rle);
        ApplicationScreen_LogoButton->fn->setReleasedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_rle);

        leTableString_Constructor(&string_ImageIsRLE, stringID_ImageIsRLE); 
        ApplicationScreen_ImageTypeLabelWidget->fn->setString(ApplicationScreen_ImageTypeLabelWidget, (leString*)&string_ImageIsRLE);
    }
    else if (ApplicationScreen_LogoButton->releasedImage == &MHGS_logo_small_rle)
    {
        //Show the next message
        leTableString_Constructor(&string_DrawRaw, stringID_DrawRaw); 
        ApplicationScreen_SloganButton->fn->setString(ApplicationScreen_SloganButton, (leString*)&string_DrawRaw);

        //Draw the intended from the previous message
        ApplicationScreen_LogoButton->fn->setPressedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_compressed);
        ApplicationScreen_LogoButton->fn->setReleasedImage(ApplicationScreen_LogoButton, &MHGS_logo_small_compressed);

        leTableString_Constructor(&string_ImageIsPaletteCompressed, stringID_ImageIsPaletteCompressed); 
        ApplicationScreen_ImageTypeLabelWidget->fn->setString(ApplicationScreen_ImageTypeLabelWidget, (leString*)&string_ImageIsPaletteCompressed);
    }
}
void event_ApplicationScreen_LogoButton_OnReleased(leButtonWidget* btn)
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

void event_SetupScreen_UpdateSQIButton_OnPressed(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_START_UPDATE;
}

void event_SetupScreen_UpdateSQIButton_OnReleased(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_ABORT_UPDATE;
}

void event_SetupScreen_RebootButtonWidget0_OnPressed(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_RESTART;
}


void event_SetupScreen_EraseYesButton_OnReleased(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_CONTINUE_UPDATE;
}

void event_SetupScreen_EraseNoButton_OnReleased(leButtonWidget* btn)
{
    app_scrn_event = SCRN_EVENT_CANCEL_UPDATE;
}


void SetupScreen_OnShow(void)
{
    SetupScreen_SQIUpdateWarningLabel->fn->setVisible(SetupScreen_SQIUpdateWarningLabel, LE_FALSE);
    
    
    leFixedString_Constructor(&sqiUpdateStr, sqiUpdateStrBuff, SQI_LOG_STR_SIZE);
    sqiUpdateStr.fn->setFont(&sqiUpdateStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DisabledString,
                                                              0));
    
    
    leFixedString_Constructor(&timeStampStr, timeStampStrCharBuff, TIMESTAMP_STR_SIZE);
//    timeStampStr.fn->setFont(&timeStampStr, (leFont*)&FPS_Font);
    sprintf(timeStampStrBuff, "Build: %s", __TIMESTAMP__);
    timeStampStr.fn->setFromCStr(&timeStampStr, timeStampStrBuff);   
    SetupScreen_TimeStampString->fn->setString(SetupScreen_TimeStampString,
                                            (leString*)&timeStampStr);
    
    
}

void SetupScreen_OnHide(void)
{
    sqiUpdateStr.fn->destructor(&sqiUpdateStr);
    timeStampStr.fn->destructor(&timeStampStr);
}

void SetupScreen_OnUpdate(void)
{
    switch(app_scrn_state)
    {
        case SCRN_STATE_INIT:
        {
           
            app_scrn_state = SCRN_STATE_IDLE;
            
            break;
        }
        case SCRN_STATE_IDLE:
        {
            switch (app_scrn_event)
            {
                case SCRN_EVENT_START_UPDATE:
                {
                    SetupScreen_SQIUpdateWarningLabel->fn->setVisible(SetupScreen_SQIUpdateWarningLabel, LE_TRUE);
                    app_scrn_event = SCRN_EVENT_NONE;
                    break;
                }
                case SCRN_EVENT_CONTINUE_UPDATE:
                {
                    SetupScreen_SQIUpdateWarningLabel->fn->setVisible(SetupScreen_SQIUpdateWarningLabel, LE_FALSE);
                    APP_StartDownload ();
                    app_scrn_event = SCRN_EVENT_NONE;
                    break;
                }
                case SCRN_EVENT_CANCEL_UPDATE:
                {
                    SetupScreen_UpdateSQIButton->fn->setPressed(SetupScreen_UpdateSQIButton, LE_FALSE);
                    SetupScreen_SQIUpdateWarningLabel->fn->setVisible(SetupScreen_SQIUpdateWarningLabel, LE_FALSE);
                    SetupScreen_SQIUpdateStatusString->fn->setString(SetupScreen_SQIUpdateStatusString, NULL);
                    
                    app_scrn_event = SCRN_EVENT_NONE;
                    
                    break;
                }
                case SCRN_EVENT_ABORT_UPDATE:
                {
                    APP_StopDownload();
                    app_scrn_event = SCRN_EVENT_NONE;
                    SetupScreen_SQIUpdateStatusString->fn->setString(SetupScreen_SQIUpdateStatusString, NULL);
                    
                    break;
                }
                case SCRN_EVENT_SHOW_LOG:
                {
                    if (strlen(charBuff) < SQI_LOG_STR_SIZE)
                    {
                        sqiUpdateStr.fn->setFromCStr(&sqiUpdateStr, charBuff);    
                        SetupScreen_SQIUpdateStatusString->fn->setString(SetupScreen_SQIUpdateStatusString,
                                                                     (leString*)&sqiUpdateStr);  
                    }
                    app_scrn_event = SCRN_EVENT_NONE;
                    break;
                }
                case SCRN_EVENT_RESTART:
                {
                    APP_StopDownload();
                    legato_showScreen(screenID_IntroScreen);
                    
                    app_scrn_event = SCRN_EVENT_NONE;
                    
                    break;
                }
                case SCRN_EVENT_EXIT:
                {
                    APP_StopDownload();
                    app_scrn_state = SCRN_STATE_EXIT;
                }
                default:
                    break;
            }
            break;
        }
        case SCRN_STATE_EXIT:
        {
            
            legato_showScreen(screenID_IntroScreen);
            
            break;
        }
        default:
            break;
    }
}

/*******************************************************************************
 End of File
 */
