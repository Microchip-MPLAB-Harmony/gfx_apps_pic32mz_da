#include "gfx/legato/generated/le_gen_init.h"

static int32_t currentScreen;
static int32_t changingToScreen;

void legato_initializeScreenState(void)
{
    leSetStringTable(&stringTable);

    screenInit_Splash();
    screenInit_screen1();

    currentScreen = -1;
    changingToScreen = -1;

    legato_showScreen(screenID_Splash);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

static void legato_hideCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_Splash:
        {
            screenHide_Splash();
            currentScreen = 0;
            break;
        }
        case screenID_screen1:
        {
            screenHide_screen1();
            currentScreen = 0;
            break;
        }
    }
}

void legato_showScreen(uint32_t id)
{
    if(changingToScreen >= 0)
        return;

    changingToScreen = id;
}

void legato_updateScreenState(void)
{
    if(changingToScreen >= 0)
    {
        legato_hideCurrentScreen();

        switch(changingToScreen)
        {
            case screenID_Splash:
            {
                screenShow_Splash();
                break;
            }
            case screenID_screen1:
            {
                screenShow_screen1();
                break;
            }
        }

        currentScreen = changingToScreen;
        changingToScreen = -1;
    }

    switch(currentScreen)
    {
        case screenID_Splash:
        {
            screenUpdate_Splash();
            break;
        }
        case screenID_screen1:
        {
            screenUpdate_screen1();
            break;
        }
    }
}

leBool legato_isChangingScreens(void)
{
    return changingToScreen != -1;
}

