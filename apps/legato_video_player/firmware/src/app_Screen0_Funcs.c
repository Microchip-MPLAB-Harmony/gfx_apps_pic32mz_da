#include "definitions.h"
#include "app.h"
#include "gfx/legato/generated/le_gen_assets.h"

void APP_Screen_SetEvent(SCREEN_EVT evt)
{
    APP_Screen0_Obj.evt |= (1 << evt);
}

void APP_Screen_ClearEvent(SCREEN_EVT evt)
{
    APP_Screen0_Obj.evt &= ~(1 << evt);
}

bool APP_Check_Event(SCREEN_EVT evt)
{
    bool retval = false;
    
    if (APP_Screen0_Obj.evt & (1 << evt))
    {
        retval = true;
        APP_Screen0_Obj.evt &= ~(1 << evt);
    }
    
    return retval;
}

void APP_Hide_Panel(PANEL_ID panel)
{
    if (APP_Panel_Obj[panel].state == PANEL_VISIBLE ||
        APP_Panel_Obj[panel].state == PANEL_SHOWING)
    {
        APP_Panel_Obj[panel].state = PANEL_HIDING;
    }
}

void APP_Show_Panel(PANEL_ID panel)
{
    if (appData.state != APP_STATE_IDLE)
        return;
    
    if (APP_Panel_Obj[panel].state == PANEL_HIDDEN ||
        APP_Panel_Obj[panel].state == PANEL_HIDING)
    {
        APP_Panel_Obj[panel].state = PANEL_SHOWING;
    }
}

void APP_Exc_Show_Panel(PANEL_ID panel)
{
    int i;
    
    if (appData.state != APP_STATE_IDLE)
        return;
    
    for (i = 0; i < MAX_PANELS; i++)
    {
        if (i == panel)
        {
            APP_Show_Panel(i);
        }
        else
        {
            APP_Hide_Panel(i);
        }
    }
}

void APP_SetHWLayerAlpha(uint32_t layer, uint8_t alpha)
{
    gfxIOCTLArg_LayerValue arg;
    arg.base.id = layer;
    arg.value.v_uint = alpha;
    
    gfxDriverInterface.ioctl(GFX_IOCTL_SET_LAYER_LOCK, &arg);
    gfxDriverInterface.ioctl(GFX_IOCTL_SET_LAYER_ALPHA, &arg);
    gfxDriverInterface.ioctl(GFX_IOCTL_SET_LAYER_UNLOCK, &arg);
    
    APP_Screen0_Obj.controlLayerAlpha = alpha;
}

void APP_SetHWLayerColorModeRGB565(uint32_t layer)
{
    gfxIOCTLArg_LayerValue arg;
    arg.base.id = layer;
    arg.value.v_uint = GFX_COLOR_MODE_RGB_565;
    
    gfxDriverInterface.ioctl(GFX_IOCTL_SET_LAYER_LOCK, &arg);
    gfxDriverInterface.ioctl(GFX_IOCTL_SET_LAYER_COLOR_MODE, &arg);
    gfxDriverInterface.ioctl(GFX_IOCTL_SET_LAYER_UNLOCK, &arg);
}

void APP_Toggle_Panel(PANEL_ID panel)
{
    if (appData.state != APP_STATE_IDLE)
        return;

    if (APP_Panel_Obj[panel].state == PANEL_HIDDEN ||
        APP_Panel_Obj[panel].state == PANEL_HIDING)
    {
        APP_Exc_Show_Panel(panel);
    }
    else if (APP_Panel_Obj[panel].state == PANEL_VISIBLE ||
             APP_Panel_Obj[panel].state == PANEL_SHOWING)
    {
        APP_Hide_Panel(panel);
    }
}

int Process_Screen_Anim(PANEL_ID panel)
{
    int currY;
    
    switch(APP_Panel_Obj[panel].state)
    {
        case PANEL_VISIBLE:
        case PANEL_HIDDEN:
            break;
        case PANEL_SHOWING:
        {
            if (animCounterLast == animCounter)
                return ANIM_ACTIVE;
            
            currY = WGETY(APP_Panel_Obj[panel].widget);
            if ((currY - APP_Panel_Obj[panel].startY) / PANEL_STEP_DIV > 0)
            {
                WSETY(APP_Panel_Obj[panel].widget, 
                      currY - (currY - APP_Panel_Obj[panel].startY) / PANEL_STEP_DIV);
                
            }
            else
            {
                WSETY(APP_Panel_Obj[panel].widget, APP_Panel_Obj[panel].startY);
                APP_Panel_Obj[panel].state = PANEL_VISIBLE;
            }
            
            currY = WGETY(APP_Panel_Obj[panel].widget);
            WSETHEIGHT(APP_Panel_Obj[panel].widget, PANEL_MINY - currY);
            
            return ANIM_ACTIVE;
        }
        case PANEL_HIDING:
        {
            if (animCounterLast == animCounter)
                return ANIM_ACTIVE;
            
            currY = WGETY(APP_Panel_Obj[panel].widget);
            if ((PANEL_MINY - currY) / PANEL_STEP_DIV > 0)
            {
                WSETY(APP_Panel_Obj[panel].widget,
                      currY + (PANEL_MINY - currY) / PANEL_STEP_DIV);
            }
            else
            {
                WSETY(APP_Panel_Obj[panel].widget, PANEL_MINY);
                APP_Panel_Obj[panel].state = PANEL_HIDDEN;
            }
            
            currY = WGETY(APP_Panel_Obj[panel].widget);
            WSETHEIGHT(APP_Panel_Obj[panel].widget, PANEL_MINY - currY);
            
            return ANIM_ACTIVE;
        }
        default:
            break;
    }
    
    //Animate Control Panel FadeIn/Out
    switch(APP_Screen0_Obj.controlPanel)
    {
        case PANEL_VISIBLE:
        case PANEL_HIDDEN:
            break;
        case PANEL_HIDING:
        {
            if (animCounterLast == animCounter)
                return ANIM_ACTIVE;

            if (APP_Screen0_Obj.controlLayerAlpha > CONTROL_LAYER_FADE_STEP)
            {
                APP_SetHWLayerAlpha(CONTROL_LAYER_ID, APP_Screen0_Obj.controlLayerAlpha - CONTROL_LAYER_FADE_STEP);
                
                return ANIM_ACTIVE;
            }
            else
            {
                Screen0_PanelWidget0->fn->setEnabled(Screen0_PanelWidget0, LE_FALSE);
                APP_SetHWLayerAlpha(CONTROL_LAYER_ID, 0);
                
                APP_Screen0_Obj.controlPanel = PANEL_HIDDEN;
            }
            
            break;
        }
        case PANEL_SHOWING:
        {
            if (animCounterLast == animCounter)
                return ANIM_ACTIVE;
            
            if (APP_Screen0_Obj.controlLayerAlpha + CONTROL_LAYER_FADE_STEP < 
                CONTROL_LAYER_MAX_ALPHA)
            {
                APP_SetHWLayerAlpha(CONTROL_LAYER_ID, 
                                    APP_Screen0_Obj.controlLayerAlpha +
                                    CONTROL_LAYER_FADE_STEP);
                
                return ANIM_ACTIVE;
            }
            else
            {
                APP_SetHWLayerAlpha(CONTROL_LAYER_ID, CONTROL_LAYER_MAX_ALPHA);
                
                APP_Screen0_Obj.controlPanel = PANEL_VISIBLE;
            }    
        }
        default:
            break;        
    }
    return ANIM_NONE;
}

void Process_Throughput_Label(void)
{
    if (prevSecCounter < secCounter)
    {
        if (appData.nBytesRead > prevBytesRead && appData.frameNum > prevFramesRead)
        {
            Screen0_UpdateThroughput((appData.nBytesRead - prevBytesRead) / 1000,
                                     appData.frameNum - prevFramesRead);

            prevBytesRead = appData.nBytesRead;
            prevFramesRead = appData.frameNum;
        }   
    }
    
    prevSecCounter = secCounter;
}

void Reset_Throughput_Counters(void)
{
    prevBytesRead = 0;
    prevFramesRead = 0;
    Screen0_UpdateThroughput(-1, -1);
}

void APP_Select_Source(APP_VID_SOURCE source)
{
    switch (source)
    {
        case SRC_USB:
        case SRC_SD:
        {
            
            appData.videoControl.src = source;
            Screen0_SourceValueLabel->fn->setString(Screen0_SourceValueLabel, 
                                                (source == SRC_USB) ? (leString*)&string_Source_USB :
                                                (leString*)&string_Source_SD);
            break;
        }
        default:
        {
            appData.videoControl.src = SRC_NONE;
            break;
        }
    }
}

void APP_Source_Enabled(APP_VID_SOURCE source, bool enable)
{

    switch (source)
    {
        case SRC_USB:
        {
            Screen0_Button_SourceUSB->fn->setVisible(Screen0_Button_SourceUSB,
                                                    (enable == true) ? LE_TRUE : LE_FALSE);
            break;
        }
        case SRC_SD:
        {

            Screen0_Button_SourceSD->fn->setVisible(Screen0_Button_SourceSD, 
                                                    (enable == true) ? LE_TRUE : LE_FALSE);
            break;
        }
        default:
        {
            break;
        }
    }
    
    if (enable)
    {
        Screen0_InsertUSBLabel->fn->setVisible(Screen0_InsertUSBLabel, LE_FALSE);
            
        if (appData.videoControl.src == SRC_NONE)
        {
            if (appData.videoControl.res == RES_NONE)
            {
                Screen0_SizeValueLabel->fn->setString(Screen0_SizeValueLabel,
                                                      (leString*)&string_Size_400x240);
                appData.videoControl.res = RES_400x240;   
            }

            if (appData.videoControl.fmt == FMT_NONE)
            {
                Screen0_FormatValueLabel->fn->setString(Screen0_FormatValueLabel,
                                                        (leString*)&string_Format_RGB565);
                appData.videoControl.fmt = FMT_RGB565;
            }

            if (appData.videoControl.fps == FPS_NONE)
            {
                Screen0_FPSValueLabel->fn->setString(Screen0_FPSValueLabel,
                                                    (leString*)&string_FPS_24);
                appData.videoControl.fps = FPS_24;
            }
            
            APP_Show_Panel(SOURCE);  
            APP_Show_Panel(SIZE);
            APP_Show_Panel(FORMAT);
            APP_Show_Panel(FPS);            
        }
    }
    else
    {
        appData.videoControl.src = (appData.videoControl.src == source) ? 
                        SRC_NONE : appData.videoControl.src;
                    
        if (appData.videoControl.src == SRC_NONE)
        {
            if (appData.sdIsConnected == false && appData.usbIsConnected == false)
            {
                Screen0_InsertUSBLabel->fn->setVisible(Screen0_InsertUSBLabel, LE_TRUE);            
            }

            Screen0_FPSValueLabel->fn->setString(Screen0_FPSValueLabel, (leString*)&string_NoSelect);
            Screen0_FormatValueLabel->fn->setString(Screen0_FormatValueLabel, (leString*)&string_NoSelect);
            Screen0_SourceValueLabel->fn->setString(Screen0_SourceValueLabel, (leString*)&string_NoSelect);
            Screen0_SizeValueLabel->fn->setString(Screen0_SizeValueLabel, (leString*)&string_NoSelect);

            appData.videoControl.res = RES_NONE;
            appData.videoControl.fps = FPS_NONE;
            appData.videoControl.fmt = FMT_NONE;
            appData.videoControl.src = SRC_NONE;
            
            APP_Show_Panel(SOURCE); 
            APP_Hide_Panel(SIZE);
            APP_Hide_Panel(FORMAT);
            APP_Hide_Panel(FPS);
        }
    }
}

void Process_Screen_Events(void)
{
    if (APP_Screen0_Obj.evt != 0)
    {
        if (APP_Check_Event(SCR_EVT_USB_IN))
        {
            APP_Source_Enabled(SRC_USB, true);
        }
        else if (APP_Check_Event(SCR_EVT_USB_OUT))
        {
            APP_Source_Enabled(SRC_USB, false);
        }
        
        if (APP_Check_Event(SCR_EVT_SD_IN))
        {
            APP_Source_Enabled(SRC_SD, true);
        }
        else if (APP_Check_Event(SCR_EVT_SD_OUT))
        {
            APP_Source_Enabled(SRC_SD, false);
        }        
        
        if (APP_Check_Event(SCR_EVT_USB_SOURCE))
        {
            APP_Select_Source(SRC_USB);
        }
        else if (APP_Check_Event(SCR_EVT_SD_SOURCE))
        {
            APP_Select_Source(SRC_SD);
        }

        if (APP_Check_Event(SCR_EVT_FILE_ERROR))
        {
            Screen0_ShowFileError(true);
        }
        
        if (APP_Check_Event(SCR_EVT_VIDEO_PLAYING))
        {
            Screen0_ShowFileError(false);
            Screen0_PlayButton->fn->setPressedImage(Screen0_PlayButton,
                                                    (leImage*)&stopbutton);
            Screen0_PlayButton->fn->setReleasedImage(Screen0_PlayButton,
                                                    (leImage*)&stopbutton);
            
            Reset_Throughput_Counters();
        }
        
        if (APP_Check_Event(SCR_EVT_VIDEO_REPLAY))
        {
            Reset_Throughput_Counters();
        }        
        
        if (APP_Check_Event(SCR_EVT_VIDEO_STOPPED))
        {
            Screen0_ShowFileError(false);
            Screen0_PlayButton->fn->setPressedImage(Screen0_PlayButton,
                                                    (leImage*)&PlayButton);
            Screen0_PlayButton->fn->setReleasedImage(Screen0_PlayButton,
                                                    (leImage*)&PlayButton);
            
            Reset_Throughput_Counters();
        }        
        
        if (APP_Check_Event(SCR_EVT_FADE_OUT_CONTROL))
        {
            if (APP_Screen0_Obj.controlPanel == PANEL_VISIBLE ||
                APP_Screen0_Obj.controlPanel == PANEL_SHOWING)
                APP_Screen0_Obj.controlPanel = PANEL_HIDING;
        }
        
        if (APP_Check_Event(SCR_EVT_FADE_IN_CONTROL))
        {
            if (APP_Screen0_Obj.controlPanel == PANEL_HIDDEN ||
                APP_Screen0_Obj.controlPanel == PANEL_HIDING)            
                APP_Screen0_Obj.controlPanel = PANEL_SHOWING;
        }    
    }
}