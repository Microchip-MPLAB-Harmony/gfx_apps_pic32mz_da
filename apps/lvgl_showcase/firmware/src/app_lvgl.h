/*******************************************************************************
 LVGL Port Header File

 Mohit M
 18-APR-2021
 *******************************************************************************/

#ifndef _APP_LVGL_H
#define _APP_LVGL_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"
#include "gfx/driver/processor/2dgpu/libnano2D.h"
#include "lvgl/lvgl.h"

/* LVGL Parameters */
#define LV_TICK_INC_VAL_MS  1
#define LV_TASK_INTERVAL_MS 15

/* Application state data type */
typedef enum {
    /* Application state machine's initial state */
    APP_LVGL_STATE_INIT = 0,

    /* State machine idle state */
    APP_LVGL_STATE_IDLE,

} APP_LVGL_STATES;

/* Application variable data type */
__ALIGNED(4)
typedef struct {
    /* The application's current state */
    APP_LVGL_STATES state;

    /* LVGL Variables */
    /* Display driver instance */
    lv_disp_drv_t lv_disp_drv;

    /* Display instance */
    lv_disp_t * lv_disp;

    /* Input driver instance */
    lv_indev_drv_t lv_indev_drv;

    /* Input instance */
    lv_indev_t * lv_indev;

    /* Display buffer parameters */
    lv_disp_buf_t lv_disp_buf;

    /* Input System Service */
    /* Input listener instance */
    SYS_INP_InputListener input_listener;

    /* Touch point x */
    uint32_t touch_x;

    /* Touch point y */
    uint32_t touch_y;

    /* Touch state */
    bool touch_pressed;

    /* Ticks */
    uint32_t ticks;

    /* nano2D GPU variables */
    /* N2D Destination Buffer */
    n2d_buffer_t n2d_dest;

    /* N2D Destination Rectangle */
    n2d_rectangle_t n2d_dest_rect;

    /* N2D Source Buffer */
    n2d_buffer_t n2d_src;

    /* N2D Source Rectangle */
    n2d_rectangle_t n2d_src_rect;

    /* N2D Orientation */
    n2d_orientation_t n2d_orient;

} APP_LVGL_DATA;

void APP_LVGL_BacklightEnable(void);
void APP_LVGL_BacklightDisable(void);
void APP_LVGL_Initialize(void);
void APP_LVGL_Tasks(void);

#endif /* _APP_LVGL_H */
