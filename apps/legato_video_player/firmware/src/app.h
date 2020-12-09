/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#ifndef VBUS_AH_PowerEnable
#define VBUS_AH_PowerEnable()  VBUS_AH_Set()
#endif
#ifndef VBUS_AH_PowerDisable
#define VBUS_AH_PowerDisable() VBUS_AH_Clear()
#endif

//Use video buffer in SRAM, otherwise default is in DDR
#define USE_SRAM_VIDEO_BUFF 1
#define USE_RGB565_VIDEO_FRAME_BUFFER 1
#define ENABLE_AUTOREPLAY 1
//#define MAX_FPS 1

//Hardcode the Layer 0 frame buffers in DDR, should match addresses in drv_gfx_glcd.c
#define FB_BUFF             0xA8000000
#define FB_BUFF2            0xA8465000

#define DISPLAY_WIDTH_PX            800
#define DISPLAY_HEIGHT_PX           480

#define SCALE_INC_DIV               4      

#define USBMSD_MOUNT_NAME           "/mnt/myDrive1"
#define SDCARD_MOUNT_NAME           "/mnt/myDrive2"

#define DEFAULT_SOURCE_FILENAME     "rgb565_wqvga_24fps.raw"
#define DEFAULT_SOURCE_WIDTH_PX     400
#define DEFAULT_SOURCE_HEIGHT_PX    240
#define DEFAULT_SOURCE_BPP          2

#define DEFAULT_DEST_WIDTH_PX       800
#define DEFAULT_DEST_HEIGHT_PX      480

#ifdef USE_SRAM_VIDEO_BUFF
#define DEFAULT_DEST_BUFF           videoBuff
#else
#define DEFAULT_DEST_BUFF           0xA8753000
#endif

#define DEFAULT_DEST_XPOS           ((DISPLAY_WIDTH_PX - DEFAULT_DEST_WIDTH_PX)/2)
#define DEFAULT_DEST_YPOS           ((DISPLAY_WIDTH_PX - DEFAULT_DEST_HEIGHT_PX)/2)

#define DEFAULT_N2D_SOURCE_FMT      N2D_RGB565

#ifdef USE_RGB565_VIDEO_FRAME_BUFFER
#define DEFAULT_N2D_DEST_FMT        N2D_RGB565
#define DEFAULT_DEST_BPP            2
#define DEFAULT_FILL                0x0
#else
#define DEFAULT_N2D_DEST_FMT        N2D_RGBA8888
#define DEFAULT_DEST_BPP            4
#define DEFAULT_FILL                0xff000000
#endif

#define WGETY(widget) widget->fn->getY(widget)
#define WSETY(widget, val) widget->fn->setY(widget, val)
#define WSETHEIGHT(widget, val) widget->fn->setHeight(widget, val)

#define PANEL_MINY 387
#define CLOCK_ANIM_TIMER_PERIOD_MS 20
#define CLOCK_SEC_TIMER_PERIOD_MS 1000
#define PANEL_STEP_DIV 4
#define CONTROL_LAYER_MAX_ALPHA 230
#define CONTROL_LAYER_FADE_STEP 5

#define PLAYBACK_24FPS_PERIOD_MS    42
#define PLAYBACK_12FPS_PERIOD_MS    80
#define PLAYBACK_8FPS_PERIOD_MS     125

#define FRAME_NUM_FADE_CONTROL      48
#define FRAME_NUM_FULL_SCREEN       24

#define VIDEO_LAYER_ID 0
#define CONTROL_LAYER_ID 1

typedef enum
{
    INITIALIZING,
    PROCESSING,
} STATE;

typedef enum
{
    PANEL_SHOWING,
    PANEL_VISIBLE,
    PANEL_HIDING,
    PANEL_HIDDEN,
} PANEL_STATE;

typedef enum
{
    SIZE,
    SOURCE,
    FORMAT,
    FPS,
    MAX_PANELS,
} PANEL_ID;

typedef enum
{
    ANIM_NONE = 0,
    ANIM_ACTIVE = 1,
} ANIM_STATUS;

typedef enum
{
    APP_STATE_INIT,
	APP_STATE_BUS_ENABLE,
    APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE,
    APP_STATE_USB_REMOVED,
    APP_STATE_USB_CONNECTED,
    APP_STATE_SD_REMOVED,
    APP_STATE_SD_CONNECTED,            
    APP_STATE_START_VIDEO,
    APP_STATE_OPEN_FILE,
    APP_STATE_PLAYBACK_START,            
    APP_STATE_READ_FRAME,
    APP_STATE_SET_FULL_SIZE,
    APP_STATE_SET_NORMAL_SIZE,
    APP_STATE_SCALE_FRAME,
    APP_STATE_PLAYBACK_END,            
    APP_STATE_STOP_VIDEO,
    APP_STATE_CLOSE_FILE,
    APP_STATE_REPLAY_VIDEO,
    APP_STATE_ERROR,
    APP_STATE_IDLE_ERROR,
    APP_STATE_IDLE,
} APP_STATES;

typedef enum
{
    RES_320x240 = 0,
    RES_400x240,
    RES_800x480,            
    RES_MAX,
    RES_NONE,
} APP_VID_RES;

typedef enum
{
    SRC_FLASH = 0,            
    SRC_USB,
    SRC_SD,
    SRC_MAX,
    SRC_NONE,            
} APP_VID_SOURCE;

typedef enum
{
    FMT_RGB565 = 0,
    FMT_RGBA8888,
    FMT_MAX,
    FMT_NONE,            
} APP_VID_FORMAT;

typedef enum
{
    FPS_8 = 0,
    FPS_12,
    FPS_24,
    FPS_MAX,
    FPS_NONE,
} APP_VID_FPS;

typedef enum
{
    EVT_PLAY,
    EVT_PAUSE,
    EVT_FULL_SCRN,
    EVT_SMALL_SCRN,
    EVT_RESIZE,
} APP_EVENT;

typedef enum
{
    SCR_EVT_NONE = 0,
    SCR_EVT_USB_IN,
    SCR_EVT_USB_OUT,
    SCR_EVT_SD_IN,
    SCR_EVT_SD_OUT,
    SCR_EVT_USB_SOURCE,
    SCR_EVT_SD_SOURCE,            
    SCR_EVT_FILE_ERROR,
    SCR_EVT_VIDEO_PLAYING,
    SCR_EVT_VIDEO_STOPPED,
    SCR_EVT_VIDEO_REPLAY,
    SCR_EVT_FADE_IN_CONTROL,
    SCR_EVT_FADE_OUT_CONTROL,
    SCR_EVT_SCREEN_TOUCH_DOWN,
} SCREEN_EVT;

typedef struct
{
 /* The application's current state */
  
    /* SYS_FS File handle for 1st file */
    SYS_FS_HANDLE fileHandle;

    /* Application's current state */
    APP_STATES state;

    uint32_t nBytesRead;
    
    char filename[256];
    uint32_t frameSizeBytes;
    uint32_t bytesPerPixel;
    uint32_t frameWidth;
    uint32_t frameHeight;
    int frameStartX;
    int frameStartY;
    uint32_t frameNum;
    
    uint8_t * frameBuff;

    bool usbIsConnected;
    bool sdIsConnected;
    
    struct 
    {
        APP_VID_RES res;
        APP_VID_FPS fps;
        APP_VID_FORMAT fmt;
        APP_VID_SOURCE src; 
        bool fs;
    } videoControl;
    
} APP_DATA;

typedef struct
{
    leWidget * widget;
    int startY, currY;    
    PANEL_STATE state;
} PANEL_OBJ;

typedef struct 
{
    STATE state;
    SCREEN_EVT evt;
    PANEL_STATE controlPanel;
    uint8_t controlLayerAlpha;
} SCREEN_OBJ;

extern APP_DATA appData;
extern PANEL_OBJ APP_Panel_Obj[MAX_PANELS];
extern SYS_TIME_HANDLE  animTimer;
extern volatile unsigned int animCounter;
extern unsigned int animCounterLast;
extern volatile unsigned int secCounter;
extern SCREEN_OBJ APP_Screen0_Obj;
extern int prevSecCounter;
extern int prevBytesRead;
extern int prevFramesRead;

void APP_Initialize ( void );

void APP_Tasks( void );

void APP_Screen_SetEvent(SCREEN_EVT evt);
void APP_Show_Panel(PANEL_ID panel);
void APP_Hide_Panel(PANEL_ID panel);
void APP_Exc_Show_Panel(PANEL_ID panel);
void APP_SetHWLayerAlpha(uint32_t layer, uint8_t alpha);
void APP_SetHWLayerColorModeRGB565(uint32_t layer);
void APP_Toggle_Panel(PANEL_ID panel);

void APP_Source_Enabled(APP_VID_SOURCE source, bool enable);
void APP_Set_FullScreen(bool enable);

void Process_Screen_Events(void);
int Process_Screen_Anim(PANEL_ID panel);
void Process_Throughput_Label(void);

void APP_StartStop_Playback(void);

void Screen0_ShowFileError(bool show);

bool APP_IsPlaying(void);

void Screen0_UpdateThroughput(int kbps, int fps);

#endif /* _APP_H */
/*******************************************************************************
 End of File
 */

