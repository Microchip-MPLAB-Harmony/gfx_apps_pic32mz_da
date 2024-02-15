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
 * Legato Graphics Asset Location IDs
 *****************************************************************************/
/*********************************
 * Legato Asset Memory Location
 * Name:          SQI
 ***********************************/
#define LE_STREAM_LOCATION_ID_SQI    1

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_compressed_palette
 * Size:   256x1 pixels
 * Type:   RGB Color Palette
 * Format: RGBA_8888
 ***********************************/
extern leImage MHGS_logo_small_compressed_palette;

/*********************************
 * Legato Image Asset
 * Name:   QuickstartDown_WQVGA
 * Size:   160x74 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage QuickstartDown_WQVGA;

/*********************************
 * Legato Image Asset
 * Name:   QuickstartUp_WQVGA
 * Size:   160x74 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage QuickstartUp_WQVGA;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_smaller
 * Size:   180x169 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage MHGS_logo_smaller;

/*********************************
 * Legato Image Asset
 * Name:   mchpLogo_small
 * Size:   120x28 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage mchpLogo_small;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_256_colors
 * Size:   141x132 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage MHGS_logo_small_256_colors;

/*********************************
 * Legato Image Asset
 * Name:   LogoImage
 * Size:   40x39 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage LogoImage;

/*********************************
 * Legato Image Asset
 * Name:   Home565Gray
 * Size:   48x48 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage Home565Gray;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_raw
 * Size:   141x132 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage MHGS_logo_small_raw;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_compressed
 * Size:   141x132 pixels
 * Type:   Color Lookup Map
 * Format: INDEX_8
 ***********************************/
extern leImage MHGS_logo_small_compressed;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_jpeg
 * Size:   141x132 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage MHGS_logo_small_jpeg;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_png
 * Size:   48x45 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage MHGS_logo_small_png;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_rle
 * Size:   96x91 pixels
 * Type:   RGB Data
 * Format: RGB_565
 ***********************************/
extern leImage MHGS_logo_small_rle;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Regular
 * Height:       21
 * Baseline:     13
 * Style:        Antialias
 * Glyph Count:  96
 * Range Count:  17
 * Glyph Ranges: 0xA
                 0x20-0x7E
***********************************/
extern leRasterFont NotoSans_Regular;

/*********************************
 * Legato Font Asset
 * Name:         NotoSansCJKtc_Regular
 * Height:       23
 * Baseline:     19
 * Style:        Antialias
 * Glyph Count:  4126
 * Range Count:  66
 * Glyph Ranges: 0xA
                 0x20-0x7E
                 0x3002
                 0x4E00-0x5D98
                 0x5E8F
                 0x5F62
                 0x61C9
                 0x6309
                 0x6389
                 0x64E6
                 0x6539
                 0x65B0
                 0x662F
                 0x66F4
                 0x672A
                 0x675F
                 0x6AA2
                 0x6B64
                 0x7247
                 0x7528
                 0x7684
                 0x7A0B
                 0x7D22
                 0x7D50
                 0x7E2E
                 0x7E6A
                 0x7E7C
                 0x7E8C
                 0x7F6E
                 0x8A00
                 0x8A2D
                 0x8A9E
                 0x9019
                 0x90E8
                 0x91CD
                 0x9215
                 0x9583
                 0x95DC
                 0x9664
                 0xFF1F
***********************************/
extern leRasterFont NotoSansCJKtc_Regular;

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Bold
 * Height:       21
 * Baseline:     15
 * Style:        Plain
 * Glyph Count:  95
 * Range Count:  1
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont NotoSans_Bold;

/*****************************************************************************
 * Legato String Table
 * Encoding        UTF8
 * Language Count: 2
 * String Count:   21
 *****************************************************************************/

// language IDs
#define language_English    0
#define language_Chinese    1

// string IDs
#define stringID_DrawRaw    0
#define stringID_SettingsDownload    1
#define stringID_DrawRLE    2
#define stringID_ImageIsJPEG    3
#define stringID_Reboot    4
#define stringID_No    5
#define stringID_DisabledString    6
#define stringID_ImageIsPNG    7
#define stringID_Yes    8
#define stringID_Done    9
#define stringID_TitleString    10
#define stringID_ImageIsRLE    11
#define stringID_SQIUpdateWarning    12
#define stringID_DrawJpeg    13
#define stringID_ImageIsRaw    14
#define stringID_DrawPaletteCompressed    15
#define stringID_DemoConfig    16
#define stringID_ApplicationString    17
#define stringID_SetupString    18
#define stringID_ImageIsPaletteCompressed    19
#define stringID_DrawPNG    20

extern const leStringTable stringTable;


// string list
extern leTableString string_DrawRaw;
extern leTableString string_SettingsDownload;
extern leTableString string_DrawRLE;
extern leTableString string_ImageIsJPEG;
extern leTableString string_Reboot;
extern leTableString string_No;
extern leTableString string_DisabledString;
extern leTableString string_ImageIsPNG;
extern leTableString string_Yes;
extern leTableString string_Done;
extern leTableString string_TitleString;
extern leTableString string_ImageIsRLE;
extern leTableString string_SQIUpdateWarning;
extern leTableString string_DrawJpeg;
extern leTableString string_ImageIsRaw;
extern leTableString string_DrawPaletteCompressed;
extern leTableString string_DemoConfig;
extern leTableString string_ApplicationString;
extern leTableString string_SetupString;
extern leTableString string_ImageIsPaletteCompressed;
extern leTableString string_DrawPNG;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
