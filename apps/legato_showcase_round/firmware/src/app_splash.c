// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

#include "definitions.h"
#include "app_screen.h"
#include "app_funcs.h"
#include "app_round.h"

typedef enum
{
    SPLASH_INIT,
    SPLASH_WAIT,
    SPLASH_EXIT,
    SPLASH_WAIT_EXIT,
} SPLASH_SCREEN_STATES;

void Splash_OnShow(void)
{
    
}

void Splash_OnHide(void)
{
    
}

void Splash_OnUpdate(void)
{
    static SPLASH_SCREEN_STATES state = SPLASH_INIT;
    
    switch(state)
    {
        case SPLASH_INIT:
        {
            if (!leRenderer_IsIdle() || leEvent_GetCount() != 0)
            {
                break;
            }
            
            APP_SetBacklightBrightness(100);
            state = SPLASH_WAIT;
            
            break;
        }
        case SPLASH_WAIT:
        {
            if (secTickCount > 3 &&
                APP_GetBacklightBrightness() == 100)
            {
                state = SPLASH_EXIT;
            }
            break;
        }
        case SPLASH_EXIT:
        {
            APP_SetBacklightBrightness(0);
            
            state = SPLASH_WAIT_EXIT;
            break;
        }
        case SPLASH_WAIT_EXIT:
        {
            if (APP_GetBacklightBrightness() == 0)
            {
                legato_showScreen(screenID_Screen0);
            }
            break;
        }
        default:
            break;
    }
}
