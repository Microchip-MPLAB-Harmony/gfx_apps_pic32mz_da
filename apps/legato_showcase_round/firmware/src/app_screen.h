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

#ifndef APP_SCREEN_H
#define	APP_SCREEN_H

#define NUM_TICK_LINES 93
#define START_ANIM_TICK_LINES 8
#define CLOCK_TICK_TIMER_PERIOD_MS 5
#define CLOCK_TICKS_PER_SEC (1000/CLOCK_TICK_TIMER_PERIOD_MS)
#define BUTTON_DIST_CENTER_PIX 106
#define CENTER_POS_XY 216
#define WHEEL_TOUCH_MIN_RADIUS_PX 145

#define BUTTON_SHOW_INC_PIX 3
#define APP_STR_SIZE 32
#define TIMER_STR_SIZE 16
#define TEMP_STR_SIZE 16

#define TEMP_MAX_VALUE_F    99
#define TEMP_MIN_VALUE_F    50
#define TEMP_DEF_VALUE_F    75

#define TEMP_MAX_VALUE_C    37
#define TEMP_MIN_VALUE_C    10

#define PCT_TICK_ANIM_STEP 4
#define MAX_TIMER_COUNT 3600
#define TICK_ANIM_EASE_COEFF 2
#define TOUCH_ANGLE_TICK_COUNT 4
#define IMAGE_ANGLE_RANGE 45

#define ROTARY_ANGLE_TEMP_STEP (360 / (TEMP_MAX_VALUE_F - TEMP_MIN_VALUE_F))

#define ON_BRIGHTNESS 100
#define ECO_BRIGHTNESS 5
#define MIN_BRIGHTNESS 5
#define OFF_BRIGHTNESS 0

#define KNOB_HOLD_SECS 2
#define UNLOCK_DELAY_SECS 2
#define LOCK_HOLD_SECS 2

//MG Gestures
#define MG_2                            0x0u
#define MG_CHECK                        0x1u
#define MG_ALPHA                        0x4u
#define MG_S                            0x5u
#define MG_STAR                         0x8u
#define MG_M                            0xfu

typedef enum
{
    SCR_MAIN_TIMER_DEMO,
    SCR_MAIN_FAN_DEMO,
    SCR_MAIN_LIGHT_DEMO,
    SCR_MAIN_THERM_DEMO,
    SCR_MAIN_ECO_DEMO,
    SCR_MAIN_VOL_DEMO,
    SCR_MAIN_SETTINGS_DEMO,
    NUM_MAIN_MENU_DEMOS,
} SCREEN_MAIN_DEMOS;

typedef enum
{
    SCR_SUCCESS = 0,
    SCR_FAILURE,
} SCREEN_RETVAL;

enum
{
  SCR_MAIN_BTN_IMG_MED = 0,
  SCR_MAIN_BTN_IMG_LRG = 1,
};

typedef enum
{
    SCR_INIT,
    SCR_WAIT,
    SCR_MAIN,
} SCREEN_STATES;


typedef enum
{
    SCR_MAIN_INIT,
    SCR_MAIN_INTRO_TICKS,
    SCR_MAIN_INTRO_BUTTONS,
    SCR_MAIN_PROCESS_EVENT,
    SCR_MAIN_PROCESS_BUTTON_HOLD,
    SCR_MAIN_HIDE_BUTTONS_FOR_SUBMENU,
    SCR_MAIN_HIDE_BUTTONS_FOR_LOCK,
    SCR_MAIN_LOCKED,
    SCR_MAIN_UNLOCKING,
} SCREEN_MAIN_STATES;

typedef enum
{
    SCR_DEMO_INIT,
    SCR_DEMO_INTRO,
    SCR_DEMO_PROCESS_EVENT,
    SCR_DEMO_UPDATE,
    SCR_DEMO_EXIT,    
} SCREEN_PERCENT_DEMO_STATES;

typedef enum
{
    SCR_BUTTONS_SHOWING,
    SCR_BUTTONS_VISIBLE,
    SCR_BUTTONS_HIDING,
    SCR_BUTTONS_HIDDEN
} SCREEN_BUTTON_STATES;

typedef enum
{
    SCR_EVT_NONE,
            
    //rotary switch events
    SCR_EVT_ROT_CW,
    SCR_EVT_ROT_CCW,
    SCR_EVT_ROT_DOWN,
    SCR_EVT_ROT_UP,
    SCR_EVT_ROT_HOLD,

    //wheel events
    SCR_EVT_WHEEL_CW,
    SCR_EVT_WHEEL_CCW,
    SCR_EVT_WHEEL_ACTIVE,
    SCR_EVT_WHEEL_RELEASED,
            
    //demo button events
    SCR_EVT_HOME_SELECT,
    SCR_EVT_GO_HOME,
    SCR_EVT_SETTINGS_SELECT,
    SCR_EVT_GO_SETTINGS,
    SCR_EVT_VOLUME_SELECT,
    SCR_EVT_GO_VOLUME,
    SCR_EVT_ECO_SELECT,
    SCR_EVT_GO_ECO,
    SCR_EVT_THERM_SELECT,
    SCR_EVT_GO_THERM,
    SCR_EVT_LIGHT_SELECT,
    SCR_EVT_GO_LIGHT,
    SCR_EVT_FAN_SELECT,
    SCR_EVT_GO_FAN,
    SCR_EVT_CLOCK_SELECT,
    SCR_EVT_GO_CLOCK,
            
    //generic events
    SCR_EVT_TIMER_STARTSTOP,
    SCR_EVT_TIMER_SEC_SELECT,
    SCR_EVT_TIMER_MIN_SELECT,
    SCR_EVT_TEMP_TOGGLE_UNITS,
            
    //button events
    SCR_EVT_CENTER_BUTTON_PRESSED,
    SCR_EVT_CENTER_BUTTON_RELEASED,
            
    //MG Gesture Events
    SCR_EVT_MG_CHECK,
    SCR_EVT_MG_STAR,
    SCR_EVT_MG_ALPHA,
    SCR_EVT_MG_M,
    SCR_EVT_MG_S,
    SCR_EVT_MG_2,
} SCR_EVENTS;

typedef enum
{
    SCR_TIMER_ADJUST_SEC,  
    SCR_TIMER_ADJUST_MIN,
} SCR_TIMER_ADJUST_MODE;

typedef enum
{
    SCR_TEMP_UNIT_F,  
    SCR_TEMP_UNIT_C,
} SCR_TEMP_UNITS;


typedef struct
{
    leButtonWidget ** btn;
    leImageSequenceWidget ** imgSeq;
    leImage * img;
} SCR_MENU_DEMO_OBJ;

typedef struct
{
    SCREEN_MAIN_STATES (*mainProcessFunc) (SCR_EVENTS event);
    SCREEN_MAIN_DEMOS demo;
    uint32_t value[NUM_MAIN_MENU_DEMOS];
} SCR_MAIN_DEMO_CONTEXT;

void Screen0_SetEvent(SCR_EVENTS event);

void Screen0_SetEventsArgs(SCR_EVENTS event, uint32_t arg);

void Screen0_ClearEvent(void);

void Screen0_ClearEvents(void);

SCR_EVENTS Screen0_GetEvent(void);

uint32_t Screen0_GetArg(void);

extern volatile uint32_t secTickCount;
extern volatile uint32_t tickCount;

#endif	/* APP_SCREEN_H */

