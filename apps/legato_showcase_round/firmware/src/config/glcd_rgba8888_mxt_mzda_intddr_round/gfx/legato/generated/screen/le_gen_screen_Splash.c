#include "gfx/legato/generated/screen/le_gen_screen_Splash.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Splash_PanelWidget0;
leImageWidget* Splash_ImageWidget0;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Splash(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Splash(void)
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

    Splash_PanelWidget0 = leWidget_New();
    Splash_PanelWidget0->fn->setPosition(Splash_PanelWidget0, 0, 0);
    Splash_PanelWidget0->fn->setSize(Splash_PanelWidget0, 432, 432);
    Splash_PanelWidget0->fn->setScheme(Splash_PanelWidget0, &WhiteBackScheme);
    root0->fn->addChild(root0, (leWidget*)Splash_PanelWidget0);

    Splash_ImageWidget0 = leImageWidget_New();
    Splash_ImageWidget0->fn->setPosition(Splash_ImageWidget0, 115, 116);
    Splash_ImageWidget0->fn->setSize(Splash_ImageWidget0, 206, 198);
    Splash_ImageWidget0->fn->setBackgroundType(Splash_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Splash_ImageWidget0->fn->setBorderType(Splash_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Splash_ImageWidget0->fn->setImage(Splash_ImageWidget0, (leImage*)&MHGC_200x200_white);
    root0->fn->addChild(root0, (leWidget*)Splash_ImageWidget0);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    Splash_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Splash(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);

    Splash_OnUpdate(); // raise event
}

void screenHide_Splash(void)
{
    Splash_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Splash_PanelWidget0 = NULL;
    Splash_ImageWidget0 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Splash(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Splash(uint32_t lyrIdx)
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

