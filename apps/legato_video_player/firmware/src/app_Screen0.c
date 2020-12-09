#include "definitions.h"
#include "app.h"
#include "gfx/legato/generated/le_gen_assets.h"

PANEL_OBJ APP_Panel_Obj[MAX_PANELS];
SYS_TIME_HANDLE  animTimer;
SYS_TIME_HANDLE  tptTimer;
volatile unsigned int animCounter = 0;
volatile unsigned int secCounter = 0;
unsigned int animCounterLast = 0;
SCREEN_OBJ APP_Screen0_Obj;
static leDynamicString fileNameText;
static leDynamicString throughPutText;
PANEL_STATE controlPanel;

int prevSecCounter = 0;
int prevBytesRead = 0;
int prevFramesRead = 0;

static void Anim_TimerCallback ( uintptr_t context )
{
    animCounter++;
}

static void Second_TimerCallback ( uintptr_t context )
{
    secCounter++;
}

void event_Screen0_qsButton_OnPressed(leButtonWidget* btn)
{
    appData.state = APP_STATE_OPEN_FILE;
}

void event_Screen0_qsButton_OnReleased(leButtonWidget* btn)
{
    if (appData.fileHandle != SYS_FS_HANDLE_INVALID)
        appData.state = APP_STATE_CLOSE_FILE;
    else
        appData.state = APP_STATE_IDLE;
}

void event_Screen0_SizeSelectButton_OnPressed(leButtonWidget* btn)
{
    APP_Toggle_Panel(SIZE);
}

void event_Screen0_MediaSelectButton_OnPressed(leButtonWidget* btn)
{
    APP_Toggle_Panel(SOURCE);
}


void event_Screen0_FormatButton_OnPressed(leButtonWidget* btn)
{
    APP_Toggle_Panel(FORMAT);
}


void event_Screen0_ButtonWidget1_OnPressed(leButtonWidget* btn)
{
    
}

void event_Screen0_Button_SourceSD_OnPressed(leButtonWidget* btn)
{
    APP_Screen_SetEvent(SCR_EVT_SD_SOURCE);
    
    APP_Hide_Panel(SOURCE);
    Screen0_SourceValueLabel->fn->setString(Screen0_SourceValueLabel,
                                            (leString*)&string_Source_SD);
    appData.videoControl.src = SRC_SD;
}


void event_Screen0_Button_SourceUSB_OnPressed(leButtonWidget* btn)
{
    APP_Screen_SetEvent(SCR_EVT_USB_SOURCE);
    
    APP_Hide_Panel(SOURCE);
    Screen0_SourceValueLabel->fn->setString(Screen0_SourceValueLabel,
                                            (leString*)&string_Source_USB);
    
    appData.videoControl.src = SRC_USB;
}


void event_Screen0_Button_Size320x240_OnPressed(leButtonWidget* btn)
{
    APP_Hide_Panel(SIZE);
    Screen0_SizeValueLabel->fn->setString(Screen0_SizeValueLabel,
                                         (leString*)&string_Size_320x240);
    
    appData.videoControl.res = RES_320x240;
    
}


void event_Screen0_Button_Size480x272_OnPressed(leButtonWidget* btn)
{
    APP_Hide_Panel(SIZE);
    Screen0_SizeValueLabel->fn->setString(Screen0_SizeValueLabel,
                                         (leString*)&string_Size_400x240);
    
    appData.videoControl.res = RES_400x240;
    
}


void event_Screen0_Button_Size800x480_OnPressed(leButtonWidget* btn)
{
    APP_Hide_Panel(SIZE);
    Screen0_SizeValueLabel->fn->setString(Screen0_SizeValueLabel,
                                         (leString*)&string_Size_800x480);
    
    appData.videoControl.res = RES_800x480;
}


void event_Screen0_Button_FormatRGB565_OnPressed(leButtonWidget* btn)
{
    APP_Hide_Panel(FORMAT);
    Screen0_FormatValueLabel->fn->setString(Screen0_FormatValueLabel,
                                         (leString*)&string_Format_RGB565);
    
    appData.videoControl.res = FMT_RGB565;
}


void event_Screen0_Button_FormatRGBA8888_OnPressed(leButtonWidget* btn)
{
    APP_Hide_Panel(FORMAT);
    Screen0_FormatValueLabel->fn->setString(Screen0_FormatValueLabel,
                                         (leString*)&string_Format_RGBA8888);
    
    appData.videoControl.res = FMT_RGBA8888;
}


void event_Screen0_Button_FPS12_OnPressed(leButtonWidget* btn)
{
    APP_Hide_Panel(FPS);
    Screen0_FPSValueLabel->fn->setString(Screen0_FPSValueLabel,
                                           (leString*)&string_FPS_12);
    
    appData.videoControl.fps = FPS_12;
}


void event_Screen0_Button_FPS8_OnPressed(leButtonWidget* btn)
{
    APP_Hide_Panel(FPS);
    Screen0_FPSValueLabel->fn->setString(Screen0_FPSValueLabel,
                                         (leString*)&string_FPS_8);
    
    appData.videoControl.fps = FPS_8;
}

void event_Screen0_Button_FPS24_OnPressed(leButtonWidget* btn)
{
    APP_Hide_Panel(FPS);
    Screen0_FPSValueLabel->fn->setString(Screen0_FPSValueLabel,
                                         (leString*)&string_FPS_24);
    
    appData.videoControl.fps = FPS_24;
}

void event_Screen0_ButtonFPS_OnPressed(leButtonWidget* btn)
{
    APP_Toggle_Panel(FPS);
}

void event_Screen0_PlayButton_OnPressed(leButtonWidget* btn)
{
    int i;
    
    for (i = SIZE; i < MAX_PANELS; i++)
    {
        APP_Hide_Panel(i);
    }

    APP_StartStop_Playback();
}

void event_Screen0_FullScreenButton_OnPressed(leButtonWidget* btn)
{
    APP_Set_FullScreen(true);
}

void event_Screen0_FullScreenButton_OnReleased(leButtonWidget* btn)
{
    APP_Set_FullScreen(false);
}

void event_Screen0_ButtonWidget0_OnPressed(leButtonWidget* btn)
{
    
}

void event_Screen0_ThroughputLabel_OnPressed(leButtonWidget* btn)
{
    Screen0_UpdateThroughput(-1, -1);
}

void event_Screen0_ThroughputLabel_OnReleased(leButtonWidget* btn)
{
    Screen0_UpdateThroughput(-1, -1);
}

static leBool _BackgroundPanelEventFilter(leWidget* target, leWidgetEvent* evt, void* data)
{
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        {
            if (APP_IsPlaying() == true)
            {
                if (APP_Screen0_Obj.controlLayerAlpha < CONTROL_LAYER_MAX_ALPHA)
                    APP_Screen_SetEvent(SCR_EVT_FADE_IN_CONTROL);
                else
                    APP_Screen_SetEvent(SCR_EVT_FADE_OUT_CONTROL);
            }
            else
            {
                static bool showPanels = false;
                int i;
                
                for (i = SIZE; i < MAX_PANELS; i++)
                {
                    if (showPanels == true)
                        APP_Hide_Panel(i);
                    else
                        APP_Show_Panel(i);
                }
                    
                showPanels = (showPanels == false) ? true : false;
            }
            
            evt->accepted = LE_TRUE;
            
            break;
        }
        default:
            break;
    }
    
    return LE_FALSE;
}

static leWidgetEventFilter BackgroundPanelEventFilter =
{
    _BackgroundPanelEventFilter,
    NULL
};

void Screen0_OnShow(void)
{
    leDynamicString_Constructor(&fileNameText);
    fileNameText.fn->setFont(&fileNameText, 
            leStringTable_GetStringFont(&stringTable, stringID_CannotOpenString, 0));
    
    leDynamicString_Constructor(&throughPutText);
    throughPutText.fn->setFont(&throughPutText, 
            leStringTable_GetStringFont(&stringTable, stringID_NoSelect, 0));
    
    animTimer = SYS_TIME_CallbackRegisterMS(Anim_TimerCallback, 
                                    (uintptr_t) NULL,
                                    CLOCK_ANIM_TIMER_PERIOD_MS,
                                    SYS_TIME_PERIODIC);
    SYS_TIME_TimerStop(animTimer);
    
    tptTimer = SYS_TIME_CallbackRegisterMS(Second_TimerCallback, 
                                    (uintptr_t) NULL,
                                    CLOCK_SEC_TIMER_PERIOD_MS,
                                    SYS_TIME_PERIODIC);
    
    APP_Panel_Obj[SIZE].widget  = Screen0_SizePanel;
    APP_Panel_Obj[SIZE].startY = APP_Panel_Obj[SIZE].currY = WGETY(Screen0_SizePanel);
    APP_Panel_Obj[SIZE].state = PANEL_VISIBLE;
    
    APP_Panel_Obj[SOURCE].widget  = Screen0_SourcePanel;
    APP_Panel_Obj[SOURCE].startY = APP_Panel_Obj[SOURCE].currY = WGETY(Screen0_SourcePanel);
    APP_Panel_Obj[SOURCE].state = PANEL_VISIBLE;
    
    APP_Panel_Obj[FORMAT].widget  = Screen0_FormatPanel;
    APP_Panel_Obj[FORMAT].startY = APP_Panel_Obj[FORMAT].currY = WGETY(Screen0_FormatPanel);
    APP_Panel_Obj[FORMAT].state = PANEL_VISIBLE;
    
    APP_Panel_Obj[FPS].widget  = Screen0_FPSPanel;
    APP_Panel_Obj[FPS].startY = APP_Panel_Obj[FPS].currY = WGETY(Screen0_FPSPanel);
    APP_Panel_Obj[FPS].state = PANEL_VISIBLE;
    
    APP_SetHWLayerAlpha(CONTROL_LAYER_ID, CONTROL_LAYER_MAX_ALPHA);
    
#ifdef USE_RGB565_VIDEO_FRAME_BUFFER    
    APP_SetHWLayerColorModeRGB565(VIDEO_LAYER_ID);
#endif
    
    APP_Source_Enabled(SRC_NONE, false);
    
    Screen0_BackgroundPanel->fn->installEventFilter(Screen0_BackgroundPanel,
                                                    BackgroundPanelEventFilter);
    
    APP_Screen0_Obj.state = INITIALIZING;
    
    APP_Screen0_Obj.evt = 0;
    
    APP_Screen0_Obj.controlPanel = PANEL_VISIBLE;
    
    APP_Screen0_Obj.controlLayerAlpha = 255;
}

void Screen0_OnHide(void)
{
    SYS_TIME_TimerDestroy(animTimer);
    fileNameText.fn->destructor(&fileNameText);
    
    throughPutText.fn->destructor(&throughPutText);
}
void Screen0_ShowFileError(bool show)
{
    if (show)
    {
        fileNameText.fn->setFromCStr(&fileNameText, appData.filename);
        Screen0_FileNameLabel->fn->setString(Screen0_FileNameLabel, (leString*)&fileNameText);        
        Screen0_FileNameLabel->fn->setVisible(Screen0_FileNameLabel, LE_TRUE);
        Screen0_ErrorLabelWidget->fn->setVisible(Screen0_ErrorLabelWidget, LE_TRUE);           
    }
    else
    {
        Screen0_FileNameLabel->fn->setVisible(Screen0_FileNameLabel, LE_FALSE);
        Screen0_ErrorLabelWidget->fn->setVisible(Screen0_ErrorLabelWidget, LE_FALSE);           
    }
}

void Screen0_UpdateThroughput(int kbps, int fps)
{
    #define MAX_CHARS_TPT_TEXT 128

    static char buff[MAX_CHARS_TPT_TEXT] = {0};
    
    if (Screen0_ThroughputLabel->fn->getPressed(Screen0_ThroughputLabel) == LE_FALSE &&
        kbps > 0)
    {
        sprintf(buff, "%i kbps", kbps);
    }
    else if (Screen0_ThroughputLabel->fn->getPressed(Screen0_ThroughputLabel) == LE_TRUE &&
            fps > 0)
    {
        sprintf(buff, "%i fps", fps);
    }
    else
    {
        sprintf(buff, "---");
    }
    
    throughPutText.fn->setFromCStr(&throughPutText, buff);
    Screen0_ThroughputLabel->fn->setString(Screen0_ThroughputLabel, (leString*)&throughPutText);        
}


void Screen0_OnUpdate(void)
{
    switch(APP_Screen0_Obj.state)
    {
        case INITIALIZING:
        {
            APP_Screen0_Obj.state = PROCESSING;
            break;
        }
        case PROCESSING:
        {
            int i;
            int retval = 0;
            uint32_t status = 0;
            
            //ProcessEvents
            Process_Screen_Events();
            
            //Process Animations
            for (i = SIZE; i < MAX_PANELS; i++)
            {
                retval = Process_Screen_Anim(i);
                status |= (retval << i);
            }
            
            if (status)
                SYS_TIME_TimerStart(animTimer);
            else
                SYS_TIME_TimerStop(animTimer);
            
            //Process Throughput Calculation
            Process_Throughput_Label();
            
            break;
        }
        default:
            break;
    }
    
    animCounterLast = animCounter;
}

