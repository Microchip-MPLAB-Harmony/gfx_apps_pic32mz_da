#include "gfx/legato/generated/screen/le_gen_screen_ApplicationScreen.h"

// screen member widget declarations
static leWidget* root0;

leWidget* ApplicationScreen_Layer0_FillPanel;
leLabelWidget* ApplicationScreen_TitleLabel;
leButtonWidget* ApplicationScreen_SloganButton;
leButtonWidget* ApplicationScreen_LogoButton;
leLabelWidget* ApplicationScreen_ImageTypeLabelWidget;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_ApplicationScreen(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_ApplicationScreen(void)
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

    ApplicationScreen_Layer0_FillPanel = leWidget_New();
    ApplicationScreen_Layer0_FillPanel->fn->setPosition(ApplicationScreen_Layer0_FillPanel, 0, 0);
    ApplicationScreen_Layer0_FillPanel->fn->setSize(ApplicationScreen_Layer0_FillPanel, 480, 272);
    ApplicationScreen_Layer0_FillPanel->fn->setScheme(ApplicationScreen_Layer0_FillPanel, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)ApplicationScreen_Layer0_FillPanel);

    ApplicationScreen_TitleLabel = leLabelWidget_New();
    ApplicationScreen_TitleLabel->fn->setPosition(ApplicationScreen_TitleLabel, 16, 0);
    ApplicationScreen_TitleLabel->fn->setSize(ApplicationScreen_TitleLabel, 455, 55);
    ApplicationScreen_TitleLabel->fn->setBackgroundType(ApplicationScreen_TitleLabel, LE_WIDGET_BACKGROUND_NONE);
    ApplicationScreen_TitleLabel->fn->setHAlignment(ApplicationScreen_TitleLabel, LE_HALIGN_CENTER);
    ApplicationScreen_TitleLabel->fn->setString(ApplicationScreen_TitleLabel, (leString*)&string_TitleString);
    root0->fn->addChild(root0, (leWidget*)ApplicationScreen_TitleLabel);

    ApplicationScreen_SloganButton = leButtonWidget_New();
    ApplicationScreen_SloganButton->fn->setPosition(ApplicationScreen_SloganButton, -1, 222);
    ApplicationScreen_SloganButton->fn->setSize(ApplicationScreen_SloganButton, 480, 50);
    ApplicationScreen_SloganButton->fn->setString(ApplicationScreen_SloganButton, (leString*)&string_DrawRaw);
    ApplicationScreen_SloganButton->fn->setReleasedEventCallback(ApplicationScreen_SloganButton, event_ApplicationScreen_SloganButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ApplicationScreen_SloganButton);

    ApplicationScreen_LogoButton = leButtonWidget_New();
    ApplicationScreen_LogoButton->fn->setPosition(ApplicationScreen_LogoButton, 48, 62);
    ApplicationScreen_LogoButton->fn->setSize(ApplicationScreen_LogoButton, 150, 132);
    ApplicationScreen_LogoButton->fn->setBackgroundType(ApplicationScreen_LogoButton, LE_WIDGET_BACKGROUND_NONE);
    ApplicationScreen_LogoButton->fn->setBorderType(ApplicationScreen_LogoButton, LE_WIDGET_BORDER_NONE);
    ApplicationScreen_LogoButton->fn->setPressedImage(ApplicationScreen_LogoButton, (leImage*)&MHGS_logo_small_compressed);
    ApplicationScreen_LogoButton->fn->setReleasedImage(ApplicationScreen_LogoButton, (leImage*)&MHGS_logo_small_compressed);
    ApplicationScreen_LogoButton->fn->setReleasedEventCallback(ApplicationScreen_LogoButton, event_ApplicationScreen_LogoButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ApplicationScreen_LogoButton);

    ApplicationScreen_ImageTypeLabelWidget = leLabelWidget_New();
    ApplicationScreen_ImageTypeLabelWidget->fn->setPosition(ApplicationScreen_ImageTypeLabelWidget, 236, 100);
    ApplicationScreen_ImageTypeLabelWidget->fn->setSize(ApplicationScreen_ImageTypeLabelWidget, 215, 51);
    ApplicationScreen_ImageTypeLabelWidget->fn->setBackgroundType(ApplicationScreen_ImageTypeLabelWidget, LE_WIDGET_BACKGROUND_NONE);
    ApplicationScreen_ImageTypeLabelWidget->fn->setHAlignment(ApplicationScreen_ImageTypeLabelWidget, LE_HALIGN_CENTER);
    ApplicationScreen_ImageTypeLabelWidget->fn->setString(ApplicationScreen_ImageTypeLabelWidget, (leString*)&string_ImageIsPaletteCompressed);
    root0->fn->addChild(root0, (leWidget*)ApplicationScreen_ImageTypeLabelWidget);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_ApplicationScreen(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_ApplicationScreen(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    ApplicationScreen_Layer0_FillPanel = NULL;
    ApplicationScreen_TitleLabel = NULL;
    ApplicationScreen_SloganButton = NULL;
    ApplicationScreen_LogoButton = NULL;
    ApplicationScreen_ImageTypeLabelWidget = NULL;


    showing = LE_FALSE;
}

void screenDestroy_ApplicationScreen(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_ApplicationScreen(uint32_t lyrIdx)
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

