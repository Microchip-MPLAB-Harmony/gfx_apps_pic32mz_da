#include "gfx/legato/generated/screen/le_gen_screen_Splash.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;

leWidget* Splash_Layer_0_FillPanel;
leImageWidget* Splash_ImageWidget0;
leImageWidget* Splash_ImageWidget1;

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
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Splash_Layer_0_FillPanel = leWidget_New();
    Splash_Layer_0_FillPanel->fn->setPosition(Splash_Layer_0_FillPanel, 0, 0);
    Splash_Layer_0_FillPanel->fn->setSize(Splash_Layer_0_FillPanel, 800, 480);
    Splash_Layer_0_FillPanel->fn->setScheme(Splash_Layer_0_FillPanel, &AriaImport_LayerFillScheme);
    root0->fn->addChild(root0, (leWidget*)Splash_Layer_0_FillPanel);

    Splash_ImageWidget0 = leImageWidget_New();
    Splash_ImageWidget0->fn->setPosition(Splash_ImageWidget0, 216, 111);
    Splash_ImageWidget0->fn->setSize(Splash_ImageWidget0, 339, 241);
    Splash_ImageWidget0->fn->setBackgroundType(Splash_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Splash_ImageWidget0->fn->setBorderType(Splash_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Splash_ImageWidget0->fn->setImage(Splash_ImageWidget0, (leImage*)&MHGC_200x200_white);
    root0->fn->addChild(root0, (leWidget*)Splash_ImageWidget0);

    Splash_ImageWidget1 = leImageWidget_New();
    Splash_ImageWidget1->fn->setPosition(Splash_ImageWidget1, 20, 20);
    Splash_ImageWidget1->fn->setSize(Splash_ImageWidget1, 197, 42);
    Splash_ImageWidget1->fn->setBackgroundType(Splash_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    Splash_ImageWidget1->fn->setBorderType(Splash_ImageWidget1, LE_WIDGET_BORDER_NONE);
    Splash_ImageWidget1->fn->setImage(Splash_ImageWidget1, (leImage*)&Microchip_logo_150x30);
    root0->fn->addChild(root0, (leWidget*)Splash_ImageWidget1);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_INDEX_8);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 300, 350);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_INDEX_8);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 400, 50);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_INDEX_8);

    Splash_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Splash(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);
    root2->fn->setSize(root2, root2->rect.width, root2->rect.height);

    Splash_OnUpdate(); // raise event
}

void screenHide_Splash(void)
{
    Splash_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Splash_Layer_0_FillPanel = NULL;
    Splash_ImageWidget0 = NULL;
    Splash_ImageWidget1 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;


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

