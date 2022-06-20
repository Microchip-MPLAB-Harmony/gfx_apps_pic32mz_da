#include "gfx/legato/generated/screen/le_gen_screen_Main.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Main_Layer0_FillPanel;
leLabelWidget* Main_TitleLabel;
leButtonWidget* Main_SloganButton;
leButtonWidget* Main_LogoButton;
leLabelWidget* Main_ImageTypeLabelWidget;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Main(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Main(void)
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

    Main_Layer0_FillPanel = leWidget_New();
    Main_Layer0_FillPanel->fn->setPosition(Main_Layer0_FillPanel, 0, 0);
    Main_Layer0_FillPanel->fn->setSize(Main_Layer0_FillPanel, 480, 272);
    Main_Layer0_FillPanel->fn->setScheme(Main_Layer0_FillPanel, &LayerScheme);
    root0->fn->addChild(root0, (leWidget*)Main_Layer0_FillPanel);

    Main_TitleLabel = leLabelWidget_New();
    Main_TitleLabel->fn->setPosition(Main_TitleLabel, 16, 0);
    Main_TitleLabel->fn->setSize(Main_TitleLabel, 455, 55);
    Main_TitleLabel->fn->setBackgroundType(Main_TitleLabel, LE_WIDGET_BACKGROUND_NONE);
    Main_TitleLabel->fn->setHAlignment(Main_TitleLabel, LE_HALIGN_CENTER);
    Main_TitleLabel->fn->setString(Main_TitleLabel, (leString*)&string_TitleString);
    root0->fn->addChild(root0, (leWidget*)Main_TitleLabel);

    Main_SloganButton = leButtonWidget_New();
    Main_SloganButton->fn->setPosition(Main_SloganButton, 10, 210);
    Main_SloganButton->fn->setSize(Main_SloganButton, 464, 50);
    Main_SloganButton->fn->setString(Main_SloganButton, (leString*)&string_DrawRLE);
    Main_SloganButton->fn->setReleasedEventCallback(Main_SloganButton, event_Main_SloganButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Main_SloganButton);

    Main_LogoButton = leButtonWidget_New();
    Main_LogoButton->fn->setPosition(Main_LogoButton, 71, 60);
    Main_LogoButton->fn->setSize(Main_LogoButton, 150, 130);
    Main_LogoButton->fn->setBackgroundType(Main_LogoButton, LE_WIDGET_BACKGROUND_NONE);
    Main_LogoButton->fn->setBorderType(Main_LogoButton, LE_WIDGET_BORDER_NONE);
    Main_LogoButton->fn->setPressedImage(Main_LogoButton, (leImage*)&MHGS_logo_small_compressed);
    Main_LogoButton->fn->setReleasedImage(Main_LogoButton, (leImage*)&MHGS_logo_small_compressed);
    Main_LogoButton->fn->setPressedOffset(Main_LogoButton, 0);
    Main_LogoButton->fn->setReleasedEventCallback(Main_LogoButton, event_Main_LogoButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Main_LogoButton);

    Main_ImageTypeLabelWidget = leLabelWidget_New();
    Main_ImageTypeLabelWidget->fn->setPosition(Main_ImageTypeLabelWidget, 236, 100);
    Main_ImageTypeLabelWidget->fn->setSize(Main_ImageTypeLabelWidget, 215, 51);
    Main_ImageTypeLabelWidget->fn->setBackgroundType(Main_ImageTypeLabelWidget, LE_WIDGET_BACKGROUND_NONE);
    Main_ImageTypeLabelWidget->fn->setHAlignment(Main_ImageTypeLabelWidget, LE_HALIGN_CENTER);
    Main_ImageTypeLabelWidget->fn->setString(Main_ImageTypeLabelWidget, (leString*)&string_ImageIsPaletteCompressed);
    root0->fn->addChild(root0, (leWidget*)Main_ImageTypeLabelWidget);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Main(void)
{
    root0->fn->setSize(root0, root0->parent->rect.width, root0->parent->rect.height);
}

void screenHide_Main(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Main_Layer0_FillPanel = NULL;
    Main_TitleLabel = NULL;
    Main_SloganButton = NULL;
    Main_LogoButton = NULL;
    Main_ImageTypeLabelWidget = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Main(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Main(uint32_t lyrIdx)
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

