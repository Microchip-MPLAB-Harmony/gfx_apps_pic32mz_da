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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"
#include <math.h>
#include "app_round.h"


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

#define MIN_NEEDLE_ANGLE 0
#define MAX_NEEDLE_ANGLE 226
#define NEEDLE_ANGLE_ANIM_DELTA 4
#define BRIGHTNESS_DELTA_PCT_DOWN 2
#define BRIGHTNESS_DELTA_PCT_UP 1
#define TMR_PERIOD 3906

#define CLOCK_TICK_TIMER_PERIOD_MS 5
#define CLOCK_TICKS_PER_SEC (1000/CLOCK_TICK_TIMER_PERIOD_MS)
#define ON_BRIGHTNESS 100
#define MIN_BRIGHTNESS 5
#define OFF_BRIGHTNESS 0

static void showNeedleAtAngle(uint32_t newAngle);
void app_touchDownHandler(const SYS_INP_TouchStateEvent* const evt);
void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt);
void app_touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt);

APP_DATA appData;
needleObj needlesObj[360];
static uint32_t lastX, lastY;
uint32_t touchAngle, touchRad = 0;
static uint32_t targetNeedleAngle;
static bool reverseKnob = false;
static uint32_t needleAngle = 0;
static volatile APP_CANVAS_ID currentBackCanvas = APP_CANVAS_RPM_BKGRND;
static APP_GFX_STATES gfxAppState = APP_GFX_INIT;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;
static volatile uint32_t brightness = 0;
static uint32_t newBrightness = 0;
static volatile uint32_t tickCount = 0;
static uint32_t lastTickCount = 0;
static volatile uint32_t secTickCount = 0;
static volatile APP_GFX_EVENTS appEvent = APP_GFX_EVENT_NONE;


static SYS_INP_InputListener app_inputListener = 
{
    .handleTouchDown = &app_touchDownHandler,
    .handleTouchUp = &app_touchUpHandler,
    .handleTouchMove = &app_touchMoveHandler
};

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

void setNeedleAngle(int32_t angle)
{
    if (angle > MAX_NEEDLE_ANGLE)
    {
        angle = MAX_NEEDLE_ANGLE;
    }
    else if (angle < MIN_NEEDLE_ANGLE)
    {
        angle = MIN_NEEDLE_ANGLE;
    }
    
    needleAngle = (angle & ~0x1);
    
    showNeedleAtAngle(needleAngle);
}

uint32_t getNeedleAngle(void)
{
    return needleAngle;
}

void moveNeedleUp(void)
{
    uint32_t angle = getNeedleAngle();
    
    angle = (angle >= 2) ? angle - 2 : MIN_NEEDLE_ANGLE;
    
    setNeedleAngle(angle);
}

void moveNeedleDown(void)
{
    uint32_t angle = getNeedleAngle();
    
    angle = (angle < MAX_NEEDLE_ANGLE - 2) ? angle + 2 : MAX_NEEDLE_ANGLE;
    
    setNeedleAngle(angle);
}

void app_touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    app_getAngleFromPoint(evt->x, evt->y, &touchAngle, &touchRad);

    lastX = evt->x;
    lastY = evt->y;

    if (touchRad > WHEEL_TOUCH_MIN_RADIUS_PX)
    {
        if (touchAngle > MAX_NEEDLE_ANGLE)
        {
            targetNeedleAngle = MAX_NEEDLE_ANGLE;
        }
        else if (touchAngle < MIN_NEEDLE_ANGLE)
        {
            targetNeedleAngle = MIN_NEEDLE_ANGLE;
        }
        else
        {
            targetNeedleAngle = (touchAngle & ~0x1);
        }
        
        appEvent = APP_GFX_EVENT_GO_TO_ANGLE;  
    }
    
}

void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
    app_getAngleFromPoint(evt->x, evt->y, &touchAngle, &touchRad);

    lastX = evt->x;
    lastY = evt->y;
    
    if (touchRad > WHEEL_TOUCH_MIN_RADIUS_PX)
    {
        if (touchAngle > MAX_NEEDLE_ANGLE)
        {
            targetNeedleAngle = MAX_NEEDLE_ANGLE;
        }
        else if (touchAngle < MIN_NEEDLE_ANGLE)
        {
            targetNeedleAngle = MIN_NEEDLE_ANGLE;
        }
        else
        {
            targetNeedleAngle = (touchAngle & ~0x1);
        }
        
        appEvent = APP_GFX_EVENT_GO_TO_ANGLE;  
    }
}

void app_touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    if (evt->x != lastX || evt->y != lastY)
    {
        app_getAngleFromPoint(evt->x, evt->y, &touchAngle, &touchRad);
        
        if (touchRad > WHEEL_TOUCH_MIN_RADIUS_PX)
        {
            appEvent = APP_GFX_EVENT_SET_ANGLE; 
//            setNeedleAngle(touchAngle);
        }
        
        lastX = evt->x;
        lastY = evt->y;        
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

void appSetNeedleObjData(leImage * imgAst,
                           uint32_t angle,
                           uint32_t x,
                           uint32_t y)
{
    needlesObj[angle].x = x;
    needlesObj[angle].y = y;
    needlesObj[angle].imgAst = imgAst;
}

static void app_initialize_needle_lookup_table(void)
{
    memset(needlesObj, 0, sizeof(needlesObj));
    
    appSetNeedleObjData(&n000_627_238, 0, 264, 210);
    appSetNeedleObjData(&n002_626_235, 2, 263, 207);
    appSetNeedleObjData(&n004_626_232, 4, 263, 204);
    appSetNeedleObjData(&n006_626_227, 6, 263, 198);
    appSetNeedleObjData(&n008_625_223, 8, 262, 194);
    appSetNeedleObjData(&n010_624_218, 10, 261, 190);
    appSetNeedleObjData(&n012_624_213, 12, 261, 186);
    appSetNeedleObjData(&n014_623_209, 14, 261, 184);
    appSetNeedleObjData(&n016_625_205, 16, 263, 180);
    appSetNeedleObjData(&n018_625_200, 18, 263, 175);
    appSetNeedleObjData(&n020_624_196, 20, 262, 172);
    appSetNeedleObjData(&n022_623_191, 22, 262, 167);
    appSetNeedleObjData(&n024_622_186, 24, 261, 163);
    appSetNeedleObjData(&n026_621_183, 26, 260, 157);
    appSetNeedleObjData(&n028_620_177, 28, 258, 151);
    
    appSetNeedleObjData(&n030_618_174, 30, 256, 147);
    appSetNeedleObjData(&n032_617_170, 32, 255, 143);
    appSetNeedleObjData(&n034_616_166, 34, 254, 141);
    appSetNeedleObjData(&n036_615_163, 36, 254, 137);
    appSetNeedleObjData(&n038_613_159, 38, 252, 133);
    appSetNeedleObjData(&n040_612_155, 40, 251, 129);
    appSetNeedleObjData(&n042_610_152, 42, 250, 126);
    appSetNeedleObjData(&n044_608_149, 44, 248, 123);
    appSetNeedleObjData(&n046_607_145, 46, 247, 119);
    appSetNeedleObjData(&n048_605_142, 48, 246, 116);
    appSetNeedleObjData(&n050_603_139, 50, 244, 113);  
    appSetNeedleObjData(&n052_602_136, 52, 243, 111);
    appSetNeedleObjData(&n054_601_134, 54, 242, 109);
    appSetNeedleObjData(&n056_599_131, 56, 239, 106);
    appSetNeedleObjData(&n058_597_128, 58, 237, 103);
    appSetNeedleObjData(&n060_596_125, 60, 236, 100);
    appSetNeedleObjData(&n062_594_123, 62, 235, 98);
    appSetNeedleObjData(&n064_592_121, 64, 233, 97);
    appSetNeedleObjData(&n066_590_118, 66, 231, 94);
    appSetNeedleObjData(&n068_588_116, 68, 229, 92);
    appSetNeedleObjData(&n070_586_115, 70, 228, 91);
    appSetNeedleObjData(&n072_584_113, 72, 226, 88);
    appSetNeedleObjData(&n074_583_111, 74, 225, 86);
    appSetNeedleObjData(&n076_581_110, 76, 223, 85);
    appSetNeedleObjData(&n078_577_109, 78, 221, 84);
    appSetNeedleObjData(&n080_576_108, 80, 220, 83);
    appSetNeedleObjData(&n082_576_107, 82, 219, 82);
    appSetNeedleObjData(&n084_571_106, 84, 217, 80);
    appSetNeedleObjData(&n086_570_106, 86, 215, 80);
    appSetNeedleObjData(&n088_569_105, 88, 213, 79);

    
    appSetNeedleObjData(&n090_210_106, 90, 203, 80);
    appSetNeedleObjData(&n088_207_105, 92, 200, 79);
    appSetNeedleObjData(&n086_205_106, 94, 197, 80);
    appSetNeedleObjData(&n084_200_106, 96, 190, 80);    
    appSetNeedleObjData(&n082_196_107, 98, 184, 81);
    appSetNeedleObjData(&n080_191_108, 100, 179, 82);
    
    appSetNeedleObjData(&n000_88_238, 180, 84, 208);    
    appSetNeedleObjData(&n_02_84_240, 182, 81, 208);
    appSetNeedleObjData(&n_04_85_242, 184, 81, 208);
    appSetNeedleObjData(&n_06_84_244, 186, 81, 209);
    appSetNeedleObjData(&n_08_88_246, 188, 84, 212);
    appSetNeedleObjData(&n_10_89_248, 190, 85, 215);
    appSetNeedleObjData(&n_12_91_250, 192, 86, 218);
    appSetNeedleObjData(&n_14_90_251, 194, 86, 220);
    appSetNeedleObjData(&n_16_92_254, 196, 88, 224);
    appSetNeedleObjData(&n_18_93_256, 198, 89, 227);
    appSetNeedleObjData(&n_20_95_258, 200, 92, 231);
    appSetNeedleObjData(&n_22_98_259, 202, 94, 232);
    appSetNeedleObjData(&n_24_99_262, 204, 96, 235);
    appSetNeedleObjData(&n_26_97_255, 206, 94, 237);
    appSetNeedleObjData(&n_28_104_257, 208, 101, 239);
    appSetNeedleObjData(&n_30_106_259, 210, 103, 241);
    appSetNeedleObjData(&n_32_108_261, 212, 104, 243);
    appSetNeedleObjData(&n_34_110_264, 214, 107, 244);
    appSetNeedleObjData(&n_36_111_273, 216, 109, 245);
    appSetNeedleObjData(&n_38_117_275, 218, 112, 247);
    appSetNeedleObjData(&n_40_120_277, 220, 114, 248);
    appSetNeedleObjData(&n_42_121_280, 222, 117, 250);
    appSetNeedleObjData(&n_44_125_280, 224, 120, 251);
    appSetNeedleObjData(&n_46_127_280, 226, 123, 253);


    appSetNeedleObjData(&n002_88_233, 178, 84, 206);
    appSetNeedleObjData(&n004_89_228, 176, 84, 204);
    appSetNeedleObjData(&n006_88_223, 174, 84, 199);
    appSetNeedleObjData(&n008_89_219, 172, 85, 195);
    appSetNeedleObjData(&n010_89_214, 170, 85, 190);
    appSetNeedleObjData(&n012_90_210, 168, 85, 186);
    appSetNeedleObjData(&n014_91_209, 166, 86, 182);
    appSetNeedleObjData(&n016_89_205, 164, 84, 178);
    appSetNeedleObjData(&n018_91_200, 162, 86, 172);
    appSetNeedleObjData(&n020_92_196, 160, 86, 168);
    appSetNeedleObjData(&n022_94_191, 158, 88, 163);
    appSetNeedleObjData(&n024_96_187, 156, 90, 159);
    appSetNeedleObjData(&n026_97_183, 154, 91, 154);
    appSetNeedleObjData(&n028_100_177, 152, 94, 148);
    appSetNeedleObjData(&n030_102_173, 150, 96, 145);
    appSetNeedleObjData(&n032_104_170, 148, 97, 142);
    appSetNeedleObjData(&n034_107_167, 146, 98, 140);
    appSetNeedleObjData(&n036_110_163, 144, 102, 137);
    appSetNeedleObjData(&n038_112_159, 142, 102, 132);
    appSetNeedleObjData(&n040_115_155, 140, 105, 128);
    appSetNeedleObjData(&n042_118_152, 138, 108, 126);
    appSetNeedleObjData(&n044_121_149, 136, 111, 123);
    appSetNeedleObjData(&n046_125_145, 134, 114, 120);
    appSetNeedleObjData(&n048_128_142, 132, 117, 117);
    appSetNeedleObjData(&n050_132_139, 130, 120, 114);
    appSetNeedleObjData(&n052_135_136, 128, 122, 112);
    appSetNeedleObjData(&n054_138_154, 126, 125, 110);
    appSetNeedleObjData(&n056_142_131, 124, 130, 106);
    appSetNeedleObjData(&n058_146_128, 122, 135, 102);
    appSetNeedleObjData(&n060_149_126, 120, 139, 99);
    appSetNeedleObjData(&n062_153_123, 118, 143, 97);
    appSetNeedleObjData(&n064_157_121, 116, 147, 94);
    appSetNeedleObjData(&n066_161_118, 114, 151, 91);
    appSetNeedleObjData(&n068_165_116, 112, 155, 90);
    appSetNeedleObjData(&n070_170_115, 110, 160, 89);
    appSetNeedleObjData(&n072_174_113, 108, 163, 87);
    appSetNeedleObjData(&n074_177_110, 106, 166, 85);
    appSetNeedleObjData(&n076_182_110, 104, 170, 84);
    appSetNeedleObjData(&n078_187_109, 102, 175, 83);
}

void appSetLayerFrame(uint32_t canvasID, 
                      uint32_t addr,
                      uint32_t x,
                      uint32_t y,
                      uint32_t width,
                      uint32_t height)
{
    gfxcSetPixelBuffer(canvasID,
                       width,
                       height,
                       GFX_COLOR_MODE_RGBA_8888,
                       (void *) addr);
    
    gfxcSetWindowPosition(canvasID, x, y);
    gfxcSetWindowSize(canvasID, width, height);
    gfxcShowCanvas(canvasID);
    gfxcCanvasUpdate(canvasID);
}

static void showNeedleAtAngle(uint32_t newAngle)
{
    newAngle &= ~0x1;
    if (newAngle <= 226)
    {
        if (needlesObj[newAngle].imgAst != NULL)
        {
            appSetLayerFrame(APP_CANVAS_NEEDLES, 
                             (uint32_t) needlesObj[newAngle].imgAst->buffer.pixels, 
                             needlesObj[newAngle].x,
                             needlesObj[newAngle].y,
                             needlesObj[newAngle].imgAst->buffer.size.width, 
                             needlesObj[newAngle].imgAst->buffer.size.height);  
        }
    }
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
                appEvent = (reverseKnob == true) ? 
                    APP_GFX_EVENT_KNOB_CCW : APP_GFX_EVENT_KNOB_CW;
            }
            else if (seqA == 0x03 && seqB == 0x09)
            {
                appEvent = (reverseKnob == false) ? 
                    APP_GFX_EVENT_KNOB_CCW : APP_GFX_EVENT_KNOB_CW;
            }            
            
            break;
        }
        case GPIO_RK2_PUSH_SW_PIN:
        {
            if (GPIO_RK2_PUSH_SW_Get() == 0)
            {
                appEvent = APP_GFX_EVENT_KNOB_DOWN;
            }
            else
            {
                appEvent = APP_GFX_EVENT_KNOB_UP;
            }
            
            break;
        }
        default:
            break;
    }
}

static void app_TimerCallback ( uintptr_t context)
{
    tickCount++;
    
    if (tickCount % CLOCK_TICKS_PER_SEC == 0)
    {
        secTickCount++;
    }
    
    if (brightness != newBrightness)
    {
        if (newBrightness > brightness)
        {
            if (brightness < newBrightness - BRIGHTNESS_DELTA_PCT_UP)
            {
                brightness += BRIGHTNESS_DELTA_PCT_UP;
            }
            else
            {
                brightness = newBrightness;
            }
        }
        else
        {
            if (brightness > newBrightness + BRIGHTNESS_DELTA_PCT_DOWN)
            {
                brightness -= BRIGHTNESS_DELTA_PCT_DOWN;
            }
            else
            {
                brightness = newBrightness;
            }        
        }

        OCMP1_CompareSecondaryValueSet( (TMR_PERIOD * brightness)/100);

    }
}

void APP_SetBacklightBrightness(unsigned int pct)
{
    if (pct == brightness || 
        brightness != newBrightness)
        return;
    
    if (pct > ON_BRIGHTNESS)
        newBrightness = ON_BRIGHTNESS;
    else    
        newBrightness = pct;
}

unsigned int APP_GetBacklightBrightness(void)
{
    return brightness;
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

void APP_ROUND_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    gfxAppState = APP_GFX_INIT;
    appEvent = APP_GFX_EVENT_NONE;
    
    app_initialize_needle_lookup_table();    

    gfxcSetLayer(APP_CANVAS_RPM_BKGRND, 0);
    gfxcSetWindowSize(APP_CANVAS_RPM_BKGRND, 432, 432);
    gfxcSetWindowPosition(APP_CANVAS_RPM_BKGRND, 0, 0);
    
    gfxcSetLayer(APP_CANVAS_SPEEDO_BKGRND, 0);
    gfxcSetWindowSize(APP_CANVAS_SPEEDO_BKGRND, 432, 432);
    gfxcSetWindowPosition(APP_CANVAS_SPEEDO_BKGRND, 0, 0);
    
    gfxcSetLayer(APP_CANVAS_MHGS_LOGO, 0);
    gfxcSetWindowSize(APP_CANVAS_MHGS_LOGO, 432, 432);
    gfxcSetWindowPosition(APP_CANVAS_MHGS_LOGO, 0, 0);

    gfxcSetLayer(APP_CANVAS_NEEDLES, 1);
    
    gfxcHideCanvas(APP_CANVAS_SPEEDO_BKGRND);
    gfxcHideCanvas(APP_CANVAS_MHGS_LOGO);    
    gfxcHideCanvas(APP_CANVAS_RPM_BKGRND);
    gfxcHideCanvas(APP_CANVAS_NEEDLES);

    gfxcCanvasUpdate(APP_CANVAS_SPEEDO_BKGRND);
    gfxcCanvasUpdate(APP_CANVAS_MHGS_LOGO);    
    gfxcCanvasUpdate(APP_CANVAS_RPM_BKGRND);
    gfxcCanvasUpdate(APP_CANVAS_NEEDLES);  
    
    app_EnableRotaryInput();

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

void app_ShowBaseCanvas(uint32_t canvasID)
{
    uint32_t i;
    for (i = 0; i < APP_CANVAS_NEEDLES; i++)
    {
        if (i == canvasID)
        {
            gfxcShowCanvas(canvasID);
        }
        else
        {
            gfxcHideCanvas(i);
        }
    }
    
    for (i = 0; i < APP_CANVAS_NEEDLES; i++)
    {
        gfxcCanvasUpdate(i);
    }
    
    gfxcCanvasUpdate(canvasID);
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_ROUND_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            
            SYS_INP_AddListener(&app_inputListener);
            timer = SYS_TIME_CallbackRegisterMS(app_TimerCallback, 1, CLOCK_TICK_TIMER_PERIOD_MS, SYS_TIME_PERIODIC); 
            TMR2_Start();
            OCMP1_Enable();            
            

            if (appInitialized)
            {

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {

            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

void event_Screen0_RPMButtonWidget_OnReleased(leButtonWidget* btn)
{
    appEvent = APP_GFX_EVENT_SWITCH_MAIN;
}

void event_Screen0_MPHButtonWidget_OnReleased(leButtonWidget* btn)
{
    appEvent = APP_GFX_EVENT_SWITCH_MAIN;
}

void Screen0_OnUpdate(void)
{
    switch (gfxAppState) 
    {
        case APP_GFX_INIT:
        {
            if(!leRenderer_IsIdle() || leEvent_GetCount() != 0)
            {
                break;
            }

            app_ShowBaseCanvas(APP_CANVAS_MHGS_LOGO);
            APP_SetBacklightBrightness(100);
            
            gfxAppState = APP_GFX_SPLASH;
            break;
        }
        case APP_GFX_SPLASH:
        {
            if (APP_GetBacklightBrightness() == 100)
            {
                gfxAppState = APP_GFX_SPLASH_WAIT;
                secTickCount = 0;
            }            
            
            break;
        }
        case APP_GFX_SPLASH_WAIT:
        {
            if (secTickCount >= SPLASH_WAIT_SECS)
            {
                APP_SetBacklightBrightness(0);
                gfxAppState = APP_GFX_SWITCH_MAIN;
            }
            break;
        }
        case APP_GFX_SWITCH_MAIN:
        {
            if (APP_GetBacklightBrightness() == 0)
            {
                app_ShowBaseCanvas(currentBackCanvas);
                setNeedleAngle(MAX_NEEDLE_ANGLE);
                
                APP_SetBacklightBrightness(100);
                gfxAppState = APP_GFX_SWITCH_WAIT;
                secTickCount = 0;
            }

            break;
        }
        case APP_GFX_SWITCH_WAIT:
        {
            if (lastTickCount == tickCount)
                break;
            
            lastTickCount = tickCount;
                    
            if (APP_GetBacklightBrightness() == 100 &&
                getNeedleAngle() == MIN_NEEDLE_ANGLE)
            {
                gfxAppState = APP_GFX_SWITCH_WAIT2;
            }
            else
            {
                uint32_t needleAngle = getNeedleAngle();
                
                if (needleAngle > MIN_NEEDLE_ANGLE)
                {
                    setNeedleAngle(needleAngle - NEEDLE_ANGLE_ANIM_DELTA);
                }
            }

            break;
        }
        case APP_GFX_SWITCH_WAIT2:
        {
            if (lastTickCount == tickCount)
                break;
            
            lastTickCount = tickCount;
            
            
            if (getNeedleAngle() == MAX_NEEDLE_ANGLE)
            {
                gfxAppState = APP_GFX_PROCESS;
                setNeedleAngle(MAX_NEEDLE_ANGLE);
            }
            else
            {
                uint32_t needleAngle = getNeedleAngle();
                
                if (needleAngle < MAX_NEEDLE_ANGLE )
                {
                    setNeedleAngle(needleAngle + NEEDLE_ANGLE_ANIM_DELTA);
                }
            }

            break;
        }
        case APP_GFX_ANIMATE_NEEDLE:
        {
            int32_t needleAngle;
//            int32_t step;
            
            if (lastTickCount == tickCount)
                break;
            
            lastTickCount = tickCount;            
            needleAngle = getNeedleAngle();
            
            if (needleAngle > targetNeedleAngle)
            {
                setNeedleAngle(needleAngle - 2);
            }
            else if (needleAngle < targetNeedleAngle)
            {
                setNeedleAngle(needleAngle + 2);
            }
            else
            {
                setNeedleAngle(targetNeedleAngle);
                gfxAppState = APP_GFX_PROCESS;
            }
            
            break;
        }
        case APP_GFX_PROCESS:
        {
            switch(appEvent)
            {
                case APP_GFX_EVENT_SWITCH_MAIN:
                {
                    currentBackCanvas = (currentBackCanvas == APP_CANVAS_RPM_BKGRND) ?
                        APP_CANVAS_SPEEDO_BKGRND : APP_CANVAS_RPM_BKGRND;
                    gfxAppState = APP_GFX_SWITCH_MAIN;
                    APP_SetBacklightBrightness(0);
                    
                    break;
                }
                case APP_GFX_EVENT_KNOB_CCW:
                {
                    moveNeedleDown();
                    break;
                }
                case APP_GFX_EVENT_KNOB_CW:
                {
                    moveNeedleUp();
                    break;
                }
                case APP_GFX_EVENT_KNOB_DOWN:
                {
                    break;
                }
                case APP_GFX_EVENT_KNOB_UP:
                {
                    break;
                }
                case APP_GFX_EVENT_GO_TO_ANGLE:
                {
                    gfxAppState = APP_GFX_ANIMATE_NEEDLE;
                    break;
                }
                case APP_GFX_EVENT_SET_ANGLE:
                {
                    setNeedleAngle(touchAngle);                
                    break;
                }
                default:
                    break;
            }
            
            appEvent = APP_GFX_EVENT_NONE;
            
            break;
        }
        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
