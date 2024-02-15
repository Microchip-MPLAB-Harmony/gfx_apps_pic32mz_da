/*******************************************************************************
 LVGL Port Source File

 Mohit M
 18-APR-2021
 *******************************************************************************/

#include "app_lvgl.h"
#include "common.h"
#include <sys/kmem.h>
#include "lv_fs_if/lv_fs_if.h"
#include "lv_examples/lv_examples.h"
#include "gfx/driver/processor/2dgpu/libnano2d.h"
#include "gfx/driver/gfx_driver.h"

/* Application data */
APP_LVGL_DATA app_lvgl;

/* Source SRAM Buffer */
__ALIGNED(4) __COHERENT uint16_t src[LV_HOR_RES_MAX*LV_VER_RES_MAX];

/* Static Functions */
static void touchDownHandler(const SYS_INP_TouchStateEvent * const evt) {
        app_lvgl.touch_pressed = true;
        app_lvgl.touch_x = evt->x;
        app_lvgl.touch_y = evt->y;
}

static void touchUpHandler(const SYS_INP_TouchStateEvent * const evt) {
        app_lvgl.touch_pressed = false;
        app_lvgl.touch_x = evt->x;
        app_lvgl.touch_y = evt->y;
}

static void touchMoveHandler(const SYS_INP_TouchMoveEvent * const evt) {
        app_lvgl.touch_x = evt->x;
        app_lvgl.touch_y = evt->y;
}

static void lv_tick_inc_cb(uintptr_t dummy) {
    app_lvgl.ticks += LV_TICK_INC_VAL_MS;
    lv_tick_inc(LV_TICK_INC_VAL_MS);
}

static void lv_disp_drv_flush_cb(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p) {
    n2d_blit(&app_lvgl.n2d_dest, NULL,
            &app_lvgl.n2d_src, NULL,
            N2D_BLEND_NONE);
    lv_disp_flush_ready(disp_drv);
}

static bool lv_indev_drv_read_cb(lv_indev_drv_t * indev_drv, lv_indev_data_t* indev_data) {
    if (app_lvgl.touch_pressed) {
        indev_data->point.x = app_lvgl.touch_x;
        indev_data->point.y = app_lvgl.touch_y;
        indev_data->state = LV_INDEV_STATE_PR;
    } else {
        indev_data->point.x = app_lvgl.touch_x;
        indev_data->point.y = app_lvgl.touch_y;
        indev_data->state = LV_INDEV_STATE_REL;
    }
    return false;
}

/* App Functions */
void APP_LVGL_BacklightEnable(void) {
    TM4301B_BACKLIGHT_Set();
}

void APP_LVGL_BacklightDisable(void) {
    TM4301B_BACKLIGHT_Clear();
}

void APP_LVGL_Initialize(void) {
	gfxPixelBuffer* frameBuff;
	gfxIOCTLArg_Value ioctlArg;
  
    /* Place the state machine in its initial state */
    app_lvgl.state = APP_LVGL_STATE_INIT;

    /* Initialize GFX Module */
//    if (GFX_Open(0, 0, 0, NULL) == NULL)
//        __builtin_software_breakpoint();
//
//    /* GFX Configuration */
//    GFX_Set(GFXF_LAYER_ACTIVE, 0);
    ioctlArg.value.v_uint = 0; //set active layer to the first layer

	if (gfxDriverInterface.ioctl(GFX_IOCTL_SET_ACTIVE_LAYER, &ioctlArg) != GFX_IOCTL_OK ||
		gfxDriverInterface.ioctl(GFX_IOCTL_GET_FRAMEBUFFER, &ioctlArg) != GFX_IOCTL_OK)
	{
		return;
	}
      
	frameBuff = ioctlArg.value.v_pbuffer;
//    GFX_Set(GFXF_LAYER_BUFFER_COUNT, 1);
//    GFX_Set(GFXF_LAYER_POSITION, 0, 0);
//    GFX_Set(GFXF_COLOR_MODE, GFX_COLOR_MODE_RGB_565);
//    GFX_Set(GFXF_LAYER_ALPHA_AMOUNT, 255);
//    GFX_Set(GFXF_LAYER_VISIBLE, GFX_TRUE);
//    GFX_Set(GFXF_LAYER_ENABLED, GFX_TRUE);

    /* nano2D GPU Configuration */
    /* N2D Orientation */
    app_lvgl.n2d_orient = N2D_0;

    /* N2D Destination Rectangle */
    app_lvgl.n2d_dest_rect.x = 0;
    app_lvgl.n2d_dest_rect.y = 0;
    app_lvgl.n2d_dest_rect.width = LV_HOR_RES_MAX;
    app_lvgl.n2d_dest_rect.height = LV_VER_RES_MAX;

    /* N2D Source Rectangle */
    app_lvgl.n2d_src_rect.x = 0;
    app_lvgl.n2d_src_rect.y = 0;
    app_lvgl.n2d_src_rect.width = LV_HOR_RES_MAX;
    app_lvgl.n2d_src_rect.height = LV_VER_RES_MAX;

    /* N2D Destination Buffer */
    //GFX_Get(GFXF_LAYER_BUFFER_ADDRESS, 0, &app_lvgl.n2d_dest.memory);
    app_lvgl.n2d_dest.memory = gfxPixelBufferOffsetGet(frameBuff, 0, 0);
       
    app_lvgl.n2d_dest.gpu = KVA_TO_PA(app_lvgl.n2d_dest.memory);
    app_lvgl.n2d_dest.format = N2D_RGB565;
    app_lvgl.n2d_dest.width = LV_HOR_RES_MAX;
    app_lvgl.n2d_dest.height = LV_VER_RES_MAX;
    app_lvgl.n2d_dest.orientation = app_lvgl.n2d_orient;
    app_lvgl.n2d_dest.stride = app_lvgl.n2d_dest.width * 16 / 8;

    /* N2D Source Buffer */
    app_lvgl.n2d_src.memory = (void*) src;
    app_lvgl.n2d_src.gpu = KVA_TO_PA(src);
    app_lvgl.n2d_src.format = N2D_RGB565;
    app_lvgl.n2d_src.width = LV_HOR_RES_MAX;
    app_lvgl.n2d_src.height = LV_VER_RES_MAX;
    app_lvgl.n2d_src.orientation = app_lvgl.n2d_orient;
    app_lvgl.n2d_src.stride = app_lvgl.n2d_src.width * 16 / 8;

    /* Initialize Input System Service */
    app_lvgl.input_listener.handleTouchDown = &touchDownHandler;
    app_lvgl.input_listener.handleTouchUp = &touchUpHandler;
    app_lvgl.input_listener.handleTouchMove = &touchMoveHandler;
    SYS_INP_AddListener(&app_lvgl.input_listener);
    app_lvgl.touch_pressed = false;

    /* Initialize LVGL */
    lv_init();

    /* Register Display in LVGL */
    lv_disp_buf_init(&app_lvgl.lv_disp_buf,
            src,
            src,
            LV_HOR_RES_MAX * LV_VER_RES_MAX);
    lv_disp_drv_init(&app_lvgl.lv_disp_drv);
    app_lvgl.lv_disp_drv.buffer = &app_lvgl.lv_disp_buf;
    app_lvgl.lv_disp_drv.flush_cb = lv_disp_drv_flush_cb;
    app_lvgl.lv_disp = lv_disp_drv_register(&app_lvgl.lv_disp_drv);

    /* Register Input in LVGL */
    lv_indev_drv_init(&app_lvgl.lv_indev_drv);
    app_lvgl.lv_indev_drv.type = LV_INDEV_TYPE_POINTER;
    app_lvgl.lv_indev_drv.read_cb = lv_indev_drv_read_cb;
    app_lvgl.lv_indev = lv_indev_drv_register(&app_lvgl.lv_indev_drv);

    /* Periodic tick for LVGL */
    SYS_TIME_CallbackRegisterMS(lv_tick_inc_cb, 0, (uint32_t)LV_TICK_INC_VAL_MS,
            SYS_TIME_PERIODIC);
}

void APP_LVGL_Tasks(void) {
    static uint32_t temp_ticks;
    /* Check the application's current state */
    switch (app_lvgl.state) {
            /* Application's initial state */
        case APP_LVGL_STATE_INIT:
#if LV_USE_FILESYSTEM == 1
            if (COMMON_APP_FS_CheckMount()) {
                /* Initialize LVGL File System Interface for FatFS */
                lv_fs_if_init();
#endif
                /* Clear terminal */
                printf("\x1b[2J\x1b[H");
                /* Print version info */
                printf("LVGL v%d.%d.%d\r\n",
                        lv_version_major(),
                        lv_version_minor(),
                        lv_version_patch());
                printf("LVGL Initialized\r\n");
                /* Reset ticks */
                temp_ticks = 0;
                /* Fill Screen Black */
                /* Fill LCD Black */
                n2d_fill(&app_lvgl.n2d_dest, N2D_NULL, 0x0000, N2D_BLEND_NONE);
                /* Demo Music Player */
                lv_demo_music();
                /* All done, turn on backlight and Idle */
                APP_LVGL_BacklightEnable();
                app_lvgl.state = APP_LVGL_STATE_IDLE;
#if LV_USE_FILESYSTEM == 1
            }
#endif
            break;

            /* State machine idle state */
        case APP_LVGL_STATE_IDLE:
            if (app_lvgl.ticks - temp_ticks >= LV_TASK_INTERVAL_MS) {
                lv_task_handler();
                temp_ticks = app_lvgl.ticks;
            }
            break;

            /* The default state should never be executed */
        default:
            break;
    }
}
