/* 
 * File:   app_funcs.h
 * Author: C18797
 *
 * Created on October 7, 2021, 2:33 PM
 */

#ifndef APP_FUNCS_H
#define	APP_FUNCS_H

void app_getAngleFromPoint(uint32_t x, uint32_t y, uint32_t * angle, uint32_t * radius);

void app_touchDownHandler(const SYS_INP_TouchStateEvent* const evt);
void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt);
void app_touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt);
void app_genericGestureHandler(const SYS_INP_GenericGestureEvent* const evt);

uint32_t app_getTouchAngle(void);
uint32_t app_getTouchRad(void);

void app_EnableRotaryInput(void);
void app_DisableRotaryInput(void);

void app_ReverseKnobEnable(bool rev);
bool app_IsKnobReversed(void);

//get tick from percent (y-axis as origin)
uint32_t app_percentToTick(uint32_t pct);
//get percent from absolute angle
uint32_t app_angleToPercent(uint32_t angle);
//get tick from absolute angle
uint32_t app_angleToTick(int32_t deg);
//get absolute angle from tick
uint32_t app_tickToAngle(uint32_t tick);
//convert angle to sane value (0 - 359)
uint32_t app_normalizeAngle(int32_t angle);

#endif	/* APP_FUNCS_H */

