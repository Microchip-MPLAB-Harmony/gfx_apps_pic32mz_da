// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include "app_screen.h"
#include "app_funcs.h"

void app_touchDownHandler(const SYS_INP_TouchStateEvent* const evt);
void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt);
void app_touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt);
void app_genericGestureHandler(const SYS_INP_GenericGestureEvent* const evt);
SCREEN_MAIN_STATES processMainTimerControl(SCR_EVENTS event);
SCREEN_MAIN_STATES processMainMenuEvents(SCR_EVENTS event);
SCREEN_MAIN_STATES processMainPercentControl(SCR_EVENTS event);
SCREEN_MAIN_STATES processMainTempControl(SCR_EVENTS event);

static SYS_INP_InputListener app_inputListener = 
{
    .handleTouchDown = &app_touchDownHandler,
    .handleTouchUp = &app_touchUpHandler,
    .handleTouchMove = &app_touchMoveHandler,
    .handleGenericGesture = &app_genericGestureHandler            
};

static int32_t app_inputListenerIdx;
volatile uint32_t tickCount = 0;
static uint32_t lastTickCount = 0;
volatile uint32_t secTickCount = 0;
static uint32_t lastSecCount = 0;
static SCREEN_STATES screenState;

static SCREEN_MAIN_STATES mainState = SCR_MAIN_INIT;
static uint32_t currTick = START_ANIM_TICK_LINES;

static SCR_EVENTS scr_events;
static volatile uint32_t scr_events_arg;

static bool timerRunning = false;
static SCR_TEMP_UNITS tempUnit = SCR_TEMP_UNIT_F;
static uint32_t tempTargetValue = 0;    
static int32_t rotaryAngle = 90;

static bool wheelActive = false;
static uint32_t knobDownCount = 0;
static uint32_t secDelayCount = 0;

SCR_MAIN_DEMO_CONTEXT mainDemoContext;

char percentStrBuff[APP_STR_SIZE];
leChar percentStrCharBuff[APP_STR_SIZE] = {0};
leFixedString percentStr;

char timerMinStrBuff[TIMER_STR_SIZE];
leChar timerMinStrCharBuff[TIMER_STR_SIZE] = {0};
leFixedString timerMinStr;

char timerSecStrBuff[TIMER_STR_SIZE];
leChar timerSecStrCharBuff[TIMER_STR_SIZE] = {0};
leFixedString timerSecStr;

char tempStrBuff[TEMP_STR_SIZE];
leChar tempStrCharBuff[TEMP_STR_SIZE] = {0};
leFixedString tempStr;

static leImageWidget ** Screen0_TickLines[NUM_TICK_LINES] = 
{
    &Screen0_Image_n0,
    &Screen0_Image_n1,
    &Screen0_Image_n2,
    &Screen0_Image_n3,
    &Screen0_Image_n4,
    &Screen0_Image_n5,
    &Screen0_Image_n6,
    &Screen0_Image_n7,
    &Screen0_Image_n8,
    &Screen0_Image_n9,
    &Screen0_Image_n10,
    &Screen0_Image_n11,
    &Screen0_Image_n12,
    &Screen0_Image_n13,
    &Screen0_Image_n14,
    &Screen0_Image_n15,
    &Screen0_Image_n16,
    &Screen0_Image_n17,
    &Screen0_Image_n18,
    &Screen0_Image_n19,
    &Screen0_Image_n20,
    &Screen0_Image_n21,
    &Screen0_Image_n22,
    &Screen0_Image_n23,
    &Screen0_Image_n24,
    &Screen0_Image_n25,
    &Screen0_Image_n26,
    &Screen0_Image_n27,
    &Screen0_Image_n28,
    &Screen0_Image_n29,
    &Screen0_Image_n30,
    &Screen0_Image_n31,
    &Screen0_Image_n32,
    &Screen0_Image_n33,
    &Screen0_Image_n34,
    &Screen0_Image_n35,
    &Screen0_Image_n36,
    &Screen0_Image_n37,
    &Screen0_Image_n38,
    &Screen0_Image_n39,
    &Screen0_Image_n40,
    &Screen0_Image_n41,
    &Screen0_Image_n42,
    &Screen0_Image_n43,
    &Screen0_Image_n44,
    &Screen0_Image_n45,
    &Screen0_Image_n46,
    &Screen0_Image_n47,
    &Screen0_Image_n48,
    &Screen0_Image_n49,
    &Screen0_Image_n50,
    &Screen0_Image_n51,
    &Screen0_Image_n52,
    &Screen0_Image_n53,
    &Screen0_Image_n54,
    &Screen0_Image_n55,
    &Screen0_Image_n56,
    &Screen0_Image_n57,
    &Screen0_Image_n58,
    &Screen0_Image_n59,
    &Screen0_Image_n60,
    &Screen0_Image_n61,
    &Screen0_Image_n62,
    &Screen0_Image_n63,
    &Screen0_Image_n64,
    &Screen0_Image_n65,
    &Screen0_Image_n66,
    &Screen0_Image_n67,
    &Screen0_Image_n68,
    &Screen0_Image_n69,
    &Screen0_Image_n70,
    &Screen0_Image_n71,
    &Screen0_Image_n72,
    &Screen0_Image_n73,
    &Screen0_Image_n74,
    &Screen0_Image_n75,
    &Screen0_Image_n76,
    &Screen0_Image_n77,
    &Screen0_Image_n78,
    &Screen0_Image_n79,
    &Screen0_Image_n80,
    &Screen0_Image_n81,
    &Screen0_Image_n82,
    &Screen0_Image_n83,
    &Screen0_Image_n84,
    &Screen0_Image_n85,
    &Screen0_Image_n86,
    &Screen0_Image_n87,
    &Screen0_Image_n88,
    &Screen0_Image_n89,
    &Screen0_Image_n90,
    &Screen0_Image_n91,
    &Screen0_Image_n92,    
};

static SCR_MENU_DEMO_OBJ Screen0_MenuDemoObj[NUM_MAIN_MENU_DEMOS] = 
{
    [SCR_MAIN_TIMER_DEMO] = 
    {
        &Screen0_ClockButton,
        &Screen0_ClockImageSequence,
        &clock_m,
    },
    
    [SCR_MAIN_FAN_DEMO] = 
    {
        &Screen0_FanButton,
        &Screen0_FanImageSequence,
        &fan_m,
    },
    
    [SCR_MAIN_LIGHT_DEMO] = 
    {
        &Screen0_LightButton,
        &Screen0_LightImageSequence,
        &bulb_m,
    },
    
    [SCR_MAIN_THERM_DEMO] = 
    {
        &Screen0_ThermButton,
        &Screen0_ThermImageSequence,
        &thermo_m,
    },
    
    [SCR_MAIN_ECO_DEMO] = 
    {
        &Screen0_EcoButton,
        &Screen0_EcoImageSequence,
        &leaf_m,
    },
    
    [SCR_MAIN_VOL_DEMO] = 
    {
        &Screen0_VolumeButton,
        &Screen0_VolumeImageSequence,
        &sound_m,
    },
    
    [SCR_MAIN_SETTINGS_DEMO] = 
    {
        &Screen0_SettingsButton,
        &Screen0_SettingsImageSequence,
        &gear_m,
    },
};

void Screen0_ShowTickLines(uint32_t value)
{
    uint32_t i;
    for (i = 0; i < NUM_TICK_LINES; i++)
    {
        (*Screen0_TickLines[i])->fn->setVisible((*Screen0_TickLines[i]), 
                        (i < value) ? LE_TRUE : LE_FALSE);
    }
}

void Screen0_ShowTickLine(uint32_t value)
{
    uint32_t i;
    for (i = 0; i < NUM_TICK_LINES; i++)
    {
        (*Screen0_TickLines[i])->fn->setVisible((*Screen0_TickLines[i]), 
                        (i == value) ? LE_TRUE : LE_FALSE);
    }
}

void Screen0_ShowTick(uint32_t idx, bool show)
{
    idx = (idx >= NUM_TICK_LINES) ? NUM_TICK_LINES - 1: idx;

    (*Screen0_TickLines[idx])->fn->setVisible((*Screen0_TickLines[idx]), 
                            (show == true) ? LE_TRUE : LE_FALSE);
}

void Screen0_ShowTickLinesByRange(uint32_t start, uint32_t end)
{
    uint32_t i;
    
    if (start < end)
    {
        for (i = 0; i < NUM_TICK_LINES; i++)
        {
            (*Screen0_TickLines[i])->fn->setVisible((*Screen0_TickLines[i]), 
                            (i <= end && i >=start ) ? LE_TRUE : LE_FALSE);
        }    
    }
    else
    {
        for (i = 0; i <= end; i++)
        {
            (*Screen0_TickLines[i])->fn->setVisible((*Screen0_TickLines[i]), 
                            LE_TRUE);
        }
        
        for (i = end + 1; i < NUM_TICK_LINES; i++)
        {
            (*Screen0_TickLines[i])->fn->setVisible((*Screen0_TickLines[i]), 
                            (i >= start ) ? LE_TRUE : LE_FALSE);
        }
        
    }
}

void Screen0_ShowTickLinesByAngle(uint32_t deg, uint32_t ticksCount)
{
    int32_t startTick, endTick;
    
    ticksCount &= ~(0x1); //make the ticks even
    ticksCount /= 2;

    startTick = app_angleToTick(deg);
    startTick = (startTick - (int32_t) ticksCount) < 0 ? 
                NUM_TICK_LINES + (startTick - (int32_t) ticksCount) : 
                (startTick - (int32_t) ticksCount);   
    
    endTick = app_angleToTick(deg);
    endTick = (endTick + ticksCount) % NUM_TICK_LINES;
    
    //wraparound
    Screen0_ShowTickLinesByRange(startTick, endTick);
}

void Screen0_HideTickLines(void)
{
    uint32_t i;
    
    for (i = 0; i < NUM_TICK_LINES; i++)
    {
        (*Screen0_TickLines[i])->fn->setVisible((*Screen0_TickLines[i]), LE_FALSE);
    }    
}

SCREEN_BUTTON_STATES Screen0_RotateShowButtons(bool show)
{
    static SCREEN_BUTTON_STATES state = SCR_BUTTONS_HIDDEN;
    static uint32_t showAngle = 0;
    
    switch(state)
    {
        case SCR_BUTTONS_HIDDEN:
        {
            if (show == true)
            {
                state = SCR_BUTTONS_SHOWING;
                showAngle = 0;
            }
            
            break;
        }
        case SCR_BUTTONS_SHOWING:
        {
            int i;
            showAngle += BUTTON_SHOW_INC_PIX;

            for (i = 0; i < NUM_MAIN_MENU_DEMOS; i++)
            {
                if (showAngle > (i * (360/(NUM_MAIN_MENU_DEMOS + 1))))
                {
                    (*(Screen0_MenuDemoObj[i].btn))->fn->setVisible(*(Screen0_MenuDemoObj[i].btn), LE_TRUE);
                }
                
                if (showAngle <= (i + 1) * (360/(NUM_MAIN_MENU_DEMOS + 1)) + 1)
                {
                    lePoint pos;
                     
                    lePolarToXY(BUTTON_DIST_CENTER_PIX, showAngle - 90, &pos);
                     
                    (*(Screen0_MenuDemoObj[i].btn))->fn->setPosition(*(Screen0_MenuDemoObj[i].btn), 
                            CENTER_POS_XY + pos.x - (*(Screen0_MenuDemoObj[i].btn))->fn->getWidth(*(Screen0_MenuDemoObj[i].btn))/2,
                            CENTER_POS_XY + pos.y - (*(Screen0_MenuDemoObj[i].btn))->fn->getHeight(*(Screen0_MenuDemoObj[i].btn))/2);
                }
            }
            
            if (showAngle > 360)
            {
                state = SCR_BUTTONS_VISIBLE;
            }

            break;
        }
        case SCR_BUTTONS_VISIBLE:
        {
            if (show == false)
            {
                showAngle = 0;
                state = SCR_BUTTONS_HIDING;
            }
            break;
        }
        case SCR_BUTTONS_HIDING:
        {
            int i;
            showAngle += BUTTON_SHOW_INC_PIX;

            for (i = 0; i < NUM_MAIN_MENU_DEMOS; i++)
            {
                if (showAngle + 10 > ((i + 2) * (360/(NUM_MAIN_MENU_DEMOS + 1))))
                {
                    (*(Screen0_MenuDemoObj[i].btn))->fn->setVisible(*(Screen0_MenuDemoObj[i].btn), LE_FALSE);
                }
                
                if (showAngle >= (i + 1) * (360/(NUM_MAIN_MENU_DEMOS + 1)))
                {
                    lePoint pos;
                     
                    lePolarToXY(BUTTON_DIST_CENTER_PIX, showAngle - 90, &pos);
                     
                    (*(Screen0_MenuDemoObj[i].btn))->fn->setPosition(*(Screen0_MenuDemoObj[i].btn), 
                            CENTER_POS_XY + pos.x - (*(Screen0_MenuDemoObj[i].btn))->fn->getWidth(*(Screen0_MenuDemoObj[i].btn))/2,
                            CENTER_POS_XY + pos.y - (*(Screen0_MenuDemoObj[i].btn))->fn->getHeight(*(Screen0_MenuDemoObj[i].btn))/2);
                }
            }
            
            if (showAngle > 360)
            {
                state = SCR_BUTTONS_HIDDEN;
            }
            
            break;
        }
        default:
            break;
    }
    
    return state;
}

void Screen0_ShowMenuButtons(bool show)
{
    uint32_t i = 0;
    for (i = 0; i < NUM_MAIN_MENU_DEMOS; i++)
    {
        (*(Screen0_MenuDemoObj[i].btn))->fn->setVisible(*(Screen0_MenuDemoObj[i].btn), 
                        (show == true ) ? LE_TRUE : LE_FALSE);
    }
}

void Screen0_updateTimerDemoLabel(uint32_t value)
{
    value = (value > MAX_TIMER_COUNT) ? MAX_TIMER_COUNT : value;
    
    sprintf(timerMinStrBuff, "%02u", value / 60);
    timerMinStr.fn->setFromCStr(&timerMinStr, timerMinStrBuff);    
    Screen0_TimerMinsButton->fn->setString(Screen0_TimerMinsButton, (leString*)&timerMinStr);
    Screen0_TimerMinsButton->fn->invalidate(Screen0_TimerMinsButton);
    
    sprintf(timerSecStrBuff, "%02u", value % 60);
    timerSecStr.fn->setFromCStr(&timerSecStr, timerSecStrBuff);    
    Screen0_TimerSecsButton->fn->setString(Screen0_TimerSecsButton, (leString*)&timerSecStr);
    Screen0_TimerSecsButton->fn->invalidate(Screen0_TimerSecsButton);
}

void Screen0_popDemoImageByIndex(uint32_t id)
{
    int i;
    
    for (i = 0; i < NUM_MAIN_MENU_DEMOS; i++)
    {
        (*(Screen0_MenuDemoObj[i].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[i].imgSeq), 
                (i == id) ? SCR_MAIN_BTN_IMG_LRG : SCR_MAIN_BTN_IMG_MED);
    }
}

void Screen0_ResetDemoImages(void)
{
    int i;
    
    for (i = 0; i < NUM_MAIN_MENU_DEMOS; i++)
    {
        (*(Screen0_MenuDemoObj[i].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[i].imgSeq), SCR_MAIN_BTN_IMG_MED);
    }
}

SCREEN_MAIN_DEMOS Screen0_popDemoImageByAngle(uint32_t deg)
{
    SCREEN_MAIN_DEMOS demo = NUM_MAIN_MENU_DEMOS;
    
    if (deg > 315 + (IMAGE_ANGLE_RANGE / 2) ||
        deg < (IMAGE_ANGLE_RANGE / 2))
    {
        demo = SCR_MAIN_FAN_DEMO;
    }
    else if (deg > 315 - (IMAGE_ANGLE_RANGE / 2))
    {
        demo = SCR_MAIN_LIGHT_DEMO;
    }
    else if (deg > 270 - (IMAGE_ANGLE_RANGE / 2))
    {
        demo = SCR_MAIN_THERM_DEMO;
    }
    else if (deg > 225 - (IMAGE_ANGLE_RANGE / 2))
    {
        demo = SCR_MAIN_ECO_DEMO;
    }
    else if (deg > 180 - (IMAGE_ANGLE_RANGE / 2))
    {
        demo = SCR_MAIN_VOL_DEMO;
    }
    else if (deg > 135 - (IMAGE_ANGLE_RANGE / 2))
    {
        demo = SCR_MAIN_SETTINGS_DEMO;
    }
    else if (deg > 90 - (IMAGE_ANGLE_RANGE / 2))
    {
        //home do nothing for now
        demo = NUM_MAIN_MENU_DEMOS;
    }
    else if (deg > 45 - (IMAGE_ANGLE_RANGE / 2))
    {
        demo = SCR_MAIN_TIMER_DEMO;
    }
    
    Screen0_popDemoImageByIndex(demo);
    
    return demo;
}

void Screen0_StartTimer(bool start)
{
    if (start == true)
    {
        Screen0_TimerStartStopImage->fn->setImage(Screen0_TimerStartStopImage, (leImage *) &Pause);
        timerRunning = true;
    }
    else
    {
        Screen0_TimerStartStopImage->fn->setImage(Screen0_TimerStartStopImage, (leImage *) &Play);
        timerRunning = false;        
    }
    
    Screen0_TimerSecsButton->fn->setVisible(Screen0_TimerSecsButton, LE_TRUE);
    Screen0_TimerMinsButton->fn->setVisible(Screen0_TimerMinsButton, LE_TRUE);
}

void Screen0_UpdateTempLabel(uint32_t temp_F)
{
    if (tempUnit == SCR_TEMP_UNIT_F)
    {
        sprintf(tempStrBuff, "%u", temp_F);
    }
    else
    {
        sprintf(tempStrBuff, "%u", ((temp_F - 32) * 5)/9);
    }
    
    if (temp_F > 85)
    {
        Screen0_TempLabel->fn->setScheme(Screen0_TempLabel, &TempWarmScheme);
    }
    else if (temp_F > 75)
    {
        Screen0_TempLabel->fn->setScheme(Screen0_TempLabel, &TempCozyScheme);
    }
    else if (temp_F > 65)
    {
        Screen0_TempLabel->fn->setScheme(Screen0_TempLabel, &TempCoolScheme);
    }
    else
    {
        Screen0_TempLabel->fn->setScheme(Screen0_TempLabel, &TempColdScheme);
    }
    
    tempStr.fn->setFromCStr(&tempStr, tempStrBuff);    
    Screen0_TempLabel->fn->setString(Screen0_TempLabel, (leString*)&tempStr); 
}

void Screen0_ToggleThermUnits(void)
{
    if (tempUnit == SCR_TEMP_UNIT_F)
    {
        tempUnit = SCR_TEMP_UNIT_C;
        Screen0_TempUnitsLabel->fn->setString(Screen0_TempUnitsLabel,
            (leString * ) &string_CelsString);
    }
    else
    {
        tempUnit = SCR_TEMP_UNIT_F;
        Screen0_TempUnitsLabel->fn->setString(Screen0_TempUnitsLabel,
            (leString * ) &string_FahrString);
    }

    Screen0_TempUnitsLabel->fn->invalidate(Screen0_TempUnitsLabel);                    
    Screen0_UpdateTempLabel(mainDemoContext.value[mainDemoContext.demo]);
}

SCREEN_RETVAL Screen0_StartDemo(SCREEN_MAIN_DEMOS demo)
{
    SCREEN_RETVAL retval = SCR_SUCCESS;
    
    switch(demo)
    {
        case SCR_MAIN_TIMER_DEMO:
        {
            mainDemoContext.mainProcessFunc = processMainTimerControl;
            mainDemoContext.demo = SCR_MAIN_TIMER_DEMO;
            
            break;
        }
        case SCR_MAIN_FAN_DEMO:
        {
            mainDemoContext.mainProcessFunc = processMainPercentControl;
            mainDemoContext.demo = SCR_MAIN_FAN_DEMO;
            
            break;
        }
        case SCR_MAIN_LIGHT_DEMO:
        {
            mainDemoContext.mainProcessFunc = processMainPercentControl;
            mainDemoContext.demo = SCR_MAIN_LIGHT_DEMO;
            
            break;
        }
        case SCR_MAIN_THERM_DEMO:
        {
            mainDemoContext.mainProcessFunc = processMainTempControl;
            mainDemoContext.demo = SCR_MAIN_THERM_DEMO;
            
            break;
        }
        case SCR_MAIN_ECO_DEMO:
        {
            if (APP_GetBacklightBrightness() > ECO_BRIGHTNESS)
            {
                APP_SetBacklightBrightness(ECO_BRIGHTNESS);
                mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] = ECO_BRIGHTNESS;
            }
            else
            {
                APP_SetBacklightBrightness(ON_BRIGHTNESS);
                mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] = ON_BRIGHTNESS;
            }
            
            retval = SCR_FAILURE;
            
            break;
        }
        case SCR_MAIN_VOL_DEMO:
        {
            mainDemoContext.mainProcessFunc = processMainPercentControl;
            mainDemoContext.demo = demo;
            
            break;
        }
        case SCR_MAIN_SETTINGS_DEMO:
        {
            if (app_IsKnobReversed() == true)
            {
                app_ReverseKnobEnable(false);
                Screen0_ReverseTagLabel->fn->setVisible(Screen0_ReverseTagLabel, false);
            }
            else
            {
                app_ReverseKnobEnable(true);
                Screen0_ReverseTagLabel->fn->setVisible(Screen0_ReverseTagLabel, true);
            }
            
            retval = SCR_FAILURE;
            break;
        }
        default:
        {
            retval = SCR_FAILURE;
            
            break;
        }
    }
    
    if (demo < NUM_MAIN_MENU_DEMOS)
    {
        (*(Screen0_MenuDemoObj[demo].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[demo].imgSeq), SCR_MAIN_BTN_IMG_MED);
    }
    
    return retval;
}

SCREEN_MAIN_STATES processMainPercentControl(SCR_EVENTS event)
{
    SCREEN_MAIN_STATES state = SCR_MAIN_PROCESS_EVENT;
    static SCREEN_PERCENT_DEMO_STATES demoState = SCR_DEMO_INIT;
    static uint32_t pctAnimValue = 0;
    
    switch(demoState)
    {
        case SCR_DEMO_INIT:
        {
            pctAnimValue = 0;
            
            Screen0_PercentDemoPanel->fn->setVisible(Screen0_PercentDemoPanel, LE_TRUE);
            Screen0_PercentImageWidget->fn->setImage(Screen0_PercentImageWidget, 
                    (leImage*)Screen0_MenuDemoObj[mainDemoContext.demo].img);
            
            sprintf(percentStrBuff, "%u", pctAnimValue);
            percentStr.fn->setFromCStr(&percentStr, percentStrBuff);    
            Screen0_PercentValueLabel->fn->setString(Screen0_PercentValueLabel, (leString*)&percentStr);    
            
            demoState = SCR_DEMO_INTRO;
            
            break;
        }
        case SCR_DEMO_INTRO:
        {
            uint32_t tick;
            
            uint32_t delta = (mainDemoContext.value[mainDemoContext.demo] - pctAnimValue) / TICK_ANIM_EASE_COEFF;
            
            if (lastTickCount != tickCount)
            {
                if (delta > 0)
                {
                    pctAnimValue += delta;
                }
                else
                {
                    pctAnimValue = mainDemoContext.value[mainDemoContext.demo];
                    demoState = SCR_DEMO_PROCESS_EVENT;
                }
                
                tick = app_percentToTick(pctAnimValue);
                sprintf(percentStrBuff, "%u", pctAnimValue);
                percentStr.fn->setFromCStr(&percentStr, percentStrBuff);    
                Screen0_PercentValueLabel->fn->setString(Screen0_PercentValueLabel, (leString*)&percentStr);             

                Screen0_ShowTickLines(tick);            
            }             
            
            break;
        }
        case SCR_DEMO_PROCESS_EVENT:
        {
            switch(event)
            {
                case SCR_EVT_ROT_CW:
                {
                    uint32_t tick;
                    
                    mainDemoContext.value[mainDemoContext.demo] = 
                            (mainDemoContext.value[mainDemoContext.demo] == 100) ?
                            100: mainDemoContext.value[mainDemoContext.demo] + 1;
                    
                    tick = app_percentToTick(mainDemoContext.value[mainDemoContext.demo]);
                    
                    Screen0_ShowTickLines(tick);
                    
                    sprintf(percentStrBuff, "%u", mainDemoContext.value[mainDemoContext.demo]);
                    percentStr.fn->setFromCStr(&percentStr, percentStrBuff);    
                    Screen0_PercentValueLabel->fn->setString(Screen0_PercentValueLabel, (leString*)&percentStr);
                    
                    APP_SetBacklightBrightness(mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] > MIN_BRIGHTNESS ? 
                            mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] :
                            MIN_BRIGHTNESS);                    
                    
                    break;
                }
                case SCR_EVT_ROT_CCW:
                {   
                    uint32_t tick;
                    
                    mainDemoContext.value[mainDemoContext.demo] = 
                            (mainDemoContext.value[mainDemoContext.demo] == 0) ?
                            0: mainDemoContext.value[mainDemoContext.demo] - 1;
                    
                    tick = app_percentToTick(mainDemoContext.value[mainDemoContext.demo]);
                    
                    Screen0_ShowTickLines(tick);
                    
                    sprintf(percentStrBuff, "%u", mainDemoContext.value[mainDemoContext.demo]);
                    percentStr.fn->setFromCStr(&percentStr, percentStrBuff);    
                    Screen0_PercentValueLabel->fn->setString(Screen0_PercentValueLabel, (leString*)&percentStr);

                    APP_SetBacklightBrightness(mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] > MIN_BRIGHTNESS ? 
                            mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] :
                            MIN_BRIGHTNESS);
                    break;
                }
                case SCR_EVT_ROT_DOWN:
                {
                    if (knobDownCount == 0)
                    {
                        knobDownCount = 1;
                    }
                    
                    break;
                }
                case SCR_EVT_ROT_UP:
                {
                    if (knobDownCount > KNOB_HOLD_SECS)
                    {
                        demoState = SCR_DEMO_EXIT;
                    }
                
                    knobDownCount = 0;
                    
                    break;
                }
                case SCR_EVT_WHEEL_CW:
                case SCR_EVT_WHEEL_CCW:
                case SCR_EVT_WHEEL_ACTIVE:
                {
                    uint32_t angle = Screen0_GetArg();
                    uint32_t tick;
                    
                    tick = app_angleToTick(angle);
                    
                    Screen0_ShowTickLines(tick);
                    
                    mainDemoContext.value[mainDemoContext.demo] = app_angleToPercent(angle);
                    
                    if (mainDemoContext.demo == SCR_MAIN_LIGHT_DEMO)
                    {
                        APP_SetBacklightBrightness(mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] > MIN_BRIGHTNESS ? 
                            mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] :
                            MIN_BRIGHTNESS);
                        
                        if (mainDemoContext.value[mainDemoContext.demo] < MIN_BRIGHTNESS)
                            mainDemoContext.value[mainDemoContext.demo] = MIN_BRIGHTNESS;
                    }
                    
                    sprintf(percentStrBuff, "%u", mainDemoContext.value[mainDemoContext.demo]);
                    percentStr.fn->setFromCStr(&percentStr, percentStrBuff);    
                    Screen0_PercentValueLabel->fn->setString(Screen0_PercentValueLabel, (leString*)&percentStr);                                           
                    
                    break;
                }
                case SCR_EVT_HOME_SELECT:
                {
                    Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_LRG);
                    break;
                }
                case SCR_EVT_GO_HOME:
                {
                    Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_MED);
                    demoState = SCR_DEMO_EXIT;

                    break;
                }
                default:
                    break;
            }

            break;
        }
        case SCR_DEMO_EXIT:
        {
            Screen0_PercentDemoPanel->fn->setVisible(Screen0_PercentDemoPanel, LE_FALSE);
            Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_MED);            

            mainDemoContext.mainProcessFunc = processMainMenuEvents;
            state = SCR_MAIN_INTRO_TICKS;
            demoState = SCR_DEMO_INIT;
            break;
        }
        default:
            break;
    }
    
    if (lastSecCount != secTickCount)
    {
        if (knobDownCount > 0)
        {
            if (knobDownCount > KNOB_HOLD_SECS)
            {
                Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_LRG);
            }
            else
            {
                Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_MED);
                knobDownCount++;
            }
        }
        
        lastSecCount = secTickCount;
    } 
    
    return state;
}
    
SCREEN_MAIN_STATES processMainTimerControl(SCR_EVENTS event)
{
    SCREEN_MAIN_STATES state = SCR_MAIN_PROCESS_EVENT;
    static SCREEN_PERCENT_DEMO_STATES demoState = SCR_DEMO_INIT;
    static uint32_t timerAnimValue = 0;
    static uint32_t timerStartValue = MAX_TIMER_COUNT;
    static SCR_TIMER_ADJUST_MODE adjustMode = SCR_TIMER_ADJUST_SEC;
    
    switch(demoState)
    {
        case SCR_DEMO_INIT:
        {
            timerAnimValue = 0;
            Screen0_TimerDemoPanel->fn->setVisible(Screen0_TimerDemoPanel, LE_TRUE);
            Screen0_TimerSecsTag->fn->setVisible(Screen0_TimerSecsTag, LE_TRUE);
            Screen0_TimerMinsTag->fn->setVisible(Screen0_TimerMinsTag, LE_TRUE);
            Screen0_TimerSecsButton->fn->setVisible(Screen0_TimerSecsButton, LE_TRUE);
            Screen0_TimerMinsButton->fn->setVisible(Screen0_TimerMinsButton, LE_TRUE);              
            
            Screen0_updateTimerDemoLabel(0);
            rotaryAngle = 0;
            adjustMode = SCR_TIMER_ADJUST_SEC;
            
            demoState = SCR_DEMO_INTRO;
            
            break;
        }
        case SCR_DEMO_INTRO:
        {
            uint32_t tick;
            uint32_t delta = (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] - timerAnimValue) / TICK_ANIM_EASE_COEFF;
            
             if (lastTickCount != tickCount)
            {
                if (delta > 0)
                {
                    timerAnimValue += delta;
                }
                else
                {
                    timerAnimValue = mainDemoContext.value[SCR_MAIN_TIMER_DEMO];
                    demoState = SCR_DEMO_PROCESS_EVENT;
                }

                Screen0_updateTimerDemoLabel(timerAnimValue);

                if (timerStartValue > 0)
                {
                    tick = app_percentToTick((timerAnimValue * 100) / 
                                            timerStartValue);
                }
                else
                {
                    tick = 0;
                }

                Screen0_ShowTickLines(tick);
                
                lastTickCount = tickCount;
            }
            
            break;
        }
        case SCR_DEMO_PROCESS_EVENT:
        {
            switch(event)
            {
                case SCR_EVT_ROT_CCW:
                {
                    if (timerRunning == true)
                        break;
                    
                    if (knobDownCount == 0)
                    {
                        rotaryAngle = app_normalizeAngle(rotaryAngle + 1);

                        if (adjustMode == SCR_TIMER_ADJUST_MIN)
                        {
                            mainDemoContext.value[SCR_MAIN_TIMER_DEMO] = 
                                    (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] - 60 > 0) ?
                                     mainDemoContext.value[SCR_MAIN_TIMER_DEMO] - 60 :
                                     0;
                        }
                        else
                        {
                            mainDemoContext.value[SCR_MAIN_TIMER_DEMO] = 
                                    (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] > 0) ?
                                     mainDemoContext.value[SCR_MAIN_TIMER_DEMO] - 1 :
                                     0;
                        }                        
                        
                        timerStartValue = mainDemoContext.value[SCR_MAIN_TIMER_DEMO];

                        Screen0_updateTimerDemoLabel(timerStartValue);

                        Screen0_ShowTickLine((360 - rotaryAngle) % NUM_TICK_LINES);
                    }
                    else
                    {
                        knobDownCount = 1;
                        adjustMode = (adjustMode == SCR_TIMER_ADJUST_SEC) ? 
                                SCR_TIMER_ADJUST_MIN : SCR_TIMER_ADJUST_SEC;
                    }
                    
                    break;
                }
                case SCR_EVT_ROT_CW:
                {   
                    if (timerRunning == true)
                        break;
                    
                    if (knobDownCount == 0)
                    {
                        rotaryAngle = app_normalizeAngle(rotaryAngle - 1);

                        if (adjustMode == SCR_TIMER_ADJUST_MIN)
                        {
                            mainDemoContext.value[SCR_MAIN_TIMER_DEMO] = 
                                    (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] + 60 < MAX_TIMER_COUNT) ?
                                     mainDemoContext.value[SCR_MAIN_TIMER_DEMO] + 60 :
                                     MAX_TIMER_COUNT;
                        }
                        else
                        {
                            mainDemoContext.value[SCR_MAIN_TIMER_DEMO] = 
                                    (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] < MAX_TIMER_COUNT) ?
                                     mainDemoContext.value[SCR_MAIN_TIMER_DEMO] + 1 :
                                     MAX_TIMER_COUNT;
                        }

                        timerStartValue = mainDemoContext.value[SCR_MAIN_TIMER_DEMO];

                        Screen0_updateTimerDemoLabel(timerStartValue);

                        Screen0_ShowTickLine((360 - rotaryAngle) % NUM_TICK_LINES);
                    }
                    else
                    {
                        knobDownCount = 1;
                        adjustMode = (adjustMode == SCR_TIMER_ADJUST_SEC) ? 
                                SCR_TIMER_ADJUST_MIN : SCR_TIMER_ADJUST_SEC;
                    }
 
                    break;
                }
                case SCR_EVT_ROT_DOWN:
                {
                    if (knobDownCount == 0)
                    {
                        knobDownCount = 1;
                    }
                    break;
                }
                case SCR_EVT_ROT_UP:
                {
                    if (knobDownCount > KNOB_HOLD_SECS)
                    {
                        demoState = SCR_DEMO_EXIT;
                        Screen0_StartTimer(false);
                        
                    }
                    else if (knobDownCount == 1)
                    {
                        Screen0_TimerSecsTag->fn->setVisible(Screen0_TimerSecsTag, LE_TRUE);
                        Screen0_TimerMinsTag->fn->setVisible(Screen0_TimerMinsTag, LE_TRUE);
                        
                        Screen0_StartTimer(timerRunning == true ? false : true);
                    }
                    
                    Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_MED);

                    knobDownCount = 0;
                    
                    break;
                }
                case SCR_EVT_WHEEL_ACTIVE:
                {
                    Screen0_TimerSecsTag->fn->setVisible(Screen0_TimerSecsTag, LE_TRUE);
                    Screen0_TimerMinsTag->fn->setVisible(Screen0_TimerMinsTag, LE_TRUE);
                    Screen0_TimerSecsButton->fn->setVisible(Screen0_TimerSecsButton, LE_TRUE);
                    Screen0_TimerMinsButton->fn->setVisible(Screen0_TimerMinsButton, LE_TRUE);   
                    
                    Screen0_StartTimer(false);
                    
                    break;
                }
                case SCR_EVT_WHEEL_CW:
                {
                    uint32_t angle = Screen0_GetArg();
                            
                    if (adjustMode == SCR_TIMER_ADJUST_MIN)
                    {
                        mainDemoContext.value[SCR_MAIN_TIMER_DEMO] = 
                                (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] + 60 < MAX_TIMER_COUNT) ?
                                 mainDemoContext.value[SCR_MAIN_TIMER_DEMO] + 60 :
                                 MAX_TIMER_COUNT;
                    }
                    else
                    {
                        mainDemoContext.value[SCR_MAIN_TIMER_DEMO] = 
                                (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] < MAX_TIMER_COUNT) ?
                                 mainDemoContext.value[SCR_MAIN_TIMER_DEMO] + 1 :
                                 MAX_TIMER_COUNT;
                    }
                    
                    timerStartValue = mainDemoContext.value[SCR_MAIN_TIMER_DEMO];
                    
                    Screen0_updateTimerDemoLabel(timerStartValue);
                    Screen0_ShowTickLinesByAngle(angle, TOUCH_ANGLE_TICK_COUNT);
                    
                    break;
                }
                case SCR_EVT_WHEEL_CCW:
                {
                    uint32_t angle = Screen0_GetArg();
                            
                    if (adjustMode == SCR_TIMER_ADJUST_MIN)
                    {
                        mainDemoContext.value[SCR_MAIN_TIMER_DEMO] = 
                                (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] - 60 > 0) ?
                                 mainDemoContext.value[SCR_MAIN_TIMER_DEMO] - 60 :
                                 0;
                    }
                    else
                    {
                        mainDemoContext.value[SCR_MAIN_TIMER_DEMO] = 
                                (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] > 0) ?
                                 mainDemoContext.value[SCR_MAIN_TIMER_DEMO] - 1 :
                                 0;
                    }
                    
                    timerStartValue = mainDemoContext.value[SCR_MAIN_TIMER_DEMO];
                    
                    Screen0_updateTimerDemoLabel(timerStartValue);
                    Screen0_ShowTickLinesByAngle(angle, TOUCH_ANGLE_TICK_COUNT);
                    
                    break;
                }
                case SCR_EVT_WHEEL_RELEASED:
                {
                    Screen0_ShowTickLines(0);
                    
                    break;
                }
                case SCR_EVT_TIMER_STARTSTOP:
                {
                    if (timerRunning == true)
                        Screen0_StartTimer(false);
                    else
                        Screen0_StartTimer(true);
                    
                    Screen0_TimerSecsTag->fn->setVisible(Screen0_TimerSecsTag, LE_TRUE);
                    Screen0_TimerMinsTag->fn->setVisible(Screen0_TimerMinsTag, LE_TRUE);                    
                    
                    break;
                }
                case SCR_EVT_TIMER_SEC_SELECT:
                {
                    adjustMode = SCR_TIMER_ADJUST_SEC;
                    break;
                }
                case SCR_EVT_TIMER_MIN_SELECT:
                {
                    adjustMode = SCR_TIMER_ADJUST_MIN;
                    break;
                }
                case SCR_EVT_HOME_SELECT:
                {
                    Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_LRG);
                    break;
                }
                case SCR_EVT_GO_HOME:
                {
                    Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_MED);
                    demoState = SCR_DEMO_EXIT;
                    
                    Screen0_StartTimer(false);

                    break;
                }
                default:
                    break;
            }

            break;
        }
        case SCR_DEMO_EXIT:
        {
            Screen0_TimerDemoPanel->fn->setVisible(Screen0_TimerDemoPanel, LE_FALSE);
            mainDemoContext.mainProcessFunc = processMainMenuEvents;
            state = SCR_MAIN_INTRO_TICKS;
            demoState = SCR_DEMO_INIT;
            rotaryAngle = 90;

            break;
        }
        default:
        {
            break;
        }
    }
    
    if (lastSecCount != secTickCount)
    {
        static bool timerLabelVisible = false;
        
        if (timerRunning == true)
        {
            if (mainDemoContext.value[SCR_MAIN_TIMER_DEMO] == 0)
            {
                timerLabelVisible = !timerLabelVisible;

                Screen0_TimerSecsButton->fn->setVisible(Screen0_TimerSecsButton,
                            (timerLabelVisible == true) ? LE_TRUE : LE_FALSE);
                Screen0_TimerMinsButton->fn->setVisible(Screen0_TimerMinsButton,
                            (timerLabelVisible == true) ? LE_TRUE : LE_FALSE);
                
                Screen0_ShowTickLines(0); 
            }
            else
            {
                uint32_t tick;
                            
                mainDemoContext.value[SCR_MAIN_TIMER_DEMO] -= 1;
             
                Screen0_updateTimerDemoLabel(mainDemoContext.value[SCR_MAIN_TIMER_DEMO]);
                
                tick = app_percentToTick((mainDemoContext.value[SCR_MAIN_TIMER_DEMO] * 100) / 
                                        timerStartValue);
                
                Screen0_ShowTickLines(tick); 
            }
            
        }
        else
        {
            timerLabelVisible = !timerLabelVisible;
            
            if (adjustMode == SCR_TIMER_ADJUST_SEC)
            {
                Screen0_TimerSecsTag->fn->setVisible(Screen0_TimerSecsTag,
                                (timerLabelVisible == true) ? LE_TRUE : LE_FALSE);
                Screen0_TimerMinsTag->fn->setVisible(Screen0_TimerMinsTag, LE_TRUE);
            }
            else
            {
                Screen0_TimerSecsTag->fn->setVisible(Screen0_TimerSecsTag, LE_TRUE);
                Screen0_TimerMinsTag->fn->setVisible(Screen0_TimerMinsTag,
                               (timerLabelVisible == true) ? LE_TRUE : LE_FALSE);

            }
        }
        
        if (knobDownCount > 0)
        {
            knobDownCount++;
            if (knobDownCount > KNOB_HOLD_SECS)
            {
                Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_LRG);
            }
        }
        
        lastSecCount = secTickCount;
    }    
    
    return state;    
}

SCREEN_MAIN_STATES processMainTempControl(SCR_EVENTS event)
{
    SCREEN_MAIN_STATES state = SCR_MAIN_PROCESS_EVENT;
    static SCREEN_PERCENT_DEMO_STATES demoState = SCR_DEMO_INIT;
    static uint32_t tempAnimValue = 0;

    switch(demoState)
    {
        case SCR_DEMO_INIT:
        {
            tempAnimValue = TEMP_MIN_VALUE_F;
            Screen0_TempDemoPanel->fn->setVisible(Screen0_TempDemoPanel, LE_TRUE);
            demoState = SCR_DEMO_INTRO;
            rotaryAngle = 90;
            
            break;
        }
        case SCR_DEMO_INTRO:
        case SCR_DEMO_UPDATE:
        {
            uint32_t tick;
            
            tempAnimValue += PCT_TICK_ANIM_STEP;
            
            if (tempAnimValue >= mainDemoContext.value[SCR_MAIN_THERM_DEMO])
            {
                tempAnimValue = mainDemoContext.value[SCR_MAIN_THERM_DEMO];
                demoState = SCR_DEMO_PROCESS_EVENT;
            }
            
            tick = app_percentToTick(((tempAnimValue - TEMP_MIN_VALUE_F) * 100) / 
                                      (TEMP_MAX_VALUE_F - TEMP_MIN_VALUE_F));
            
            rotaryAngle = app_tickToAngle(tick);
            
            Screen0_UpdateTempLabel(tempAnimValue);
            
            Screen0_ShowTickLines(tick);            
            
            break;
        }
        case SCR_DEMO_PROCESS_EVENT:
        {
            switch(event)
            {
                case SCR_EVT_ROT_CW:
                {
                    if (knobDownCount == 0)
                    {
                        rotaryAngle = app_normalizeAngle(rotaryAngle - ROTARY_ANGLE_TEMP_STEP);

                        tempTargetValue = TEMP_MIN_VALUE_F + 
                                ((TEMP_MAX_VALUE_F - TEMP_MIN_VALUE_F) * app_angleToPercent(rotaryAngle)) / 100;

                        Screen0_UpdateTempLabel(tempTargetValue);

                        Screen0_ShowTickLinesByAngle(rotaryAngle, TOUCH_ANGLE_TICK_COUNT);                    

                        wheelActive = true;
                    }
                    else
                    {
                        knobDownCount = 1;
                        Screen0_ToggleThermUnits();
                    }
                    
                    break;
                }
                case SCR_EVT_ROT_CCW:
                {
                    if (knobDownCount == 0)
                    {
                        rotaryAngle = app_normalizeAngle(rotaryAngle + ROTARY_ANGLE_TEMP_STEP);

                        tempTargetValue = TEMP_MIN_VALUE_F + 
                                ((TEMP_MAX_VALUE_F - TEMP_MIN_VALUE_F) * app_angleToPercent(rotaryAngle)) / 100;

                        Screen0_UpdateTempLabel(tempTargetValue);

                        Screen0_ShowTickLinesByAngle(rotaryAngle, TOUCH_ANGLE_TICK_COUNT);                    

                        wheelActive = true;
                    }
                    else
                    {
                        knobDownCount = 1;
                        Screen0_ToggleThermUnits();
                    }
 
                    break;
                }
                case SCR_EVT_ROT_DOWN:
                {
                    knobDownCount = 1;
                    break;
                }
                case SCR_EVT_ROT_UP:
                {
                    if (knobDownCount > KNOB_HOLD_SECS)
                    {
                        demoState = SCR_DEMO_EXIT;
                    }
                    else if (knobDownCount == 1)
                    {
                        wheelActive = false;
                    }
                    
                    Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_MED);
                    
                    knobDownCount = 0;
                    
                    break;
                }
                case SCR_EVT_WHEEL_CW:
                case SCR_EVT_WHEEL_CCW:
                case SCR_EVT_WHEEL_ACTIVE:
                {
                    uint32_t angle = Screen0_GetArg();
                    
                    tempTargetValue = TEMP_MIN_VALUE_F + 
                            ((TEMP_MAX_VALUE_F - TEMP_MIN_VALUE_F) * app_angleToPercent(angle)) / 100;
                    
                    Screen0_UpdateTempLabel(tempTargetValue);
                    
                    Screen0_ShowTickLinesByAngle(angle, TOUCH_ANGLE_TICK_COUNT);
                    
                    wheelActive = true;
                    
                    break;
                }
                case SCR_EVT_WHEEL_RELEASED:
                {
                    tempAnimValue = TEMP_MIN_VALUE_F;
                    demoState = SCR_DEMO_UPDATE;
                    wheelActive = false;
                    
                    break;
                }
                case SCR_EVT_TEMP_TOGGLE_UNITS:
                {
                    Screen0_ToggleThermUnits();
                    
                    break;
                }
                case SCR_EVT_HOME_SELECT:
                {
                    Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_LRG);
                    break;
                }
                case SCR_EVT_GO_HOME:
                {
                    Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_MED);
                    demoState = SCR_DEMO_EXIT;

                    break;
                }
                default:
                {
                    if (lastSecCount != secTickCount)
                    {
                        if (tempTargetValue !=  mainDemoContext.value[SCR_MAIN_THERM_DEMO] 
                            && wheelActive == false)
                        {
                            uint32_t tick;

                            mainDemoContext.value[SCR_MAIN_THERM_DEMO] = 
                                    (tempTargetValue >  mainDemoContext.value[SCR_MAIN_THERM_DEMO]) ?
                                    mainDemoContext.value[SCR_MAIN_THERM_DEMO] + 1 : 
                                    mainDemoContext.value[SCR_MAIN_THERM_DEMO] - 1;

                            tick = app_percentToTick(((mainDemoContext.value[SCR_MAIN_THERM_DEMO] - TEMP_MIN_VALUE_F) * 100) / 
                                                      (TEMP_MAX_VALUE_F - TEMP_MIN_VALUE_F));

                            Screen0_UpdateTempLabel(mainDemoContext.value[SCR_MAIN_THERM_DEMO]);
                            Screen0_ShowTickLines(tick);

                            if (tempTargetValue !=  mainDemoContext.value[SCR_MAIN_THERM_DEMO])
                            {
                                tick = app_percentToTick(((tempTargetValue - TEMP_MIN_VALUE_F) * 100) / 
                                                          (TEMP_MAX_VALUE_F - TEMP_MIN_VALUE_F));
                                Screen0_ShowTick(tick, (secTickCount % 2) == 1 ? true : false);
                            }
                        }
                        
                        if (knobDownCount > 0)
                        {
                            knobDownCount++;
                            if (knobDownCount > KNOB_HOLD_SECS)
                            {
                                Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_LRG);
                            }
                        }

                        lastSecCount = secTickCount;                        
                    }
                    break;
                }
            }
            
            break;
        }
        case SCR_DEMO_EXIT:
        {
            Screen0_TempDemoPanel->fn->setVisible(Screen0_TempDemoPanel, LE_FALSE);
            mainDemoContext.mainProcessFunc = processMainMenuEvents;
            state = SCR_MAIN_INTRO_TICKS;
            demoState = SCR_DEMO_INIT;
            rotaryAngle = 90;

            break;
        }
        default:
            break;
    }
    
    return state;
}

SCREEN_MAIN_STATES processLockedScreenEvents(SCR_EVENTS event)
{
    SCREEN_MAIN_STATES state = SCR_MAIN_LOCKED;
    
    switch(event)
    {
        //Unlock with star
        case SCR_EVT_MG_STAR:
        {
            Screen0_GestureLabelWidget->fn->setVisible(Screen0_GestureLabelWidget, LE_TRUE);
            Screen0_GestureLabelWidget->fn->setString(Screen0_GestureLabelWidget, (leString*) &string_StarString);

            break;
        }
        case SCR_EVT_MG_CHECK:
        {
            Screen0_GestureLabelWidget->fn->setVisible(Screen0_GestureLabelWidget, LE_TRUE);
            Screen0_GestureLabelWidget->fn->setString(Screen0_GestureLabelWidget, (leString*) &string_CheckString);
            break;
        }
        case SCR_EVT_MG_ALPHA:
        {
            Screen0_GestureLabelWidget->fn->setVisible(Screen0_GestureLabelWidget, LE_TRUE);
            Screen0_GestureLabelWidget->fn->setString(Screen0_GestureLabelWidget, (leString*) &string_AlphaString);
            
            break;
        }
        case SCR_EVT_MG_M:
        {
            Screen0_GestureLabelWidget->fn->setVisible(Screen0_GestureLabelWidget, LE_TRUE);
            Screen0_GestureLabelWidget->fn->setString(Screen0_GestureLabelWidget, (leString*) &string_MString);
            
            break;
        }
        case SCR_EVT_MG_S:
        {
            Screen0_GestureLabelWidget->fn->setVisible(Screen0_GestureLabelWidget, LE_TRUE);
            Screen0_GestureLabelWidget->fn->setString(Screen0_GestureLabelWidget, (leString*) &string_SString);

            APP_SetBacklightBrightness(ON_BRIGHTNESS);
            mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] = ON_BRIGHTNESS;

            Screen0_UnlockLabelWidget->fn->setVisible(Screen0_UnlockLabelWidget, LE_FALSE);
            Screen0_MchpLogoImage->fn->setImage(Screen0_MchpLogoImage, &unlock);            
            state = SCR_MAIN_UNLOCKING;

                        
            
            break;
        }
        case SCR_EVT_MG_2:
        {
            Screen0_GestureLabelWidget->fn->setVisible(Screen0_GestureLabelWidget, LE_TRUE);
            Screen0_GestureLabelWidget->fn->setString(Screen0_GestureLabelWidget, (leString*) &string_TwoString);
            
            break;
        }     
        default:
        {
            break;
        }
    }
    
    return state;
}

SCREEN_MAIN_STATES processHoldScreenEvents(SCR_EVENTS event)
{
    SCREEN_MAIN_STATES state = SCR_MAIN_PROCESS_BUTTON_HOLD;
    
    switch(event)
    {
        case SCR_EVT_CENTER_BUTTON_RELEASED:
        {
            state = SCR_MAIN_PROCESS_EVENT;
            
            break;
        }        
        default:
        {
            break;
        }
    }
    
    return state;
}

SCREEN_MAIN_STATES processMainMenuEvents(SCR_EVENTS event)
{
    SCREEN_MAIN_STATES state = SCR_MAIN_PROCESS_EVENT;
    static SCREEN_MAIN_DEMOS demoSelect;
    
    switch(event)
    {
        case SCR_EVT_ROT_CCW:
        {
            rotaryAngle = app_normalizeAngle(rotaryAngle + 45);
            Screen0_ShowTickLinesByAngle(rotaryAngle, TOUCH_ANGLE_TICK_COUNT);
            demoSelect = Screen0_popDemoImageByAngle(rotaryAngle);
            
            break;
        }
        case SCR_EVT_ROT_CW:
        {
            rotaryAngle = app_normalizeAngle(rotaryAngle - 45);
            Screen0_ShowTickLinesByAngle(rotaryAngle, TOUCH_ANGLE_TICK_COUNT);
            demoSelect = Screen0_popDemoImageByAngle(rotaryAngle);
            
            break;
        }
        case SCR_EVT_ROT_DOWN:
        {
            knobDownCount = 1;
            break;
        }
        case SCR_EVT_ROT_UP:
        {
            SCREEN_RETVAL retval;
            
            if (knobDownCount == 1)
            {
                retval = Screen0_StartDemo(demoSelect);

                if (retval == SCR_SUCCESS)
                    state = SCR_MAIN_HIDE_BUTTONS_FOR_SUBMENU;
                
                knobDownCount = 0;
            }

            break;
        }
        case SCR_EVT_WHEEL_CW:
        case SCR_EVT_WHEEL_CCW:
        case SCR_EVT_WHEEL_ACTIVE:
        {
            uint32_t angle = Screen0_GetArg();
            Screen0_ShowTickLinesByAngle(angle, TOUCH_ANGLE_TICK_COUNT);
            Screen0_popDemoImageByAngle(angle);
            
            break;
        }
        case SCR_EVT_WHEEL_RELEASED:
        {
            Screen0_popDemoImageByIndex(NUM_MAIN_MENU_DEMOS);
            Screen0_ShowTickLines(0);
            break;
        }
        case SCR_EVT_HOME_SELECT:
        {
            Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_LRG);
            break;
        }
        case SCR_EVT_GO_HOME:
        {
            Screen0_HomeImageSequence->fn->showImage(Screen0_HomeImageSequence, SCR_MAIN_BTN_IMG_MED);
            mainDemoContext.mainProcessFunc = processMainMenuEvents;
            state = SCR_MAIN_INTRO_BUTTONS;
            
            break;
        }
        case SCR_EVT_SETTINGS_SELECT:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_SETTINGS_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_SETTINGS_DEMO].imgSeq), SCR_MAIN_BTN_IMG_LRG);
            break;
        }
        case SCR_EVT_GO_SETTINGS:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_SETTINGS_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_SETTINGS_DEMO].imgSeq), SCR_MAIN_BTN_IMG_MED);
            
            Screen0_StartDemo(SCR_MAIN_SETTINGS_DEMO);
            
            break;
        }
        case SCR_EVT_VOLUME_SELECT:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_VOL_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_VOL_DEMO].imgSeq), SCR_MAIN_BTN_IMG_LRG);
            
            break;
        }
        case SCR_EVT_GO_VOLUME:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_VOL_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_VOL_DEMO].imgSeq), SCR_MAIN_BTN_IMG_MED);

            Screen0_StartDemo(SCR_MAIN_VOL_DEMO);
                    
            state = SCR_MAIN_HIDE_BUTTONS_FOR_SUBMENU;
                        
            break;
        }
        case SCR_EVT_ECO_SELECT:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_ECO_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_ECO_DEMO].imgSeq), SCR_MAIN_BTN_IMG_LRG);
            
            break;
        }
        case SCR_EVT_GO_ECO:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_ECO_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_ECO_DEMO].imgSeq), SCR_MAIN_BTN_IMG_MED);
            
            Screen0_StartDemo(SCR_MAIN_ECO_DEMO);
            
            break;
        }
        case SCR_EVT_THERM_SELECT:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_THERM_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_THERM_DEMO].imgSeq), SCR_MAIN_BTN_IMG_LRG);
            break;
        }
        case SCR_EVT_GO_THERM:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_THERM_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_THERM_DEMO].imgSeq), SCR_MAIN_BTN_IMG_MED);
            
            Screen0_StartDemo(SCR_MAIN_THERM_DEMO);
            
            state = SCR_MAIN_HIDE_BUTTONS_FOR_SUBMENU;
            
            break;
        }
        case SCR_EVT_LIGHT_SELECT:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_LIGHT_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_LIGHT_DEMO].imgSeq), SCR_MAIN_BTN_IMG_LRG);
            break;
        }
        case SCR_EVT_GO_LIGHT:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_LIGHT_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_LIGHT_DEMO].imgSeq), SCR_MAIN_BTN_IMG_MED);
            
            Screen0_StartDemo(SCR_MAIN_LIGHT_DEMO);
            
            state = SCR_MAIN_HIDE_BUTTONS_FOR_SUBMENU;
            
            break;
        }
        case SCR_EVT_FAN_SELECT:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_FAN_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_FAN_DEMO].imgSeq), SCR_MAIN_BTN_IMG_LRG);
            break;
        }
        case SCR_EVT_GO_FAN:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_FAN_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_FAN_DEMO].imgSeq), SCR_MAIN_BTN_IMG_MED);
            
            Screen0_StartDemo(SCR_MAIN_FAN_DEMO);
            
            state = SCR_MAIN_HIDE_BUTTONS_FOR_SUBMENU;
            
            break;
        }
        case SCR_EVT_CLOCK_SELECT:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_TIMER_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_TIMER_DEMO].imgSeq), SCR_MAIN_BTN_IMG_LRG);
            break;
        }
        case SCR_EVT_GO_CLOCK:
        {
            (*(Screen0_MenuDemoObj[SCR_MAIN_TIMER_DEMO].imgSeq))->fn->showImage(*(Screen0_MenuDemoObj[SCR_MAIN_TIMER_DEMO].imgSeq), SCR_MAIN_BTN_IMG_MED);

            Screen0_StartDemo(SCR_MAIN_TIMER_DEMO);
            
            state = SCR_MAIN_HIDE_BUTTONS_FOR_SUBMENU;
            
            break;
        }
        case SCR_EVT_CENTER_BUTTON_PRESSED:
        {
            mainDemoContext.mainProcessFunc = processHoldScreenEvents;
            state = SCR_MAIN_PROCESS_BUTTON_HOLD;
            
            break;
        }
        default:
            break;
    }
    
    return state;
}

int32_t Screen0_ProcessMain(void)
{
    switch(mainState)
    {
        case SCR_MAIN_INIT:
        {
            mainState = SCR_MAIN_INTRO_TICKS;
            break;
        }
        case SCR_MAIN_INTRO_TICKS:
        {
            //animate ticks
            if (lastTickCount != tickCount)
            {
                currTick += NUM_TICK_LINES/32;
                Screen0_ShowTickLinesByRange(currTick - START_ANIM_TICK_LINES, currTick);
                
                if (currTick >= NUM_TICK_LINES + START_ANIM_TICK_LINES)
                {
                    Screen0_ResetDemoImages();
                    Screen0_ShowTickLines(0);
                    currTick = START_ANIM_TICK_LINES;
                    mainState = SCR_MAIN_INTRO_BUTTONS;
                }
            }
            break;
        }
        case SCR_MAIN_INTRO_BUTTONS:
        {
            if (lastTickCount != tickCount)
            {
                SCREEN_BUTTON_STATES retval;
                
                retval = Screen0_RotateShowButtons(true);
                if (retval == SCR_BUTTONS_VISIBLE)
                {
                    Screen0_MchpLogoImage->fn->setVisible(Screen0_MchpLogoImage, LE_TRUE);
                    mainState = SCR_MAIN_PROCESS_EVENT;
                    mainDemoContext.mainProcessFunc = &processMainMenuEvents;
                }
                
            }
            break;
        }
        case SCR_MAIN_PROCESS_EVENT:
        {
            SCR_EVENTS event = Screen0_GetEvent();
            
            mainState = mainDemoContext.mainProcessFunc(event);
            
            Screen0_ClearEvents();
       
            break;
        }
        case SCR_MAIN_PROCESS_BUTTON_HOLD:
        {
            SCR_EVENTS event = Screen0_GetEvent();
            
            mainState = mainDemoContext.mainProcessFunc(event);
            
            Screen0_ClearEvents();
            
            if (lastSecCount != secTickCount)
            {
                secDelayCount++;
                if (secDelayCount > LOCK_HOLD_SECS)
                {
                    secDelayCount = 0;
                    mainDemoContext.mainProcessFunc = &processLockedScreenEvents;
                    mainState = SCR_MAIN_HIDE_BUTTONS_FOR_LOCK;
                }

                lastSecCount = secTickCount;
            }   
            
            break;
        }
        case SCR_MAIN_HIDE_BUTTONS_FOR_SUBMENU:
        {
            if (lastTickCount != tickCount)
            {            
                SCREEN_BUTTON_STATES retval;
                retval = Screen0_RotateShowButtons(false);
                if (retval == SCR_BUTTONS_HIDDEN)
                {
                    Screen0_HideTickLines();
                    Screen0_MchpLogoImage->fn->setVisible(Screen0_MchpLogoImage, LE_FALSE);
                    rotaryAngle = 90;
                    mainState = SCR_MAIN_PROCESS_EVENT;
                }
            }
            break;
        }
        case SCR_MAIN_HIDE_BUTTONS_FOR_LOCK:
        {
            if (lastTickCount != tickCount)
            {            
                SCREEN_BUTTON_STATES retval;
                retval = Screen0_RotateShowButtons(false);
                if (retval == SCR_BUTTONS_HIDDEN)
                {
                    APP_SetBacklightBrightness(ECO_BRIGHTNESS);
                    mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] = ECO_BRIGHTNESS;
                    Screen0_HideTickLines();
                    Screen0_MchpLogoImage->fn->setImage(Screen0_MchpLogoImage, &lock);
                    Screen0_UnlockLabelWidget->fn->setVisible(Screen0_UnlockLabelWidget, LE_TRUE);
                    Screen0_HomeImageSequence->fn->setVisible(Screen0_HomeImageSequence, LE_FALSE);
                    rotaryAngle = 90;
                    mainState = SCR_MAIN_LOCKED;
                }
            }            
            break;
        }
        case SCR_MAIN_LOCKED:
        {
            SCR_EVENTS event = Screen0_GetEvent();
            
            mainState = mainDemoContext.mainProcessFunc(event);
            
            Screen0_ClearEvents();
            
            break;
        }
        case SCR_MAIN_UNLOCKING:
        {
            if (lastSecCount != secTickCount)
            {
                secDelayCount++;
                if (secDelayCount > UNLOCK_DELAY_SECS)
                {
                    secDelayCount = 0;
                    Screen0_MchpLogoImage->fn->setImage(Screen0_MchpLogoImage, &mchp_circle);
                    Screen0_HomeImageSequence->fn->setVisible(Screen0_HomeImageSequence, LE_TRUE);
                    Screen0_GestureLabelWidget->fn->setVisible(Screen0_GestureLabelWidget, LE_FALSE);
                    
                    mainState = SCR_MAIN_INTRO_TICKS;
                }

                lastSecCount = secTickCount;
            }             
            break;
        }
    }
    
    return mainState;
}

void Screen0_SetEvent(SCR_EVENTS event)
{
    scr_events = event;
}

void Screen0_SetEventsArgs(SCR_EVENTS event, uint32_t arg)
{
    scr_events = event;
    scr_events_arg = arg;
}

void Screen0_ClearEvent(void)
{
    scr_events = 0;
}

void Screen0_ClearEvents(void)
{
    scr_events = 0;
}

SCR_EVENTS Screen0_GetEvent(void)
{
    return scr_events;
}

uint32_t Screen0_GetArg(void)
{
    return scr_events_arg;
}

void Screen0_OnShow(void)
{
    app_inputListenerIdx = SYS_INP_AddListener(&app_inputListener);
    
    app_EnableRotaryInput();
    
    screenState = SCR_INIT;
    tempUnit = SCR_TEMP_UNIT_F;
    
    Screen0_ShowTickLines(0);
    Screen0_ShowMenuButtons(false);
    Screen0_MchpLogoImage->fn->setVisible(Screen0_MchpLogoImage, LE_FALSE);

    Screen0_PercentDemoPanel->fn->setVisible(Screen0_PercentDemoPanel, LE_FALSE);
    Screen0_TimerDemoPanel->fn->setVisible(Screen0_TimerDemoPanel, LE_FALSE);
    Screen0_TempDemoPanel->fn->setVisible(Screen0_TempDemoPanel, LE_FALSE);
    Screen0_UnlockLabelWidget->fn->setVisible(Screen0_UnlockLabelWidget, LE_FALSE);

    memset(&mainDemoContext, 0, sizeof(mainDemoContext));
    mainDemoContext.mainProcessFunc = &processMainMenuEvents;
    mainDemoContext.value[SCR_MAIN_THERM_DEMO] = TEMP_DEF_VALUE_F;
    tempTargetValue = TEMP_DEF_VALUE_F;
    
    mainDemoContext.value[SCR_MAIN_LIGHT_DEMO] = ON_BRIGHTNESS;
    
    leFixedString_Constructor(&percentStr, percentStrCharBuff, APP_STR_SIZE);
    percentStr.fn->setFont(&percentStr, (leFont*)&PercentFont);
    
    leFixedString_Constructor(&timerMinStr, timerMinStrCharBuff, TIMER_STR_SIZE);
    timerMinStr.fn->setFont(&timerMinStr, (leFont*)&TimerFont);
    
    leFixedString_Constructor(&timerSecStr, timerSecStrCharBuff, TIMER_STR_SIZE);
    timerSecStr.fn->setFont(&timerSecStr, (leFont*)&TimerFont_S);
    
    leFixedString_Constructor(&tempStr, tempStrCharBuff, TEMP_STR_SIZE);
    tempStr.fn->setFont(&tempStr, (leFont*)&PercentFont);     
}

void Screen0_OnHide(void)
{
    SYS_INP_RemoveListener(app_inputListenerIdx);
    
    app_DisableRotaryInput();
    
    percentStr.fn->destructor(&percentStr);
    timerMinStr.fn->destructor(&timerMinStr);
    timerSecStr.fn->destructor(&timerSecStr);
    tempStr.fn->destructor(&timerSecStr);
}

void event_Screen0_HomeButton_OnPressed(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_HOME_SELECT);
}

void event_Screen0_HomeButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_GO_HOME);
}

void event_Screen0_SettingsButton_OnPressed(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_SETTINGS_SELECT);
}

void event_Screen0_SettingsButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_GO_SETTINGS);
}

void event_Screen0_VolumeButton_OnPressed(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_VOLUME_SELECT);
}

void event_Screen0_VolumeButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_GO_VOLUME);
}

void event_Screen0_EcoButton_OnPressed(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_ECO_SELECT);
}

void event_Screen0_EcoButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_GO_ECO);
}

void event_Screen0_ThermButton_OnPressed(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_THERM_SELECT);
}

void event_Screen0_ThermButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_GO_THERM);
}

void event_Screen0_LightButton_OnPressed(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_LIGHT_SELECT);
}

void event_Screen0_LightButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_GO_LIGHT);
}

void event_Screen0_FanButton_OnPressed(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_FAN_SELECT);
}

void event_Screen0_FanButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_GO_FAN);
}

void event_Screen0_ClockButton_OnPressed(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_CLOCK_SELECT);
}

void event_Screen0_ClockButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_GO_CLOCK);
}

void event_Screen0_TimerStartStop_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_TIMER_STARTSTOP);
}

void event_Screen0_TimerMinsButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_TIMER_MIN_SELECT);
}

void event_Screen0_TimerSecsButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_TIMER_SEC_SELECT);
}

void event_Screen0_FahrCelsButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_TEMP_TOGGLE_UNITS);
}

void event_Screen0_CenterButton_OnPressed(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_CENTER_BUTTON_PRESSED);
}

void event_Screen0_CenterButton_OnReleased(leButtonWidget* btn)
{
    Screen0_SetEvent(SCR_EVT_CENTER_BUTTON_RELEASED);
}

void Screen0_OnUpdate(void)
{
    switch(screenState)
    {
        case SCR_INIT:
        {
            if (!leRenderer_IsIdle() || leEvent_GetCount() != 0)
            {
                break;
            }
            
            APP_SetBacklightBrightness(100);
            screenState = SCR_WAIT;
            rotaryAngle = 90;

            break;            
        }
        case SCR_WAIT:
        {
            if (APP_GetBacklightBrightness() == 100)
            {
                screenState = SCR_MAIN;
            }
            break;            
        }
        case SCR_MAIN:
        {
            Screen0_ProcessMain();
            break;
        }
        default:
            break;
    }
    
    lastTickCount = tickCount;
}