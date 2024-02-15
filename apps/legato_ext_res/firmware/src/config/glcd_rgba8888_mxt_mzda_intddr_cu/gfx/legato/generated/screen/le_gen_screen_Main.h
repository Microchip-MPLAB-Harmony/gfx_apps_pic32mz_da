#ifndef LE_GEN_SCREEN_MAIN_H
#define LE_GEN_SCREEN_MAIN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Main_Layer0_FillPanel;
extern leLabelWidget* Main_TitleLabel;
extern leButtonWidget* Main_SloganButton;
extern leButtonWidget* Main_LogoButton;
extern leLabelWidget* Main_ImageTypeLabelWidget;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Main_SloganButton_OnReleased(leButtonWidget* btn);
void event_Main_LogoButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Main(void); // called when Legato is initialized
leResult screenShow_Main(void); // called when screen is shown
void screenHide_Main(void); // called when screen is hidden
void screenDestroy_Main(void); // called when Legato is destroyed
void screenUpdate_Main(void); // called when Legato is updating

leWidget* screenGetRoot_Main(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MAIN_H
