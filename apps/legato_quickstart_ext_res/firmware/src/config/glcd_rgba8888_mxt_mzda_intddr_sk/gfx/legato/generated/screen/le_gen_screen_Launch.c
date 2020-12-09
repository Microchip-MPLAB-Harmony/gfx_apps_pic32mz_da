#include "gfx/legato/generated/screen/le_gen_screen_Launch.h"

// screen member widget declarations
leWidget* root0;

leWidget* Launch_PanelWidget0;
leButtonWidget* Launch_ButtonWidget_LaunchLabel;
leButtonWidget* Launch_ButtonWidget_GoToMain;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Launch(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Launch(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Launch_PanelWidget0 = leWidget_New();
    Launch_PanelWidget0->fn->setPosition(Launch_PanelWidget0, 0, 0);
    Launch_PanelWidget0->fn->setSize(Launch_PanelWidget0, 480, 272);
    Launch_PanelWidget0->fn->setScheme(Launch_PanelWidget0, &LayerScheme);
    root0->fn->addChild(root0, (leWidget*)Launch_PanelWidget0);

    Launch_ButtonWidget_LaunchLabel = leButtonWidget_New();
    Launch_ButtonWidget_LaunchLabel->fn->setPosition(Launch_ButtonWidget_LaunchLabel, 30, 30);
    Launch_ButtonWidget_LaunchLabel->fn->setSize(Launch_ButtonWidget_LaunchLabel, 420, 130);
    Launch_ButtonWidget_LaunchLabel->fn->setBackgroundType(Launch_ButtonWidget_LaunchLabel, LE_WIDGET_BACKGROUND_NONE);
    Launch_ButtonWidget_LaunchLabel->fn->setBorderType(Launch_ButtonWidget_LaunchLabel, LE_WIDGET_BORDER_NONE);
    Launch_ButtonWidget_LaunchLabel->fn->setString(Launch_ButtonWidget_LaunchLabel, (leString*)&string_ConnectUSB);
    Launch_ButtonWidget_LaunchLabel->fn->setPressedOffset(Launch_ButtonWidget_LaunchLabel, 0);
    Launch_ButtonWidget_LaunchLabel->fn->setReleasedEventCallback(Launch_ButtonWidget_LaunchLabel, event_Launch_ButtonWidget_LaunchLabel_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Launch_ButtonWidget_LaunchLabel);

    Launch_ButtonWidget_GoToMain = leButtonWidget_New();
    Launch_ButtonWidget_GoToMain->fn->setPosition(Launch_ButtonWidget_GoToMain, 40, 160);
    Launch_ButtonWidget_GoToMain->fn->setSize(Launch_ButtonWidget_GoToMain, 400, 80);
    Launch_ButtonWidget_GoToMain->fn->setEnabled(Launch_ButtonWidget_GoToMain, LE_FALSE);
    Launch_ButtonWidget_GoToMain->fn->setVisible(Launch_ButtonWidget_GoToMain, LE_FALSE);
    Launch_ButtonWidget_GoToMain->fn->setString(Launch_ButtonWidget_GoToMain, (leString*)&string_GoToMain);
    Launch_ButtonWidget_GoToMain->fn->setReleasedEventCallback(Launch_ButtonWidget_GoToMain, event_Launch_ButtonWidget_GoToMain_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Launch_ButtonWidget_GoToMain);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Launch(void)
{
}

void screenHide_Launch(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Launch_PanelWidget0 = NULL;
    Launch_ButtonWidget_LaunchLabel = NULL;
    Launch_ButtonWidget_GoToMain = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Launch(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Launch(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

