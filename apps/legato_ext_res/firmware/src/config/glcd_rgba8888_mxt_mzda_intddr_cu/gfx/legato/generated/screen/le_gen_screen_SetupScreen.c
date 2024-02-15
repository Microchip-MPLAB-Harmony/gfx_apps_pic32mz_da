#include "gfx/legato/generated/screen/le_gen_screen_SetupScreen.h"

// screen member widget declarations
static leWidget* root0;

leWidget* SetupScreen_PanelWidget0;
leLabelWidget* SetupScreen_LabelWidget0;
leButtonWidget* SetupScreen_UpdateSQIButton;
leLabelWidget* SetupScreen_SQIUpdateStatusString;
leButtonWidget* SetupScreen_RebootButtonWidget0;
leLabelWidget* SetupScreen_TimeStampString;
leLabelWidget* SetupScreen_SQIUpdateWarningLabel;
leButtonWidget* SetupScreen_EraseYesButton;
leButtonWidget* SetupScreen_EraseNoButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_SetupScreen(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_SetupScreen(void)
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

    SetupScreen_PanelWidget0 = leWidget_New();
    SetupScreen_PanelWidget0->fn->setPosition(SetupScreen_PanelWidget0, 1, -4);
    SetupScreen_PanelWidget0->fn->setSize(SetupScreen_PanelWidget0, 480, 320);
    SetupScreen_PanelWidget0->fn->setScheme(SetupScreen_PanelWidget0, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)SetupScreen_PanelWidget0);

    SetupScreen_LabelWidget0 = leLabelWidget_New();
    SetupScreen_LabelWidget0->fn->setPosition(SetupScreen_LabelWidget0, 9, 4);
    SetupScreen_LabelWidget0->fn->setSize(SetupScreen_LabelWidget0, 153, 45);
    SetupScreen_LabelWidget0->fn->setScheme(SetupScreen_LabelWidget0, &WhiteBackgroundScheme);
    SetupScreen_LabelWidget0->fn->setBackgroundType(SetupScreen_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    SetupScreen_LabelWidget0->fn->setHAlignment(SetupScreen_LabelWidget0, LE_HALIGN_CENTER);
    SetupScreen_LabelWidget0->fn->setString(SetupScreen_LabelWidget0, (leString*)&string_DemoConfig);
    root0->fn->addChild(root0, (leWidget*)SetupScreen_LabelWidget0);

    SetupScreen_UpdateSQIButton = leButtonWidget_New();
    SetupScreen_UpdateSQIButton->fn->setPosition(SetupScreen_UpdateSQIButton, 8, 103);
    SetupScreen_UpdateSQIButton->fn->setSize(SetupScreen_UpdateSQIButton, 140, 50);
    SetupScreen_UpdateSQIButton->fn->setScheme(SetupScreen_UpdateSQIButton, &SettingsScheme);
    SetupScreen_UpdateSQIButton->fn->setBorderType(SetupScreen_UpdateSQIButton, LE_WIDGET_BORDER_LINE);
    SetupScreen_UpdateSQIButton->fn->setMargins(SetupScreen_UpdateSQIButton, 4, 5, 4, 4);
    SetupScreen_UpdateSQIButton->fn->setToggleable(SetupScreen_UpdateSQIButton, LE_TRUE);
    SetupScreen_UpdateSQIButton->fn->setString(SetupScreen_UpdateSQIButton, (leString*)&string_SettingsDownload);
    SetupScreen_UpdateSQIButton->fn->setPressedEventCallback(SetupScreen_UpdateSQIButton, event_SetupScreen_UpdateSQIButton_OnPressed);
    SetupScreen_UpdateSQIButton->fn->setReleasedEventCallback(SetupScreen_UpdateSQIButton, event_SetupScreen_UpdateSQIButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SetupScreen_UpdateSQIButton);

    SetupScreen_SQIUpdateStatusString = leLabelWidget_New();
    SetupScreen_SQIUpdateStatusString->fn->setPosition(SetupScreen_SQIUpdateStatusString, 148, 103);
    SetupScreen_SQIUpdateStatusString->fn->setSize(SetupScreen_SQIUpdateStatusString, 325, 50);
    SetupScreen_SQIUpdateStatusString->fn->setBackgroundType(SetupScreen_SQIUpdateStatusString, LE_WIDGET_BACKGROUND_NONE);
    SetupScreen_SQIUpdateStatusString->fn->setBorderType(SetupScreen_SQIUpdateStatusString, LE_WIDGET_BORDER_LINE);
    SetupScreen_SQIUpdateStatusString->fn->setHAlignment(SetupScreen_SQIUpdateStatusString, LE_HALIGN_CENTER);
    root0->fn->addChild(root0, (leWidget*)SetupScreen_SQIUpdateStatusString);

    SetupScreen_RebootButtonWidget0 = leButtonWidget_New();
    SetupScreen_RebootButtonWidget0->fn->setPosition(SetupScreen_RebootButtonWidget0, 8, 52);
    SetupScreen_RebootButtonWidget0->fn->setSize(SetupScreen_RebootButtonWidget0, 465, 50);
    SetupScreen_RebootButtonWidget0->fn->setScheme(SetupScreen_RebootButtonWidget0, &SettingsScheme);
    SetupScreen_RebootButtonWidget0->fn->setBorderType(SetupScreen_RebootButtonWidget0, LE_WIDGET_BORDER_LINE);
    SetupScreen_RebootButtonWidget0->fn->setString(SetupScreen_RebootButtonWidget0, (leString*)&string_Reboot);
    SetupScreen_RebootButtonWidget0->fn->setPressedEventCallback(SetupScreen_RebootButtonWidget0, event_SetupScreen_RebootButtonWidget0_OnPressed);
    root0->fn->addChild(root0, (leWidget*)SetupScreen_RebootButtonWidget0);

    SetupScreen_TimeStampString = leLabelWidget_New();
    SetupScreen_TimeStampString->fn->setPosition(SetupScreen_TimeStampString, 163, 14);
    SetupScreen_TimeStampString->fn->setSize(SetupScreen_TimeStampString, 234, 25);
    SetupScreen_TimeStampString->fn->setScheme(SetupScreen_TimeStampString, &WhiteBackgroundScheme);
    SetupScreen_TimeStampString->fn->setBackgroundType(SetupScreen_TimeStampString, LE_WIDGET_BACKGROUND_NONE);
    SetupScreen_TimeStampString->fn->setHAlignment(SetupScreen_TimeStampString, LE_HALIGN_RIGHT);
    root0->fn->addChild(root0, (leWidget*)SetupScreen_TimeStampString);

    SetupScreen_SQIUpdateWarningLabel = leLabelWidget_New();
    SetupScreen_SQIUpdateWarningLabel->fn->setPosition(SetupScreen_SQIUpdateWarningLabel, 41, 62);
    SetupScreen_SQIUpdateWarningLabel->fn->setSize(SetupScreen_SQIUpdateWarningLabel, 409, 215);
    SetupScreen_SQIUpdateWarningLabel->fn->setScheme(SetupScreen_SQIUpdateWarningLabel, &WhiteBackgroundScheme);
    SetupScreen_SQIUpdateWarningLabel->fn->setHAlignment(SetupScreen_SQIUpdateWarningLabel, LE_HALIGN_CENTER);
    SetupScreen_SQIUpdateWarningLabel->fn->setVAlignment(SetupScreen_SQIUpdateWarningLabel, LE_VALIGN_TOP);
    SetupScreen_SQIUpdateWarningLabel->fn->setMargins(SetupScreen_SQIUpdateWarningLabel, 4, 50, 4, 4);
    SetupScreen_SQIUpdateWarningLabel->fn->setString(SetupScreen_SQIUpdateWarningLabel, (leString*)&string_SQIUpdateWarning);
    root0->fn->addChild(root0, (leWidget*)SetupScreen_SQIUpdateWarningLabel);

    SetupScreen_EraseYesButton = leButtonWidget_New();
    SetupScreen_EraseYesButton->fn->setPosition(SetupScreen_EraseYesButton, 18, 107);
    SetupScreen_EraseYesButton->fn->setSize(SetupScreen_EraseYesButton, 184, 60);
    SetupScreen_EraseYesButton->fn->setScheme(SetupScreen_EraseYesButton, &InfoPageScheme);
    SetupScreen_EraseYesButton->fn->setString(SetupScreen_EraseYesButton, (leString*)&string_Yes);
    SetupScreen_EraseYesButton->fn->setReleasedEventCallback(SetupScreen_EraseYesButton, event_SetupScreen_EraseYesButton_OnReleased);
    SetupScreen_SQIUpdateWarningLabel->fn->addChild(SetupScreen_SQIUpdateWarningLabel, (leWidget*)SetupScreen_EraseYesButton);

    SetupScreen_EraseNoButton = leButtonWidget_New();
    SetupScreen_EraseNoButton->fn->setPosition(SetupScreen_EraseNoButton, 204, 107);
    SetupScreen_EraseNoButton->fn->setSize(SetupScreen_EraseNoButton, 191, 60);
    SetupScreen_EraseNoButton->fn->setBorderType(SetupScreen_EraseNoButton, LE_WIDGET_BORDER_LINE);
    SetupScreen_EraseNoButton->fn->setString(SetupScreen_EraseNoButton, (leString*)&string_No);
    SetupScreen_EraseNoButton->fn->setReleasedEventCallback(SetupScreen_EraseNoButton, event_SetupScreen_EraseNoButton_OnReleased);
    SetupScreen_SQIUpdateWarningLabel->fn->addChild(SetupScreen_SQIUpdateWarningLabel, (leWidget*)SetupScreen_EraseNoButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    SetupScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_SetupScreen(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    SetupScreen_OnUpdate(); // raise event
}

void screenHide_SetupScreen(void)
{
    SetupScreen_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    SetupScreen_PanelWidget0 = NULL;
    SetupScreen_LabelWidget0 = NULL;
    SetupScreen_UpdateSQIButton = NULL;
    SetupScreen_SQIUpdateStatusString = NULL;
    SetupScreen_RebootButtonWidget0 = NULL;
    SetupScreen_TimeStampString = NULL;
    SetupScreen_SQIUpdateWarningLabel = NULL;
    SetupScreen_EraseYesButton = NULL;
    SetupScreen_EraseNoButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_SetupScreen(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_SetupScreen(uint32_t lyrIdx)
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

