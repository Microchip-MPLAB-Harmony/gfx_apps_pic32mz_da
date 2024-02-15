#ifndef LE_GEN_SCREEN_APPLICATIONSCREEN_H
#define LE_GEN_SCREEN_APPLICATIONSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* ApplicationScreen_Layer0_FillPanel;
extern leLabelWidget* ApplicationScreen_TitleLabel;
extern leButtonWidget* ApplicationScreen_SloganButton;
extern leButtonWidget* ApplicationScreen_LogoButton;
extern leLabelWidget* ApplicationScreen_ImageTypeLabelWidget;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_ApplicationScreen_SloganButton_OnReleased(leButtonWidget* btn);
void event_ApplicationScreen_LogoButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_ApplicationScreen(void); // called when Legato is initialized
leResult screenShow_ApplicationScreen(void); // called when screen is shown
void screenHide_ApplicationScreen(void); // called when screen is hidden
void screenDestroy_ApplicationScreen(void); // called when Legato is destroyed
void screenUpdate_ApplicationScreen(void); // called when Legato is updating

leWidget* screenGetRoot_ApplicationScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_APPLICATIONSCREEN_H
