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
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************
#include <stdio.h>
#include "definitions.h"
#include "gfx/driver/processor/2dgpu/libnano2d.h"
#include <sys/kmem.h>
#include "app.h"
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
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData USB_ALIGN;

n2d_buffer_t blitDest = {0};
n2d_buffer_t fillDest = {0};
n2d_buffer_t blitSrc  = {0};
n2d_rectangle_t blitDestRect  = {0};
n2d_rectangle_t fillDestRect  = {0};
n2d_rectangle_t blitSrcRect = {0};

volatile unsigned int frameCount = 1;
unsigned int lastFrameCount = 0;
SYS_TIME_HANDLE  frameCountTimer;

static uint32_t fbIndex = 0;

static uint32_t fb[2] = {FB_BUFF, FB_BUFF2};

static char fullFileName[1024] = {0};

#ifdef USE_SRAM_VIDEO_BUFF
static char __attribute__ ((aligned(32))) videoBuff[DEFAULT_SOURCE_WIDTH_PX *
                                                    DEFAULT_SOURCE_HEIGHT_PX *
                                                    DEFAULT_SOURCE_BPP];
#endif

static char * fileNameRes[RES_MAX] = {"320x240", "400x240", "800x480"};
static char * fileNameFmt[FMT_MAX] = {"rgb565", "rgba8888"};
static char * fileNameFPS[FPS_MAX] = {"8fps", "12fps", "24fps"};
static char * sourcePath[SRC_MAX] = {"myDrive0", "myDrive1", "myDrive2"};
unsigned int fpsPeriod[FPS_MAX] = {PLAYBACK_8FPS_PERIOD_MS,
                                   PLAYBACK_12FPS_PERIOD_MS,
                                   PLAYBACK_24FPS_PERIOD_MS};

unsigned int bppFmt[FMT_MAX] = {2, 4};

SYS_INP_InputListener appInputListener;

extern n2d_error_t n2d_blit(
                    n2d_buffer_t *destination,
                    n2d_rectangle_t *destination_rectangle,
                    n2d_buffer_t *source,
                    n2d_rectangle_t *source_rectangle,
                    n2d_blend_t blend);
extern n2d_error_t n2d_fill(
                    n2d_buffer_t *destination,
                    n2d_rectangle_t *rectangle,
                    n2d_color_t color,
                    n2d_blend_t blend);

static void Playback_TimerCallback ( uintptr_t context )
{
    frameCount++;
}

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    appData.usbIsConnected = false;
    
    appData.frameBuff = (uint8_t *) (KVA0_TO_KVA1(DEFAULT_DEST_BUFF));
    appData.fileHandle = SYS_FS_HANDLE_INVALID;    
    appData.frameNum = 0;

    appData.videoControl.res = RES_NONE;
    appData.videoControl.fps = FPS_NONE;
    appData.videoControl.fmt = FMT_NONE;
    appData.videoControl.src = SRC_NONE;
    appData.videoControl.fs = true;

    appData.frameStartX = 0;
    appData.frameStartY = 0;
    
    //Set default to RGB565 WVGA 24fps
    sprintf(appData.filename, "%s", DEFAULT_SOURCE_FILENAME);
    appData.frameSizeBytes = DEFAULT_SOURCE_HEIGHT_PX *
                             DEFAULT_SOURCE_WIDTH_PX *
                             DEFAULT_SOURCE_BPP;
    appData.bytesPerPixel = DEFAULT_SOURCE_BPP;
    appData.frameWidth = DEFAULT_SOURCE_WIDTH_PX;
    appData.frameHeight = DEFAULT_SOURCE_HEIGHT_PX;
    appData.frameStartX = DEFAULT_DEST_XPOS;
    appData.frameStartY = DEFAULT_DEST_YPOS;
    
    appData.nBytesRead = 0;
}

USB_HOST_EVENT_RESPONSE APP_USBHostEventHandler (USB_HOST_EVENT event, void * eventData, uintptr_t context)
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

void APP_SYSFSEventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
{
    switch(event)
    {
        case SYS_FS_EVENT_MOUNT:
        {
            if (strcmp((const char *)eventData, USBMSD_MOUNT_NAME) == 0)
            {
                appData.usbIsConnected = true;

                APP_Screen_SetEvent(SCR_EVT_USB_IN);
            }
            else if (strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                appData.sdIsConnected = true;

                APP_Screen_SetEvent(SCR_EVT_SD_IN);
            }
            break;
        }   
        case SYS_FS_EVENT_UNMOUNT:
        {
            if (strcmp((const char *)eventData, USBMSD_MOUNT_NAME) == 0)
            {
                appData.usbIsConnected = false;

                APP_Screen_SetEvent(SCR_EVT_USB_OUT);
            }
            else if (strcmp((const char *)eventData, SDCARD_MOUNT_NAME) == 0)
            {
                appData.sdIsConnected = false;

                APP_Screen_SetEvent(SCR_EVT_SD_OUT);
            }         
            break;
        }   
        default:
            break;
    }
}

void APP_StartStop_Playback(void)
{
    if (appData.state == APP_STATE_IDLE)
    {
        appData.state = APP_STATE_START_VIDEO;
    }
    else if (appData.state != APP_STATE_IDLE)
    {
        appData.state = APP_STATE_STOP_VIDEO;
    }
}

void APP_Set_FullScreen(bool enable)
{
    if (appData.state == APP_STATE_READ_FRAME ||
        appData.state == APP_STATE_SCALE_FRAME ||
        appData.state == APP_STATE_SET_NORMAL_SIZE ||
        appData.state == APP_STATE_SET_FULL_SIZE)
    {
        if (enable)
        {
            appData.state = APP_STATE_SET_FULL_SIZE;
        }
        else
        {
            appData.state = APP_STATE_SET_NORMAL_SIZE;
        }
    }
    
    appData.videoControl.fs = enable;

}

bool APP_IsPlaying(void)
{
    if (appData.state > APP_STATE_PLAYBACK_START &&
        appData.state < APP_STATE_PLAYBACK_END)
    {
        return true;
    }
    
    return false;
}

static void APP_Clear_FrameBuffers(void)
{
        //Clear the frame buffers
    fillDest.gpu = KVA_TO_PA(FB_BUFF);
    fillDest.memory = (void*)(FB_BUFF);

    n2d_fill(&fillDest,
             &fillDestRect,
             DEFAULT_FILL,
             N2D_BLEND_NONE);

    fillDest.gpu = KVA_TO_PA(FB_BUFF2);
    fillDest.memory = (void*)(FB_BUFF2);

    n2d_fill(&fillDest,
             &fillDestRect,
             DEFAULT_FILL,
             N2D_BLEND_NONE);
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    switch(appData.state)
    {
        case APP_STATE_INIT:
        {
            APP_Clear_FrameBuffers();
            
            if (leIsDrawing() == LE_FALSE)
                appData.state = APP_STATE_BUS_ENABLE;
            break;
        }
        case APP_STATE_BUS_ENABLE:
        {
           /* Set the event handler and enable the bus */
            SYS_FS_EventHandlerSet((void *)APP_SYSFSEventHandler, (uintptr_t)NULL);
            USB_HOST_EventHandlerSet(APP_USBHostEventHandler, 0);
            USB_HOST_BusEnable(0);
            appData.state = APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE;
            
            break;
        }    
        case APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE:
        {
            appData.state = APP_STATE_IDLE;
            
            if(USB_HOST_BusIsEnabled(0) < 0)
            {
                appData.state = APP_STATE_ERROR;
            }
            break;
        }
        case APP_STATE_USB_CONNECTED:
        {
            appData.usbIsConnected = true;
            
            APP_Screen_SetEvent(SCR_EVT_USB_IN);
            
            appData.state = APP_STATE_IDLE;
            break;
        }
        case APP_STATE_USB_REMOVED:
        {
            appData.usbIsConnected = false;
            
            APP_Screen_SetEvent(SCR_EVT_USB_OUT);
            
            appData.state = APP_STATE_IDLE;
            break;
        }
        case APP_STATE_START_VIDEO:
        {
            //Error Check
            if ((appData.videoControl.fps >= FPS_MAX ||
                appData.videoControl.fmt >= FMT_MAX ||
                appData.videoControl.res >= RES_MAX ||
                appData.videoControl.src >= SRC_MAX) ||
                (appData.sdIsConnected == false && 
                 appData.usbIsConnected == false))
            {
                appData.state = APP_STATE_IDLE;
                break;
            }
            
            //COnfigure app settings here
            switch(appData.videoControl.res)
            {
                case RES_800x480:
                {
                    appData.frameWidth = 800;
                    appData.frameHeight = 480;
                    break;
                }
                case RES_400x240:
                {
                    appData.frameWidth = 400;
                    appData.frameHeight = 240;
                    break;
                }
                case RES_320x240:
                {
                    appData.frameWidth = 320;
                    appData.frameHeight = 240;
                    break;
                }
                default:
                    break;
            }
            
            appData.frameStartX = (DISPLAY_WIDTH_PX - appData.frameWidth) / 2;
            appData.frameStartY = (DISPLAY_HEIGHT_PX - appData.frameHeight) / 2;

            appData.frameSizeBytes = appData.frameWidth *
                                     appData.frameHeight *
                                     bppFmt[appData.videoControl.fmt];
            
            //Build the filename
            sprintf(appData.filename, "%s_%s_%s.rgb",
                    fileNameFmt[appData.videoControl.fmt],
                    fileNameRes[appData.videoControl.res],
                    fileNameFPS[appData.videoControl.fps]);
            
            //TODO: Add settings
            SYS_TIME_TimerDestroy(frameCountTimer);
            frameCountTimer = SYS_TIME_CallbackRegisterMS(Playback_TimerCallback, 
                                    (uintptr_t) NULL,
                                    fpsPeriod[appData.videoControl.fps],
                                    SYS_TIME_PERIODIC);
            
            //Configure blit source rect
            blitSrcRect.width = appData.frameWidth;
            blitSrcRect.height = appData.frameHeight;
            
            blitSrc.format = DEFAULT_N2D_SOURCE_FMT;
            blitSrc.gpu = KVA_TO_PA(DEFAULT_DEST_BUFF);
            blitSrc.memory = (void*)(KVA0_TO_KVA1(DEFAULT_DEST_BUFF));
            blitSrc.width = blitSrcRect.width;
            blitSrc.height = blitSrcRect.height;
            blitSrc.orientation = N2D_0;
            blitSrc.stride = appData.frameWidth * appData.bytesPerPixel;

            //Configure blit dest rect
            blitDestRect.width = appData.frameWidth;
            blitDestRect.height = appData.frameHeight;
            blitDestRect.x = appData.frameStartX;
            blitDestRect.y = appData.frameStartY;
            
            blitDest.format = DEFAULT_N2D_DEST_FMT;
            blitDest.gpu = KVA_TO_PA(FB_BUFF);
            blitDest.memory = (void*)(FB_BUFF);
            blitDest.width = DISPLAY_WIDTH_PX;
            blitDest.height = DISPLAY_HEIGHT_PX;
            blitDest.orientation = N2D_0;
            blitDest.stride = DISPLAY_WIDTH_PX * DEFAULT_DEST_BPP;
            
            fillDest.format  = DEFAULT_N2D_DEST_FMT;
            fillDest.gpu = KVA_TO_PA(FB_BUFF);
            fillDest.memory = (void*)(FB_BUFF);
            fillDest.width = DISPLAY_WIDTH_PX;
            fillDest.height = DISPLAY_HEIGHT_PX;
            fillDest.orientation = N2D_0;
            fillDest.stride = DISPLAY_WIDTH_PX * DEFAULT_DEST_BPP; 
            
            fillDestRect.height = DISPLAY_HEIGHT_PX;
            fillDestRect.width = DISPLAY_WIDTH_PX;
            
            appData.nBytesRead = 0;
            appData.frameNum = 0;
            
            appData.state = APP_STATE_OPEN_FILE;
            
            break;
        }
        case APP_STATE_IDLE:
        {
            break;
        }          
        case APP_STATE_OPEN_FILE:
        {
            /* Try opening the file for append */
            sprintf(fullFileName, "/mnt/%s/%s", sourcePath[appData.videoControl.src], appData.filename);
            appData.fileHandle = SYS_FS_FileOpen(fullFileName, (SYS_FS_FILE_OPEN_READ));
            if(appData.fileHandle == SYS_FS_HANDLE_INVALID)
            {
                /* Could not open the file. Error out*/
                APP_Screen_SetEvent(SCR_EVT_FILE_ERROR);
                appData.state = APP_STATE_IDLE;

            }
            else
            {
                /* File opened successfully. Start Reading Frames*/
                APP_Screen_SetEvent(SCR_EVT_VIDEO_PLAYING);
                appData.state = APP_STATE_READ_FRAME;

            }
            break;
        }
        case APP_STATE_READ_FRAME:
        {
            int retval;
            
            if (frameCount != lastFrameCount)
            {
                retval = SYS_FS_FileSeek(appData.fileHandle, (appData.frameSizeBytes * appData.frameNum), SYS_FS_SEEK_SET);
                if (retval < 0)
                {
                    appData.state = APP_STATE_ERROR;
                }

                retval = SYS_FS_FileRead(appData.fileHandle, 
                                         appData.frameBuff, 
                                         appData.frameSizeBytes);
                if (retval <= 0)
                {
#ifdef ENABLE_AUTOREPLAY
                    appData.state = APP_STATE_REPLAY_VIDEO;
#else                    
                    appData.state = APP_STATE_STOP_VIDEO;
#endif
                    break;
                }
                else
                {
                    appData.frameNum++;
                    appData.nBytesRead += retval;

                    if (appData.frameNum == FRAME_NUM_FULL_SCREEN && 
                        appData.videoControl.fs == true)
                    {
                        appData.state = APP_STATE_SET_FULL_SIZE;
                    }   
                    else    
                    {
                        if (appData.frameNum == FRAME_NUM_FADE_CONTROL)
                        {
                            APP_Screen_SetEvent(SCR_EVT_FADE_OUT_CONTROL);
                        }
                        
                        appData.state = APP_STATE_SCALE_FRAME;
                    }                    
                    

                }
#ifndef MAX_FPS                
                lastFrameCount = frameCount;
#endif
            }
                
            break;
        }
        case APP_STATE_SCALE_FRAME:
        {
            n2d_error_t retval;
            
            blitDest.gpu = KVA_TO_PA(fb[fbIndex]);
            blitDest.memory = (void*)(fb[fbIndex]);
            
            retval = n2d_blit(&blitDest,
                     &blitDestRect,
                     &blitSrc,
                     &blitSrcRect,
                     N2D_BLEND_NONE);
            
            //SWAP
            PLIB_GLCD_LayerBaseAddressSet(VIDEO_LAYER_ID,
                                 (uint32_t)fb[fbIndex]);
            
            fbIndex = (fbIndex == 0) ? 1 : 0;
 
            if (retval == N2D_SUCCESS)
            {
                 appData.state = APP_STATE_READ_FRAME;
            }
            else
            {
                appData.state = APP_STATE_ERROR;
            }
            
            break;
        }
        case APP_STATE_SET_NORMAL_SIZE:
        {
            n2d_error_t retval;
            
            if (frameCount == lastFrameCount)
                break;
#ifndef MAX_FPS
            lastFrameCount = frameCount;
#endif
            
            //Clear frame
            fillDest.gpu = KVA_TO_PA(fb[fbIndex]);
            fillDest.memory = (void*)(fb[fbIndex]);
            
            n2d_fill(&fillDest,
                     &fillDestRect,
                     0xff000000,
                     N2D_BLEND_NONE);
            
            if (((blitDestRect.width - appData.frameWidth)/ SCALE_INC_DIV) > 0)
                    blitDestRect.width -= 
                        ((blitDestRect.width - appData.frameWidth)/ SCALE_INC_DIV);
            else
                blitDestRect.width = appData.frameWidth;
            
            if (((blitDestRect.height - appData.frameHeight)/ SCALE_INC_DIV) > 0)
                    blitDestRect.height -= 
                        ((blitDestRect.height - appData.frameHeight)/ SCALE_INC_DIV);
            else
                blitDestRect.height = appData.frameHeight;      
            
            //Blit frame
            blitDest.gpu = KVA_TO_PA(fb[fbIndex]);
            blitDest.memory = (void*)(fb[fbIndex]);            

            blitDestRect.x = (DISPLAY_WIDTH_PX - blitDestRect.width) / 2;
            blitDestRect.y = (DISPLAY_HEIGHT_PX - blitDestRect.height) / 2;
            
            retval = n2d_blit(&blitDest,
                     &blitDestRect,
                     &blitSrc,
                     &blitSrcRect,
                     N2D_BLEND_NONE);
            
            //SWAP
            PLIB_GLCD_LayerBaseAddressSet(VIDEO_LAYER_ID,
                                 (uint32_t)fb[fbIndex]);
            
            fbIndex = (fbIndex == 0) ? 1 : 0;
            
            if (blitDestRect.width == appData.frameWidth &&
                blitDestRect.height == appData.frameHeight)
            {
                //final Clear
                fillDest.gpu = KVA_TO_PA(fb[fbIndex]);
                fillDest.memory = (void*)(fb[fbIndex]);
            
                n2d_fill(&fillDest,
                     &fillDestRect,
                     0xff000000,
                     N2D_BLEND_NONE);
            
                appData.state = APP_STATE_READ_FRAME;
            }
            
            if (retval != N2D_SUCCESS)
            {
                appData.state = APP_STATE_ERROR;
            }

            break;
        }
        case APP_STATE_SET_FULL_SIZE:
        {
            n2d_error_t retval;
            
            if (frameCount == lastFrameCount)
                break;
#ifndef MAX_FPS            
            lastFrameCount = frameCount;
#endif
            
            if (((DISPLAY_WIDTH_PX - blitDestRect.width) / SCALE_INC_DIV )> 0)
                blitDestRect.width += 
                        (DISPLAY_WIDTH_PX - blitDestRect.width) / SCALE_INC_DIV;
            else
                blitDestRect.width = DISPLAY_WIDTH_PX;
            
            if (((DISPLAY_HEIGHT_PX - blitDestRect.height) / SCALE_INC_DIV )> 0)
                blitDestRect.height += 
                        (DISPLAY_HEIGHT_PX - blitDestRect.height) / SCALE_INC_DIV;
            else
                blitDestRect.height = DISPLAY_HEIGHT_PX;
            

            blitDestRect.x = (DISPLAY_WIDTH_PX - blitDestRect.width) / 2;
            blitDestRect.y = (DISPLAY_HEIGHT_PX - blitDestRect.height) / 2;
            
            //Blit frame
            blitDest.gpu = KVA_TO_PA(fb[fbIndex]);
            blitDest.memory = (void*)(fb[fbIndex]);
            
            retval = n2d_blit(&blitDest,
                     &blitDestRect,
                     &blitSrc,
                     &blitSrcRect,
                     N2D_BLEND_NONE);
            
            //SWAP
            PLIB_GLCD_LayerBaseAddressSet(VIDEO_LAYER_ID,
                                 (uint32_t)fb[fbIndex]);
            
            fbIndex = (fbIndex == 0) ? 1 : 0;
            
            if (blitDestRect.width == DISPLAY_WIDTH_PX &&
                blitDestRect.height == DISPLAY_HEIGHT_PX)
            {
                appData.state = APP_STATE_READ_FRAME;
            }
            
            if (retval != N2D_SUCCESS)
            {
                appData.state = APP_STATE_ERROR;
            }            
            
            break;
        }
        case APP_STATE_REPLAY_VIDEO:
        {
            appData.frameNum = 0;
            appData.nBytesRead = 0;
            APP_Screen_SetEvent(SCR_EVT_VIDEO_REPLAY);
            appData.state = APP_STATE_READ_FRAME;
            
            break;
        }        
        case APP_STATE_STOP_VIDEO:
        {
            
            appData.frameNum = 0;
            appData.nBytesRead = 0;
            
            APP_Clear_FrameBuffers();
            
            APP_Screen_SetEvent(SCR_EVT_FADE_IN_CONTROL);
            
            APP_Screen_SetEvent(SCR_EVT_VIDEO_STOPPED);
            
            appData.state = APP_STATE_CLOSE_FILE;
                    
            break;
        }
        case APP_STATE_CLOSE_FILE:
        {
            /* Close the file */
            SYS_FS_FileClose(appData.fileHandle);
            
            appData.fileHandle = SYS_FS_HANDLE_INVALID;
            
            /* The test was successful. Lets idle. */

            appData.state = APP_STATE_IDLE;

            break;
        }
        case APP_STATE_ERROR:
        {
            if (appData.usbIsConnected)
                SYS_FS_Unmount("/mnt/myDrive1");
            
            if (appData.sdIsConnected)
                SYS_FS_Unmount("/mnt/myDrive2");
            
            appData.state =  APP_STATE_IDLE_ERROR;
            
            break;
        }
        case APP_STATE_IDLE_ERROR:
        {
            break;
        }
        default:
            break;

    }
}

/*******************************************************************************
 End of File
 */
