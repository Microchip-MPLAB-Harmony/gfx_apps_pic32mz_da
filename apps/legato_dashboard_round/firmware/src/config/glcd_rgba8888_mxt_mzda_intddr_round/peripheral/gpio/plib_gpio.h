/*******************************************************************************
  GPIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_gpio.h

  Summary:
    GPIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (GPIO) module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PLIB_GPIO_H
#define PLIB_GPIO_H

#include <device.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


/*** Macros for GPIO_RB3 pin ***/
#define GPIO_RB3_Set()               (LATBSET = (1<<3))
#define GPIO_RB3_Clear()             (LATBCLR = (1<<3))
#define GPIO_RB3_Toggle()            (LATBINV= (1<<3))
#define GPIO_RB3_OutputEnable()      (TRISBCLR = (1<<3))
#define GPIO_RB3_InputEnable()       (TRISBSET = (1<<3))
#define GPIO_RB3_Get()               ((PORTB >> 3) & 0x1)
#define GPIO_RB3_PIN                  GPIO_PIN_RB3

/*** Macros for GPIO_RB13_SW4 pin ***/
#define GPIO_RB13_SW4_Set()               (LATBSET = (1<<13))
#define GPIO_RB13_SW4_Clear()             (LATBCLR = (1<<13))
#define GPIO_RB13_SW4_Toggle()            (LATBINV= (1<<13))
#define GPIO_RB13_SW4_OutputEnable()      (TRISBCLR = (1<<13))
#define GPIO_RB13_SW4_InputEnable()       (TRISBSET = (1<<13))
#define GPIO_RB13_SW4_Get()               ((PORTB >> 13) & 0x1)
#define GPIO_RB13_SW4_PIN                  GPIO_PIN_RB13

/*** Macros for GPIO_RB1_LED_B pin ***/
#define GPIO_RB1_LED_B_Set()               (LATBSET = (1<<1))
#define GPIO_RB1_LED_B_Clear()             (LATBCLR = (1<<1))
#define GPIO_RB1_LED_B_Toggle()            (LATBINV= (1<<1))
#define GPIO_RB1_LED_B_OutputEnable()      (TRISBCLR = (1<<1))
#define GPIO_RB1_LED_B_InputEnable()       (TRISBSET = (1<<1))
#define GPIO_RB1_LED_B_Get()               ((PORTB >> 1) & 0x1)
#define GPIO_RB1_LED_B_PIN                  GPIO_PIN_RB1

/*** Macros for GPIO_RB11_SW1 pin ***/
#define GPIO_RB11_SW1_Set()               (LATBSET = (1<<11))
#define GPIO_RB11_SW1_Clear()             (LATBCLR = (1<<11))
#define GPIO_RB11_SW1_Toggle()            (LATBINV= (1<<11))
#define GPIO_RB11_SW1_OutputEnable()      (TRISBCLR = (1<<11))
#define GPIO_RB11_SW1_InputEnable()       (TRISBSET = (1<<11))
#define GPIO_RB11_SW1_Get()               ((PORTB >> 11) & 0x1)
#define GPIO_RB11_SW1_PIN                  GPIO_PIN_RB11

/*** Macros for GPIO_RC2_SW_CW pin ***/
#define GPIO_RC2_SW_CW_Set()               (LATCSET = (1<<2))
#define GPIO_RC2_SW_CW_Clear()             (LATCCLR = (1<<2))
#define GPIO_RC2_SW_CW_Toggle()            (LATCINV= (1<<2))
#define GPIO_RC2_SW_CW_OutputEnable()      (TRISCCLR = (1<<2))
#define GPIO_RC2_SW_CW_InputEnable()       (TRISCSET = (1<<2))
#define GPIO_RC2_SW_CW_Get()               ((PORTC >> 2) & 0x1)
#define GPIO_RC2_SW_CW_PIN                  GPIO_PIN_RC2
#define GPIO_RC2_SW_CW_InterruptEnable()   (CNENCSET = (1<<2))
#define GPIO_RC2_SW_CW_InterruptDisable()  (CNENCCLR = (1<<2))

/*** Macros for GPIO_RC3_SW_CCW pin ***/
#define GPIO_RC3_SW_CCW_Set()               (LATCSET = (1<<3))
#define GPIO_RC3_SW_CCW_Clear()             (LATCCLR = (1<<3))
#define GPIO_RC3_SW_CCW_Toggle()            (LATCINV= (1<<3))
#define GPIO_RC3_SW_CCW_OutputEnable()      (TRISCCLR = (1<<3))
#define GPIO_RC3_SW_CCW_InputEnable()       (TRISCSET = (1<<3))
#define GPIO_RC3_SW_CCW_Get()               ((PORTC >> 3) & 0x1)
#define GPIO_RC3_SW_CCW_PIN                  GPIO_PIN_RC3
#define GPIO_RC3_SW_CCW_InterruptEnable()   (CNENCSET = (1<<3))
#define GPIO_RC3_SW_CCW_InterruptDisable()  (CNENCCLR = (1<<3))

/*** Macros for GPIO_RC4_LED_G pin ***/
#define GPIO_RC4_LED_G_Set()               (LATCSET = (1<<4))
#define GPIO_RC4_LED_G_Clear()             (LATCCLR = (1<<4))
#define GPIO_RC4_LED_G_Toggle()            (LATCINV= (1<<4))
#define GPIO_RC4_LED_G_OutputEnable()      (TRISCCLR = (1<<4))
#define GPIO_RC4_LED_G_InputEnable()       (TRISCSET = (1<<4))
#define GPIO_RC4_LED_G_Get()               ((PORTC >> 4) & 0x1)
#define GPIO_RC4_LED_G_PIN                  GPIO_PIN_RC4

/*** Macros for GPIO_RC1_LED_R pin ***/
#define GPIO_RC1_LED_R_Set()               (LATCSET = (1<<1))
#define GPIO_RC1_LED_R_Clear()             (LATCCLR = (1<<1))
#define GPIO_RC1_LED_R_Toggle()            (LATCINV= (1<<1))
#define GPIO_RC1_LED_R_OutputEnable()      (TRISCCLR = (1<<1))
#define GPIO_RC1_LED_R_InputEnable()       (TRISCSET = (1<<1))
#define GPIO_RC1_LED_R_Get()               ((PORTC >> 1) & 0x1)
#define GPIO_RC1_LED_R_PIN                  GPIO_PIN_RC1

/*** Macros for RF12_UART4_TX pin ***/
#define RF12_UART4_TX_Get()               ((PORTF >> 12) & 0x1)
#define RF12_UART4_TX_PIN                  GPIO_PIN_RF12

/*** Macros for RG9_UART4_RX pin ***/
#define RG9_UART4_RX_Get()               ((PORTG >> 9) & 0x1)
#define RG9_UART4_RX_PIN                  GPIO_PIN_RG9

/*** Macros for GPIO_RG15_SW2 pin ***/
#define GPIO_RG15_SW2_Set()               (LATGSET = (1<<15))
#define GPIO_RG15_SW2_Clear()             (LATGCLR = (1<<15))
#define GPIO_RG15_SW2_Toggle()            (LATGINV= (1<<15))
#define GPIO_RG15_SW2_OutputEnable()      (TRISGCLR = (1<<15))
#define GPIO_RG15_SW2_InputEnable()       (TRISGSET = (1<<15))
#define GPIO_RG15_SW2_Get()               ((PORTG >> 15) & 0x1)
#define GPIO_RG15_SW2_PIN                  GPIO_PIN_RG15

/*** Macros for DRV_TOUCH_PIN_INT pin ***/
#define DRV_TOUCH_PIN_INT_Set()               (LATHSET = (1<<14))
#define DRV_TOUCH_PIN_INT_Clear()             (LATHCLR = (1<<14))
#define DRV_TOUCH_PIN_INT_Toggle()            (LATHINV= (1<<14))
#define DRV_TOUCH_PIN_INT_OutputEnable()      (TRISHCLR = (1<<14))
#define DRV_TOUCH_PIN_INT_InputEnable()       (TRISHSET = (1<<14))
#define DRV_TOUCH_PIN_INT_Get()               ((PORTH >> 14) & 0x1)
#define DRV_TOUCH_PIN_INT_PIN                  GPIO_PIN_RH14

/*** Macros for SDCD pin ***/
#define SDCD_Get()               ((PORTA >> 0) & 0x1)
#define SDCD_PIN                  GPIO_PIN_RA0

/*** Macros for SDCK pin ***/
#define SDCK_Get()               ((PORTA >> 6) & 0x1)
#define SDCK_PIN                  GPIO_PIN_RA6

/*** Macros for SDDATA3 pin ***/
#define SDDATA3_Get()               ((PORTA >> 7) & 0x1)
#define SDDATA3_PIN                  GPIO_PIN_RA7

/*** Macros for SDDATA1 pin ***/
#define SDDATA1_Get()               ((PORTG >> 12) & 0x1)
#define SDDATA1_PIN                  GPIO_PIN_RG12

/*** Macros for SDDATA0 pin ***/
#define SDDATA0_Get()               ((PORTG >> 13) & 0x1)
#define SDDATA0_PIN                  GPIO_PIN_RG13

/*** Macros for SDDATA2 pin ***/
#define SDDATA2_Get()               ((PORTG >> 14) & 0x1)
#define SDDATA2_PIN                  GPIO_PIN_RG14

/*** Macros for SDCMD pin ***/
#define SDCMD_Get()               ((PORTD >> 4) & 0x1)
#define SDCMD_PIN                  GPIO_PIN_RD4

/*** Macros for RESX pin ***/
#define RESX_Set()               (LATDSET = (1<<10))
#define RESX_Clear()             (LATDCLR = (1<<10))
#define RESX_Toggle()            (LATDINV= (1<<10))
#define RESX_OutputEnable()      (TRISDCLR = (1<<10))
#define RESX_InputEnable()       (TRISDSET = (1<<10))
#define RESX_Get()               ((PORTD >> 10) & 0x1)
#define RESX_PIN                  GPIO_PIN_RD10

/*** Macros for WDRV_WINC_RESETN pin ***/
#define WDRV_WINC_RESETN_Set()               (LATHSET = (1<<6))
#define WDRV_WINC_RESETN_Clear()             (LATHCLR = (1<<6))
#define WDRV_WINC_RESETN_Toggle()            (LATHINV= (1<<6))
#define WDRV_WINC_RESETN_OutputEnable()      (TRISHCLR = (1<<6))
#define WDRV_WINC_RESETN_InputEnable()       (TRISHSET = (1<<6))
#define WDRV_WINC_RESETN_Get()               ((PORTH >> 6) & 0x1)
#define WDRV_WINC_RESETN_PIN                  GPIO_PIN_RH6

/*** Macros for GPIO_RH12_SW3 pin ***/
#define GPIO_RH12_SW3_Set()               (LATHSET = (1<<12))
#define GPIO_RH12_SW3_Clear()             (LATHCLR = (1<<12))
#define GPIO_RH12_SW3_Toggle()            (LATHINV= (1<<12))
#define GPIO_RH12_SW3_OutputEnable()      (TRISHCLR = (1<<12))
#define GPIO_RH12_SW3_InputEnable()       (TRISHSET = (1<<12))
#define GPIO_RH12_SW3_Get()               ((PORTH >> 12) & 0x1)
#define GPIO_RH12_SW3_PIN                  GPIO_PIN_RH12

/*** Macros for BACKLIGHT_TYPE_2 pin ***/
#define BACKLIGHT_TYPE_2_Set()               (LATDSET = (1<<7))
#define BACKLIGHT_TYPE_2_Clear()             (LATDCLR = (1<<7))
#define BACKLIGHT_TYPE_2_Toggle()            (LATDINV= (1<<7))
#define BACKLIGHT_TYPE_2_OutputEnable()      (TRISDCLR = (1<<7))
#define BACKLIGHT_TYPE_2_InputEnable()       (TRISDSET = (1<<7))
#define BACKLIGHT_TYPE_2_Get()               ((PORTD >> 7) & 0x1)
#define BACKLIGHT_TYPE_2_PIN                  GPIO_PIN_RD7

/*** Macros for GPIO_RK2_PUSH_SW pin ***/
#define GPIO_RK2_PUSH_SW_Set()               (LATKSET = (1<<2))
#define GPIO_RK2_PUSH_SW_Clear()             (LATKCLR = (1<<2))
#define GPIO_RK2_PUSH_SW_Toggle()            (LATKINV= (1<<2))
#define GPIO_RK2_PUSH_SW_OutputEnable()      (TRISKCLR = (1<<2))
#define GPIO_RK2_PUSH_SW_InputEnable()       (TRISKSET = (1<<2))
#define GPIO_RK2_PUSH_SW_Get()               ((PORTK >> 2) & 0x1)
#define GPIO_RK2_PUSH_SW_PIN                  GPIO_PIN_RK2
#define GPIO_RK2_PUSH_SW_InterruptEnable()   (CNENKSET = (1<<2))
#define GPIO_RK2_PUSH_SW_InterruptDisable()  (CNENKCLR = (1<<2))

/*** Macros for DISPLAY_ENABLE pin ***/
#define DISPLAY_ENABLE_Set()               (LATKSET = (1<<1))
#define DISPLAY_ENABLE_Clear()             (LATKCLR = (1<<1))
#define DISPLAY_ENABLE_Toggle()            (LATKINV= (1<<1))
#define DISPLAY_ENABLE_OutputEnable()      (TRISKCLR = (1<<1))
#define DISPLAY_ENABLE_InputEnable()       (TRISKSET = (1<<1))
#define DISPLAY_ENABLE_Get()               ((PORTK >> 1) & 0x1)
#define DISPLAY_ENABLE_PIN                  GPIO_PIN_RK1

/*** Macros for WDRV_WINC_CHIP_EN pin ***/
#define WDRV_WINC_CHIP_EN_Set()               (LATHSET = (1<<11))
#define WDRV_WINC_CHIP_EN_Clear()             (LATHCLR = (1<<11))
#define WDRV_WINC_CHIP_EN_Toggle()            (LATHINV= (1<<11))
#define WDRV_WINC_CHIP_EN_OutputEnable()      (TRISHCLR = (1<<11))
#define WDRV_WINC_CHIP_EN_InputEnable()       (TRISHSET = (1<<11))
#define WDRV_WINC_CHIP_EN_Get()               ((PORTH >> 11) & 0x1)
#define WDRV_WINC_CHIP_EN_PIN                  GPIO_PIN_RH11

/*** Macros for SDO pin ***/
#define SDO_Set()               (LATDSET = (1<<14))
#define SDO_Clear()             (LATDCLR = (1<<14))
#define SDO_Toggle()            (LATDINV= (1<<14))
#define SDO_OutputEnable()      (TRISDCLR = (1<<14))
#define SDO_InputEnable()       (TRISDSET = (1<<14))
#define SDO_Get()               ((PORTD >> 14) & 0x1)
#define SDO_PIN                  GPIO_PIN_RD14

/*** Macros for SCK pin ***/
#define SCK_Set()               (LATBSET = (1<<14))
#define SCK_Clear()             (LATBCLR = (1<<14))
#define SCK_Toggle()            (LATBINV= (1<<14))
#define SCK_OutputEnable()      (TRISBCLR = (1<<14))
#define SCK_InputEnable()       (TRISBSET = (1<<14))
#define SCK_Get()               ((PORTB >> 14) & 0x1)
#define SCK_PIN                  GPIO_PIN_RB14

/*** Macros for SDI pin ***/
#define SDI_Set()               (LATCSET = (1<<14))
#define SDI_Clear()             (LATCCLR = (1<<14))
#define SDI_Toggle()            (LATCINV= (1<<14))
#define SDI_OutputEnable()      (TRISCCLR = (1<<14))
#define SDI_InputEnable()       (TRISCSET = (1<<14))
#define SDI_Get()               ((PORTC >> 14) & 0x1)
#define SDI_PIN                  GPIO_PIN_RC14

/*** Macros for CSX pin ***/
#define CSX_Set()               (LATBSET = (1<<12))
#define CSX_Clear()             (LATBCLR = (1<<12))
#define CSX_Toggle()            (LATBINV= (1<<12))
#define CSX_OutputEnable()      (TRISBCLR = (1<<12))
#define CSX_InputEnable()       (TRISBSET = (1<<12))
#define CSX_Get()               ((PORTB >> 12) & 0x1)
#define CSX_PIN                  GPIO_PIN_RB12


// *****************************************************************************
/* GPIO Port

  Summary:
    Identifies the available GPIO Ports.

  Description:
    This enumeration identifies the available GPIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/

typedef enum
{
    GPIO_PORT_A = 0,
    GPIO_PORT_B = 1,
    GPIO_PORT_C = 2,
    GPIO_PORT_D = 3,
    GPIO_PORT_E = 4,
    GPIO_PORT_F = 5,
    GPIO_PORT_G = 6,
    GPIO_PORT_H = 7,
    GPIO_PORT_J = 8,
    GPIO_PORT_K = 9,
} GPIO_PORT;

typedef enum
{
    GPIO_INTERRUPT_ON_MISMATCH,
    GPIO_INTERRUPT_ON_RISING_EDGE,
    GPIO_INTERRUPT_ON_FALLING_EDGE,
    GPIO_INTERRUPT_ON_BOTH_EDGES,
}GPIO_INTERRUPT_STYLE;

// *****************************************************************************
/* GPIO Port Pins

  Summary:
    Identifies the available GPIO port pins.

  Description:
    This enumeration identifies the available GPIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/

typedef enum
{
    GPIO_PIN_RA0 = 0,
    GPIO_PIN_RA1 = 1,
    GPIO_PIN_RA2 = 2,
    GPIO_PIN_RA3 = 3,
    GPIO_PIN_RA4 = 4,
    GPIO_PIN_RA5 = 5,
    GPIO_PIN_RA6 = 6,
    GPIO_PIN_RA7 = 7,
    GPIO_PIN_RA9 = 9,
    GPIO_PIN_RA10 = 10,
    GPIO_PIN_RA14 = 14,
    GPIO_PIN_RA15 = 15,
    GPIO_PIN_RB0 = 16,
    GPIO_PIN_RB1 = 17,
    GPIO_PIN_RB2 = 18,
    GPIO_PIN_RB3 = 19,
    GPIO_PIN_RB4 = 20,
    GPIO_PIN_RB5 = 21,
    GPIO_PIN_RB6 = 22,
    GPIO_PIN_RB7 = 23,
    GPIO_PIN_RB8 = 24,
    GPIO_PIN_RB9 = 25,
    GPIO_PIN_RB10 = 26,
    GPIO_PIN_RB11 = 27,
    GPIO_PIN_RB12 = 28,
    GPIO_PIN_RB13 = 29,
    GPIO_PIN_RB14 = 30,
    GPIO_PIN_RB15 = 31,
    GPIO_PIN_RC1 = 33,
    GPIO_PIN_RC2 = 34,
    GPIO_PIN_RC3 = 35,
    GPIO_PIN_RC4 = 36,
    GPIO_PIN_RC12 = 44,
    GPIO_PIN_RC13 = 45,
    GPIO_PIN_RC14 = 46,
    GPIO_PIN_RC15 = 47,
    GPIO_PIN_RD0 = 48,
    GPIO_PIN_RD1 = 49,
    GPIO_PIN_RD2 = 50,
    GPIO_PIN_RD3 = 51,
    GPIO_PIN_RD4 = 52,
    GPIO_PIN_RD5 = 53,
    GPIO_PIN_RD6 = 54,
    GPIO_PIN_RD7 = 55,
    GPIO_PIN_RD9 = 57,
    GPIO_PIN_RD10 = 58,
    GPIO_PIN_RD11 = 59,
    GPIO_PIN_RD12 = 60,
    GPIO_PIN_RD13 = 61,
    GPIO_PIN_RD14 = 62,
    GPIO_PIN_RD15 = 63,
    GPIO_PIN_RE0 = 64,
    GPIO_PIN_RE1 = 65,
    GPIO_PIN_RE2 = 66,
    GPIO_PIN_RE3 = 67,
    GPIO_PIN_RE4 = 68,
    GPIO_PIN_RE5 = 69,
    GPIO_PIN_RE6 = 70,
    GPIO_PIN_RE7 = 71,
    GPIO_PIN_RE8 = 72,
    GPIO_PIN_RE9 = 73,
    GPIO_PIN_RF0 = 80,
    GPIO_PIN_RF1 = 81,
    GPIO_PIN_RF2 = 82,
    GPIO_PIN_RF3 = 83,
    GPIO_PIN_RF4 = 84,
    GPIO_PIN_RF5 = 85,
    GPIO_PIN_RF8 = 88,
    GPIO_PIN_RF12 = 92,
    GPIO_PIN_RF13 = 93,
    GPIO_PIN_RG0 = 96,
    GPIO_PIN_RG1 = 97,
    GPIO_PIN_RG6 = 102,
    GPIO_PIN_RG7 = 103,
    GPIO_PIN_RG8 = 104,
    GPIO_PIN_RG9 = 105,
    GPIO_PIN_RG12 = 108,
    GPIO_PIN_RG13 = 109,
    GPIO_PIN_RG14 = 110,
    GPIO_PIN_RG15 = 111,
    GPIO_PIN_RH0 = 112,
    GPIO_PIN_RH1 = 113,
    GPIO_PIN_RH2 = 114,
    GPIO_PIN_RH3 = 115,
    GPIO_PIN_RH4 = 116,
    GPIO_PIN_RH5 = 117,
    GPIO_PIN_RH6 = 118,
    GPIO_PIN_RH7 = 119,
    GPIO_PIN_RH8 = 120,
    GPIO_PIN_RH9 = 121,
    GPIO_PIN_RH10 = 122,
    GPIO_PIN_RH11 = 123,
    GPIO_PIN_RH12 = 124,
    GPIO_PIN_RH13 = 125,
    GPIO_PIN_RH14 = 126,
    GPIO_PIN_RH15 = 127,
    GPIO_PIN_RJ0 = 128,
    GPIO_PIN_RJ1 = 129,
    GPIO_PIN_RJ2 = 130,
    GPIO_PIN_RJ3 = 131,
    GPIO_PIN_RJ4 = 132,
    GPIO_PIN_RJ5 = 133,
    GPIO_PIN_RJ6 = 134,
    GPIO_PIN_RJ7 = 135,
    GPIO_PIN_RJ8 = 136,
    GPIO_PIN_RJ9 = 137,
    GPIO_PIN_RJ10 = 138,
    GPIO_PIN_RJ11 = 139,
    GPIO_PIN_RJ12 = 140,
    GPIO_PIN_RJ13 = 141,
    GPIO_PIN_RJ14 = 142,
    GPIO_PIN_RJ15 = 143,
    GPIO_PIN_RK0 = 144,
    GPIO_PIN_RK1 = 145,
    GPIO_PIN_RK2 = 146,
    GPIO_PIN_RK3 = 147,
    GPIO_PIN_RK4 = 148,
    GPIO_PIN_RK5 = 149,
    GPIO_PIN_RK6 = 150,
    GPIO_PIN_RK7 = 151,

    /* This element should not be used in any of the GPIO APIs.
       It will be used by other modules or application to denote that none of the GPIO Pin is used */
    GPIO_PIN_NONE = -1

} GPIO_PIN;

typedef  void (*GPIO_PIN_CALLBACK) ( GPIO_PIN pin, uintptr_t context);

void GPIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

uint32_t GPIO_PortRead(GPIO_PORT port);

void GPIO_PortWrite(GPIO_PORT port, uint32_t mask, uint32_t value);

uint32_t GPIO_PortLatchRead ( GPIO_PORT port );

void GPIO_PortSet(GPIO_PORT port, uint32_t mask);

void GPIO_PortClear(GPIO_PORT port, uint32_t mask);

void GPIO_PortToggle(GPIO_PORT port, uint32_t mask);

void GPIO_PortInputEnable(GPIO_PORT port, uint32_t mask);

void GPIO_PortOutputEnable(GPIO_PORT port, uint32_t mask);

void GPIO_PortInterruptEnable(GPIO_PORT port, uint32_t mask);

void GPIO_PortInterruptDisable(GPIO_PORT port, uint32_t mask);

// *****************************************************************************
// *****************************************************************************
// Section: Local Data types and Prototypes
// *****************************************************************************
// *****************************************************************************

typedef struct {

    /* target pin */
    GPIO_PIN                 pin;

    /* Callback for event on target pin*/
    GPIO_PIN_CALLBACK        callback;

    /* Callback Context */
    uintptr_t               context;

} GPIO_PIN_CALLBACK_OBJ;

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

static inline void GPIO_PinWrite(GPIO_PIN pin, bool value)
{
    GPIO_PortWrite((GPIO_PORT)(pin>>4), (uint32_t)(0x1) << (pin & 0xF), (uint32_t)(value) << (pin & 0xF));
}

static inline bool GPIO_PinRead(GPIO_PIN pin)
{
    return (bool)(((GPIO_PortRead((GPIO_PORT)(pin>>4))) >> (pin & 0xF)) & 0x1);
}

static inline bool GPIO_PinLatchRead(GPIO_PIN pin)
{
    return (bool)((GPIO_PortLatchRead((GPIO_PORT)(pin>>4)) >> (pin & 0xF)) & 0x1);
}

static inline void GPIO_PinToggle(GPIO_PIN pin)
{
    GPIO_PortToggle((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}

static inline void GPIO_PinSet(GPIO_PIN pin)
{
    GPIO_PortSet((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}

static inline void GPIO_PinClear(GPIO_PIN pin)
{
    GPIO_PortClear((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}

static inline void GPIO_PinInputEnable(GPIO_PIN pin)
{
    GPIO_PortInputEnable((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}

static inline void GPIO_PinOutputEnable(GPIO_PIN pin)
{
    GPIO_PortOutputEnable((GPIO_PORT)(pin>>4), 0x1 << (pin & 0xF));
}

#define GPIO_PinInterruptEnable(pin)       GPIO_PinIntEnable(pin, GPIO_INTERRUPT_ON_MISMATCH)
#define GPIO_PinInterruptDisable(pin)      GPIO_PinIntDisable(pin)

void GPIO_PinIntEnable(GPIO_PIN pin, GPIO_INTERRUPT_STYLE style);
void GPIO_PinIntDisable(GPIO_PIN pin);

bool GPIO_PinInterruptCallbackRegister(
    GPIO_PIN pin,
    const   GPIO_PIN_CALLBACK callBack,
    uintptr_t context
);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_GPIO_H
