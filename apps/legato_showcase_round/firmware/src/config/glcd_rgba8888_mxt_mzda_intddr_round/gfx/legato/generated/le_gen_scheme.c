#include "gfx/legato/generated/le_gen_scheme.h"

const leScheme DefaultScheme = 
{
    {
        { { 0xCF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0x0, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xBA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0x0, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0x0, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC675, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0x1, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0x0, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D4FF, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0xFF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xFFC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFF000000, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0x0, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme ClearScheme = 
{
    {
        { { 0xCE, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0x0, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xBA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0x0, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0x0, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC674, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0x1, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0x0, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D400, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0xFF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFF000000, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0x0, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme PercentScheme = 
{
    {
        { { 0xCF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0xD3, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xDA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0x9B, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0x9EFF, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC674, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0x9EFF, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0x9EDFFF, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D400, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0x9EDFFFFF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFF9EDFFF, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0x98, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme SubtextScheme = 
{
    {
        { { 0xCF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0xFF, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xBA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0xFF, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0xFFFF, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC675, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0xFFFF, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0xFFFFFF, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D4FF, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0xFFFFFFFF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xFFC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0xF, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme TimerScheme = 
{
    {
        { { 0xCF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0x91, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xDA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0xEC, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0xFBE0, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC674, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0xFBC1, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0xFF7F01, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D400, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0xFF7F01FF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFFFF7F01, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0xCF, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme TempCoolScheme = 
{
    {
        { { 0xCF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0xC5, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xBA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0xB7, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0xBE1F, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC675, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0xBDFF, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0xC1C1FF, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D4FF, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0xC1C1FFFF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xFFC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFFC1C1FF, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0x92, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme TempWarmScheme = 
{
    {
        { { 0xCF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0x9B, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xBA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0xF2, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0xFC10, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC675, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0xFC21, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0xFF8080, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D4FF, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0xFF8080FF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xFFC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFFFF8080, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0xD1, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme WhiteTextScheme = 
{
    {
        { { 0xCF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0xFF, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xBA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0xFF, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0xFFFF, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC675, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0xFFFF, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0xFFFFFF, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D4FF, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0xFFFFFFFF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xFFC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0xF, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme TempCozyScheme = 
{
    {
        { { 0xCF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0xCD, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xBA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0xF6, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0xFDF7, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC675, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0xFDEF, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0xFFC0C0, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D4FF, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0xFFC0C0FF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xFFC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFFFFC0C0, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0xD8, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme TempColdScheme = 
{
    {
        { { 0xCF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0x8A, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xBA, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0x93, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xC67A, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0x841F, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xC675, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0x843F, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xC8D0D4, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0x8181FF, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xC8D0D4FF, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0x8181FFFF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xFFC8D0D4, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFF8181FF, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xFC, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0x68, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};

const leScheme WhiteBackScheme = 
{
    {
        { { 0xFF, 0xCF, 0xFF, 0x80, 0x40, 0x0, 0xE1, 0x80, 0xFF, 0xE1, 0xCF, 0x0, 0x12, 0xFF, 0xE1, 0x91 } }, // GS_8
        { { 0xFF, 0xBA, 0xFF, 0x92, 0x49, 0x0, 0xDB, 0x92, 0xFF, 0xDB, 0xBA, 0x0, 0x3, 0xFF, 0xDB, 0x92 } }, // RGB_332
        { { 0xFFFF, 0xC67A, 0xFFFF, 0x8410, 0x4208, 0x0, 0xD71C, 0x8410, 0xFFFF, 0xD71C, 0xC67A, 0x0, 0x1F, 0xFFFF, 0xD71C, 0x8C92 } }, // RGB_565
        { { 0xFFFF, 0xC675, 0xFFFF, 0x8421, 0x4211, 0x1, 0xD739, 0x8421, 0xFFFF, 0xD739, 0xC675, 0x1, 0x3F, 0xFFFF, 0xD739, 0x8CA5 } }, // RGBA_5551
        { { 0xFFFFFF, 0xC8D0D4, 0xFFFFFF, 0x808080, 0x404040, 0x0, 0xD6E3E7, 0x808080, 0xFFFFFF, 0xD6E3E7, 0xC8D0D4, 0x0, 0xFF, 0xFFFFFF, 0xD6E3E7, 0x8C9294 } }, // RGB_888
        { { 0xFFFFFFFF, 0xC8D0D4FF, 0xFFFFFFFF, 0x808080FF, 0x404040FF, 0xFF, 0xD6E3E7FF, 0x808080FF, 0xFFFFFFFF, 0xD6E3E7FF, 0xC8D0D4FF, 0xFF, 0xFFFF, 0xFFFFFFFF, 0xD6E3E7FF, 0x8C9294FF } }, // RGBA_8888
        { { 0xFFFFFFFF, 0xFFC8D0D4, 0xFFFFFFFF, 0xFF808080, 0xFF404040, 0xFF000000, 0xFFD6E3E7, 0xFF808080, 0xFFFFFFFF, 0xFFD6E3E7, 0xFFC8D0D4, 0xFF000000, 0xFF0000FF, 0xFFFFFFFF, 0xFFD6E3E7, 0xFF8C9294 } }, // ARGB_8888
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } },
        { { 0xF, 0xFC, 0xF, 0x8, 0xED, 0x0, 0xFE, 0x8, 0xF, 0xFE, 0xFC, 0x0, 0xC, 0xF, 0xFE, 0xF6 } }, // INDEX_8
        { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } }, // MONOCHROME
    },
    0,
    NULL
};
