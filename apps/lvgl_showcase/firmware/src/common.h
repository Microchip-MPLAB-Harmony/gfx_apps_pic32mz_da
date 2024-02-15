/*******************************************************************************
 Common Interface Header File

 Mohit M 
 18-APR-2021
 *******************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"

/* Common Interface Functions for APP_FS */
bool COMMON_APP_FS_CheckMount(void);

#endif /* _COMMON_H */
