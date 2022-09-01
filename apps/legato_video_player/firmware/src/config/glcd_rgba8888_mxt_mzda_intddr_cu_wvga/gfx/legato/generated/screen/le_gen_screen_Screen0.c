#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;

leWidget* Screen0_BackgroundPanel;
leWidget* Screen0_PanelWidget0;
leWidget* Screen0_PanelWidget1;
leWidget* Screen0_SourcePanel;
leWidget* Screen0_SizePanel;
leWidget* Screen0_FormatPanel;
leWidget* Screen0_FPSPanel;
leWidget* Screen0_MiddlePanel;
leImageWidget* Screen0_ImageWidget0;
leButtonWidget* Screen0_PlayButton;
leLabelWidget* Screen0_SizeLabel;
leLabelWidget* Screen0_MediaLabel;
leLabelWidget* Screen0_FormatLabel;
leLabelWidget* Screen0_FPSLabel;
leLabelWidget* Screen0_LabelWidget0;
leLabelWidget* Screen0_FileNameLabel;
leLabelWidget* Screen0_ErrorLabelWidget;
leButtonWidget* Screen0_SizeSelectButton;
leButtonWidget* Screen0_MediaSelectButton;
leButtonWidget* Screen0_FormatButton;
leButtonWidget* Screen0_ButtonFPS;
leButtonWidget* Screen0_FullScreenButton;
leButtonWidget* Screen0_ThroughputLabel;
leButtonWidget* Screen0_Button_SourceSD;
leButtonWidget* Screen0_Button_SourceUSB;
leLabelWidget* Screen0_InsertUSBLabel;
leButtonWidget* Screen0_Button_Size320x240;
leButtonWidget* Screen0_Button_Size480x272;
leButtonWidget* Screen0_Button_Size800x480;
leButtonWidget* Screen0_Button_FormatRGB565;
leButtonWidget* Screen0_Button_FormatRGBA8888;
leButtonWidget* Screen0_Button_FPS12;
leButtonWidget* Screen0_Button_FPS8;
leButtonWidget* Screen0_Button_FPS24;
leLabelWidget* Screen0_SizeValueLabel;
leLabelWidget* Screen0_SourceValueLabel;
leLabelWidget* Screen0_FormatValueLabel;
leLabelWidget* Screen0_FPSValueLabel;

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
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_BackgroundPanel = leWidget_New();
    Screen0_BackgroundPanel->fn->setPosition(Screen0_BackgroundPanel, 0, 0);
    Screen0_BackgroundPanel->fn->setSize(Screen0_BackgroundPanel, 800, 480);
    Screen0_BackgroundPanel->fn->setScheme(Screen0_BackgroundPanel, &BlackScheme);
    Screen0_BackgroundPanel->fn->setBackgroundType(Screen0_BackgroundPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen0_BackgroundPanel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 800, 480);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget0 = leWidget_New();
    Screen0_PanelWidget0->fn->setPosition(Screen0_PanelWidget0, 0, 0);
    Screen0_PanelWidget0->fn->setSize(Screen0_PanelWidget0, 800, 480);
    Screen0_PanelWidget0->fn->setEnabled(Screen0_PanelWidget0, LE_FALSE);
    Screen0_PanelWidget0->fn->setScheme(Screen0_PanelWidget0, &ClearScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_PanelWidget0);

    Screen0_PanelWidget1 = leWidget_New();
    Screen0_PanelWidget1->fn->setPosition(Screen0_PanelWidget1, 0, 360);
    Screen0_PanelWidget1->fn->setSize(Screen0_PanelWidget1, 800, 80);
    Screen0_PanelWidget1->fn->setScheme(Screen0_PanelWidget1, &PanelScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_PanelWidget1);

    Screen0_SourcePanel = leWidget_New();
    Screen0_SourcePanel->fn->setPosition(Screen0_SourcePanel, 133, 273);
    Screen0_SourcePanel->fn->setSize(Screen0_SourcePanel, 92, 114);
    Screen0_SourcePanel->fn->setScheme(Screen0_SourcePanel, &SourcePanelScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_SourcePanel);

    Screen0_Button_SourceSD = leButtonWidget_New();
    Screen0_Button_SourceSD->fn->setPosition(Screen0_Button_SourceSD, 0, 45);
    Screen0_Button_SourceSD->fn->setSize(Screen0_Button_SourceSD, 90, 40);
    Screen0_Button_SourceSD->fn->setVisible(Screen0_Button_SourceSD, LE_FALSE);
    Screen0_Button_SourceSD->fn->setScheme(Screen0_Button_SourceSD, &SourcePanelScheme);
    Screen0_Button_SourceSD->fn->setBackgroundType(Screen0_Button_SourceSD, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_SourceSD->fn->setBorderType(Screen0_Button_SourceSD, LE_WIDGET_BORDER_NONE);
    Screen0_Button_SourceSD->fn->setString(Screen0_Button_SourceSD, (leString*)&string_Source_SD);
    Screen0_Button_SourceSD->fn->setPressedEventCallback(Screen0_Button_SourceSD, event_Screen0_Button_SourceSD_OnPressed);
    Screen0_SourcePanel->fn->addChild(Screen0_SourcePanel, (leWidget*)Screen0_Button_SourceSD);

    Screen0_Button_SourceUSB = leButtonWidget_New();
    Screen0_Button_SourceUSB->fn->setPosition(Screen0_Button_SourceUSB, 0, 0);
    Screen0_Button_SourceUSB->fn->setSize(Screen0_Button_SourceUSB, 90, 40);
    Screen0_Button_SourceUSB->fn->setVisible(Screen0_Button_SourceUSB, LE_FALSE);
    Screen0_Button_SourceUSB->fn->setScheme(Screen0_Button_SourceUSB, &SourcePanelScheme);
    Screen0_Button_SourceUSB->fn->setBackgroundType(Screen0_Button_SourceUSB, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_SourceUSB->fn->setBorderType(Screen0_Button_SourceUSB, LE_WIDGET_BORDER_NONE);
    Screen0_Button_SourceUSB->fn->setString(Screen0_Button_SourceUSB, (leString*)&string_Source_USB);
    Screen0_Button_SourceUSB->fn->setPressedEventCallback(Screen0_Button_SourceUSB, event_Screen0_Button_SourceUSB_OnPressed);
    Screen0_SourcePanel->fn->addChild(Screen0_SourcePanel, (leWidget*)Screen0_Button_SourceUSB);

    Screen0_InsertUSBLabel = leLabelWidget_New();
    Screen0_InsertUSBLabel->fn->setPosition(Screen0_InsertUSBLabel, 0, 0);
    Screen0_InsertUSBLabel->fn->setSize(Screen0_InsertUSBLabel, 93, 78);
    Screen0_InsertUSBLabel->fn->setScheme(Screen0_InsertUSBLabel, &SourcePanelScheme);
    Screen0_InsertUSBLabel->fn->setBackgroundType(Screen0_InsertUSBLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_InsertUSBLabel->fn->setHAlignment(Screen0_InsertUSBLabel, LE_HALIGN_CENTER);
    Screen0_InsertUSBLabel->fn->setString(Screen0_InsertUSBLabel, (leString*)&string_InsertUSBDrive);
    Screen0_SourcePanel->fn->addChild(Screen0_SourcePanel, (leWidget*)Screen0_InsertUSBLabel);

    Screen0_SizePanel = leWidget_New();
    Screen0_SizePanel->fn->setPosition(Screen0_SizePanel, 226, 230);
    Screen0_SizePanel->fn->setSize(Screen0_SizePanel, 92, 159);
    Screen0_SizePanel->fn->setScheme(Screen0_SizePanel, &SizePanelScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_SizePanel);

    Screen0_Button_Size320x240 = leButtonWidget_New();
    Screen0_Button_Size320x240->fn->setPosition(Screen0_Button_Size320x240, 0, 3);
    Screen0_Button_Size320x240->fn->setSize(Screen0_Button_Size320x240, 91, 40);
    Screen0_Button_Size320x240->fn->setScheme(Screen0_Button_Size320x240, &SizePanelScheme);
    Screen0_Button_Size320x240->fn->setBackgroundType(Screen0_Button_Size320x240, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_Size320x240->fn->setBorderType(Screen0_Button_Size320x240, LE_WIDGET_BORDER_NONE);
    Screen0_Button_Size320x240->fn->setString(Screen0_Button_Size320x240, (leString*)&string_Size_320x240);
    Screen0_Button_Size320x240->fn->setPressedOffset(Screen0_Button_Size320x240, 0);
    Screen0_Button_Size320x240->fn->setPressedEventCallback(Screen0_Button_Size320x240, event_Screen0_Button_Size320x240_OnPressed);
    Screen0_SizePanel->fn->addChild(Screen0_SizePanel, (leWidget*)Screen0_Button_Size320x240);

    Screen0_Button_Size480x272 = leButtonWidget_New();
    Screen0_Button_Size480x272->fn->setPosition(Screen0_Button_Size480x272, 0, 46);
    Screen0_Button_Size480x272->fn->setSize(Screen0_Button_Size480x272, 90, 40);
    Screen0_Button_Size480x272->fn->setScheme(Screen0_Button_Size480x272, &SizePanelScheme);
    Screen0_Button_Size480x272->fn->setBackgroundType(Screen0_Button_Size480x272, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_Size480x272->fn->setBorderType(Screen0_Button_Size480x272, LE_WIDGET_BORDER_NONE);
    Screen0_Button_Size480x272->fn->setString(Screen0_Button_Size480x272, (leString*)&string_Size_400x240);
    Screen0_Button_Size480x272->fn->setPressedOffset(Screen0_Button_Size480x272, 0);
    Screen0_Button_Size480x272->fn->setPressedEventCallback(Screen0_Button_Size480x272, event_Screen0_Button_Size480x272_OnPressed);
    Screen0_SizePanel->fn->addChild(Screen0_SizePanel, (leWidget*)Screen0_Button_Size480x272);

    Screen0_Button_Size800x480 = leButtonWidget_New();
    Screen0_Button_Size800x480->fn->setPosition(Screen0_Button_Size800x480, 0, 88);
    Screen0_Button_Size800x480->fn->setSize(Screen0_Button_Size800x480, 91, 40);
    Screen0_Button_Size800x480->fn->setVisible(Screen0_Button_Size800x480, LE_FALSE);
    Screen0_Button_Size800x480->fn->setScheme(Screen0_Button_Size800x480, &SizePanelScheme);
    Screen0_Button_Size800x480->fn->setBackgroundType(Screen0_Button_Size800x480, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_Size800x480->fn->setBorderType(Screen0_Button_Size800x480, LE_WIDGET_BORDER_NONE);
    Screen0_Button_Size800x480->fn->setString(Screen0_Button_Size800x480, (leString*)&string_Size_800x480);
    Screen0_Button_Size800x480->fn->setPressedEventCallback(Screen0_Button_Size800x480, event_Screen0_Button_Size800x480_OnPressed);
    Screen0_SizePanel->fn->addChild(Screen0_SizePanel, (leWidget*)Screen0_Button_Size800x480);

    Screen0_FormatPanel = leWidget_New();
    Screen0_FormatPanel->fn->setPosition(Screen0_FormatPanel, 319, 318);
    Screen0_FormatPanel->fn->setSize(Screen0_FormatPanel, 92, 71);
    Screen0_FormatPanel->fn->setScheme(Screen0_FormatPanel, &FormatPanelScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_FormatPanel);

    Screen0_Button_FormatRGB565 = leButtonWidget_New();
    Screen0_Button_FormatRGB565->fn->setPosition(Screen0_Button_FormatRGB565, 0, 0);
    Screen0_Button_FormatRGB565->fn->setSize(Screen0_Button_FormatRGB565, 90, 40);
    Screen0_Button_FormatRGB565->fn->setScheme(Screen0_Button_FormatRGB565, &FormatPanelScheme);
    Screen0_Button_FormatRGB565->fn->setBackgroundType(Screen0_Button_FormatRGB565, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_FormatRGB565->fn->setBorderType(Screen0_Button_FormatRGB565, LE_WIDGET_BORDER_NONE);
    Screen0_Button_FormatRGB565->fn->setString(Screen0_Button_FormatRGB565, (leString*)&string_Format_RGB565);
    Screen0_Button_FormatRGB565->fn->setPressedEventCallback(Screen0_Button_FormatRGB565, event_Screen0_Button_FormatRGB565_OnPressed);
    Screen0_FormatPanel->fn->addChild(Screen0_FormatPanel, (leWidget*)Screen0_Button_FormatRGB565);

    Screen0_Button_FormatRGBA8888 = leButtonWidget_New();
    Screen0_Button_FormatRGBA8888->fn->setPosition(Screen0_Button_FormatRGBA8888, 0, 45);
    Screen0_Button_FormatRGBA8888->fn->setSize(Screen0_Button_FormatRGBA8888, 90, 40);
    Screen0_Button_FormatRGBA8888->fn->setVisible(Screen0_Button_FormatRGBA8888, LE_FALSE);
    Screen0_Button_FormatRGBA8888->fn->setScheme(Screen0_Button_FormatRGBA8888, &FormatPanelScheme);
    Screen0_Button_FormatRGBA8888->fn->setBackgroundType(Screen0_Button_FormatRGBA8888, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_FormatRGBA8888->fn->setBorderType(Screen0_Button_FormatRGBA8888, LE_WIDGET_BORDER_NONE);
    Screen0_Button_FormatRGBA8888->fn->setString(Screen0_Button_FormatRGBA8888, (leString*)&string_Format_RGBA8888);
    Screen0_Button_FormatRGBA8888->fn->setPressedEventCallback(Screen0_Button_FormatRGBA8888, event_Screen0_Button_FormatRGBA8888_OnPressed);
    Screen0_FormatPanel->fn->addChild(Screen0_FormatPanel, (leWidget*)Screen0_Button_FormatRGBA8888);

    Screen0_FPSPanel = leWidget_New();
    Screen0_FPSPanel->fn->setPosition(Screen0_FPSPanel, 412, 318);
    Screen0_FPSPanel->fn->setSize(Screen0_FPSPanel, 92, 68);
    Screen0_FPSPanel->fn->setScheme(Screen0_FPSPanel, &FPSPanelScheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_FPSPanel);

    Screen0_Button_FPS12 = leButtonWidget_New();
    Screen0_Button_FPS12->fn->setPosition(Screen0_Button_FPS12, 1, 55);
    Screen0_Button_FPS12->fn->setSize(Screen0_Button_FPS12, 90, 40);
    Screen0_Button_FPS12->fn->setVisible(Screen0_Button_FPS12, LE_FALSE);
    Screen0_Button_FPS12->fn->setScheme(Screen0_Button_FPS12, &FPSPanelScheme);
    Screen0_Button_FPS12->fn->setBackgroundType(Screen0_Button_FPS12, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_FPS12->fn->setBorderType(Screen0_Button_FPS12, LE_WIDGET_BORDER_NONE);
    Screen0_Button_FPS12->fn->setString(Screen0_Button_FPS12, (leString*)&string_FPS_12);
    Screen0_Button_FPS12->fn->setPressedEventCallback(Screen0_Button_FPS12, event_Screen0_Button_FPS12_OnPressed);
    Screen0_FPSPanel->fn->addChild(Screen0_FPSPanel, (leWidget*)Screen0_Button_FPS12);

    Screen0_Button_FPS8 = leButtonWidget_New();
    Screen0_Button_FPS8->fn->setPosition(Screen0_Button_FPS8, 0, 92);
    Screen0_Button_FPS8->fn->setSize(Screen0_Button_FPS8, 90, 40);
    Screen0_Button_FPS8->fn->setVisible(Screen0_Button_FPS8, LE_FALSE);
    Screen0_Button_FPS8->fn->setScheme(Screen0_Button_FPS8, &FPSPanelScheme);
    Screen0_Button_FPS8->fn->setBackgroundType(Screen0_Button_FPS8, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_FPS8->fn->setBorderType(Screen0_Button_FPS8, LE_WIDGET_BORDER_NONE);
    Screen0_Button_FPS8->fn->setString(Screen0_Button_FPS8, (leString*)&string_FPS_8);
    Screen0_Button_FPS8->fn->setPressedEventCallback(Screen0_Button_FPS8, event_Screen0_Button_FPS8_OnPressed);
    Screen0_FPSPanel->fn->addChild(Screen0_FPSPanel, (leWidget*)Screen0_Button_FPS8);

    Screen0_Button_FPS24 = leButtonWidget_New();
    Screen0_Button_FPS24->fn->setPosition(Screen0_Button_FPS24, 0, 4);
    Screen0_Button_FPS24->fn->setSize(Screen0_Button_FPS24, 90, 40);
    Screen0_Button_FPS24->fn->setScheme(Screen0_Button_FPS24, &FPSPanelScheme);
    Screen0_Button_FPS24->fn->setBackgroundType(Screen0_Button_FPS24, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Button_FPS24->fn->setBorderType(Screen0_Button_FPS24, LE_WIDGET_BORDER_NONE);
    Screen0_Button_FPS24->fn->setString(Screen0_Button_FPS24, (leString*)&string_FPS_24);
    Screen0_Button_FPS24->fn->setPressedEventCallback(Screen0_Button_FPS24, event_Screen0_Button_FPS24_OnPressed);
    Screen0_FPSPanel->fn->addChild(Screen0_FPSPanel, (leWidget*)Screen0_Button_FPS24);

    Screen0_MiddlePanel = leWidget_New();
    Screen0_MiddlePanel->fn->setPosition(Screen0_MiddlePanel, 0, 387);
    Screen0_MiddlePanel->fn->setSize(Screen0_MiddlePanel, 800, 35);
    Screen0_MiddlePanel->fn->setScheme(Screen0_MiddlePanel, &Panel2Scheme);
    root1->fn->addChild(root1, (leWidget*)Screen0_MiddlePanel);

    Screen0_SizeValueLabel = leLabelWidget_New();
    Screen0_SizeValueLabel->fn->setPosition(Screen0_SizeValueLabel, 226, 0);
    Screen0_SizeValueLabel->fn->setSize(Screen0_SizeValueLabel, 92, 35);
    Screen0_SizeValueLabel->fn->setScheme(Screen0_SizeValueLabel, &Panel2Scheme);
    Screen0_SizeValueLabel->fn->setBackgroundType(Screen0_SizeValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SizeValueLabel->fn->setHAlignment(Screen0_SizeValueLabel, LE_HALIGN_CENTER);
    Screen0_SizeValueLabel->fn->setString(Screen0_SizeValueLabel, (leString*)&string_NoSelect);
    Screen0_MiddlePanel->fn->addChild(Screen0_MiddlePanel, (leWidget*)Screen0_SizeValueLabel);

    Screen0_SourceValueLabel = leLabelWidget_New();
    Screen0_SourceValueLabel->fn->setPosition(Screen0_SourceValueLabel, 133, 0);
    Screen0_SourceValueLabel->fn->setSize(Screen0_SourceValueLabel, 92, 35);
    Screen0_SourceValueLabel->fn->setScheme(Screen0_SourceValueLabel, &Panel2Scheme);
    Screen0_SourceValueLabel->fn->setBackgroundType(Screen0_SourceValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SourceValueLabel->fn->setHAlignment(Screen0_SourceValueLabel, LE_HALIGN_CENTER);
    Screen0_SourceValueLabel->fn->setString(Screen0_SourceValueLabel, (leString*)&string_NoSelect);
    Screen0_MiddlePanel->fn->addChild(Screen0_MiddlePanel, (leWidget*)Screen0_SourceValueLabel);

    Screen0_FormatValueLabel = leLabelWidget_New();
    Screen0_FormatValueLabel->fn->setPosition(Screen0_FormatValueLabel, 319, 0);
    Screen0_FormatValueLabel->fn->setSize(Screen0_FormatValueLabel, 92, 35);
    Screen0_FormatValueLabel->fn->setScheme(Screen0_FormatValueLabel, &Panel2Scheme);
    Screen0_FormatValueLabel->fn->setBackgroundType(Screen0_FormatValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FormatValueLabel->fn->setHAlignment(Screen0_FormatValueLabel, LE_HALIGN_CENTER);
    Screen0_FormatValueLabel->fn->setString(Screen0_FormatValueLabel, (leString*)&string_NoSelect);
    Screen0_MiddlePanel->fn->addChild(Screen0_MiddlePanel, (leWidget*)Screen0_FormatValueLabel);

    Screen0_FPSValueLabel = leLabelWidget_New();
    Screen0_FPSValueLabel->fn->setPosition(Screen0_FPSValueLabel, 411, 0);
    Screen0_FPSValueLabel->fn->setSize(Screen0_FPSValueLabel, 92, 35);
    Screen0_FPSValueLabel->fn->setScheme(Screen0_FPSValueLabel, &Panel2Scheme);
    Screen0_FPSValueLabel->fn->setBackgroundType(Screen0_FPSValueLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FPSValueLabel->fn->setHAlignment(Screen0_FPSValueLabel, LE_HALIGN_CENTER);
    Screen0_FPSValueLabel->fn->setString(Screen0_FPSValueLabel, (leString*)&string_NoSelect);
    Screen0_MiddlePanel->fn->addChild(Screen0_MiddlePanel, (leWidget*)Screen0_FPSValueLabel);

    Screen0_ImageWidget0 = leImageWidget_New();
    Screen0_ImageWidget0->fn->setPosition(Screen0_ImageWidget0, 13, 355);
    Screen0_ImageWidget0->fn->setSize(Screen0_ImageWidget0, 106, 88);
    Screen0_ImageWidget0->fn->setBackgroundType(Screen0_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget0->fn->setBorderType(Screen0_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget0->fn->setImage(Screen0_ImageWidget0, (leImage*)&VideoPlayerIcon);
    root1->fn->addChild(root1, (leWidget*)Screen0_ImageWidget0);

    Screen0_PlayButton = leButtonWidget_New();
    Screen0_PlayButton->fn->setPosition(Screen0_PlayButton, 589, 334);
    Screen0_PlayButton->fn->setSize(Screen0_PlayButton, 146, 145);
    Screen0_PlayButton->fn->setBackgroundType(Screen0_PlayButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_PlayButton->fn->setBorderType(Screen0_PlayButton, LE_WIDGET_BORDER_NONE);
    Screen0_PlayButton->fn->setPressedImage(Screen0_PlayButton, (leImage*)&PlayButton);
    Screen0_PlayButton->fn->setReleasedImage(Screen0_PlayButton, (leImage*)&PlayButton);
    Screen0_PlayButton->fn->setPressedEventCallback(Screen0_PlayButton, event_Screen0_PlayButton_OnPressed);
    root1->fn->addChild(root1, (leWidget*)Screen0_PlayButton);

    Screen0_SizeLabel = leLabelWidget_New();
    Screen0_SizeLabel->fn->setPosition(Screen0_SizeLabel, 238, 362);
    Screen0_SizeLabel->fn->setSize(Screen0_SizeLabel, 69, 25);
    Screen0_SizeLabel->fn->setScheme(Screen0_SizeLabel, &PanelScheme);
    Screen0_SizeLabel->fn->setBackgroundType(Screen0_SizeLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SizeLabel->fn->setHAlignment(Screen0_SizeLabel, LE_HALIGN_CENTER);
    Screen0_SizeLabel->fn->setString(Screen0_SizeLabel, (leString*)&string_Size);
    root1->fn->addChild(root1, (leWidget*)Screen0_SizeLabel);

    Screen0_MediaLabel = leLabelWidget_New();
    Screen0_MediaLabel->fn->setPosition(Screen0_MediaLabel, 145, 362);
    Screen0_MediaLabel->fn->setSize(Screen0_MediaLabel, 70, 25);
    Screen0_MediaLabel->fn->setScheme(Screen0_MediaLabel, &PanelScheme);
    Screen0_MediaLabel->fn->setBackgroundType(Screen0_MediaLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_MediaLabel->fn->setString(Screen0_MediaLabel, (leString*)&string_Media);
    root1->fn->addChild(root1, (leWidget*)Screen0_MediaLabel);

    Screen0_FormatLabel = leLabelWidget_New();
    Screen0_FormatLabel->fn->setPosition(Screen0_FormatLabel, 327, 363);
    Screen0_FormatLabel->fn->setSize(Screen0_FormatLabel, 76, 25);
    Screen0_FormatLabel->fn->setScheme(Screen0_FormatLabel, &PanelScheme);
    Screen0_FormatLabel->fn->setBackgroundType(Screen0_FormatLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FormatLabel->fn->setHAlignment(Screen0_FormatLabel, LE_HALIGN_CENTER);
    Screen0_FormatLabel->fn->setString(Screen0_FormatLabel, (leString*)&string_Format);
    root1->fn->addChild(root1, (leWidget*)Screen0_FormatLabel);

    Screen0_FPSLabel = leLabelWidget_New();
    Screen0_FPSLabel->fn->setPosition(Screen0_FPSLabel, 414, 362);
    Screen0_FPSLabel->fn->setSize(Screen0_FPSLabel, 72, 25);
    Screen0_FPSLabel->fn->setScheme(Screen0_FPSLabel, &PanelScheme);
    Screen0_FPSLabel->fn->setBackgroundType(Screen0_FPSLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FPSLabel->fn->setHAlignment(Screen0_FPSLabel, LE_HALIGN_CENTER);
    Screen0_FPSLabel->fn->setString(Screen0_FPSLabel, (leString*)&string_FrameRate);
    root1->fn->addChild(root1, (leWidget*)Screen0_FPSLabel);

    Screen0_LabelWidget0 = leLabelWidget_New();
    Screen0_LabelWidget0->fn->setPosition(Screen0_LabelWidget0, 465, 365);
    Screen0_LabelWidget0->fn->setSize(Screen0_LabelWidget0, 32, 25);
    Screen0_LabelWidget0->fn->setBackgroundType(Screen0_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget0->fn->setString(Screen0_LabelWidget0, (leString*)&string_max);
    root1->fn->addChild(root1, (leWidget*)Screen0_LabelWidget0);

    Screen0_FileNameLabel = leLabelWidget_New();
    Screen0_FileNameLabel->fn->setPosition(Screen0_FileNameLabel, 311, 445);
    Screen0_FileNameLabel->fn->setSize(Screen0_FileNameLabel, 301, 25);
    Screen0_FileNameLabel->fn->setVisible(Screen0_FileNameLabel, LE_FALSE);
    Screen0_FileNameLabel->fn->setScheme(Screen0_FileNameLabel, &ErrorTextScheme);
    Screen0_FileNameLabel->fn->setBackgroundType(Screen0_FileNameLabel, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_FileNameLabel);

    Screen0_ErrorLabelWidget = leLabelWidget_New();
    Screen0_ErrorLabelWidget->fn->setPosition(Screen0_ErrorLabelWidget, 132, 444);
    Screen0_ErrorLabelWidget->fn->setSize(Screen0_ErrorLabelWidget, 181, 29);
    Screen0_ErrorLabelWidget->fn->setVisible(Screen0_ErrorLabelWidget, LE_FALSE);
    Screen0_ErrorLabelWidget->fn->setScheme(Screen0_ErrorLabelWidget, &ErrorTextScheme);
    Screen0_ErrorLabelWidget->fn->setBackgroundType(Screen0_ErrorLabelWidget, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ErrorLabelWidget->fn->setString(Screen0_ErrorLabelWidget, (leString*)&string_CannotOpenString);
    root1->fn->addChild(root1, (leWidget*)Screen0_ErrorLabelWidget);

    Screen0_SizeSelectButton = leButtonWidget_New();
    Screen0_SizeSelectButton->fn->setPosition(Screen0_SizeSelectButton, 226, 360);
    Screen0_SizeSelectButton->fn->setSize(Screen0_SizeSelectButton, 90, 80);
    Screen0_SizeSelectButton->fn->setBackgroundType(Screen0_SizeSelectButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_SizeSelectButton->fn->setBorderType(Screen0_SizeSelectButton, LE_WIDGET_BORDER_NONE);
    Screen0_SizeSelectButton->fn->setPressedOffset(Screen0_SizeSelectButton, 0);
    Screen0_SizeSelectButton->fn->setPressedEventCallback(Screen0_SizeSelectButton, event_Screen0_SizeSelectButton_OnPressed);
    root1->fn->addChild(root1, (leWidget*)Screen0_SizeSelectButton);

    Screen0_MediaSelectButton = leButtonWidget_New();
    Screen0_MediaSelectButton->fn->setPosition(Screen0_MediaSelectButton, 133, 360);
    Screen0_MediaSelectButton->fn->setSize(Screen0_MediaSelectButton, 90, 80);
    Screen0_MediaSelectButton->fn->setBackgroundType(Screen0_MediaSelectButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_MediaSelectButton->fn->setBorderType(Screen0_MediaSelectButton, LE_WIDGET_BORDER_NONE);
    Screen0_MediaSelectButton->fn->setPressedEventCallback(Screen0_MediaSelectButton, event_Screen0_MediaSelectButton_OnPressed);
    root1->fn->addChild(root1, (leWidget*)Screen0_MediaSelectButton);

    Screen0_FormatButton = leButtonWidget_New();
    Screen0_FormatButton->fn->setPosition(Screen0_FormatButton, 319, 360);
    Screen0_FormatButton->fn->setSize(Screen0_FormatButton, 90, 80);
    Screen0_FormatButton->fn->setBackgroundType(Screen0_FormatButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FormatButton->fn->setBorderType(Screen0_FormatButton, LE_WIDGET_BORDER_NONE);
    Screen0_FormatButton->fn->setPressedEventCallback(Screen0_FormatButton, event_Screen0_FormatButton_OnPressed);
    root1->fn->addChild(root1, (leWidget*)Screen0_FormatButton);

    Screen0_ButtonFPS = leButtonWidget_New();
    Screen0_ButtonFPS->fn->setPosition(Screen0_ButtonFPS, 412, 360);
    Screen0_ButtonFPS->fn->setSize(Screen0_ButtonFPS, 90, 80);
    Screen0_ButtonFPS->fn->setBackgroundType(Screen0_ButtonFPS, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonFPS->fn->setBorderType(Screen0_ButtonFPS, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonFPS->fn->setPressedEventCallback(Screen0_ButtonFPS, event_Screen0_ButtonFPS_OnPressed);
    root1->fn->addChild(root1, (leWidget*)Screen0_ButtonFPS);

    Screen0_FullScreenButton = leButtonWidget_New();
    Screen0_FullScreenButton->fn->setPosition(Screen0_FullScreenButton, 736, 370);
    Screen0_FullScreenButton->fn->setSize(Screen0_FullScreenButton, 60, 70);
    Screen0_FullScreenButton->fn->setBackgroundType(Screen0_FullScreenButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_FullScreenButton->fn->setBorderType(Screen0_FullScreenButton, LE_WIDGET_BORDER_NONE);
    Screen0_FullScreenButton->fn->setToggleable(Screen0_FullScreenButton, LE_TRUE);
    Screen0_FullScreenButton->fn->setPressed(Screen0_FullScreenButton, LE_TRUE);
    Screen0_FullScreenButton->fn->setPressedImage(Screen0_FullScreenButton, (leImage*)&RectBig);
    Screen0_FullScreenButton->fn->setReleasedImage(Screen0_FullScreenButton, (leImage*)&RectSmall);
    Screen0_FullScreenButton->fn->setPressedEventCallback(Screen0_FullScreenButton, event_Screen0_FullScreenButton_OnPressed);
    Screen0_FullScreenButton->fn->setReleasedEventCallback(Screen0_FullScreenButton, event_Screen0_FullScreenButton_OnReleased);
    root1->fn->addChild(root1, (leWidget*)Screen0_FullScreenButton);

    Screen0_ThroughputLabel = leButtonWidget_New();
    Screen0_ThroughputLabel->fn->setPosition(Screen0_ThroughputLabel, 504, 387);
    Screen0_ThroughputLabel->fn->setSize(Screen0_ThroughputLabel, 88, 35);
    Screen0_ThroughputLabel->fn->setScheme(Screen0_ThroughputLabel, &Panel2Scheme);
    Screen0_ThroughputLabel->fn->setBackgroundType(Screen0_ThroughputLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ThroughputLabel->fn->setBorderType(Screen0_ThroughputLabel, LE_WIDGET_BORDER_NONE);
    Screen0_ThroughputLabel->fn->setToggleable(Screen0_ThroughputLabel, LE_TRUE);
    Screen0_ThroughputLabel->fn->setString(Screen0_ThroughputLabel, (leString*)&string_NoSelect);
    Screen0_ThroughputLabel->fn->setPressedEventCallback(Screen0_ThroughputLabel, event_Screen0_ThroughputLabel_OnPressed);
    Screen0_ThroughputLabel->fn->setReleasedEventCallback(Screen0_ThroughputLabel, event_Screen0_ThroughputLabel_OnReleased);
    root1->fn->addChild(root1, (leWidget*)Screen0_ThroughputLabel);

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

    Screen0_BackgroundPanel = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_PanelWidget0 = NULL;
    Screen0_PanelWidget1 = NULL;
    Screen0_SourcePanel = NULL;
    Screen0_SizePanel = NULL;
    Screen0_FormatPanel = NULL;
    Screen0_FPSPanel = NULL;
    Screen0_MiddlePanel = NULL;
    Screen0_ImageWidget0 = NULL;
    Screen0_PlayButton = NULL;
    Screen0_SizeLabel = NULL;
    Screen0_MediaLabel = NULL;
    Screen0_FormatLabel = NULL;
    Screen0_FPSLabel = NULL;
    Screen0_LabelWidget0 = NULL;
    Screen0_FileNameLabel = NULL;
    Screen0_ErrorLabelWidget = NULL;
    Screen0_SizeSelectButton = NULL;
    Screen0_MediaSelectButton = NULL;
    Screen0_FormatButton = NULL;
    Screen0_ButtonFPS = NULL;
    Screen0_FullScreenButton = NULL;
    Screen0_ThroughputLabel = NULL;
    Screen0_Button_SourceSD = NULL;
    Screen0_Button_SourceUSB = NULL;
    Screen0_InsertUSBLabel = NULL;
    Screen0_Button_Size320x240 = NULL;
    Screen0_Button_Size480x272 = NULL;
    Screen0_Button_Size800x480 = NULL;
    Screen0_Button_FormatRGB565 = NULL;
    Screen0_Button_FormatRGBA8888 = NULL;
    Screen0_Button_FPS12 = NULL;
    Screen0_Button_FPS8 = NULL;
    Screen0_Button_FPS24 = NULL;
    Screen0_SizeValueLabel = NULL;
    Screen0_SourceValueLabel = NULL;
    Screen0_FormatValueLabel = NULL;
    Screen0_FPSValueLabel = NULL;


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

