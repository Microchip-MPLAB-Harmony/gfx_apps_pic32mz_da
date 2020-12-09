#ifndef LE_GEN_SCREEN_LAUNCH_H
#define LE_GEN_SCREEN_LAUNCH_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Launch_PanelWidget0;
extern leButtonWidget* Launch_ButtonWidget_LaunchLabel;
extern leButtonWidget* Launch_ButtonWidget_GoToMain;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Launch_ButtonWidget_LaunchLabel_OnReleased(leButtonWidget* btn);
void event_Launch_ButtonWidget_GoToMain_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Launch(void); // called when Legato is initialized
leResult screenShow_Launch(void); // called when screen is shown
void screenHide_Launch(void); // called when screen is hidden
void screenDestroy_Launch(void); // called when Legato is destroyed
void screenUpdate_Launch(void); // called when Legato is updating

leWidget* screenGetRoot_Launch(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_LAUNCH_H
