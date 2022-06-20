#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme DefaultScheme;
extern const leScheme ClearScheme;
extern const leScheme PercentScheme;
extern const leScheme SubtextScheme;
extern const leScheme TimerScheme;
extern const leScheme TempCoolScheme;
extern const leScheme TempWarmScheme;
extern const leScheme WhiteTextScheme;
extern const leScheme TempCozyScheme;
extern const leScheme TempColdScheme;
extern const leScheme WhiteBackScheme;

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
