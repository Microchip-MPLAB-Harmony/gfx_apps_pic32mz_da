#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme ClearScheme;
extern const leScheme BlackScheme;
extern const leScheme PanelScheme;
extern const leScheme Panel2Scheme;
extern const leScheme SizePanelScheme;
extern const leScheme SourcePanelScheme;
extern const leScheme FormatPanelScheme;
extern const leScheme FPSPanelScheme;
extern const leScheme ErrorTextScheme;

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
