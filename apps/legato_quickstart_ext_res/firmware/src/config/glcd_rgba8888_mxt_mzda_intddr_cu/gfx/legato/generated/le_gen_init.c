#include "gfx/legato/generated/le_gen_init.h"

static int32_t currentScreen;
static int32_t changingToScreen;

void legato_initializeScreenState(void)
{
    leSetStringTable(&stringTable);

    initializeStrings();

    screenInit_Main();
    screenInit_Launch();

    currentScreen = -1;
    changingToScreen = -1;

    legato_showScreen(screenID_Launch);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

static void legato_hideCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_Main:
        {
            screenHide_Main();
            currentScreen = 0;
            break;
        }
        case screenID_Launch:
        {
            screenHide_Launch();
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
            case screenID_Main:
            {
                screenShow_Main();
                break;
            }
            case screenID_Launch:
            {
                screenShow_Launch();
                break;
            }
        }

        currentScreen = changingToScreen;
        changingToScreen = -1;
    }

    switch(currentScreen)
    {
        case screenID_Main:
        {
            screenUpdate_Main();
            break;
        }
        case screenID_Launch:
        {
            screenUpdate_Launch();
            break;
        }
    }
}

leBool legato_isChangingScreens(void)
{
    return changingToScreen != -1;
}

