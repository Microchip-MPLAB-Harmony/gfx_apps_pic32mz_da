#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   18
 *****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned short - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned byte[3] - the offset of the string codepoint data in
 *                      the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 *     unsigned short - length of the string in bytes (encoding dependent)
 *     codepoint data - the string data
 ****************************************************************************/

const uint8_t stringTable_data[176] =
{
    0x12,0x00,0x01,0x00,0x02,0x4C,0x00,0x00,0x03,0x50,0x00,0x00,0x03,0x64,0x00,0x00,
    0x03,0x68,0x00,0x00,0x01,0x6E,0x00,0x00,0x02,0x72,0x00,0x00,0x02,0x76,0x00,0x00,
    0x03,0x7A,0x00,0x00,0x02,0x84,0x00,0x00,0x02,0x88,0x00,0x00,0x01,0x8C,0x00,0x00,
    0x03,0x92,0x00,0x00,0x04,0x98,0x00,0x00,0x02,0x9C,0x00,0x00,0x02,0xA0,0x00,0x00,
    0x02,0xA4,0x00,0x00,0x02,0xA8,0x00,0x00,0x05,0xAC,0x00,0x00,0x02,0x00,0xBA,0x43,
    0x12,0x00,0x44,0x72,0x61,0x77,0x20,0x27,0x53,0x27,0x20,0x74,0x6F,0x0A,0x75,0x6E,
    0x6C,0x6F,0x63,0x6B,0x01,0x00,0x72,0x00,0x03,0x00,0x6D,0x69,0x6E,0x00,0x02,0x00,
    0x39,0x30,0x01,0x00,0x2A,0x00,0x01,0x00,0x4D,0x00,0x08,0x00,0x4C,0x69,0x67,0x68,
    0x74,0x69,0x6E,0x67,0x01,0x00,0x32,0x00,0x01,0x00,0x2F,0x00,0x03,0x00,0x31,0x30,
    0x30,0x00,0x03,0x00,0x73,0x65,0x63,0x00,0x02,0x00,0x35,0x39,0x01,0x00,0x53,0x00,
    0x01,0x00,0x3F,0x00,0x01,0x00,0x25,0x00,0x02,0x00,0xBA,0x46,0x02,0x00,0x35,0x39,
};

/* font asset pointer list */
leFont* fontList[6] =
{
    (leFont*)&NotoSans_Regular,
    (leFont*)&PercentFont,
    (leFont*)&SubLabelFont,
    (leFont*)&SmallTagFont,
    (leFont*)&TimerFont,
    (leFont*)&TimerFont_S,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        176, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};


// string list
leTableString string_CelsString;
leTableString string_UnlockText;
leTableString string_ReverseString;
leTableString string_MinsString;
leTableString string_DefaultTempString;
leTableString string_StarString;
leTableString string_MString;
leTableString string_LightingString;
leTableString string_TwoString;
leTableString string_CheckString;
leTableString string_DefaultPercentString;
leTableString string_SecString;
leTableString string_DefaultMinsValueString;
leTableString string_SString;
leTableString string_AlphaString;
leTableString string_PercentSign;
leTableString string_FahrString;
leTableString string_DefaultSecsValueString;

void initializeStrings(void)
{
    leTableString_Constructor(&string_CelsString, stringID_CelsString);
    leTableString_Constructor(&string_UnlockText, stringID_UnlockText);
    leTableString_Constructor(&string_ReverseString, stringID_ReverseString);
    leTableString_Constructor(&string_MinsString, stringID_MinsString);
    leTableString_Constructor(&string_DefaultTempString, stringID_DefaultTempString);
    leTableString_Constructor(&string_StarString, stringID_StarString);
    leTableString_Constructor(&string_MString, stringID_MString);
    leTableString_Constructor(&string_LightingString, stringID_LightingString);
    leTableString_Constructor(&string_TwoString, stringID_TwoString);
    leTableString_Constructor(&string_CheckString, stringID_CheckString);
    leTableString_Constructor(&string_DefaultPercentString, stringID_DefaultPercentString);
    leTableString_Constructor(&string_SecString, stringID_SecString);
    leTableString_Constructor(&string_DefaultMinsValueString, stringID_DefaultMinsValueString);
    leTableString_Constructor(&string_SString, stringID_SString);
    leTableString_Constructor(&string_AlphaString, stringID_AlphaString);
    leTableString_Constructor(&string_PercentSign, stringID_PercentSign);
    leTableString_Constructor(&string_FahrString, stringID_FahrString);
    leTableString_Constructor(&string_DefaultSecsValueString, stringID_DefaultSecsValueString);
}
