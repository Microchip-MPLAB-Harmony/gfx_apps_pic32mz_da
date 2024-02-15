#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme RedScheme;
extern const leScheme GreenScheme;
extern const leScheme WhiteScheme;
extern const leScheme BlueScheme;
extern const leScheme ProgressScheme;
extern const leScheme SettingsScheme;
extern const leScheme WhiteBackgroundScheme;
extern const leScheme PlayerVolScheme;
extern const leScheme InfoPageScheme;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

void legato_initialize_schemes(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LEGATO_INIT_SCHEME_H
