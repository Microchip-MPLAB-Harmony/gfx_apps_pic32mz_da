// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "definitions.h"
#include "app_screen.h"

static uint32_t lastX, lastY;
uint32_t touchAngle, touchRad = 0;
static uint32_t lastTouchAngle;
static bool wheelActive = false;
static bool reverseKnob = false;

void app_getAngleFromPoint(uint32_t x, uint32_t y, uint32_t * angle, uint32_t * radius)
{
    lePoint centerPt, pt;
    float rad, mag, dot, det;
    int32_t deg;
    float xf, yf;

    // transform the vector
    centerPt.x = 432/2;
    centerPt.y = 432/2;
    
    pt.x = x;
    pt.y = y;

    pt.x -= centerPt.x;
    pt.y -= centerPt.y;
    pt.y *= -1;

    // normalize the vector
    mag = leSqrt((pt.x * pt.x) + (pt.y * pt.y));

    xf = (float)pt.x / mag;
    yf = (float)pt.y / mag;

    // calculate the angle
    dot = (xf * 1.0f) + (yf * 0.0f);
    det = (xf * 0.0f) - (yf * 1.0f);

    rad = -atan2f(det, dot);

    deg = (int32_t)(rad * 57.295827909f);

    // normalize the angle
    if(deg < 0)
    {
        deg += 360;
    }
    
    deg %= 360;
    
    *angle = deg;
    *radius = mag;
}

uint32_t app_angleToTick(int32_t deg)
{
    uint32_t tick;
    
    deg %= 360;
    
    if (deg < 0)
    {
        deg += 360;
    }
    
    //hack to support 100%
    if (deg > 88 && deg < 92)
        return NUM_TICK_LINES;
    
    //convert to clockwise relative to 90
    deg = 90 - deg;
    
    if (deg < 0)
    {
        deg += 360;
    }
    
    deg %= 360;
    
    tick = (NUM_TICK_LINES * deg) / 360;
    
    return tick;
}
uint32_t app_normalizeAngle(int32_t angle)
{
    angle %= 360;
    
    if (angle < 0)
        angle += 360;
    
    return angle;
}

uint32_t app_tickToAngle(uint32_t tick)
{
    uint32_t angle = 0;
    
    if (tick > NUM_TICK_LINES)
        angle = 90;
    
    //get relative angle
    angle = (tick * 360) / NUM_TICK_LINES;
    
    //get absolute angle from 0-deg + axis
    angle = (360 - angle + 90) % 360;
    
    if (angle < 0)
    {
        angle += 360;
    }    
    
    return angle;
}

uint32_t app_angleToPercent(int32_t deg)
{
    if (deg/360 > 0)
        return 100;
        
    deg %= 360;
    
    if (deg < 0)
    {
        deg += 360;
    }
    
    //hack to support 100%
    if (deg > 88 && deg < 92)
        return 100;

    //convert to clockwise relative to 90    
    deg = 90 - deg;
    
    if (deg < 0)
    {
        deg += 360;
    }
    
    deg %= 360;
    
    return ((deg * 100) / 360);
}

uint32_t app_percentToTick(uint32_t pct)
{
    uint32_t tick = ((NUM_TICK_LINES * pct) / 100);
    
    return tick;
}

void app_touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    app_getAngleFromPoint(evt->x, evt->y, &touchAngle, &touchRad);

    lastX = evt->x;
    lastY = evt->y;
    
    if (touchRad > WHEEL_TOUCH_MIN_RADIUS_PX)
    {
        Screen0_SetEventsArgs(SCR_EVT_WHEEL_ACTIVE, touchAngle);
        lastTouchAngle = touchAngle;
        wheelActive = true;
    }
}

void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
    app_getAngleFromPoint(evt->x, evt->y, &touchAngle, &touchRad);

    lastX = evt->x;
    lastY = evt->y;
    
    if (wheelActive == true)
    {
        Screen0_SetEvent(SCR_EVT_WHEEL_RELEASED);
        wheelActive = false;
    }
}

void app_touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    if (evt->x != lastX || evt->y != lastY)
    {
        app_getAngleFromPoint(evt->x, evt->y, &touchAngle, &touchRad);
        
        if (touchAngle != lastTouchAngle &&
            touchRad > WHEEL_TOUCH_MIN_RADIUS_PX)
        {
            //Rough check for CW wrap-around wheel
            if ((touchAngle > lastTouchAngle) && 
                (evt->y > CENTER_POS_XY) && 
                (evt->y > lastY))
            {
                Screen0_SetEventsArgs(SCR_EVT_WHEEL_CCW, touchAngle);
            }
            //Rough check for CCW wrap-around wheel
            else if ((touchAngle < lastTouchAngle) && 
                (evt->y < CENTER_POS_XY) && 
                (evt->y < lastY))
            {
                Screen0_SetEventsArgs(SCR_EVT_WHEEL_CW, touchAngle);
            }
            else if (touchAngle > lastTouchAngle)
            {
                Screen0_SetEventsArgs(SCR_EVT_WHEEL_CCW, touchAngle);
            }
            else
            {
                Screen0_SetEventsArgs(SCR_EVT_WHEEL_CW, touchAngle);
            }
            
            lastTouchAngle = touchAngle;
        }
        
        lastX = evt->x;
        lastY = evt->y;        
    }
}

void app_genericGestureHandler(const SYS_INP_GenericGestureEvent* const evt)
{
    switch (evt->gest)
    {
        case MG_CHECK:
        {
            Screen0_SetEvent(SCR_EVT_MG_CHECK);
            break;
        }
        case MG_STAR:
        {
            Screen0_SetEvent(SCR_EVT_MG_STAR);
            break;
        }
        case MG_ALPHA:
        {
            Screen0_SetEvent(SCR_EVT_MG_ALPHA);
            break;
        }
        case MG_M:
        {
            Screen0_SetEvent(SCR_EVT_MG_M);
            break;
        }            
        case MG_S:
        {
            Screen0_SetEvent(SCR_EVT_MG_S);
            break;
        }            
        case MG_2:
        {
            Screen0_SetEvent(SCR_EVT_MG_2);
            break;
        }            
        default:
        {
            break;
        }
    }
}

uint32_t app_getTouchAngle(void)
{
    return touchAngle;
}

uint32_t app_getTouchRad(void)
{
    return touchRad;
}

void app_RotaryInputHandler ( GPIO_PIN pin, uintptr_t context)
{
    static uint8_t seqA, seqB;
    
    switch (pin)
    {
        case GPIO_RC3_SW_CCW_PIN:
        case GPIO_RC2_SW_CW_PIN:
        {
            seqA = (seqA << 1) | (GPIO_RC2_SW_CW_Get() & 0x1);
            seqB = (seqB << 1) | (GPIO_RC3_SW_CCW_Get() & 0x1);
            
            seqA &= 0x0F;
            seqB &= 0x0F;
            
            if (seqA == 0x09 && seqB == 0x03)
            {
                Screen0_SetEvent((reverseKnob == true) ? 
                                 SCR_EVT_ROT_CCW: SCR_EVT_ROT_CW);
            }
            else if (seqA == 0x03 && seqB == 0x09)
            {
                Screen0_SetEvent((reverseKnob == true) ?
                                 SCR_EVT_ROT_CW : SCR_EVT_ROT_CCW);
            }            
            
            break;
        }
        case GPIO_RK2_PUSH_SW_PIN:
        {
            if (GPIO_RK2_PUSH_SW_Get() == 0)
            {
                Screen0_SetEvent(SCR_EVT_ROT_DOWN);
            }
            else
            {
                Screen0_SetEvent(SCR_EVT_ROT_UP);
            }
            break;
        }
        default:
            break;
    }
}

void app_EnableRotaryInput(void)
{
    GPIO_RK2_PUSH_SW_InterruptEnable();
    GPIO_RC3_SW_CCW_InterruptEnable();
    GPIO_RC2_SW_CW_InterruptEnable();
    
    GPIO_PinInterruptEnable(GPIO_RC3_SW_CCW_PIN);
    GPIO_PinInterruptEnable(GPIO_RC2_SW_CW_PIN);
    GPIO_PinInterruptEnable(GPIO_RK2_PUSH_SW_PIN);
    
    GPIO_PinInterruptCallbackRegister(GPIO_RC3_SW_CCW_PIN, app_RotaryInputHandler, 0);
    GPIO_PinInterruptCallbackRegister(GPIO_RC2_SW_CW_PIN, app_RotaryInputHandler, 0);
    GPIO_PinInterruptCallbackRegister(GPIO_RK2_PUSH_SW_PIN, app_RotaryInputHandler, 0);
}

void app_DisableRotaryInput(void)
{
    GPIO_RK2_PUSH_SW_InterruptDisable();
    GPIO_RC3_SW_CCW_InterruptDisable();
    GPIO_RC2_SW_CW_InterruptDisable();
}

void app_ReverseKnobEnable(bool rev)
{
    reverseKnob = rev;
}

bool app_IsKnobReversed(void)
{
    return reverseKnob;
}
