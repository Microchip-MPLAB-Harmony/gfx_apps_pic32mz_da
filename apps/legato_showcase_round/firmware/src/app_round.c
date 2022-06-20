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
#include "app_round.h"
#include "app_screen.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define BRIGHTNESS_DELTA_PCT_DOWN 2
#define BRIGHTNESS_DELTA_PCT_UP 1
#define TMR_PERIOD 3906

APP_ROUND_DATA appData;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;
uint32_t brightness = 0;
uint32_t newBrightness = 0;

void APP_ROUND_Initialize ( void )
{
    appData.state = APP_ROUND_STATE_INIT;
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
    if (pct == brightness)
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

/******************************************************************************
  Function:
    void APP_ROUND_Tasks ( void )

  Remarks:
    See prototype in app_round.h.
 */

void APP_ROUND_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_ROUND_STATE_INIT:
        {   
            timer = SYS_TIME_CallbackRegisterMS(app_TimerCallback, 1, CLOCK_TICK_TIMER_PERIOD_MS, SYS_TIME_PERIODIC); 
            TMR2_Start();
            OCMP1_Enable();
            
            appData.state = APP_ROUND_STATE_SERVICE_TASKS;
            break;
        }
        case APP_ROUND_STATE_SERVICE_TASKS:
        {
            break;
        }
        /* The default state should never be executed. */
        default:
            break;

    }
}


/*******************************************************************************
 End of File
 */
