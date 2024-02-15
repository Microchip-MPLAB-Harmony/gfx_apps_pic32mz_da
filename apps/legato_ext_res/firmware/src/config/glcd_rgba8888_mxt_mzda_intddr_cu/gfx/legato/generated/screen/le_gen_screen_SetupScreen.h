#ifndef LE_GEN_SCREEN_SETUPSCREEN_H
#define LE_GEN_SCREEN_SETUPSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* SetupScreen_PanelWidget0;
extern leLabelWidget* SetupScreen_LabelWidget0;
extern leButtonWidget* SetupScreen_UpdateSQIButton;
extern leLabelWidget* SetupScreen_SQIUpdateStatusString;
extern leButtonWidget* SetupScreen_RebootButtonWidget0;
extern leLabelWidget* SetupScreen_TimeStampString;
extern leLabelWidget* SetupScreen_SQIUpdateWarningLabel;
extern leButtonWidget* SetupScreen_EraseYesButton;
extern leButtonWidget* SetupScreen_EraseNoButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_SetupScreen_UpdateSQIButton_OnPressed(leButtonWidget* btn);
void event_SetupScreen_UpdateSQIButton_OnReleased(leButtonWidget* btn);
void event_SetupScreen_RebootButtonWidget0_OnPressed(leButtonWidget* btn);
void event_SetupScreen_EraseYesButton_OnReleased(leButtonWidget* btn);
void event_SetupScreen_EraseNoButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SetupScreen(void); // called when Legato is initialized
leResult screenShow_SetupScreen(void); // called when screen is shown
void screenHide_SetupScreen(void); // called when screen is hidden
void screenDestroy_SetupScreen(void); // called when Legato is destroyed
void screenUpdate_SetupScreen(void); // called when Legato is updating

leWidget* screenGetRoot_SetupScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void SetupScreen_OnShow(void); // called when this screen is shown
void SetupScreen_OnHide(void); // called when this screen is hidden
void SetupScreen_OnUpdate(void); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SETUPSCREEN_H
