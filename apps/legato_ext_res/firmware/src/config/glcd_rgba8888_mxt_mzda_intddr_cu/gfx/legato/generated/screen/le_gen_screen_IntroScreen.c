#include "gfx/legato/generated/screen/le_gen_screen_IntroScreen.h"

// screen member widget declarations
static leWidget* root0;

leWidget* IntroScreen_Panel_0;
leImageWidget* IntroScreen_ImageWidget_0;
leImageWidget* IntroScreen_ImageWidget_1;
leButtonWidget* IntroScreen_SetupButton;
leButtonWidget* IntroScreen_ApplicationButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_IntroScreen(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_IntroScreen(void)
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

    IntroScreen_Panel_0 = leWidget_New();
    IntroScreen_Panel_0->fn->setPosition(IntroScreen_Panel_0, 0, -1);
    IntroScreen_Panel_0->fn->setSize(IntroScreen_Panel_0, 480, 272);
    IntroScreen_Panel_0->fn->setScheme(IntroScreen_Panel_0, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)IntroScreen_Panel_0);

    IntroScreen_ImageWidget_0 = leImageWidget_New();
    IntroScreen_ImageWidget_0->fn->setPosition(IntroScreen_ImageWidget_0, 166, 48);
    IntroScreen_ImageWidget_0->fn->setSize(IntroScreen_ImageWidget_0, 142, 131);
    IntroScreen_ImageWidget_0->fn->setBackgroundType(IntroScreen_ImageWidget_0, LE_WIDGET_BACKGROUND_NONE);
    IntroScreen_ImageWidget_0->fn->setBorderType(IntroScreen_ImageWidget_0, LE_WIDGET_BORDER_NONE);
    IntroScreen_ImageWidget_0->fn->setImage(IntroScreen_ImageWidget_0, (leImage*)&MHGS_logo_small_256_colors);
    root0->fn->addChild(root0, (leWidget*)IntroScreen_ImageWidget_0);

    IntroScreen_ImageWidget_1 = leImageWidget_New();
    IntroScreen_ImageWidget_1->fn->setPosition(IntroScreen_ImageWidget_1, 5, 8);
    IntroScreen_ImageWidget_1->fn->setSize(IntroScreen_ImageWidget_1, 127, 31);
    IntroScreen_ImageWidget_1->fn->setBackgroundType(IntroScreen_ImageWidget_1, LE_WIDGET_BACKGROUND_NONE);
    IntroScreen_ImageWidget_1->fn->setBorderType(IntroScreen_ImageWidget_1, LE_WIDGET_BORDER_NONE);
    IntroScreen_ImageWidget_1->fn->setImage(IntroScreen_ImageWidget_1, (leImage*)&mchpLogo_small);
    root0->fn->addChild(root0, (leWidget*)IntroScreen_ImageWidget_1);

    IntroScreen_SetupButton = leButtonWidget_New();
    IntroScreen_SetupButton->fn->setPosition(IntroScreen_SetupButton, 35, 145);
    IntroScreen_SetupButton->fn->setSize(IntroScreen_SetupButton, 100, 85);
    IntroScreen_SetupButton->fn->setBackgroundType(IntroScreen_SetupButton, LE_WIDGET_BACKGROUND_NONE);
    IntroScreen_SetupButton->fn->setBorderType(IntroScreen_SetupButton, LE_WIDGET_BORDER_LINE);
    IntroScreen_SetupButton->fn->setString(IntroScreen_SetupButton, (leString*)&string_SetupString);
    IntroScreen_SetupButton->fn->setReleasedEventCallback(IntroScreen_SetupButton, event_IntroScreen_SetupButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)IntroScreen_SetupButton);

    IntroScreen_ApplicationButton = leButtonWidget_New();
    IntroScreen_ApplicationButton->fn->setPosition(IntroScreen_ApplicationButton, 335, 148);
    IntroScreen_ApplicationButton->fn->setSize(IntroScreen_ApplicationButton, 105, 85);
    IntroScreen_ApplicationButton->fn->setBackgroundType(IntroScreen_ApplicationButton, LE_WIDGET_BACKGROUND_NONE);
    IntroScreen_ApplicationButton->fn->setBorderType(IntroScreen_ApplicationButton, LE_WIDGET_BORDER_LINE);
    IntroScreen_ApplicationButton->fn->setString(IntroScreen_ApplicationButton, (leString*)&string_ApplicationString);
    IntroScreen_ApplicationButton->fn->setReleasedEventCallback(IntroScreen_ApplicationButton, event_IntroScreen_ApplicationButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)IntroScreen_ApplicationButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_IntroScreen(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_IntroScreen(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    IntroScreen_Panel_0 = NULL;
    IntroScreen_ImageWidget_0 = NULL;
    IntroScreen_ImageWidget_1 = NULL;
    IntroScreen_SetupButton = NULL;
    IntroScreen_ApplicationButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_IntroScreen(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_IntroScreen(uint32_t lyrIdx)
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

