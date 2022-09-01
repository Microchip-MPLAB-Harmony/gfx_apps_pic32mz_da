#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;

leImageWidget* Screen0_ImageWidget0;
leWidget* Screen0_PanelWidget0;
leWidget* Screen0_NeedlePanel;
leLabelWidget* Screen0_GestureLabelWidget;
leWidget* Screen0_ButtonsPanel;
leLabelWidget* Screen0_UnlockLabelWidget;
leWidget* Screen0_PercentDemoPanel;
leWidget* Screen0_TimerDemoPanel;
leWidget* Screen0_TempDemoPanel;
leButtonWidget* Screen0_CenterButton;
leImageWidget* Screen0_Image_n0;
leImageWidget* Screen0_Image_n1;
leImageWidget* Screen0_Image_n2;
leImageWidget* Screen0_Image_n3;
leImageWidget* Screen0_Image_n4;
leImageWidget* Screen0_Image_n5;
leImageWidget* Screen0_Image_n6;
leImageWidget* Screen0_Image_n7;
leImageWidget* Screen0_Image_n8;
leImageWidget* Screen0_Image_n9;
leImageWidget* Screen0_Image_n10;
leImageWidget* Screen0_Image_n11;
leImageWidget* Screen0_Image_n12;
leImageWidget* Screen0_Image_n13;
leImageWidget* Screen0_Image_n14;
leImageWidget* Screen0_Image_n15;
leImageWidget* Screen0_Image_n16;
leImageWidget* Screen0_Image_n17;
leImageWidget* Screen0_Image_n18;
leImageWidget* Screen0_Image_n19;
leImageWidget* Screen0_Image_n20;
leImageWidget* Screen0_Image_n21;
leImageWidget* Screen0_Image_n22;
leImageWidget* Screen0_Image_n23;
leImageWidget* Screen0_Image_n24;
leImageWidget* Screen0_Image_n25;
leImageWidget* Screen0_Image_n26;
leImageWidget* Screen0_Image_n27;
leImageWidget* Screen0_Image_n28;
leImageWidget* Screen0_Image_n29;
leImageWidget* Screen0_Image_n30;
leImageWidget* Screen0_Image_n31;
leImageWidget* Screen0_Image_n32;
leImageWidget* Screen0_Image_n33;
leImageWidget* Screen0_Image_n34;
leImageWidget* Screen0_Image_n35;
leImageWidget* Screen0_Image_n36;
leImageWidget* Screen0_Image_n37;
leImageWidget* Screen0_Image_n38;
leImageWidget* Screen0_Image_n39;
leImageWidget* Screen0_Image_n40;
leImageWidget* Screen0_Image_n41;
leImageWidget* Screen0_Image_n42;
leImageWidget* Screen0_Image_n43;
leImageWidget* Screen0_Image_n44;
leImageWidget* Screen0_Image_n45;
leImageWidget* Screen0_Image_n46;
leImageWidget* Screen0_Image_n47;
leImageWidget* Screen0_Image_n48;
leImageWidget* Screen0_Image_n49;
leImageWidget* Screen0_Image_n50;
leImageWidget* Screen0_Image_n51;
leImageWidget* Screen0_Image_n52;
leImageWidget* Screen0_Image_n53;
leImageWidget* Screen0_Image_n54;
leImageWidget* Screen0_Image_n55;
leImageWidget* Screen0_Image_n56;
leImageWidget* Screen0_Image_n57;
leImageWidget* Screen0_Image_n58;
leImageWidget* Screen0_Image_n59;
leImageWidget* Screen0_Image_n60;
leImageWidget* Screen0_Image_n61;
leImageWidget* Screen0_Image_n62;
leImageWidget* Screen0_Image_n63;
leImageWidget* Screen0_Image_n64;
leImageWidget* Screen0_Image_n65;
leImageWidget* Screen0_Image_n66;
leImageWidget* Screen0_Image_n67;
leImageWidget* Screen0_Image_n68;
leImageWidget* Screen0_Image_n69;
leImageWidget* Screen0_Image_n70;
leImageWidget* Screen0_Image_n71;
leImageWidget* Screen0_Image_n72;
leImageWidget* Screen0_Image_n73;
leImageWidget* Screen0_Image_n74;
leImageWidget* Screen0_Image_n75;
leImageWidget* Screen0_Image_n76;
leImageWidget* Screen0_Image_n92;
leImageWidget* Screen0_Image_n91;
leImageWidget* Screen0_Image_n90;
leImageWidget* Screen0_Image_n89;
leImageWidget* Screen0_Image_n88;
leImageWidget* Screen0_Image_n87;
leImageWidget* Screen0_Image_n86;
leImageWidget* Screen0_Image_n85;
leImageWidget* Screen0_Image_n84;
leImageWidget* Screen0_Image_n83;
leImageWidget* Screen0_Image_n82;
leImageWidget* Screen0_Image_n81;
leImageWidget* Screen0_Image_n80;
leImageWidget* Screen0_Image_n79;
leImageWidget* Screen0_Image_n78;
leImageWidget* Screen0_Image_n77;
leImageWidget* Screen0_MchpLogoImage;
leButtonWidget* Screen0_HomeButton;
leButtonWidget* Screen0_SettingsButton;
leButtonWidget* Screen0_VolumeButton;
leButtonWidget* Screen0_EcoButton;
leButtonWidget* Screen0_ThermButton;
leButtonWidget* Screen0_LightButton;
leButtonWidget* Screen0_FanButton;
leButtonWidget* Screen0_ClockButton;
leImageSequenceWidget* Screen0_HomeImageSequence;
leImageSequenceWidget* Screen0_SettingsImageSequence;
leLabelWidget* Screen0_ReverseTagLabel;
leImageSequenceWidget* Screen0_VolumeImageSequence;
leImageSequenceWidget* Screen0_EcoImageSequence;
leImageSequenceWidget* Screen0_ThermImageSequence;
leImageSequenceWidget* Screen0_LightImageSequence;
leImageSequenceWidget* Screen0_FanImageSequence;
leImageSequenceWidget* Screen0_ClockImageSequence;
leLabelWidget* Screen0_PercentValueLabel;
leImageWidget* Screen0_PercentImageWidget;
leLabelWidget* Screen0_PercentSymbol;
leButtonWidget* Screen0_TimerStartStop;
leButtonWidget* Screen0_TimerMinsButton;
leButtonWidget* Screen0_TimerSecsButton;
leLabelWidget* Screen0_TimerMinsTag;
leLabelWidget* Screen0_TimerSecsTag;
leImageWidget* Screen0_TimerStartStopImage;
leLabelWidget* Screen0_TempLabel;
leButtonWidget* Screen0_FahrCelsButton;
leImageWidget* Screen0_ImageWidget1;
leLabelWidget* Screen0_TempUnitsLabel;

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
    Screen0_ImageWidget0->fn->setImage(Screen0_ImageWidget0, (leImage*)&RoundBackground_base_432_gray);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget0);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 432, 432);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget0 = leWidget_New();
    Screen0_PanelWidget0->fn->setPosition(Screen0_PanelWidget0, 0, 0);
    Screen0_PanelWidget0->fn->setSize(Screen0_PanelWidget0, 432, 432);
    Screen0_PanelWidget0->fn->setScheme(Screen0_PanelWidget0, &ClearScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_PanelWidget0);

    Screen0_NeedlePanel = leWidget_New();
    Screen0_NeedlePanel->fn->setPosition(Screen0_NeedlePanel, 0, 0);
    Screen0_NeedlePanel->fn->setSize(Screen0_NeedlePanel, 432, 432);
    Screen0_NeedlePanel->fn->setEnabled(Screen0_NeedlePanel, LE_FALSE);
    Screen0_NeedlePanel->fn->setScheme(Screen0_NeedlePanel, &ClearScheme);
    Screen0_NeedlePanel->fn->setBackgroundType(Screen0_NeedlePanel, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_NeedlePanel);

    Screen0_Image_n0 = leImageWidget_New();
    Screen0_Image_n0->fn->setPosition(Screen0_Image_n0, 212, 55);
    Screen0_Image_n0->fn->setSize(Screen0_Image_n0, 5, 27);
    Screen0_Image_n0->fn->setScheme(Screen0_Image_n0, &ClearScheme);
    Screen0_Image_n0->fn->setBackgroundType(Screen0_Image_n0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n0->fn->setBorderType(Screen0_Image_n0, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n0->fn->setImage(Screen0_Image_n0, (leImage*)&n0);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n0);

    Screen0_Image_n1 = leImageWidget_New();
    Screen0_Image_n1->fn->setPosition(Screen0_Image_n1, 221, 56);
    Screen0_Image_n1->fn->setSize(Screen0_Image_n1, 6, 26);
    Screen0_Image_n1->fn->setScheme(Screen0_Image_n1, &ClearScheme);
    Screen0_Image_n1->fn->setBackgroundType(Screen0_Image_n1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n1->fn->setBorderType(Screen0_Image_n1, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n1->fn->setImage(Screen0_Image_n1, (leImage*)&n1);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n1);

    Screen0_Image_n2 = leImageWidget_New();
    Screen0_Image_n2->fn->setPosition(Screen0_Image_n2, 230, 57);
    Screen0_Image_n2->fn->setSize(Screen0_Image_n2, 7, 27);
    Screen0_Image_n2->fn->setScheme(Screen0_Image_n2, &ClearScheme);
    Screen0_Image_n2->fn->setBackgroundType(Screen0_Image_n2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n2->fn->setBorderType(Screen0_Image_n2, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n2->fn->setImage(Screen0_Image_n2, (leImage*)&n2);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n2);

    Screen0_Image_n3 = leImageWidget_New();
    Screen0_Image_n3->fn->setPosition(Screen0_Image_n3, 239, 59);
    Screen0_Image_n3->fn->setSize(Screen0_Image_n3, 9, 26);
    Screen0_Image_n3->fn->setScheme(Screen0_Image_n3, &ClearScheme);
    Screen0_Image_n3->fn->setBackgroundType(Screen0_Image_n3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n3->fn->setBorderType(Screen0_Image_n3, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n3->fn->setImage(Screen0_Image_n3, (leImage*)&n3);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n3);

    Screen0_Image_n4 = leImageWidget_New();
    Screen0_Image_n4->fn->setPosition(Screen0_Image_n4, 248, 61);
    Screen0_Image_n4->fn->setSize(Screen0_Image_n4, 10, 26);
    Screen0_Image_n4->fn->setScheme(Screen0_Image_n4, &ClearScheme);
    Screen0_Image_n4->fn->setBackgroundType(Screen0_Image_n4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n4->fn->setBorderType(Screen0_Image_n4, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n4->fn->setImage(Screen0_Image_n4, (leImage*)&n4);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n4);

    Screen0_Image_n5 = leImageWidget_New();
    Screen0_Image_n5->fn->setPosition(Screen0_Image_n5, 256, 64);
    Screen0_Image_n5->fn->setSize(Screen0_Image_n5, 12, 26);
    Screen0_Image_n5->fn->setScheme(Screen0_Image_n5, &ClearScheme);
    Screen0_Image_n5->fn->setBackgroundType(Screen0_Image_n5, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n5->fn->setBorderType(Screen0_Image_n5, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n5->fn->setImage(Screen0_Image_n5, (leImage*)&n5);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n5);

    Screen0_Image_n6 = leImageWidget_New();
    Screen0_Image_n6->fn->setPosition(Screen0_Image_n6, 265, 68);
    Screen0_Image_n6->fn->setSize(Screen0_Image_n6, 13, 26);
    Screen0_Image_n6->fn->setScheme(Screen0_Image_n6, &ClearScheme);
    Screen0_Image_n6->fn->setBackgroundType(Screen0_Image_n6, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n6->fn->setBorderType(Screen0_Image_n6, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n6->fn->setImage(Screen0_Image_n6, (leImage*)&n6);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n6);

    Screen0_Image_n7 = leImageWidget_New();
    Screen0_Image_n7->fn->setPosition(Screen0_Image_n7, 273, 73);
    Screen0_Image_n7->fn->setSize(Screen0_Image_n7, 15, 24);
    Screen0_Image_n7->fn->setScheme(Screen0_Image_n7, &ClearScheme);
    Screen0_Image_n7->fn->setBackgroundType(Screen0_Image_n7, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n7->fn->setBorderType(Screen0_Image_n7, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n7->fn->setImage(Screen0_Image_n7, (leImage*)&n7);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n7);

    Screen0_Image_n8 = leImageWidget_New();
    Screen0_Image_n8->fn->setPosition(Screen0_Image_n8, 281, 78);
    Screen0_Image_n8->fn->setSize(Screen0_Image_n8, 16, 24);
    Screen0_Image_n8->fn->setScheme(Screen0_Image_n8, &ClearScheme);
    Screen0_Image_n8->fn->setBackgroundType(Screen0_Image_n8, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n8->fn->setBorderType(Screen0_Image_n8, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n8->fn->setImage(Screen0_Image_n8, (leImage*)&n8);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n8);

    Screen0_Image_n9 = leImageWidget_New();
    Screen0_Image_n9->fn->setPosition(Screen0_Image_n9, 289, 84);
    Screen0_Image_n9->fn->setSize(Screen0_Image_n9, 17, 23);
    Screen0_Image_n9->fn->setScheme(Screen0_Image_n9, &ClearScheme);
    Screen0_Image_n9->fn->setBackgroundType(Screen0_Image_n9, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n9->fn->setBorderType(Screen0_Image_n9, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n9->fn->setImage(Screen0_Image_n9, (leImage*)&n9);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n9);

    Screen0_Image_n10 = leImageWidget_New();
    Screen0_Image_n10->fn->setPosition(Screen0_Image_n10, 296, 90);
    Screen0_Image_n10->fn->setSize(Screen0_Image_n10, 18, 22);
    Screen0_Image_n10->fn->setScheme(Screen0_Image_n10, &ClearScheme);
    Screen0_Image_n10->fn->setBackgroundType(Screen0_Image_n10, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n10->fn->setBorderType(Screen0_Image_n10, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n10->fn->setImage(Screen0_Image_n10, (leImage*)&n10);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n10);

    Screen0_Image_n11 = leImageWidget_New();
    Screen0_Image_n11->fn->setPosition(Screen0_Image_n11, 303, 97);
    Screen0_Image_n11->fn->setSize(Screen0_Image_n11, 19, 21);
    Screen0_Image_n11->fn->setScheme(Screen0_Image_n11, &ClearScheme);
    Screen0_Image_n11->fn->setBackgroundType(Screen0_Image_n11, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n11->fn->setBorderType(Screen0_Image_n11, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n11->fn->setImage(Screen0_Image_n11, (leImage*)&n11);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n11);

    Screen0_Image_n12 = leImageWidget_New();
    Screen0_Image_n12->fn->setPosition(Screen0_Image_n12, 309, 105);
    Screen0_Image_n12->fn->setSize(Screen0_Image_n12, 21, 19);
    Screen0_Image_n12->fn->setScheme(Screen0_Image_n12, &ClearScheme);
    Screen0_Image_n12->fn->setBackgroundType(Screen0_Image_n12, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n12->fn->setBorderType(Screen0_Image_n12, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n12->fn->setImage(Screen0_Image_n12, (leImage*)&n12);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n12);

    Screen0_Image_n13 = leImageWidget_New();
    Screen0_Image_n13->fn->setPosition(Screen0_Image_n13, 316, 113);
    Screen0_Image_n13->fn->setSize(Screen0_Image_n13, 21, 18);
    Screen0_Image_n13->fn->setScheme(Screen0_Image_n13, &ClearScheme);
    Screen0_Image_n13->fn->setBackgroundType(Screen0_Image_n13, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n13->fn->setBorderType(Screen0_Image_n13, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n13->fn->setImage(Screen0_Image_n13, (leImage*)&n13);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n13);

    Screen0_Image_n14 = leImageWidget_New();
    Screen0_Image_n14->fn->setPosition(Screen0_Image_n14, 322, 121);
    Screen0_Image_n14->fn->setSize(Screen0_Image_n14, 21, 17);
    Screen0_Image_n14->fn->setScheme(Screen0_Image_n14, &ClearScheme);
    Screen0_Image_n14->fn->setBackgroundType(Screen0_Image_n14, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n14->fn->setBorderType(Screen0_Image_n14, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n14->fn->setImage(Screen0_Image_n14, (leImage*)&n14);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n14);

    Screen0_Image_n15 = leImageWidget_New();
    Screen0_Image_n15->fn->setPosition(Screen0_Image_n15, 327, 130);
    Screen0_Image_n15->fn->setSize(Screen0_Image_n15, 22, 16);
    Screen0_Image_n15->fn->setScheme(Screen0_Image_n15, &ClearScheme);
    Screen0_Image_n15->fn->setBackgroundType(Screen0_Image_n15, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n15->fn->setBorderType(Screen0_Image_n15, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n15->fn->setImage(Screen0_Image_n15, (leImage*)&n15);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n15);

    Screen0_Image_n16 = leImageWidget_New();
    Screen0_Image_n16->fn->setPosition(Screen0_Image_n16, 331, 139);
    Screen0_Image_n16->fn->setSize(Screen0_Image_n16, 23, 15);
    Screen0_Image_n16->fn->setScheme(Screen0_Image_n16, &ClearScheme);
    Screen0_Image_n16->fn->setBackgroundType(Screen0_Image_n16, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n16->fn->setBorderType(Screen0_Image_n16, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n16->fn->setImage(Screen0_Image_n16, (leImage*)&n16);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n16);

    Screen0_Image_n17 = leImageWidget_New();
    Screen0_Image_n17->fn->setPosition(Screen0_Image_n17, 336, 148);
    Screen0_Image_n17->fn->setSize(Screen0_Image_n17, 23, 14);
    Screen0_Image_n17->fn->setScheme(Screen0_Image_n17, &ClearScheme);
    Screen0_Image_n17->fn->setBackgroundType(Screen0_Image_n17, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n17->fn->setBorderType(Screen0_Image_n17, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n17->fn->setImage(Screen0_Image_n17, (leImage*)&n17);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n17);

    Screen0_Image_n18 = leImageWidget_New();
    Screen0_Image_n18->fn->setPosition(Screen0_Image_n18, 339, 158);
    Screen0_Image_n18->fn->setSize(Screen0_Image_n18, 24, 12);
    Screen0_Image_n18->fn->setScheme(Screen0_Image_n18, &ClearScheme);
    Screen0_Image_n18->fn->setBackgroundType(Screen0_Image_n18, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n18->fn->setBorderType(Screen0_Image_n18, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n18->fn->setImage(Screen0_Image_n18, (leImage*)&n18);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n18);

    Screen0_Image_n19 = leImageWidget_New();
    Screen0_Image_n19->fn->setPosition(Screen0_Image_n19, 342, 168);
    Screen0_Image_n19->fn->setSize(Screen0_Image_n19, 24, 11);
    Screen0_Image_n19->fn->setScheme(Screen0_Image_n19, &ClearScheme);
    Screen0_Image_n19->fn->setBackgroundType(Screen0_Image_n19, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n19->fn->setBorderType(Screen0_Image_n19, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n19->fn->setImage(Screen0_Image_n19, (leImage*)&n19);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n19);

    Screen0_Image_n20 = leImageWidget_New();
    Screen0_Image_n20->fn->setPosition(Screen0_Image_n20, 344, 178);
    Screen0_Image_n20->fn->setSize(Screen0_Image_n20, 25, 10);
    Screen0_Image_n20->fn->setScheme(Screen0_Image_n20, &ClearScheme);
    Screen0_Image_n20->fn->setBackgroundType(Screen0_Image_n20, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n20->fn->setBorderType(Screen0_Image_n20, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n20->fn->setImage(Screen0_Image_n20, (leImage*)&n20);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n20);

    Screen0_Image_n21 = leImageWidget_New();
    Screen0_Image_n21->fn->setPosition(Screen0_Image_n21, 346, 189);
    Screen0_Image_n21->fn->setSize(Screen0_Image_n21, 25, 7);
    Screen0_Image_n21->fn->setScheme(Screen0_Image_n21, &ClearScheme);
    Screen0_Image_n21->fn->setBackgroundType(Screen0_Image_n21, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n21->fn->setBorderType(Screen0_Image_n21, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n21->fn->setImage(Screen0_Image_n21, (leImage*)&n21);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n21);

    Screen0_Image_n22 = leImageWidget_New();
    Screen0_Image_n22->fn->setPosition(Screen0_Image_n22, 347, 199);
    Screen0_Image_n22->fn->setSize(Screen0_Image_n22, 25, 6);
    Screen0_Image_n22->fn->setScheme(Screen0_Image_n22, &ClearScheme);
    Screen0_Image_n22->fn->setBackgroundType(Screen0_Image_n22, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n22->fn->setBorderType(Screen0_Image_n22, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n22->fn->setImage(Screen0_Image_n22, (leImage*)&n22);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n22);

    Screen0_Image_n23 = leImageWidget_New();
    Screen0_Image_n23->fn->setPosition(Screen0_Image_n23, 348, 209);
    Screen0_Image_n23->fn->setSize(Screen0_Image_n23, 25, 5);
    Screen0_Image_n23->fn->setScheme(Screen0_Image_n23, &ClearScheme);
    Screen0_Image_n23->fn->setBackgroundType(Screen0_Image_n23, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n23->fn->setBorderType(Screen0_Image_n23, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n23->fn->setImage(Screen0_Image_n23, (leImage*)&n23);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n23);

    Screen0_Image_n24 = leImageWidget_New();
    Screen0_Image_n24->fn->setPosition(Screen0_Image_n24, 347, 219);
    Screen0_Image_n24->fn->setSize(Screen0_Image_n24, 26, 4);
    Screen0_Image_n24->fn->setScheme(Screen0_Image_n24, &ClearScheme);
    Screen0_Image_n24->fn->setBackgroundType(Screen0_Image_n24, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n24->fn->setBorderType(Screen0_Image_n24, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n24->fn->setImage(Screen0_Image_n24, (leImage*)&n24);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n24);

    Screen0_Image_n25 = leImageWidget_New();
    Screen0_Image_n25->fn->setPosition(Screen0_Image_n25, 346, 228);
    Screen0_Image_n25->fn->setSize(Screen0_Image_n25, 26, 6);
    Screen0_Image_n25->fn->setScheme(Screen0_Image_n25, &ClearScheme);
    Screen0_Image_n25->fn->setBackgroundType(Screen0_Image_n25, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n25->fn->setBorderType(Screen0_Image_n25, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n25->fn->setImage(Screen0_Image_n25, (leImage*)&n25);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n25);

    Screen0_Image_n26 = leImageWidget_New();
    Screen0_Image_n26->fn->setPosition(Screen0_Image_n26, 344, 236);
    Screen0_Image_n26->fn->setSize(Screen0_Image_n26, 27, 8);
    Screen0_Image_n26->fn->setScheme(Screen0_Image_n26, &ClearScheme);
    Screen0_Image_n26->fn->setBackgroundType(Screen0_Image_n26, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n26->fn->setBorderType(Screen0_Image_n26, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n26->fn->setImage(Screen0_Image_n26, (leImage*)&n26);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n26);

    Screen0_Image_n27 = leImageWidget_New();
    Screen0_Image_n27->fn->setPosition(Screen0_Image_n27, 342, 245);
    Screen0_Image_n27->fn->setSize(Screen0_Image_n27, 26, 9);
    Screen0_Image_n27->fn->setScheme(Screen0_Image_n27, &ClearScheme);
    Screen0_Image_n27->fn->setBackgroundType(Screen0_Image_n27, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n27->fn->setBorderType(Screen0_Image_n27, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n27->fn->setImage(Screen0_Image_n27, (leImage*)&n27);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n27);

    Screen0_Image_n28 = leImageWidget_New();
    Screen0_Image_n28->fn->setPosition(Screen0_Image_n28, 339, 253);
    Screen0_Image_n28->fn->setSize(Screen0_Image_n28, 27, 11);
    Screen0_Image_n28->fn->setScheme(Screen0_Image_n28, &ClearScheme);
    Screen0_Image_n28->fn->setBackgroundType(Screen0_Image_n28, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n28->fn->setBorderType(Screen0_Image_n28, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n28->fn->setImage(Screen0_Image_n28, (leImage*)&n28);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n28);

    Screen0_Image_n29 = leImageWidget_New();
    Screen0_Image_n29->fn->setPosition(Screen0_Image_n29, 336, 262);
    Screen0_Image_n29->fn->setSize(Screen0_Image_n29, 26, 12);
    Screen0_Image_n29->fn->setScheme(Screen0_Image_n29, &ClearScheme);
    Screen0_Image_n29->fn->setBackgroundType(Screen0_Image_n29, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n29->fn->setBorderType(Screen0_Image_n29, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n29->fn->setImage(Screen0_Image_n29, (leImage*)&n29);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n29);

    Screen0_Image_n30 = leImageWidget_New();
    Screen0_Image_n30->fn->setPosition(Screen0_Image_n30, 332, 269);
    Screen0_Image_n30->fn->setSize(Screen0_Image_n30, 26, 15);
    Screen0_Image_n30->fn->setScheme(Screen0_Image_n30, &ClearScheme);
    Screen0_Image_n30->fn->setBackgroundType(Screen0_Image_n30, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n30->fn->setBorderType(Screen0_Image_n30, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n30->fn->setImage(Screen0_Image_n30, (leImage*)&n30);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n30);

    Screen0_Image_n31 = leImageWidget_New();
    Screen0_Image_n31->fn->setPosition(Screen0_Image_n31, 328, 277);
    Screen0_Image_n31->fn->setSize(Screen0_Image_n31, 26, 16);
    Screen0_Image_n31->fn->setScheme(Screen0_Image_n31, &ClearScheme);
    Screen0_Image_n31->fn->setBackgroundType(Screen0_Image_n31, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n31->fn->setBorderType(Screen0_Image_n31, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n31->fn->setImage(Screen0_Image_n31, (leImage*)&n31);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n31);

    Screen0_Image_n32 = leImageWidget_New();
    Screen0_Image_n32->fn->setPosition(Screen0_Image_n32, 324, 285);
    Screen0_Image_n32->fn->setSize(Screen0_Image_n32, 24, 17);
    Screen0_Image_n32->fn->setScheme(Screen0_Image_n32, &ClearScheme);
    Screen0_Image_n32->fn->setBackgroundType(Screen0_Image_n32, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n32->fn->setBorderType(Screen0_Image_n32, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n32->fn->setImage(Screen0_Image_n32, (leImage*)&n32);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n32);

    Screen0_Image_n33 = leImageWidget_New();
    Screen0_Image_n33->fn->setPosition(Screen0_Image_n33, 319, 292);
    Screen0_Image_n33->fn->setSize(Screen0_Image_n33, 23, 19);
    Screen0_Image_n33->fn->setScheme(Screen0_Image_n33, &ClearScheme);
    Screen0_Image_n33->fn->setBackgroundType(Screen0_Image_n33, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n33->fn->setBorderType(Screen0_Image_n33, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n33->fn->setImage(Screen0_Image_n33, (leImage*)&n33);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n33);

    Screen0_Image_n34 = leImageWidget_New();
    Screen0_Image_n34->fn->setPosition(Screen0_Image_n34, 313, 300);
    Screen0_Image_n34->fn->setSize(Screen0_Image_n34, 23, 20);
    Screen0_Image_n34->fn->setScheme(Screen0_Image_n34, &ClearScheme);
    Screen0_Image_n34->fn->setBackgroundType(Screen0_Image_n34, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n34->fn->setBorderType(Screen0_Image_n34, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n34->fn->setImage(Screen0_Image_n34, (leImage*)&n34);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n34);

    Screen0_Image_n35 = leImageWidget_New();
    Screen0_Image_n35->fn->setPosition(Screen0_Image_n35, 307, 307);
    Screen0_Image_n35->fn->setSize(Screen0_Image_n35, 22, 20);
    Screen0_Image_n35->fn->setScheme(Screen0_Image_n35, &ClearScheme);
    Screen0_Image_n35->fn->setBackgroundType(Screen0_Image_n35, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n35->fn->setBorderType(Screen0_Image_n35, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n35->fn->setImage(Screen0_Image_n35, (leImage*)&n35);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n35);

    Screen0_Image_n36 = leImageWidget_New();
    Screen0_Image_n36->fn->setPosition(Screen0_Image_n36, 301, 313);
    Screen0_Image_n36->fn->setSize(Screen0_Image_n36, 20, 22);
    Screen0_Image_n36->fn->setScheme(Screen0_Image_n36, &ClearScheme);
    Screen0_Image_n36->fn->setBackgroundType(Screen0_Image_n36, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n36->fn->setBorderType(Screen0_Image_n36, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n36->fn->setImage(Screen0_Image_n36, (leImage*)&n36);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n36);

    Screen0_Image_n37 = leImageWidget_New();
    Screen0_Image_n37->fn->setPosition(Screen0_Image_n37, 294, 319);
    Screen0_Image_n37->fn->setSize(Screen0_Image_n37, 19, 22);
    Screen0_Image_n37->fn->setScheme(Screen0_Image_n37, &ClearScheme);
    Screen0_Image_n37->fn->setBackgroundType(Screen0_Image_n37, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n37->fn->setBorderType(Screen0_Image_n37, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n37->fn->setImage(Screen0_Image_n37, (leImage*)&n37);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n37);

    Screen0_Image_n38 = leImageWidget_New();
    Screen0_Image_n38->fn->setPosition(Screen0_Image_n38, 287, 324);
    Screen0_Image_n38->fn->setSize(Screen0_Image_n38, 17, 24);
    Screen0_Image_n38->fn->setScheme(Screen0_Image_n38, &ClearScheme);
    Screen0_Image_n38->fn->setBackgroundType(Screen0_Image_n38, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n38->fn->setBorderType(Screen0_Image_n38, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n38->fn->setImage(Screen0_Image_n38, (leImage*)&n38);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n38);

    Screen0_Image_n39 = leImageWidget_New();
    Screen0_Image_n39->fn->setPosition(Screen0_Image_n39, 279, 330);
    Screen0_Image_n39->fn->setSize(Screen0_Image_n39, 16, 23);
    Screen0_Image_n39->fn->setScheme(Screen0_Image_n39, &ClearScheme);
    Screen0_Image_n39->fn->setBackgroundType(Screen0_Image_n39, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n39->fn->setBorderType(Screen0_Image_n39, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n39->fn->setImage(Screen0_Image_n39, (leImage*)&n39);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n39);

    Screen0_Image_n40 = leImageWidget_New();
    Screen0_Image_n40->fn->setPosition(Screen0_Image_n40, 271, 334);
    Screen0_Image_n40->fn->setSize(Screen0_Image_n40, 15, 25);
    Screen0_Image_n40->fn->setScheme(Screen0_Image_n40, &ClearScheme);
    Screen0_Image_n40->fn->setBackgroundType(Screen0_Image_n40, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n40->fn->setBorderType(Screen0_Image_n40, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n40->fn->setImage(Screen0_Image_n40, (leImage*)&n40);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n40);

    Screen0_Image_n41 = leImageWidget_New();
    Screen0_Image_n41->fn->setPosition(Screen0_Image_n41, 263, 338);
    Screen0_Image_n41->fn->setSize(Screen0_Image_n41, 13, 25);
    Screen0_Image_n41->fn->setScheme(Screen0_Image_n41, &ClearScheme);
    Screen0_Image_n41->fn->setBackgroundType(Screen0_Image_n41, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n41->fn->setBorderType(Screen0_Image_n41, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n41->fn->setImage(Screen0_Image_n41, (leImage*)&n41);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n41);

    Screen0_Image_n42 = leImageWidget_New();
    Screen0_Image_n42->fn->setPosition(Screen0_Image_n42, 254, 342);
    Screen0_Image_n42->fn->setSize(Screen0_Image_n42, 12, 25);
    Screen0_Image_n42->fn->setScheme(Screen0_Image_n42, &ClearScheme);
    Screen0_Image_n42->fn->setBackgroundType(Screen0_Image_n42, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n42->fn->setBorderType(Screen0_Image_n42, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n42->fn->setImage(Screen0_Image_n42, (leImage*)&n42);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n42);

    Screen0_Image_n43 = leImageWidget_New();
    Screen0_Image_n43->fn->setPosition(Screen0_Image_n43, 245, 345);
    Screen0_Image_n43->fn->setSize(Screen0_Image_n43, 10, 25);
    Screen0_Image_n43->fn->setScheme(Screen0_Image_n43, &ClearScheme);
    Screen0_Image_n43->fn->setBackgroundType(Screen0_Image_n43, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n43->fn->setBorderType(Screen0_Image_n43, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n43->fn->setImage(Screen0_Image_n43, (leImage*)&n43);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n43);

    Screen0_Image_n44 = leImageWidget_New();
    Screen0_Image_n44->fn->setPosition(Screen0_Image_n44, 236, 347);
    Screen0_Image_n44->fn->setSize(Screen0_Image_n44, 8, 25);
    Screen0_Image_n44->fn->setScheme(Screen0_Image_n44, &ClearScheme);
    Screen0_Image_n44->fn->setBackgroundType(Screen0_Image_n44, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n44->fn->setBorderType(Screen0_Image_n44, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n44->fn->setImage(Screen0_Image_n44, (leImage*)&n44);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n44);

    Screen0_Image_n45 = leImageWidget_New();
    Screen0_Image_n45->fn->setPosition(Screen0_Image_n45, 227, 349);
    Screen0_Image_n45->fn->setSize(Screen0_Image_n45, 6, 25);
    Screen0_Image_n45->fn->setScheme(Screen0_Image_n45, &ClearScheme);
    Screen0_Image_n45->fn->setBackgroundType(Screen0_Image_n45, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n45->fn->setBorderType(Screen0_Image_n45, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n45->fn->setImage(Screen0_Image_n45, (leImage*)&n45);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n45);

    Screen0_Image_n46 = leImageWidget_New();
    Screen0_Image_n46->fn->setPosition(Screen0_Image_n46, 216, 349);
    Screen0_Image_n46->fn->setSize(Screen0_Image_n46, 6, 27);
    Screen0_Image_n46->fn->setScheme(Screen0_Image_n46, &ClearScheme);
    Screen0_Image_n46->fn->setBackgroundType(Screen0_Image_n46, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n46->fn->setBorderType(Screen0_Image_n46, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n46->fn->setImage(Screen0_Image_n46, (leImage*)&n46);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n46);

    Screen0_Image_n47 = leImageWidget_New();
    Screen0_Image_n47->fn->setPosition(Screen0_Image_n47, 207, 350);
    Screen0_Image_n47->fn->setSize(Screen0_Image_n47, 5, 27);
    Screen0_Image_n47->fn->setScheme(Screen0_Image_n47, &ClearScheme);
    Screen0_Image_n47->fn->setBackgroundType(Screen0_Image_n47, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n47->fn->setBorderType(Screen0_Image_n47, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n47->fn->setImage(Screen0_Image_n47, (leImage*)&n47);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n47);

    Screen0_Image_n48 = leImageWidget_New();
    Screen0_Image_n48->fn->setPosition(Screen0_Image_n48, 195, 349);
    Screen0_Image_n48->fn->setSize(Screen0_Image_n48, 6, 25);
    Screen0_Image_n48->fn->setScheme(Screen0_Image_n48, &ClearScheme);
    Screen0_Image_n48->fn->setBackgroundType(Screen0_Image_n48, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n48->fn->setBorderType(Screen0_Image_n48, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n48->fn->setImage(Screen0_Image_n48, (leImage*)&n48);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n48);

    Screen0_Image_n49 = leImageWidget_New();
    Screen0_Image_n49->fn->setPosition(Screen0_Image_n49, 184, 347);
    Screen0_Image_n49->fn->setSize(Screen0_Image_n49, 8, 25);
    Screen0_Image_n49->fn->setScheme(Screen0_Image_n49, &ClearScheme);
    Screen0_Image_n49->fn->setBackgroundType(Screen0_Image_n49, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n49->fn->setBorderType(Screen0_Image_n49, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n49->fn->setImage(Screen0_Image_n49, (leImage*)&n49);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n49);

    Screen0_Image_n50 = leImageWidget_New();
    Screen0_Image_n50->fn->setPosition(Screen0_Image_n50, 173, 345);
    Screen0_Image_n50->fn->setSize(Screen0_Image_n50, 10, 25);
    Screen0_Image_n50->fn->setScheme(Screen0_Image_n50, &ClearScheme);
    Screen0_Image_n50->fn->setBackgroundType(Screen0_Image_n50, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n50->fn->setBorderType(Screen0_Image_n50, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n50->fn->setImage(Screen0_Image_n50, (leImage*)&n50);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n50);

    Screen0_Image_n51 = leImageWidget_New();
    Screen0_Image_n51->fn->setPosition(Screen0_Image_n51, 163, 342);
    Screen0_Image_n51->fn->setSize(Screen0_Image_n51, 11, 25);
    Screen0_Image_n51->fn->setScheme(Screen0_Image_n51, &ClearScheme);
    Screen0_Image_n51->fn->setBackgroundType(Screen0_Image_n51, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n51->fn->setBorderType(Screen0_Image_n51, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n51->fn->setImage(Screen0_Image_n51, (leImage*)&n51);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n51);

    Screen0_Image_n52 = leImageWidget_New();
    Screen0_Image_n52->fn->setPosition(Screen0_Image_n52, 152, 338);
    Screen0_Image_n52->fn->setSize(Screen0_Image_n52, 14, 25);
    Screen0_Image_n52->fn->setScheme(Screen0_Image_n52, &ClearScheme);
    Screen0_Image_n52->fn->setBackgroundType(Screen0_Image_n52, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n52->fn->setBorderType(Screen0_Image_n52, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n52->fn->setImage(Screen0_Image_n52, (leImage*)&n52);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n52);

    Screen0_Image_n53 = leImageWidget_New();
    Screen0_Image_n53->fn->setPosition(Screen0_Image_n53, 143, 334);
    Screen0_Image_n53->fn->setSize(Screen0_Image_n53, 14, 25);
    Screen0_Image_n53->fn->setScheme(Screen0_Image_n53, &ClearScheme);
    Screen0_Image_n53->fn->setBackgroundType(Screen0_Image_n53, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n53->fn->setBorderType(Screen0_Image_n53, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n53->fn->setImage(Screen0_Image_n53, (leImage*)&n53);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n53);

    Screen0_Image_n54 = leImageWidget_New();
    Screen0_Image_n54->fn->setPosition(Screen0_Image_n54, 133, 330);
    Screen0_Image_n54->fn->setSize(Screen0_Image_n54, 16, 23);
    Screen0_Image_n54->fn->setScheme(Screen0_Image_n54, &ClearScheme);
    Screen0_Image_n54->fn->setBackgroundType(Screen0_Image_n54, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n54->fn->setBorderType(Screen0_Image_n54, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n54->fn->setImage(Screen0_Image_n54, (leImage*)&n54);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n54);

    Screen0_Image_n55 = leImageWidget_New();
    Screen0_Image_n55->fn->setPosition(Screen0_Image_n55, 124, 324);
    Screen0_Image_n55->fn->setSize(Screen0_Image_n55, 18, 24);
    Screen0_Image_n55->fn->setScheme(Screen0_Image_n55, &ClearScheme);
    Screen0_Image_n55->fn->setBackgroundType(Screen0_Image_n55, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n55->fn->setBorderType(Screen0_Image_n55, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n55->fn->setImage(Screen0_Image_n55, (leImage*)&n55);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n55);

    Screen0_Image_n56 = leImageWidget_New();
    Screen0_Image_n56->fn->setPosition(Screen0_Image_n56, 115, 319);
    Screen0_Image_n56->fn->setSize(Screen0_Image_n56, 19, 22);
    Screen0_Image_n56->fn->setScheme(Screen0_Image_n56, &ClearScheme);
    Screen0_Image_n56->fn->setBackgroundType(Screen0_Image_n56, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n56->fn->setBorderType(Screen0_Image_n56, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n56->fn->setImage(Screen0_Image_n56, (leImage*)&n56);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n56);

    Screen0_Image_n57 = leImageWidget_New();
    Screen0_Image_n57->fn->setPosition(Screen0_Image_n57, 107, 313);
    Screen0_Image_n57->fn->setSize(Screen0_Image_n57, 21, 22);
    Screen0_Image_n57->fn->setScheme(Screen0_Image_n57, &ClearScheme);
    Screen0_Image_n57->fn->setBackgroundType(Screen0_Image_n57, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n57->fn->setBorderType(Screen0_Image_n57, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n57->fn->setImage(Screen0_Image_n57, (leImage*)&n57);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n57);

    Screen0_Image_n58 = leImageWidget_New();
    Screen0_Image_n58->fn->setPosition(Screen0_Image_n58, 100, 307);
    Screen0_Image_n58->fn->setSize(Screen0_Image_n58, 21, 21);
    Screen0_Image_n58->fn->setScheme(Screen0_Image_n58, &ClearScheme);
    Screen0_Image_n58->fn->setBackgroundType(Screen0_Image_n58, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n58->fn->setBorderType(Screen0_Image_n58, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n58->fn->setImage(Screen0_Image_n58, (leImage*)&n58);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n58);

    Screen0_Image_n59 = leImageWidget_New();
    Screen0_Image_n59->fn->setPosition(Screen0_Image_n59, 93, 300);
    Screen0_Image_n59->fn->setSize(Screen0_Image_n59, 22, 20);
    Screen0_Image_n59->fn->setScheme(Screen0_Image_n59, &ClearScheme);
    Screen0_Image_n59->fn->setBackgroundType(Screen0_Image_n59, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n59->fn->setBorderType(Screen0_Image_n59, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n59->fn->setImage(Screen0_Image_n59, (leImage*)&n59);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n59);

    Screen0_Image_n60 = leImageWidget_New();
    Screen0_Image_n60->fn->setPosition(Screen0_Image_n60, 86, 292);
    Screen0_Image_n60->fn->setSize(Screen0_Image_n60, 23, 19);
    Screen0_Image_n60->fn->setScheme(Screen0_Image_n60, &ClearScheme);
    Screen0_Image_n60->fn->setBackgroundType(Screen0_Image_n60, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n60->fn->setBorderType(Screen0_Image_n60, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n60->fn->setImage(Screen0_Image_n60, (leImage*)&n60);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n60);

    Screen0_Image_n61 = leImageWidget_New();
    Screen0_Image_n61->fn->setPosition(Screen0_Image_n61, 80, 285);
    Screen0_Image_n61->fn->setSize(Screen0_Image_n61, 24, 17);
    Screen0_Image_n61->fn->setScheme(Screen0_Image_n61, &ClearScheme);
    Screen0_Image_n61->fn->setBackgroundType(Screen0_Image_n61, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n61->fn->setBorderType(Screen0_Image_n61, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n61->fn->setImage(Screen0_Image_n61, (leImage*)&n61);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n61);

    Screen0_Image_n62 = leImageWidget_New();
    Screen0_Image_n62->fn->setPosition(Screen0_Image_n62, 75, 277);
    Screen0_Image_n62->fn->setSize(Screen0_Image_n62, 25, 16);
    Screen0_Image_n62->fn->setScheme(Screen0_Image_n62, &ClearScheme);
    Screen0_Image_n62->fn->setBackgroundType(Screen0_Image_n62, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n62->fn->setBorderType(Screen0_Image_n62, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n62->fn->setImage(Screen0_Image_n62, (leImage*)&n62);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n62);

    Screen0_Image_n63 = leImageWidget_New();
    Screen0_Image_n63->fn->setPosition(Screen0_Image_n63, 70, 269);
    Screen0_Image_n63->fn->setSize(Screen0_Image_n63, 26, 15);
    Screen0_Image_n63->fn->setScheme(Screen0_Image_n63, &ClearScheme);
    Screen0_Image_n63->fn->setBackgroundType(Screen0_Image_n63, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n63->fn->setBorderType(Screen0_Image_n63, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n63->fn->setImage(Screen0_Image_n63, (leImage*)&n63);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n63);

    Screen0_Image_n64 = leImageWidget_New();
    Screen0_Image_n64->fn->setPosition(Screen0_Image_n64, 66, 262);
    Screen0_Image_n64->fn->setSize(Screen0_Image_n64, 26, 12);
    Screen0_Image_n64->fn->setScheme(Screen0_Image_n64, &ClearScheme);
    Screen0_Image_n64->fn->setBackgroundType(Screen0_Image_n64, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n64->fn->setBorderType(Screen0_Image_n64, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n64->fn->setImage(Screen0_Image_n64, (leImage*)&n64);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n64);

    Screen0_Image_n65 = leImageWidget_New();
    Screen0_Image_n65->fn->setPosition(Screen0_Image_n65, 62, 253);
    Screen0_Image_n65->fn->setSize(Screen0_Image_n65, 27, 11);
    Screen0_Image_n65->fn->setScheme(Screen0_Image_n65, &ClearScheme);
    Screen0_Image_n65->fn->setBackgroundType(Screen0_Image_n65, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n65->fn->setBorderType(Screen0_Image_n65, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n65->fn->setImage(Screen0_Image_n65, (leImage*)&n65);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n65);

    Screen0_Image_n66 = leImageWidget_New();
    Screen0_Image_n66->fn->setPosition(Screen0_Image_n66, 60, 245);
    Screen0_Image_n66->fn->setSize(Screen0_Image_n66, 26, 9);
    Screen0_Image_n66->fn->setScheme(Screen0_Image_n66, &ClearScheme);
    Screen0_Image_n66->fn->setBackgroundType(Screen0_Image_n66, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n66->fn->setBorderType(Screen0_Image_n66, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n66->fn->setImage(Screen0_Image_n66, (leImage*)&n66);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n66);

    Screen0_Image_n67 = leImageWidget_New();
    Screen0_Image_n67->fn->setPosition(Screen0_Image_n67, 58, 236);
    Screen0_Image_n67->fn->setSize(Screen0_Image_n67, 26, 8);
    Screen0_Image_n67->fn->setScheme(Screen0_Image_n67, &ClearScheme);
    Screen0_Image_n67->fn->setBackgroundType(Screen0_Image_n67, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n67->fn->setBorderType(Screen0_Image_n67, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n67->fn->setImage(Screen0_Image_n67, (leImage*)&n67);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n67);

    Screen0_Image_n68 = leImageWidget_New();
    Screen0_Image_n68->fn->setPosition(Screen0_Image_n68, 56, 228);
    Screen0_Image_n68->fn->setSize(Screen0_Image_n68, 26, 6);
    Screen0_Image_n68->fn->setScheme(Screen0_Image_n68, &ClearScheme);
    Screen0_Image_n68->fn->setBackgroundType(Screen0_Image_n68, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n68->fn->setBorderType(Screen0_Image_n68, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n68->fn->setImage(Screen0_Image_n68, (leImage*)&n68);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n68);

    Screen0_Image_n69 = leImageWidget_New();
    Screen0_Image_n69->fn->setPosition(Screen0_Image_n69, 56, 219);
    Screen0_Image_n69->fn->setSize(Screen0_Image_n69, 25, 4);
    Screen0_Image_n69->fn->setScheme(Screen0_Image_n69, &ClearScheme);
    Screen0_Image_n69->fn->setBackgroundType(Screen0_Image_n69, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n69->fn->setBorderType(Screen0_Image_n69, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n69->fn->setImage(Screen0_Image_n69, (leImage*)&n69);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n69);

    Screen0_Image_n70 = leImageWidget_New();
    Screen0_Image_n70->fn->setPosition(Screen0_Image_n70, 55, 210);
    Screen0_Image_n70->fn->setSize(Screen0_Image_n70, 25, 5);
    Screen0_Image_n70->fn->setScheme(Screen0_Image_n70, &ClearScheme);
    Screen0_Image_n70->fn->setBackgroundType(Screen0_Image_n70, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n70->fn->setBorderType(Screen0_Image_n70, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n70->fn->setImage(Screen0_Image_n70, (leImage*)&n70);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n70);

    Screen0_Image_n71 = leImageWidget_New();
    Screen0_Image_n71->fn->setPosition(Screen0_Image_n71, 56, 199);
    Screen0_Image_n71->fn->setSize(Screen0_Image_n71, 25, 6);
    Screen0_Image_n71->fn->setScheme(Screen0_Image_n71, &ClearScheme);
    Screen0_Image_n71->fn->setBackgroundType(Screen0_Image_n71, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n71->fn->setBorderType(Screen0_Image_n71, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n71->fn->setImage(Screen0_Image_n71, (leImage*)&n71);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n71);

    Screen0_Image_n72 = leImageWidget_New();
    Screen0_Image_n72->fn->setPosition(Screen0_Image_n72, 57, 189);
    Screen0_Image_n72->fn->setSize(Screen0_Image_n72, 25, 7);
    Screen0_Image_n72->fn->setScheme(Screen0_Image_n72, &ClearScheme);
    Screen0_Image_n72->fn->setBackgroundType(Screen0_Image_n72, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n72->fn->setBorderType(Screen0_Image_n72, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n72->fn->setImage(Screen0_Image_n72, (leImage*)&n72);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n72);

    Screen0_Image_n73 = leImageWidget_New();
    Screen0_Image_n73->fn->setPosition(Screen0_Image_n73, 59, 178);
    Screen0_Image_n73->fn->setSize(Screen0_Image_n73, 25, 10);
    Screen0_Image_n73->fn->setScheme(Screen0_Image_n73, &ClearScheme);
    Screen0_Image_n73->fn->setBackgroundType(Screen0_Image_n73, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n73->fn->setBorderType(Screen0_Image_n73, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n73->fn->setImage(Screen0_Image_n73, (leImage*)&n73);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n73);

    Screen0_Image_n74 = leImageWidget_New();
    Screen0_Image_n74->fn->setPosition(Screen0_Image_n74, 62, 168);
    Screen0_Image_n74->fn->setSize(Screen0_Image_n74, 24, 11);
    Screen0_Image_n74->fn->setScheme(Screen0_Image_n74, &ClearScheme);
    Screen0_Image_n74->fn->setBackgroundType(Screen0_Image_n74, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n74->fn->setBorderType(Screen0_Image_n74, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n74->fn->setImage(Screen0_Image_n74, (leImage*)&n74);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n74);

    Screen0_Image_n75 = leImageWidget_New();
    Screen0_Image_n75->fn->setPosition(Screen0_Image_n75, 65, 158);
    Screen0_Image_n75->fn->setSize(Screen0_Image_n75, 24, 12);
    Screen0_Image_n75->fn->setScheme(Screen0_Image_n75, &ClearScheme);
    Screen0_Image_n75->fn->setBackgroundType(Screen0_Image_n75, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n75->fn->setBorderType(Screen0_Image_n75, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n75->fn->setImage(Screen0_Image_n75, (leImage*)&n75);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n75);

    Screen0_Image_n76 = leImageWidget_New();
    Screen0_Image_n76->fn->setPosition(Screen0_Image_n76, 69, 148);
    Screen0_Image_n76->fn->setSize(Screen0_Image_n76, 24, 14);
    Screen0_Image_n76->fn->setScheme(Screen0_Image_n76, &ClearScheme);
    Screen0_Image_n76->fn->setBackgroundType(Screen0_Image_n76, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n76->fn->setBorderType(Screen0_Image_n76, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n76->fn->setImage(Screen0_Image_n76, (leImage*)&n76);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n76);

    Screen0_Image_n92 = leImageWidget_New();
    Screen0_Image_n92->fn->setPosition(Screen0_Image_n92, 202, 55);
    Screen0_Image_n92->fn->setSize(Screen0_Image_n92, 11, 26);
    Screen0_Image_n92->fn->setScheme(Screen0_Image_n92, &ClearScheme);
    Screen0_Image_n92->fn->setBackgroundType(Screen0_Image_n92, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n92->fn->setBorderType(Screen0_Image_n92, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n92->fn->setImage(Screen0_Image_n92, (leImage*)&n92);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n92);

    Screen0_Image_n91 = leImageWidget_New();
    Screen0_Image_n91->fn->setPosition(Screen0_Image_n91, 191, 57);
    Screen0_Image_n91->fn->setSize(Screen0_Image_n91, 7, 27);
    Screen0_Image_n91->fn->setScheme(Screen0_Image_n91, &ClearScheme);
    Screen0_Image_n91->fn->setBackgroundType(Screen0_Image_n91, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n91->fn->setBorderType(Screen0_Image_n91, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n91->fn->setImage(Screen0_Image_n91, (leImage*)&n91);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n91);

    Screen0_Image_n90 = leImageWidget_New();
    Screen0_Image_n90->fn->setPosition(Screen0_Image_n90, 180, 59);
    Screen0_Image_n90->fn->setSize(Screen0_Image_n90, 9, 26);
    Screen0_Image_n90->fn->setScheme(Screen0_Image_n90, &ClearScheme);
    Screen0_Image_n90->fn->setBackgroundType(Screen0_Image_n90, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n90->fn->setBorderType(Screen0_Image_n90, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n90->fn->setImage(Screen0_Image_n90, (leImage*)&n90);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n90);

    Screen0_Image_n89 = leImageWidget_New();
    Screen0_Image_n89->fn->setPosition(Screen0_Image_n89, 170, 61);
    Screen0_Image_n89->fn->setSize(Screen0_Image_n89, 11, 26);
    Screen0_Image_n89->fn->setScheme(Screen0_Image_n89, &ClearScheme);
    Screen0_Image_n89->fn->setBackgroundType(Screen0_Image_n89, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n89->fn->setBorderType(Screen0_Image_n89, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n89->fn->setImage(Screen0_Image_n89, (leImage*)&n89);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n89);

    Screen0_Image_n88 = leImageWidget_New();
    Screen0_Image_n88->fn->setPosition(Screen0_Image_n88, 160, 64);
    Screen0_Image_n88->fn->setSize(Screen0_Image_n88, 12, 26);
    Screen0_Image_n88->fn->setScheme(Screen0_Image_n88, &ClearScheme);
    Screen0_Image_n88->fn->setBackgroundType(Screen0_Image_n88, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n88->fn->setBorderType(Screen0_Image_n88, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n88->fn->setImage(Screen0_Image_n88, (leImage*)&n88);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n88);

    Screen0_Image_n87 = leImageWidget_New();
    Screen0_Image_n87->fn->setPosition(Screen0_Image_n87, 150, 68);
    Screen0_Image_n87->fn->setSize(Screen0_Image_n87, 13, 26);
    Screen0_Image_n87->fn->setScheme(Screen0_Image_n87, &ClearScheme);
    Screen0_Image_n87->fn->setBackgroundType(Screen0_Image_n87, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n87->fn->setBorderType(Screen0_Image_n87, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n87->fn->setImage(Screen0_Image_n87, (leImage*)&n87);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n87);

    Screen0_Image_n86 = leImageWidget_New();
    Screen0_Image_n86->fn->setPosition(Screen0_Image_n86, 140, 73);
    Screen0_Image_n86->fn->setSize(Screen0_Image_n86, 15, 24);
    Screen0_Image_n86->fn->setScheme(Screen0_Image_n86, &ClearScheme);
    Screen0_Image_n86->fn->setBackgroundType(Screen0_Image_n86, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n86->fn->setBorderType(Screen0_Image_n86, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n86->fn->setImage(Screen0_Image_n86, (leImage*)&n86);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n86);

    Screen0_Image_n85 = leImageWidget_New();
    Screen0_Image_n85->fn->setPosition(Screen0_Image_n85, 131, 78);
    Screen0_Image_n85->fn->setSize(Screen0_Image_n85, 16, 24);
    Screen0_Image_n85->fn->setScheme(Screen0_Image_n85, &ClearScheme);
    Screen0_Image_n85->fn->setBackgroundType(Screen0_Image_n85, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n85->fn->setBorderType(Screen0_Image_n85, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n85->fn->setImage(Screen0_Image_n85, (leImage*)&n85);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n85);

    Screen0_Image_n84 = leImageWidget_New();
    Screen0_Image_n84->fn->setPosition(Screen0_Image_n84, 122, 84);
    Screen0_Image_n84->fn->setSize(Screen0_Image_n84, 18, 23);
    Screen0_Image_n84->fn->setScheme(Screen0_Image_n84, &ClearScheme);
    Screen0_Image_n84->fn->setBackgroundType(Screen0_Image_n84, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n84->fn->setBorderType(Screen0_Image_n84, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n84->fn->setImage(Screen0_Image_n84, (leImage*)&n84);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n84);

    Screen0_Image_n83 = leImageWidget_New();
    Screen0_Image_n83->fn->setPosition(Screen0_Image_n83, 114, 90);
    Screen0_Image_n83->fn->setSize(Screen0_Image_n83, 18, 22);
    Screen0_Image_n83->fn->setScheme(Screen0_Image_n83, &ClearScheme);
    Screen0_Image_n83->fn->setBackgroundType(Screen0_Image_n83, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n83->fn->setBorderType(Screen0_Image_n83, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n83->fn->setImage(Screen0_Image_n83, (leImage*)&n83);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n83);

    Screen0_Image_n82 = leImageWidget_New();
    Screen0_Image_n82->fn->setPosition(Screen0_Image_n82, 103, 98);
    Screen0_Image_n82->fn->setSize(Screen0_Image_n82, 24, 19);
    Screen0_Image_n82->fn->setScheme(Screen0_Image_n82, &ClearScheme);
    Screen0_Image_n82->fn->setBackgroundType(Screen0_Image_n82, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n82->fn->setBorderType(Screen0_Image_n82, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n82->fn->setImage(Screen0_Image_n82, (leImage*)&n82);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n82);

    Screen0_Image_n81 = leImageWidget_New();
    Screen0_Image_n81->fn->setPosition(Screen0_Image_n81, 98, 105);
    Screen0_Image_n81->fn->setSize(Screen0_Image_n81, 24, 19);
    Screen0_Image_n81->fn->setScheme(Screen0_Image_n81, &ClearScheme);
    Screen0_Image_n81->fn->setBackgroundType(Screen0_Image_n81, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n81->fn->setBorderType(Screen0_Image_n81, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n81->fn->setImage(Screen0_Image_n81, (leImage*)&n81);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n81);

    Screen0_Image_n80 = leImageWidget_New();
    Screen0_Image_n80->fn->setPosition(Screen0_Image_n80, 91, 113);
    Screen0_Image_n80->fn->setSize(Screen0_Image_n80, 21, 18);
    Screen0_Image_n80->fn->setScheme(Screen0_Image_n80, &ClearScheme);
    Screen0_Image_n80->fn->setBackgroundType(Screen0_Image_n80, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n80->fn->setBorderType(Screen0_Image_n80, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n80->fn->setImage(Screen0_Image_n80, (leImage*)&n80);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n80);

    Screen0_Image_n79 = leImageWidget_New();
    Screen0_Image_n79->fn->setPosition(Screen0_Image_n79, 85, 121);
    Screen0_Image_n79->fn->setSize(Screen0_Image_n79, 22, 17);
    Screen0_Image_n79->fn->setScheme(Screen0_Image_n79, &ClearScheme);
    Screen0_Image_n79->fn->setBackgroundType(Screen0_Image_n79, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n79->fn->setBorderType(Screen0_Image_n79, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n79->fn->setImage(Screen0_Image_n79, (leImage*)&n79);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n79);

    Screen0_Image_n78 = leImageWidget_New();
    Screen0_Image_n78->fn->setPosition(Screen0_Image_n78, 79, 130);
    Screen0_Image_n78->fn->setSize(Screen0_Image_n78, 22, 16);
    Screen0_Image_n78->fn->setScheme(Screen0_Image_n78, &ClearScheme);
    Screen0_Image_n78->fn->setBackgroundType(Screen0_Image_n78, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n78->fn->setBorderType(Screen0_Image_n78, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n78->fn->setImage(Screen0_Image_n78, (leImage*)&n78);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n78);

    Screen0_Image_n77 = leImageWidget_New();
    Screen0_Image_n77->fn->setPosition(Screen0_Image_n77, 74, 139);
    Screen0_Image_n77->fn->setSize(Screen0_Image_n77, 23, 15);
    Screen0_Image_n77->fn->setScheme(Screen0_Image_n77, &ClearScheme);
    Screen0_Image_n77->fn->setBackgroundType(Screen0_Image_n77, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Image_n77->fn->setBorderType(Screen0_Image_n77, LE_WIDGET_BORDER_NONE);
    Screen0_Image_n77->fn->setImage(Screen0_Image_n77, (leImage*)&n77);
    Screen0_NeedlePanel->fn->addChild(Screen0_NeedlePanel, (leWidget*)Screen0_Image_n77);

    Screen0_GestureLabelWidget = leLabelWidget_New();
    Screen0_GestureLabelWidget->fn->setPosition(Screen0_GestureLabelWidget, 188, 284);
    Screen0_GestureLabelWidget->fn->setSize(Screen0_GestureLabelWidget, 50, 39);
    Screen0_GestureLabelWidget->fn->setVisible(Screen0_GestureLabelWidget, LE_FALSE);
    Screen0_GestureLabelWidget->fn->setScheme(Screen0_GestureLabelWidget, &WhiteTextScheme);
    Screen0_GestureLabelWidget->fn->setBackgroundType(Screen0_GestureLabelWidget, LE_WIDGET_BACKGROUND_NONE);
    Screen0_GestureLabelWidget->fn->setHAlignment(Screen0_GestureLabelWidget, LE_HALIGN_CENTER);
    Screen0_GestureLabelWidget->fn->setString(Screen0_GestureLabelWidget, (leString*)&string_CheckString);
    root1->fn->addChild(root1, (leWidget*)Screen0_GestureLabelWidget);

    Screen0_ButtonsPanel = leWidget_New();
    Screen0_ButtonsPanel->fn->setPosition(Screen0_ButtonsPanel, 0, 0);
    Screen0_ButtonsPanel->fn->setSize(Screen0_ButtonsPanel, 432, 432);
    Screen0_ButtonsPanel->fn->setBackgroundType(Screen0_ButtonsPanel, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_ButtonsPanel);

    Screen0_MchpLogoImage = leImageWidget_New();
    Screen0_MchpLogoImage->fn->setPosition(Screen0_MchpLogoImage, 157, 162);
    Screen0_MchpLogoImage->fn->setSize(Screen0_MchpLogoImage, 110, 110);
    Screen0_MchpLogoImage->fn->setBackgroundType(Screen0_MchpLogoImage, LE_WIDGET_BACKGROUND_NONE);
    Screen0_MchpLogoImage->fn->setBorderType(Screen0_MchpLogoImage, LE_WIDGET_BORDER_NONE);
    Screen0_MchpLogoImage->fn->setImage(Screen0_MchpLogoImage, (leImage*)&mchp_circle);
    Screen0_ButtonsPanel->fn->addChild(Screen0_ButtonsPanel, (leWidget*)Screen0_MchpLogoImage);

    Screen0_HomeButton = leButtonWidget_New();
    Screen0_HomeButton->fn->setPosition(Screen0_HomeButton, 186, 81);
    Screen0_HomeButton->fn->setSize(Screen0_HomeButton, 55, 55);
    Screen0_HomeButton->fn->setBackgroundType(Screen0_HomeButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_HomeButton->fn->setBorderType(Screen0_HomeButton, LE_WIDGET_BORDER_NONE);
    Screen0_HomeButton->fn->setPressedEventCallback(Screen0_HomeButton, event_Screen0_HomeButton_OnPressed);
    Screen0_HomeButton->fn->setReleasedEventCallback(Screen0_HomeButton, event_Screen0_HomeButton_OnReleased);
    Screen0_ButtonsPanel->fn->addChild(Screen0_ButtonsPanel, (leWidget*)Screen0_HomeButton);

    Screen0_HomeImageSequence = leImageSequenceWidget_New();
    Screen0_HomeImageSequence->fn->setPosition(Screen0_HomeImageSequence, 0, 0);
    Screen0_HomeImageSequence->fn->setSize(Screen0_HomeImageSequence, 55, 55);
    Screen0_HomeImageSequence->fn->setEnabled(Screen0_HomeImageSequence, LE_FALSE);
    Screen0_HomeImageSequence->fn->setBackgroundType(Screen0_HomeImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Screen0_HomeImageSequence->fn->setImageCount(Screen0_HomeImageSequence, 2);
    Screen0_HomeImageSequence->fn->setImage(Screen0_HomeImageSequence, 0, &home_m);
    Screen0_HomeImageSequence->fn->setImageDelay(Screen0_HomeImageSequence, 0, 1000);
    Screen0_HomeImageSequence->fn->setImage(Screen0_HomeImageSequence, 1, &home_l);
    Screen0_HomeImageSequence->fn->setImageDelay(Screen0_HomeImageSequence, 1, 1000);
    Screen0_HomeButton->fn->addChild(Screen0_HomeButton, (leWidget*)Screen0_HomeImageSequence);

    Screen0_SettingsButton = leButtonWidget_New();
    Screen0_SettingsButton->fn->setPosition(Screen0_SettingsButton, 109, 123);
    Screen0_SettingsButton->fn->setSize(Screen0_SettingsButton, 55, 55);
    Screen0_SettingsButton->fn->setBackgroundType(Screen0_SettingsButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SettingsButton->fn->setBorderType(Screen0_SettingsButton, LE_WIDGET_BORDER_NONE);
    Screen0_SettingsButton->fn->setPressedEventCallback(Screen0_SettingsButton, event_Screen0_SettingsButton_OnPressed);
    Screen0_SettingsButton->fn->setReleasedEventCallback(Screen0_SettingsButton, event_Screen0_SettingsButton_OnReleased);
    Screen0_ButtonsPanel->fn->addChild(Screen0_ButtonsPanel, (leWidget*)Screen0_SettingsButton);

    Screen0_SettingsImageSequence = leImageSequenceWidget_New();
    Screen0_SettingsImageSequence->fn->setPosition(Screen0_SettingsImageSequence, 0, 0);
    Screen0_SettingsImageSequence->fn->setSize(Screen0_SettingsImageSequence, 55, 55);
    Screen0_SettingsImageSequence->fn->setEnabled(Screen0_SettingsImageSequence, LE_FALSE);
    Screen0_SettingsImageSequence->fn->setBackgroundType(Screen0_SettingsImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SettingsImageSequence->fn->setImageCount(Screen0_SettingsImageSequence, 2);
    Screen0_SettingsImageSequence->fn->setImage(Screen0_SettingsImageSequence, 0, &gear_m);
    Screen0_SettingsImageSequence->fn->setImageDelay(Screen0_SettingsImageSequence, 0, 1000);
    Screen0_SettingsImageSequence->fn->setImage(Screen0_SettingsImageSequence, 1, &gear_l);
    Screen0_SettingsImageSequence->fn->setImageDelay(Screen0_SettingsImageSequence, 1, 1000);
    Screen0_SettingsButton->fn->addChild(Screen0_SettingsButton, (leWidget*)Screen0_SettingsImageSequence);

    Screen0_ReverseTagLabel = leLabelWidget_New();
    Screen0_ReverseTagLabel->fn->setPosition(Screen0_ReverseTagLabel, 16, 14);
    Screen0_ReverseTagLabel->fn->setSize(Screen0_ReverseTagLabel, 22, 24);
    Screen0_ReverseTagLabel->fn->setEnabled(Screen0_ReverseTagLabel, LE_FALSE);
    Screen0_ReverseTagLabel->fn->setVisible(Screen0_ReverseTagLabel, LE_FALSE);
    Screen0_ReverseTagLabel->fn->setScheme(Screen0_ReverseTagLabel, &WhiteTextScheme);
    Screen0_ReverseTagLabel->fn->setBackgroundType(Screen0_ReverseTagLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ReverseTagLabel->fn->setHAlignment(Screen0_ReverseTagLabel, LE_HALIGN_CENTER);
    Screen0_ReverseTagLabel->fn->setString(Screen0_ReverseTagLabel, (leString*)&string_ReverseString);
    Screen0_SettingsButton->fn->addChild(Screen0_SettingsButton, (leWidget*)Screen0_ReverseTagLabel);

    Screen0_VolumeButton = leButtonWidget_New();
    Screen0_VolumeButton->fn->setPosition(Screen0_VolumeButton, 84, 187);
    Screen0_VolumeButton->fn->setSize(Screen0_VolumeButton, 55, 55);
    Screen0_VolumeButton->fn->setBackgroundType(Screen0_VolumeButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_VolumeButton->fn->setBorderType(Screen0_VolumeButton, LE_WIDGET_BORDER_NONE);
    Screen0_VolumeButton->fn->setPressedEventCallback(Screen0_VolumeButton, event_Screen0_VolumeButton_OnPressed);
    Screen0_VolumeButton->fn->setReleasedEventCallback(Screen0_VolumeButton, event_Screen0_VolumeButton_OnReleased);
    Screen0_ButtonsPanel->fn->addChild(Screen0_ButtonsPanel, (leWidget*)Screen0_VolumeButton);

    Screen0_VolumeImageSequence = leImageSequenceWidget_New();
    Screen0_VolumeImageSequence->fn->setPosition(Screen0_VolumeImageSequence, 0, 0);
    Screen0_VolumeImageSequence->fn->setSize(Screen0_VolumeImageSequence, 55, 55);
    Screen0_VolumeImageSequence->fn->setEnabled(Screen0_VolumeImageSequence, LE_FALSE);
    Screen0_VolumeImageSequence->fn->setBackgroundType(Screen0_VolumeImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Screen0_VolumeImageSequence->fn->setImageCount(Screen0_VolumeImageSequence, 2);
    Screen0_VolumeImageSequence->fn->setImage(Screen0_VolumeImageSequence, 0, &sound_m);
    Screen0_VolumeImageSequence->fn->setImageDelay(Screen0_VolumeImageSequence, 0, 1000);
    Screen0_VolumeImageSequence->fn->setImage(Screen0_VolumeImageSequence, 1, &sound_l);
    Screen0_VolumeImageSequence->fn->setImageDelay(Screen0_VolumeImageSequence, 1, 1000);
    Screen0_VolumeButton->fn->addChild(Screen0_VolumeButton, (leWidget*)Screen0_VolumeImageSequence);

    Screen0_EcoButton = leButtonWidget_New();
    Screen0_EcoButton->fn->setPosition(Screen0_EcoButton, 116, 255);
    Screen0_EcoButton->fn->setSize(Screen0_EcoButton, 55, 55);
    Screen0_EcoButton->fn->setBackgroundType(Screen0_EcoButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_EcoButton->fn->setBorderType(Screen0_EcoButton, LE_WIDGET_BORDER_NONE);
    Screen0_EcoButton->fn->setPressedEventCallback(Screen0_EcoButton, event_Screen0_EcoButton_OnPressed);
    Screen0_EcoButton->fn->setReleasedEventCallback(Screen0_EcoButton, event_Screen0_EcoButton_OnReleased);
    Screen0_ButtonsPanel->fn->addChild(Screen0_ButtonsPanel, (leWidget*)Screen0_EcoButton);

    Screen0_EcoImageSequence = leImageSequenceWidget_New();
    Screen0_EcoImageSequence->fn->setPosition(Screen0_EcoImageSequence, -3, 2);
    Screen0_EcoImageSequence->fn->setSize(Screen0_EcoImageSequence, 55, 55);
    Screen0_EcoImageSequence->fn->setEnabled(Screen0_EcoImageSequence, LE_FALSE);
    Screen0_EcoImageSequence->fn->setBackgroundType(Screen0_EcoImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Screen0_EcoImageSequence->fn->setImageCount(Screen0_EcoImageSequence, 2);
    Screen0_EcoImageSequence->fn->setImage(Screen0_EcoImageSequence, 0, &leaf_m);
    Screen0_EcoImageSequence->fn->setImageDelay(Screen0_EcoImageSequence, 0, 1000);
    Screen0_EcoImageSequence->fn->setImage(Screen0_EcoImageSequence, 1, &leaf_l);
    Screen0_EcoImageSequence->fn->setImageDelay(Screen0_EcoImageSequence, 1, 1000);
    Screen0_EcoButton->fn->addChild(Screen0_EcoButton, (leWidget*)Screen0_EcoImageSequence);

    Screen0_ThermButton = leButtonWidget_New();
    Screen0_ThermButton->fn->setPosition(Screen0_ThermButton, 185, 293);
    Screen0_ThermButton->fn->setSize(Screen0_ThermButton, 55, 55);
    Screen0_ThermButton->fn->setBackgroundType(Screen0_ThermButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ThermButton->fn->setBorderType(Screen0_ThermButton, LE_WIDGET_BORDER_NONE);
    Screen0_ThermButton->fn->setPressedEventCallback(Screen0_ThermButton, event_Screen0_ThermButton_OnPressed);
    Screen0_ThermButton->fn->setReleasedEventCallback(Screen0_ThermButton, event_Screen0_ThermButton_OnReleased);
    Screen0_ButtonsPanel->fn->addChild(Screen0_ButtonsPanel, (leWidget*)Screen0_ThermButton);

    Screen0_ThermImageSequence = leImageSequenceWidget_New();
    Screen0_ThermImageSequence->fn->setPosition(Screen0_ThermImageSequence, 0, 0);
    Screen0_ThermImageSequence->fn->setSize(Screen0_ThermImageSequence, 55, 55);
    Screen0_ThermImageSequence->fn->setEnabled(Screen0_ThermImageSequence, LE_FALSE);
    Screen0_ThermImageSequence->fn->setBackgroundType(Screen0_ThermImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ThermImageSequence->fn->setImageCount(Screen0_ThermImageSequence, 2);
    Screen0_ThermImageSequence->fn->setImage(Screen0_ThermImageSequence, 0, &thermo_m);
    Screen0_ThermImageSequence->fn->setImageDelay(Screen0_ThermImageSequence, 0, 1000);
    Screen0_ThermImageSequence->fn->setImage(Screen0_ThermImageSequence, 1, &thermo_l);
    Screen0_ThermImageSequence->fn->setImageDelay(Screen0_ThermImageSequence, 1, 1000);
    Screen0_ThermButton->fn->addChild(Screen0_ThermButton, (leWidget*)Screen0_ThermImageSequence);

    Screen0_LightButton = leButtonWidget_New();
    Screen0_LightButton->fn->setPosition(Screen0_LightButton, 258, 257);
    Screen0_LightButton->fn->setSize(Screen0_LightButton, 55, 55);
    Screen0_LightButton->fn->setBackgroundType(Screen0_LightButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LightButton->fn->setBorderType(Screen0_LightButton, LE_WIDGET_BORDER_NONE);
    Screen0_LightButton->fn->setPressedEventCallback(Screen0_LightButton, event_Screen0_LightButton_OnPressed);
    Screen0_LightButton->fn->setReleasedEventCallback(Screen0_LightButton, event_Screen0_LightButton_OnReleased);
    Screen0_ButtonsPanel->fn->addChild(Screen0_ButtonsPanel, (leWidget*)Screen0_LightButton);

    Screen0_LightImageSequence = leImageSequenceWidget_New();
    Screen0_LightImageSequence->fn->setPosition(Screen0_LightImageSequence, 0, 0);
    Screen0_LightImageSequence->fn->setSize(Screen0_LightImageSequence, 55, 55);
    Screen0_LightImageSequence->fn->setEnabled(Screen0_LightImageSequence, LE_FALSE);
    Screen0_LightImageSequence->fn->setBackgroundType(Screen0_LightImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LightImageSequence->fn->setImageCount(Screen0_LightImageSequence, 2);
    Screen0_LightImageSequence->fn->setImage(Screen0_LightImageSequence, 0, &bulb_m);
    Screen0_LightImageSequence->fn->setImageDelay(Screen0_LightImageSequence, 0, 1000);
    Screen0_LightImageSequence->fn->setImage(Screen0_LightImageSequence, 1, &bulb_l);
    Screen0_LightImageSequence->fn->setImageDelay(Screen0_LightImageSequence, 1, 1000);
    Screen0_LightButton->fn->addChild(Screen0_LightButton, (leWidget*)Screen0_LightImageSequence);

    Screen0_FanButton = leButtonWidget_New();
    Screen0_FanButton->fn->setPosition(Screen0_FanButton, 292, 187);
    Screen0_FanButton->fn->setSize(Screen0_FanButton, 55, 55);
    Screen0_FanButton->fn->setBackgroundType(Screen0_FanButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FanButton->fn->setBorderType(Screen0_FanButton, LE_WIDGET_BORDER_NONE);
    Screen0_FanButton->fn->setPressedEventCallback(Screen0_FanButton, event_Screen0_FanButton_OnPressed);
    Screen0_FanButton->fn->setReleasedEventCallback(Screen0_FanButton, event_Screen0_FanButton_OnReleased);
    Screen0_ButtonsPanel->fn->addChild(Screen0_ButtonsPanel, (leWidget*)Screen0_FanButton);

    Screen0_FanImageSequence = leImageSequenceWidget_New();
    Screen0_FanImageSequence->fn->setPosition(Screen0_FanImageSequence, 0, 0);
    Screen0_FanImageSequence->fn->setSize(Screen0_FanImageSequence, 55, 55);
    Screen0_FanImageSequence->fn->setEnabled(Screen0_FanImageSequence, LE_FALSE);
    Screen0_FanImageSequence->fn->setBackgroundType(Screen0_FanImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FanImageSequence->fn->setImageCount(Screen0_FanImageSequence, 2);
    Screen0_FanImageSequence->fn->setImage(Screen0_FanImageSequence, 0, &fan_m);
    Screen0_FanImageSequence->fn->setImageDelay(Screen0_FanImageSequence, 0, 1000);
    Screen0_FanImageSequence->fn->setImage(Screen0_FanImageSequence, 1, &fan_l);
    Screen0_FanImageSequence->fn->setImageDelay(Screen0_FanImageSequence, 1, 1000);
    Screen0_FanButton->fn->addChild(Screen0_FanButton, (leWidget*)Screen0_FanImageSequence);

    Screen0_ClockButton = leButtonWidget_New();
    Screen0_ClockButton->fn->setPosition(Screen0_ClockButton, 262, 120);
    Screen0_ClockButton->fn->setSize(Screen0_ClockButton, 55, 55);
    Screen0_ClockButton->fn->setBackgroundType(Screen0_ClockButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ClockButton->fn->setBorderType(Screen0_ClockButton, LE_WIDGET_BORDER_NONE);
    Screen0_ClockButton->fn->setPressedEventCallback(Screen0_ClockButton, event_Screen0_ClockButton_OnPressed);
    Screen0_ClockButton->fn->setReleasedEventCallback(Screen0_ClockButton, event_Screen0_ClockButton_OnReleased);
    Screen0_ButtonsPanel->fn->addChild(Screen0_ButtonsPanel, (leWidget*)Screen0_ClockButton);

    Screen0_ClockImageSequence = leImageSequenceWidget_New();
    Screen0_ClockImageSequence->fn->setPosition(Screen0_ClockImageSequence, 0, 0);
    Screen0_ClockImageSequence->fn->setSize(Screen0_ClockImageSequence, 55, 55);
    Screen0_ClockImageSequence->fn->setEnabled(Screen0_ClockImageSequence, LE_FALSE);
    Screen0_ClockImageSequence->fn->setBackgroundType(Screen0_ClockImageSequence, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ClockImageSequence->fn->setImageCount(Screen0_ClockImageSequence, 2);
    Screen0_ClockImageSequence->fn->setImage(Screen0_ClockImageSequence, 0, &clock_m);
    Screen0_ClockImageSequence->fn->setImageDelay(Screen0_ClockImageSequence, 0, 1000);
    Screen0_ClockImageSequence->fn->setImage(Screen0_ClockImageSequence, 1, &clock_l);
    Screen0_ClockImageSequence->fn->setImageDelay(Screen0_ClockImageSequence, 1, 1000);
    Screen0_ClockButton->fn->addChild(Screen0_ClockButton, (leWidget*)Screen0_ClockImageSequence);

    Screen0_UnlockLabelWidget = leLabelWidget_New();
    Screen0_UnlockLabelWidget->fn->setPosition(Screen0_UnlockLabelWidget, 146, 105);
    Screen0_UnlockLabelWidget->fn->setSize(Screen0_UnlockLabelWidget, 132, 38);
    Screen0_UnlockLabelWidget->fn->setVisible(Screen0_UnlockLabelWidget, LE_FALSE);
    Screen0_UnlockLabelWidget->fn->setScheme(Screen0_UnlockLabelWidget, &WhiteTextScheme);
    Screen0_UnlockLabelWidget->fn->setBackgroundType(Screen0_UnlockLabelWidget, LE_WIDGET_BACKGROUND_NONE);
    Screen0_UnlockLabelWidget->fn->setHAlignment(Screen0_UnlockLabelWidget, LE_HALIGN_CENTER);
    Screen0_UnlockLabelWidget->fn->setString(Screen0_UnlockLabelWidget, (leString*)&string_UnlockText);
    root1->fn->addChild(root1, (leWidget*)Screen0_UnlockLabelWidget);

    Screen0_PercentDemoPanel = leWidget_New();
    Screen0_PercentDemoPanel->fn->setPosition(Screen0_PercentDemoPanel, 100, 140);
    Screen0_PercentDemoPanel->fn->setSize(Screen0_PercentDemoPanel, 230, 220);
    Screen0_PercentDemoPanel->fn->setEnabled(Screen0_PercentDemoPanel, LE_FALSE);
    Screen0_PercentDemoPanel->fn->setScheme(Screen0_PercentDemoPanel, &ClearScheme);
    Screen0_PercentDemoPanel->fn->setBackgroundType(Screen0_PercentDemoPanel, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_PercentDemoPanel);

    Screen0_PercentValueLabel = leLabelWidget_New();
    Screen0_PercentValueLabel->fn->setPosition(Screen0_PercentValueLabel, -6, 13);
    Screen0_PercentValueLabel->fn->setSize(Screen0_PercentValueLabel, 230, 101);
    Screen0_PercentValueLabel->fn->setEnabled(Screen0_PercentValueLabel, LE_FALSE);
    Screen0_PercentValueLabel->fn->setScheme(Screen0_PercentValueLabel, &PercentScheme);
    Screen0_PercentValueLabel->fn->setBackgroundType(Screen0_PercentValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_PercentValueLabel->fn->setHAlignment(Screen0_PercentValueLabel, LE_HALIGN_CENTER);
    Screen0_PercentValueLabel->fn->setString(Screen0_PercentValueLabel, (leString*)&string_DefaultPercentString);
    Screen0_PercentDemoPanel->fn->addChild(Screen0_PercentDemoPanel, (leWidget*)Screen0_PercentValueLabel);

    Screen0_PercentImageWidget = leImageWidget_New();
    Screen0_PercentImageWidget->fn->setPosition(Screen0_PercentImageWidget, 94, 164);
    Screen0_PercentImageWidget->fn->setSize(Screen0_PercentImageWidget, 42, 38);
    Screen0_PercentImageWidget->fn->setEnabled(Screen0_PercentImageWidget, LE_FALSE);
    Screen0_PercentImageWidget->fn->setBackgroundType(Screen0_PercentImageWidget, LE_WIDGET_BACKGROUND_NONE);
    Screen0_PercentImageWidget->fn->setBorderType(Screen0_PercentImageWidget, LE_WIDGET_BORDER_NONE);
    Screen0_PercentImageWidget->fn->setImage(Screen0_PercentImageWidget, (leImage*)&bulb_m);
    Screen0_PercentDemoPanel->fn->addChild(Screen0_PercentDemoPanel, (leWidget*)Screen0_PercentImageWidget);

    Screen0_PercentSymbol = leLabelWidget_New();
    Screen0_PercentSymbol->fn->setPosition(Screen0_PercentSymbol, 98, 121);
    Screen0_PercentSymbol->fn->setSize(Screen0_PercentSymbol, 36, 34);
    Screen0_PercentSymbol->fn->setEnabled(Screen0_PercentSymbol, LE_FALSE);
    Screen0_PercentSymbol->fn->setScheme(Screen0_PercentSymbol, &PercentScheme);
    Screen0_PercentSymbol->fn->setBackgroundType(Screen0_PercentSymbol, LE_WIDGET_BACKGROUND_NONE);
    Screen0_PercentSymbol->fn->setString(Screen0_PercentSymbol, (leString*)&string_PercentSign);
    Screen0_PercentDemoPanel->fn->addChild(Screen0_PercentDemoPanel, (leWidget*)Screen0_PercentSymbol);

    Screen0_TimerDemoPanel = leWidget_New();
    Screen0_TimerDemoPanel->fn->setPosition(Screen0_TimerDemoPanel, 80, 140);
    Screen0_TimerDemoPanel->fn->setSize(Screen0_TimerDemoPanel, 271, 220);
    Screen0_TimerDemoPanel->fn->setScheme(Screen0_TimerDemoPanel, &ClearScheme);
    Screen0_TimerDemoPanel->fn->setBackgroundType(Screen0_TimerDemoPanel, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_TimerDemoPanel);

    Screen0_TimerStartStop = leButtonWidget_New();
    Screen0_TimerStartStop->fn->setPosition(Screen0_TimerStartStop, 101, 128);
    Screen0_TimerStartStop->fn->setSize(Screen0_TimerStartStop, 65, 60);
    Screen0_TimerStartStop->fn->setBackgroundType(Screen0_TimerStartStop, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TimerStartStop->fn->setBorderType(Screen0_TimerStartStop, LE_WIDGET_BORDER_NONE);
    Screen0_TimerStartStop->fn->setReleasedEventCallback(Screen0_TimerStartStop, event_Screen0_TimerStartStop_OnReleased);
    Screen0_TimerDemoPanel->fn->addChild(Screen0_TimerDemoPanel, (leWidget*)Screen0_TimerStartStop);

    Screen0_TimerStartStopImage = leImageWidget_New();
    Screen0_TimerStartStopImage->fn->setPosition(Screen0_TimerStartStopImage, 0, 0);
    Screen0_TimerStartStopImage->fn->setSize(Screen0_TimerStartStopImage, 66, 67);
    Screen0_TimerStartStopImage->fn->setEnabled(Screen0_TimerStartStopImage, LE_FALSE);
    Screen0_TimerStartStopImage->fn->setBackgroundType(Screen0_TimerStartStopImage, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TimerStartStopImage->fn->setBorderType(Screen0_TimerStartStopImage, LE_WIDGET_BORDER_NONE);
    Screen0_TimerStartStopImage->fn->setImage(Screen0_TimerStartStopImage, (leImage*)&Play);
    Screen0_TimerStartStop->fn->addChild(Screen0_TimerStartStop, (leWidget*)Screen0_TimerStartStopImage);

    Screen0_TimerMinsButton = leButtonWidget_New();
    Screen0_TimerMinsButton->fn->setPosition(Screen0_TimerMinsButton, 10, 13);
    Screen0_TimerMinsButton->fn->setSize(Screen0_TimerMinsButton, 126, 92);
    Screen0_TimerMinsButton->fn->setScheme(Screen0_TimerMinsButton, &TimerScheme);
    Screen0_TimerMinsButton->fn->setBackgroundType(Screen0_TimerMinsButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TimerMinsButton->fn->setBorderType(Screen0_TimerMinsButton, LE_WIDGET_BORDER_NONE);
    Screen0_TimerMinsButton->fn->setString(Screen0_TimerMinsButton, (leString*)&string_DefaultMinsValueString);
    Screen0_TimerMinsButton->fn->setReleasedEventCallback(Screen0_TimerMinsButton, event_Screen0_TimerMinsButton_OnReleased);
    Screen0_TimerDemoPanel->fn->addChild(Screen0_TimerDemoPanel, (leWidget*)Screen0_TimerMinsButton);

    Screen0_TimerSecsButton = leButtonWidget_New();
    Screen0_TimerSecsButton->fn->setPosition(Screen0_TimerSecsButton, 147, 16);
    Screen0_TimerSecsButton->fn->setSize(Screen0_TimerSecsButton, 115, 73);
    Screen0_TimerSecsButton->fn->setScheme(Screen0_TimerSecsButton, &TimerScheme);
    Screen0_TimerSecsButton->fn->setBackgroundType(Screen0_TimerSecsButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TimerSecsButton->fn->setBorderType(Screen0_TimerSecsButton, LE_WIDGET_BORDER_NONE);
    Screen0_TimerSecsButton->fn->setString(Screen0_TimerSecsButton, (leString*)&string_DefaultSecsValueString);
    Screen0_TimerSecsButton->fn->setReleasedEventCallback(Screen0_TimerSecsButton, event_Screen0_TimerSecsButton_OnReleased);
    Screen0_TimerDemoPanel->fn->addChild(Screen0_TimerDemoPanel, (leWidget*)Screen0_TimerSecsButton);

    Screen0_TimerMinsTag = leLabelWidget_New();
    Screen0_TimerMinsTag->fn->setPosition(Screen0_TimerMinsTag, 134, 86);
    Screen0_TimerMinsTag->fn->setSize(Screen0_TimerMinsTag, 39, 19);
    Screen0_TimerMinsTag->fn->setScheme(Screen0_TimerMinsTag, &TimerScheme);
    Screen0_TimerMinsTag->fn->setBackgroundType(Screen0_TimerMinsTag, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TimerMinsTag->fn->setString(Screen0_TimerMinsTag, (leString*)&string_MinsString);
    Screen0_TimerDemoPanel->fn->addChild(Screen0_TimerDemoPanel, (leWidget*)Screen0_TimerMinsTag);

    Screen0_TimerSecsTag = leLabelWidget_New();
    Screen0_TimerSecsTag->fn->setPosition(Screen0_TimerSecsTag, 210, 86);
    Screen0_TimerSecsTag->fn->setSize(Screen0_TimerSecsTag, 33, 21);
    Screen0_TimerSecsTag->fn->setScheme(Screen0_TimerSecsTag, &TimerScheme);
    Screen0_TimerSecsTag->fn->setBackgroundType(Screen0_TimerSecsTag, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TimerSecsTag->fn->setString(Screen0_TimerSecsTag, (leString*)&string_SecString);
    Screen0_TimerDemoPanel->fn->addChild(Screen0_TimerDemoPanel, (leWidget*)Screen0_TimerSecsTag);

    Screen0_TempDemoPanel = leWidget_New();
    Screen0_TempDemoPanel->fn->setPosition(Screen0_TempDemoPanel, 80, 140);
    Screen0_TempDemoPanel->fn->setSize(Screen0_TempDemoPanel, 270, 220);
    Screen0_TempDemoPanel->fn->setBackgroundType(Screen0_TempDemoPanel, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_TempDemoPanel);

    Screen0_TempLabel = leLabelWidget_New();
    Screen0_TempLabel->fn->setPosition(Screen0_TempLabel, 54, 15);
    Screen0_TempLabel->fn->setSize(Screen0_TempLabel, 156, 105);
    Screen0_TempLabel->fn->setScheme(Screen0_TempLabel, &TempCoolScheme);
    Screen0_TempLabel->fn->setBackgroundType(Screen0_TempLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TempLabel->fn->setHAlignment(Screen0_TempLabel, LE_HALIGN_CENTER);
    Screen0_TempLabel->fn->setString(Screen0_TempLabel, (leString*)&string_DefaultTempString);
    Screen0_TempDemoPanel->fn->addChild(Screen0_TempDemoPanel, (leWidget*)Screen0_TempLabel);

    Screen0_FahrCelsButton = leButtonWidget_New();
    Screen0_FahrCelsButton->fn->setPosition(Screen0_FahrCelsButton, 19, 11);
    Screen0_FahrCelsButton->fn->setSize(Screen0_FahrCelsButton, 228, 112);
    Screen0_FahrCelsButton->fn->setScheme(Screen0_FahrCelsButton, &WhiteTextScheme);
    Screen0_FahrCelsButton->fn->setBackgroundType(Screen0_FahrCelsButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FahrCelsButton->fn->setBorderType(Screen0_FahrCelsButton, LE_WIDGET_BORDER_NONE);
    Screen0_FahrCelsButton->fn->setReleasedEventCallback(Screen0_FahrCelsButton, event_Screen0_FahrCelsButton_OnReleased);
    Screen0_TempDemoPanel->fn->addChild(Screen0_TempDemoPanel, (leWidget*)Screen0_FahrCelsButton);

    Screen0_ImageWidget1 = leImageWidget_New();
    Screen0_ImageWidget1->fn->setPosition(Screen0_ImageWidget1, 110, 141);
    Screen0_ImageWidget1->fn->setSize(Screen0_ImageWidget1, 45, 67);
    Screen0_ImageWidget1->fn->setBackgroundType(Screen0_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget1->fn->setBorderType(Screen0_ImageWidget1, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget1->fn->setImage(Screen0_ImageWidget1, (leImage*)&thermo_l);
    Screen0_TempDemoPanel->fn->addChild(Screen0_TempDemoPanel, (leWidget*)Screen0_ImageWidget1);

    Screen0_TempUnitsLabel = leLabelWidget_New();
    Screen0_TempUnitsLabel->fn->setPosition(Screen0_TempUnitsLabel, 215, 52);
    Screen0_TempUnitsLabel->fn->setSize(Screen0_TempUnitsLabel, 39, 53);
    Screen0_TempUnitsLabel->fn->setScheme(Screen0_TempUnitsLabel, &WhiteTextScheme);
    Screen0_TempUnitsLabel->fn->setBackgroundType(Screen0_TempUnitsLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TempUnitsLabel->fn->setString(Screen0_TempUnitsLabel, (leString*)&string_FahrString);
    Screen0_TempDemoPanel->fn->addChild(Screen0_TempDemoPanel, (leWidget*)Screen0_TempUnitsLabel);

    Screen0_CenterButton = leButtonWidget_New();
    Screen0_CenterButton->fn->setPosition(Screen0_CenterButton, 170, 178);
    Screen0_CenterButton->fn->setSize(Screen0_CenterButton, 84, 79);
    Screen0_CenterButton->fn->setBackgroundType(Screen0_CenterButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_CenterButton->fn->setBorderType(Screen0_CenterButton, LE_WIDGET_BORDER_NONE);
    Screen0_CenterButton->fn->setPressedEventCallback(Screen0_CenterButton, event_Screen0_CenterButton_OnPressed);
    Screen0_CenterButton->fn->setReleasedEventCallback(Screen0_CenterButton, event_Screen0_CenterButton_OnReleased);
    root1->fn->addChild(root1, (leWidget*)Screen0_CenterButton);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

    Screen0_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);

    Screen0_OnUpdate(); // raise event
}

void screenHide_Screen0(void)
{
    Screen0_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_ImageWidget0 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_PanelWidget0 = NULL;
    Screen0_NeedlePanel = NULL;
    Screen0_GestureLabelWidget = NULL;
    Screen0_ButtonsPanel = NULL;
    Screen0_UnlockLabelWidget = NULL;
    Screen0_PercentDemoPanel = NULL;
    Screen0_TimerDemoPanel = NULL;
    Screen0_TempDemoPanel = NULL;
    Screen0_CenterButton = NULL;
    Screen0_Image_n0 = NULL;
    Screen0_Image_n1 = NULL;
    Screen0_Image_n2 = NULL;
    Screen0_Image_n3 = NULL;
    Screen0_Image_n4 = NULL;
    Screen0_Image_n5 = NULL;
    Screen0_Image_n6 = NULL;
    Screen0_Image_n7 = NULL;
    Screen0_Image_n8 = NULL;
    Screen0_Image_n9 = NULL;
    Screen0_Image_n10 = NULL;
    Screen0_Image_n11 = NULL;
    Screen0_Image_n12 = NULL;
    Screen0_Image_n13 = NULL;
    Screen0_Image_n14 = NULL;
    Screen0_Image_n15 = NULL;
    Screen0_Image_n16 = NULL;
    Screen0_Image_n17 = NULL;
    Screen0_Image_n18 = NULL;
    Screen0_Image_n19 = NULL;
    Screen0_Image_n20 = NULL;
    Screen0_Image_n21 = NULL;
    Screen0_Image_n22 = NULL;
    Screen0_Image_n23 = NULL;
    Screen0_Image_n24 = NULL;
    Screen0_Image_n25 = NULL;
    Screen0_Image_n26 = NULL;
    Screen0_Image_n27 = NULL;
    Screen0_Image_n28 = NULL;
    Screen0_Image_n29 = NULL;
    Screen0_Image_n30 = NULL;
    Screen0_Image_n31 = NULL;
    Screen0_Image_n32 = NULL;
    Screen0_Image_n33 = NULL;
    Screen0_Image_n34 = NULL;
    Screen0_Image_n35 = NULL;
    Screen0_Image_n36 = NULL;
    Screen0_Image_n37 = NULL;
    Screen0_Image_n38 = NULL;
    Screen0_Image_n39 = NULL;
    Screen0_Image_n40 = NULL;
    Screen0_Image_n41 = NULL;
    Screen0_Image_n42 = NULL;
    Screen0_Image_n43 = NULL;
    Screen0_Image_n44 = NULL;
    Screen0_Image_n45 = NULL;
    Screen0_Image_n46 = NULL;
    Screen0_Image_n47 = NULL;
    Screen0_Image_n48 = NULL;
    Screen0_Image_n49 = NULL;
    Screen0_Image_n50 = NULL;
    Screen0_Image_n51 = NULL;
    Screen0_Image_n52 = NULL;
    Screen0_Image_n53 = NULL;
    Screen0_Image_n54 = NULL;
    Screen0_Image_n55 = NULL;
    Screen0_Image_n56 = NULL;
    Screen0_Image_n57 = NULL;
    Screen0_Image_n58 = NULL;
    Screen0_Image_n59 = NULL;
    Screen0_Image_n60 = NULL;
    Screen0_Image_n61 = NULL;
    Screen0_Image_n62 = NULL;
    Screen0_Image_n63 = NULL;
    Screen0_Image_n64 = NULL;
    Screen0_Image_n65 = NULL;
    Screen0_Image_n66 = NULL;
    Screen0_Image_n67 = NULL;
    Screen0_Image_n68 = NULL;
    Screen0_Image_n69 = NULL;
    Screen0_Image_n70 = NULL;
    Screen0_Image_n71 = NULL;
    Screen0_Image_n72 = NULL;
    Screen0_Image_n73 = NULL;
    Screen0_Image_n74 = NULL;
    Screen0_Image_n75 = NULL;
    Screen0_Image_n76 = NULL;
    Screen0_Image_n92 = NULL;
    Screen0_Image_n91 = NULL;
    Screen0_Image_n90 = NULL;
    Screen0_Image_n89 = NULL;
    Screen0_Image_n88 = NULL;
    Screen0_Image_n87 = NULL;
    Screen0_Image_n86 = NULL;
    Screen0_Image_n85 = NULL;
    Screen0_Image_n84 = NULL;
    Screen0_Image_n83 = NULL;
    Screen0_Image_n82 = NULL;
    Screen0_Image_n81 = NULL;
    Screen0_Image_n80 = NULL;
    Screen0_Image_n79 = NULL;
    Screen0_Image_n78 = NULL;
    Screen0_Image_n77 = NULL;
    Screen0_MchpLogoImage = NULL;
    Screen0_HomeButton = NULL;
    Screen0_SettingsButton = NULL;
    Screen0_VolumeButton = NULL;
    Screen0_EcoButton = NULL;
    Screen0_ThermButton = NULL;
    Screen0_LightButton = NULL;
    Screen0_FanButton = NULL;
    Screen0_ClockButton = NULL;
    Screen0_HomeImageSequence = NULL;
    Screen0_SettingsImageSequence = NULL;
    Screen0_ReverseTagLabel = NULL;
    Screen0_VolumeImageSequence = NULL;
    Screen0_EcoImageSequence = NULL;
    Screen0_ThermImageSequence = NULL;
    Screen0_LightImageSequence = NULL;
    Screen0_FanImageSequence = NULL;
    Screen0_ClockImageSequence = NULL;
    Screen0_PercentValueLabel = NULL;
    Screen0_PercentImageWidget = NULL;
    Screen0_PercentSymbol = NULL;
    Screen0_TimerStartStop = NULL;
    Screen0_TimerMinsButton = NULL;
    Screen0_TimerSecsButton = NULL;
    Screen0_TimerMinsTag = NULL;
    Screen0_TimerSecsTag = NULL;
    Screen0_TimerStartStopImage = NULL;
    Screen0_TempLabel = NULL;
    Screen0_FahrCelsButton = NULL;
    Screen0_ImageWidget1 = NULL;
    Screen0_TempUnitsLabel = NULL;


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
        default:
        {
            return NULL;
        }
    }
}

