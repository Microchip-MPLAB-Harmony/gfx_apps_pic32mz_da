#include "gfx/legato/generated/le_gen_init.h"

static int32_t currentScreen;
static int32_t changingToScreen;

void legato_initializeScreenState(void)
{
    leSetStringTable(&stringTable);

    initializeStrings();

    screenInit_ApplicationScreen();
    screenInit_SetupScreen();
    screenInit_IntroScreen();

    currentScreen = -1;
    changingToScreen = -1;

    legato_showScreen(screenID_IntroScreen);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

static void legato_hideCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_ApplicationScreen:
        {
            screenHide_ApplicationScreen();
            currentScreen = 0;
            break;
        }
        case screenID_SetupScreen:
        {
            screenHide_SetupScreen();
            currentScreen = 0;
            break;
        }
        case screenID_IntroScreen:
        {
            screenHide_IntroScreen();
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
    if(leIsDrawing() == LE_TRUE)
        return;

    if(changingToScreen >= 0)
    {
        legato_hideCurrentScreen();

        switch(changingToScreen)
        {
            case screenID_ApplicationScreen:
            {
                screenShow_ApplicationScreen();
                break;
            }
            case screenID_SetupScreen:
            {
                screenShow_SetupScreen();
                break;
            }
            case screenID_IntroScreen:
            {
                screenShow_IntroScreen();
                break;
            }
        }

        currentScreen = changingToScreen;
        changingToScreen = -1;
    }

    switch(currentScreen)
    {
        case screenID_ApplicationScreen:
        {
            screenUpdate_ApplicationScreen();
            break;
        }
        case screenID_SetupScreen:
        {
            screenUpdate_SetupScreen();
            break;
        }
        case screenID_IntroScreen:
        {
            screenUpdate_IntroScreen();
            break;
        }
    }
}

leBool legato_isChangingScreens(void)
{
    return changingToScreen != -1;
}

