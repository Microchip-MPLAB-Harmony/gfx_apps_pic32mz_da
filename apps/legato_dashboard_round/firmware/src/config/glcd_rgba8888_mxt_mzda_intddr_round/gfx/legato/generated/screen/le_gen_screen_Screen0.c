#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;

leImageWidget* Screen0_ImageWidget0;
leButtonWidget* Screen0_RPMButtonWidget;
leImageWidget* Screen0_ImageWidget1;
leButtonWidget* Screen0_MPHButtonWidget;
leWidget* Screen0_PanelWidget0;
leImageWidget* Screen0_ImageWidget4;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen0(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen0(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 432, 432);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_ImageWidget0 = leImageWidget_New();
    Screen0_ImageWidget0->fn->setPosition(Screen0_ImageWidget0, 0, 0);
    Screen0_ImageWidget0->fn->setSize(Screen0_ImageWidget0, 432, 432);
    Screen0_ImageWidget0->fn->setEnabled(Screen0_ImageWidget0, LE_FALSE);
    Screen0_ImageWidget0->fn->setBackgroundType(Screen0_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget0->fn->setBorderType(Screen0_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget0->fn->setImage(Screen0_ImageWidget0, (leImage*)&rpm_background);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget0);

    Screen0_RPMButtonWidget = leButtonWidget_New();
    Screen0_RPMButtonWidget->fn->setPosition(Screen0_RPMButtonWidget, 176, 182);
    Screen0_RPMButtonWidget->fn->setSize(Screen0_RPMButtonWidget, 80, 80);
    Screen0_RPMButtonWidget->fn->setBackgroundType(Screen0_RPMButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    Screen0_RPMButtonWidget->fn->setBorderType(Screen0_RPMButtonWidget, LE_WIDGET_BORDER_NONE);
    Screen0_RPMButtonWidget->fn->setPressedImage(Screen0_RPMButtonWidget, (leImage*)&mchp_logo2);
    Screen0_RPMButtonWidget->fn->setReleasedImage(Screen0_RPMButtonWidget, (leImage*)&mchp_logo2);
    Screen0_RPMButtonWidget->fn->setPressedOffset(Screen0_RPMButtonWidget, 0);
    Screen0_RPMButtonWidget->fn->setReleasedEventCallback(Screen0_RPMButtonWidget, event_Screen0_RPMButtonWidget_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Screen0_RPMButtonWidget);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 432, 432);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_ImageWidget1 = leImageWidget_New();
    Screen0_ImageWidget1->fn->setPosition(Screen0_ImageWidget1, 0, 0);
    Screen0_ImageWidget1->fn->setSize(Screen0_ImageWidget1, 432, 432);
    Screen0_ImageWidget1->fn->setEnabled(Screen0_ImageWidget1, LE_FALSE);
    Screen0_ImageWidget1->fn->setBackgroundType(Screen0_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget1->fn->setBorderType(Screen0_ImageWidget1, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget1->fn->setImage(Screen0_ImageWidget1, (leImage*)&speedo_background);
    root1->fn->addChild(root1, (leWidget*)Screen0_ImageWidget1);

    Screen0_MPHButtonWidget = leButtonWidget_New();
    Screen0_MPHButtonWidget->fn->setPosition(Screen0_MPHButtonWidget, 176, 182);
    Screen0_MPHButtonWidget->fn->setSize(Screen0_MPHButtonWidget, 80, 80);
    Screen0_MPHButtonWidget->fn->setBackgroundType(Screen0_MPHButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    Screen0_MPHButtonWidget->fn->setBorderType(Screen0_MPHButtonWidget, LE_WIDGET_BORDER_NONE);
    Screen0_MPHButtonWidget->fn->setPressedImage(Screen0_MPHButtonWidget, (leImage*)&mchp_logo2);
    Screen0_MPHButtonWidget->fn->setReleasedImage(Screen0_MPHButtonWidget, (leImage*)&mchp_logo2);
    Screen0_MPHButtonWidget->fn->setPressedOffset(Screen0_MPHButtonWidget, 0);
    Screen0_MPHButtonWidget->fn->setReleasedEventCallback(Screen0_MPHButtonWidget, event_Screen0_MPHButtonWidget_OnReleased);
    root1->fn->addChild(root1, (leWidget*)Screen0_MPHButtonWidget);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 432, 432);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget0 = leWidget_New();
    Screen0_PanelWidget0->fn->setPosition(Screen0_PanelWidget0, 0, 0);
    Screen0_PanelWidget0->fn->setSize(Screen0_PanelWidget0, 432, 432);
    Screen0_PanelWidget0->fn->setEnabled(Screen0_PanelWidget0, LE_FALSE);
    Screen0_PanelWidget0->fn->setScheme(Screen0_PanelWidget0, &WhiteBaseScheme);
    root2->fn->addChild(root2, (leWidget*)Screen0_PanelWidget0);

    Screen0_ImageWidget4 = leImageWidget_New();
    Screen0_ImageWidget4->fn->setPosition(Screen0_ImageWidget4, 0, 0);
    Screen0_ImageWidget4->fn->setSize(Screen0_ImageWidget4, 432, 432);
    Screen0_ImageWidget4->fn->setEnabled(Screen0_ImageWidget4, LE_FALSE);
    Screen0_ImageWidget4->fn->setBackgroundType(Screen0_ImageWidget4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget4->fn->setBorderType(Screen0_ImageWidget4, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget4->fn->setImage(Screen0_ImageWidget4, (leImage*)&MHGC_200x200_white);
    root2->fn->addChild(root2, (leWidget*)Screen0_ImageWidget4);

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_RGBA_8888);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);
    root2->fn->setSize(root2, root2->rect.width, root2->rect.height);

    Screen0_OnUpdate(); // raise event
}

void screenHide_Screen0(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_ImageWidget0 = NULL;
    Screen0_RPMButtonWidget = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_ImageWidget1 = NULL;
    Screen0_MPHButtonWidget = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    Screen0_PanelWidget0 = NULL;
    Screen0_ImageWidget4 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen0(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        case 1:
        {
            return root1;
        }
        case 2:
        {
            return root2;
        }
        default:
        {
            return NULL;
        }
    }
}

