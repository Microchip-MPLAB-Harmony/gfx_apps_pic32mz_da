#ifndef LE_GEN_SCREEN_INTROSCREEN_H
#define LE_GEN_SCREEN_INTROSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* IntroScreen_Panel_0;
extern leImageWidget* IntroScreen_ImageWidget_0;
extern leImageWidget* IntroScreen_ImageWidget_1;
extern leButtonWidget* IntroScreen_SetupButton;
extern leButtonWidget* IntroScreen_ApplicationButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_IntroScreen_SetupButton_OnReleased(leButtonWidget* btn);
void event_IntroScreen_ApplicationButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_IntroScreen(void); // called when Legato is initialized
leResult screenShow_IntroScreen(void); // called when screen is shown
void screenHide_IntroScreen(void); // called when screen is hidden
void screenDestroy_IntroScreen(void); // called when Legato is destroyed
void screenUpdate_IntroScreen(void); // called when Legato is updating

leWidget* screenGetRoot_IntroScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_INTROSCREEN_H
