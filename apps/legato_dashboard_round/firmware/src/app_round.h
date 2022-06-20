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

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
#define BACKLIGHT_TYPE_1_Clear()
#define BACKLIGHT_TYPE_1_Set()
    
#define SPLASH_WAIT_SECS 2
    
#define WHEEL_TOUCH_MIN_RADIUS_PX 50
// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/
    
typedef enum
{
    APP_CANVAS_RPM_BKGRND,
    APP_CANVAS_SPEEDO_BKGRND,
    APP_CANVAS_MHGS_LOGO,
    APP_CANVAS_NEEDLES,
} APP_CANVAS_ID;

typedef enum
{
    /* Application's state machine's initial state. */
    APP_STATE_INIT=0,
    APP_STATE_SERVICE_TASKS,
    /* TODO: Define states used by the application state machine. */
} APP_STATES;

typedef enum
{
    APP_GFX_INIT,
    APP_GFX_SPLASH,
    APP_GFX_SPLASH_WAIT,
    APP_GFX_SWITCH_MAIN,
    APP_GFX_SWITCH_WAIT,
    APP_GFX_SWITCH_WAIT2,
    APP_GFX_PROCESS,
    APP_GFX_ANIMATE_NEEDLE,
} APP_GFX_STATES;

typedef enum
{
    APP_GFX_EVENT_NONE = 0,
    APP_GFX_EVENT_SWITCH_MAIN,
    APP_GFX_EVENT_KNOB_CCW,
    APP_GFX_EVENT_KNOB_CW,
    APP_GFX_EVENT_KNOB_DOWN,
    APP_GFX_EVENT_KNOB_UP,
    APP_GFX_EVENT_GO_TO_ANGLE,
    APP_GFX_EVENT_SET_ANGLE,
} APP_GFX_EVENTS;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_STATES state;

    /* TODO: Define any additional data used by the application. */

} APP_DATA;

typedef struct
{
    leImage * imgAst;
    uint32_t x;
    uint32_t y;
} needleObj;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_ROUND_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_ROUND_Tasks( void );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_H */

/*******************************************************************************
 End of File
 */

