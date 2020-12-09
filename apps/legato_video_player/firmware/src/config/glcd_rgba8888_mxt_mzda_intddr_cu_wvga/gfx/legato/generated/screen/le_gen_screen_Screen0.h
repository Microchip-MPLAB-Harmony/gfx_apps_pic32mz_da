#ifndef LE_GEN_SCREEN_SCREEN0_H
#define LE_GEN_SCREEN_SCREEN0_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen0_BackgroundPanel;
extern leWidget* Screen0_PanelWidget0;
extern leWidget* Screen0_PanelWidget1;
extern leWidget* Screen0_SourcePanel;
extern leWidget* Screen0_SizePanel;
extern leWidget* Screen0_FormatPanel;
extern leWidget* Screen0_FPSPanel;
extern leWidget* Screen0_MiddlePanel;
extern leImageWidget* Screen0_ImageWidget0;
extern leButtonWidget* Screen0_PlayButton;
extern leLabelWidget* Screen0_SizeLabel;
extern leLabelWidget* Screen0_MediaLabel;
extern leLabelWidget* Screen0_FormatLabel;
extern leLabelWidget* Screen0_FPSLabel;
extern leLabelWidget* Screen0_LabelWidget0;
extern leLabelWidget* Screen0_FileNameLabel;
extern leLabelWidget* Screen0_ErrorLabelWidget;
extern leButtonWidget* Screen0_SizeSelectButton;
extern leButtonWidget* Screen0_MediaSelectButton;
extern leButtonWidget* Screen0_FormatButton;
extern leButtonWidget* Screen0_ButtonFPS;
extern leButtonWidget* Screen0_FullScreenButton;
extern leButtonWidget* Screen0_ThroughputLabel;
extern leButtonWidget* Screen0_Button_SourceSD;
extern leButtonWidget* Screen0_Button_SourceUSB;
extern leLabelWidget* Screen0_InsertUSBLabel;
extern leButtonWidget* Screen0_Button_Size320x240;
extern leButtonWidget* Screen0_Button_Size480x272;
extern leButtonWidget* Screen0_Button_Size800x480;
extern leButtonWidget* Screen0_Button_FormatRGB565;
extern leButtonWidget* Screen0_Button_FormatRGBA8888;
extern leButtonWidget* Screen0_Button_FPS12;
extern leButtonWidget* Screen0_Button_FPS8;
extern leButtonWidget* Screen0_Button_FPS24;
extern leLabelWidget* Screen0_SizeValueLabel;
extern leLabelWidget* Screen0_SourceValueLabel;
extern leLabelWidget* Screen0_FormatValueLabel;
extern leLabelWidget* Screen0_FPSValueLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen0_PlayButton_OnPressed(leButtonWidget* btn);
void event_Screen0_SizeSelectButton_OnPressed(leButtonWidget* btn);
void event_Screen0_MediaSelectButton_OnPressed(leButtonWidget* btn);
void event_Screen0_FormatButton_OnPressed(leButtonWidget* btn);
void event_Screen0_ButtonFPS_OnPressed(leButtonWidget* btn);
void event_Screen0_FullScreenButton_OnPressed(leButtonWidget* btn);
void event_Screen0_FullScreenButton_OnReleased(leButtonWidget* btn);
void event_Screen0_ThroughputLabel_OnPressed(leButtonWidget* btn);
void event_Screen0_ThroughputLabel_OnReleased(leButtonWidget* btn);
void event_Screen0_Button_SourceSD_OnPressed(leButtonWidget* btn);
void event_Screen0_Button_SourceUSB_OnPressed(leButtonWidget* btn);
void event_Screen0_Button_Size320x240_OnPressed(leButtonWidget* btn);
void event_Screen0_Button_Size480x272_OnPressed(leButtonWidget* btn);
void event_Screen0_Button_Size800x480_OnPressed(leButtonWidget* btn);
void event_Screen0_Button_FormatRGB565_OnPressed(leButtonWidget* btn);
void event_Screen0_Button_FormatRGBA8888_OnPressed(leButtonWidget* btn);
void event_Screen0_Button_FPS12_OnPressed(leButtonWidget* btn);
void event_Screen0_Button_FPS8_OnPressed(leButtonWidget* btn);
void event_Screen0_Button_FPS24_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen0(void); // called when Legato is initialized
leResult screenShow_Screen0(void); // called when screen is shown
void screenHide_Screen0(void); // called when screen is hidden
void screenDestroy_Screen0(void); // called when Legato is destroyed
void screenUpdate_Screen0(void); // called when Legato is updating

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen0_OnShow(void); // called when this screen is shown
void Screen0_OnHide(void); // called when this screen is hidden
void Screen0_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN0_H
