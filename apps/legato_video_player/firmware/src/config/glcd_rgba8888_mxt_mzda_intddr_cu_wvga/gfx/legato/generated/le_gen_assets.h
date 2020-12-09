/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.


  Description:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.

*******************************************************************************/


// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C)  Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

// DOM-IGNORE-END

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

extern const lePalette leGlobalPalette;

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   PlayButton
 * Size:   120x116 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage PlayButton;

/*********************************
 * Legato Image Asset
 * Name:   PauseButton
 * Size:   120x116 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage PauseButton;

/*********************************
 * Legato Image Asset
 * Name:   VideoPlayerIcon
 * Size:   80x62 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage VideoPlayerIcon;

/*********************************
 * Legato Image Asset
 * Name:   RectSmall
 * Size:   30x18 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage RectSmall;

/*********************************
 * Legato Image Asset
 * Name:   RectBig
 * Size:   40x23 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage RectBig;

/*********************************
 * Legato Image Asset
 * Name:   stopbutton
 * Size:   120x116 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage stopbutton;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Medium
 * Height:       21
 * Baseline:     17
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  8
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont NotoSans_Medium;

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Medium_Select
 * Height:       21
 * Baseline:     13
 * Style:        Antialias
 * Glyph Count:  96
 * Range Count:  19
 * Glyph Ranges: 0xA
                 0x20-0x7E
***********************************/
extern leRasterFont NotoSans_Medium_Select;

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_MediumItalic
 * Height:       21
 * Baseline:     10
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  4
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont NotoSans_MediumItalic;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   19
 *****************************************************************************/

// language IDs
#define language_Default    0

// string IDs
#define stringID_InsertUSBDrive    0
#define stringID_Format_RGBA8888    1
#define stringID_Source_Flash    2
#define stringID_CannotOpenString    3
#define stringID_Size    4
#define stringID_Format_RGB565    5
#define stringID_FPS_12    6
#define stringID_FPS_8    7
#define stringID_max    8
#define stringID_Source_SD    9
#define stringID_Source_USB    10
#define stringID_Size_400x240    11
#define stringID_FPS_24    12
#define stringID_Format    13
#define stringID_FrameRate    14
#define stringID_NoSelect    15
#define stringID_Size_800x480    16
#define stringID_Media    17
#define stringID_Size_320x240    18

extern const leStringTable stringTable;


// string list
extern leTableString string_InsertUSBDrive;
extern leTableString string_Format_RGBA8888;
extern leTableString string_Source_Flash;
extern leTableString string_CannotOpenString;
extern leTableString string_Size;
extern leTableString string_Format_RGB565;
extern leTableString string_FPS_12;
extern leTableString string_FPS_8;
extern leTableString string_max;
extern leTableString string_Source_SD;
extern leTableString string_Source_USB;
extern leTableString string_Size_400x240;
extern leTableString string_FPS_24;
extern leTableString string_Format;
extern leTableString string_FrameRate;
extern leTableString string_NoSelect;
extern leTableString string_Size_800x480;
extern leTableString string_Media;
extern leTableString string_Size_320x240;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
