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

#include "app_round.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

APP_ROUND_DATA appData;

void APP_ROUND_Initialize ( void )
{
    appData.state = APP_ROUND_STATE_INIT;
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
