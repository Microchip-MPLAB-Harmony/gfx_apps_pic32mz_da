/*******************************************************************************
  SYS PORTS Static Functions for PORTS System Service

  Company:
    Microchip Technology Inc.

  File Name:
    plib_gpio.c

  Summary:
    GPIO function implementations for the GPIO PLIB.

  Description:
    The GPIO PLIB provides a simple interface to manage peripheral
    input-output controller.

*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#include "plib_gpio.h"


/* Array to store callback objects of each configured interrupt */
GPIO_PIN_CALLBACK_OBJ portPinCbObj[3];

/* Array to store number of interrupts in each PORT Channel + previous interrupt count */
uint8_t portNumCb[10 + 1] = { 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 3, };

/******************************************************************************
  Function:
    GPIO_Initialize ( void )

  Summary:
    Initialize the GPIO library.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_Initialize ( void )
{

    /* PORTA Initialization */
    CNPUASET = 0xd; /* Pull-Up Enable */
    /* PORTB Initialization */
    ODCBSET = 0x2; /* Open Drain Enable */
    LATB = 0x2; /* Initial Latch Value */
    TRISBCLR = 0x500a; /* Direction Control */
    ANSELBCLR = 0x7c2b; /* Digital Mode Enable */
    CNPUBSET = 0x1000; /* Pull-Up Enable */
    /* PORTC Initialization */
    ODCCSET = 0x12; /* Open Drain Enable */
    LATC = 0x12; /* Initial Latch Value */
    TRISCCLR = 0x12; /* Direction Control */
    ANSELCCLR = 0x1e; /* Digital Mode Enable */
    CNPUCSET = 0xc; /* Pull-Up Enable */

    /* Change Notice Enable */
    CNCONCSET = _CNCONC_ON_MASK;
    PORTC;
    IEC3SET = _IEC3_CNCIE_MASK;
    /* PORTD Initialization */
    LATD = 0x0; /* Initial Latch Value */
    TRISDCLR = 0x4480; /* Direction Control */
    ANSELDCLR = 0x4000; /* Digital Mode Enable */
    CNPUDSET = 0x4400; /* Pull-Up Enable */
    /* PORTE Initialization */
    ANSELECLR = 0x200; /* Digital Mode Enable */
    /* PORTF Initialization */
    ANSELFCLR = 0x1000; /* Digital Mode Enable */
    CNPUFSET = 0x1000; /* Pull-Up Enable */
    /* PORTG Initialization */
    ANSELGCLR = 0x8380; /* Digital Mode Enable */
    CNPUGSET = 0x200; /* Pull-Up Enable */
    /* PORTH Initialization */
    LATH = 0x0; /* Initial Latch Value */
    TRISHCLR = 0x840; /* Direction Control */
    ANSELHCLR = 0x800; /* Digital Mode Enable */
    CNPUHSET = 0x4040; /* Pull-Up Enable */
    /* PORTJ Initialization */
    /* PORTK Initialization */
    LATK = 0x1; /* Initial Latch Value */
    TRISKCLR = 0x3; /* Direction Control */
    ANSELKCLR = 0x6; /* Digital Mode Enable */
    CNPUKSET = 0x6; /* Pull-Up Enable */

    /* Change Notice Enable */
    CNCONKSET = _CNCONK_ON_MASK;
    PORTK;
    IEC3SET = _IEC3_CNKIE_MASK;

    /* Unlock system for PPS configuration */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

    CFGCONbits.IOLOCK = 0;

    /* PPS Input Remapping */
    C2RXR = 13;
    C1RXR = 1;
    U4RXR = 1;
    SDI1R = 8;

    /* PPS Output Remapping */
    RPF12R = 2;
    RPG8R = 15;
    RPF2R = 15;
    RPB10R = 5;
    RPB0R = 5;
    RPD0R = 12;

        /* Lock back the system after PPS configuration */
    CFGCONbits.IOLOCK = 1;

    SYSKEY = 0x00000000;

    uint32_t i;
    /* Initialize Interrupt Pin data structures */
    portPinCbObj[0 + 0].pin = GPIO_PIN_RC2;
    
    portPinCbObj[0 + 1].pin = GPIO_PIN_RC3;
    
    portPinCbObj[2 + 0].pin = GPIO_PIN_RK2;
    
    for(i=0; i<3; i++)
    {
        portPinCbObj[i].callback = NULL;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: GPIO APIs which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    uint32_t GPIO_PortRead ( GPIO_PORT port )

  Summary:
    Read all the I/O lines of the selected port.

  Description:
    This function reads the live data values on all the I/O lines of the
    selected port.  Bit values returned in each position indicate corresponding
    pin levels.
    1 = Pin is high.
    0 = Pin is low.

    This function reads the value regardless of pin configuration, whether it is
    set as as an input, driven by the GPIO Controller, or driven by a peripheral.

  Remarks:
    If the port has less than 32-bits, unimplemented pins will read as
    low (0).
    Implemented pins are Right aligned in the 32-bit return value.
*/
uint32_t GPIO_PortRead(GPIO_PORT port)
{
    return (*(volatile uint32_t *)(&PORTA + (port * 0x40)));
}

// *****************************************************************************
/* Function:
    void GPIO_PortWrite (GPIO_PORT port, uint32_t mask, uint32_t value);

  Summary:
    Write the value on the masked I/O lines of the selected port.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PortWrite(GPIO_PORT port, uint32_t mask, uint32_t value)
{
    *(volatile uint32_t *)(&LATA + (port * 0x40)) = (*(volatile uint32_t *)(&LATA + (port * 0x40)) & (~mask)) | (mask & value);
}

// *****************************************************************************
/* Function:
    uint32_t GPIO_PortLatchRead ( GPIO_PORT port )

  Summary:
    Read the latched value on all the I/O lines of the selected port.

  Remarks:
    See plib_gpio.h for more details.
*/
uint32_t GPIO_PortLatchRead(GPIO_PORT port)
{
    return (*(volatile uint32_t *)(&LATA + (port * 0x40)));
}

// *****************************************************************************
/* Function:
    void GPIO_PortSet ( GPIO_PORT port, uint32_t mask )

  Summary:
    Set the selected IO pins of a port.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PortSet(GPIO_PORT port, uint32_t mask)
{
    *(volatile uint32_t *)(&LATASET + (port * 0x40)) = mask;
}

// *****************************************************************************
/* Function:
    void GPIO_PortClear ( GPIO_PORT port, uint32_t mask )

  Summary:
    Clear the selected IO pins of a port.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PortClear(GPIO_PORT port, uint32_t mask)
{
    *(volatile uint32_t *)(&LATACLR + (port * 0x40)) = mask;
}

// *****************************************************************************
/* Function:
    void GPIO_PortToggle ( GPIO_PORT port, uint32_t mask )

  Summary:
    Toggles the selected IO pins of a port.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PortToggle(GPIO_PORT port, uint32_t mask)
{
    *(volatile uint32_t *)(&LATAINV + (port * 0x40))= mask;
}

// *****************************************************************************
/* Function:
    void GPIO_PortInputEnable ( GPIO_PORT port, uint32_t mask )

  Summary:
    Enables selected IO pins of a port as input.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PortInputEnable(GPIO_PORT port, uint32_t mask)
{
    *(volatile uint32_t *)(&TRISASET + (port * 0x40)) = mask;
}

// *****************************************************************************
/* Function:
    void GPIO_PortOutputEnable ( GPIO_PORT port, uint32_t mask )

  Summary:
    Enables selected IO pins of a port as output(s).

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PortOutputEnable(GPIO_PORT port, uint32_t mask)
{
    *(volatile uint32_t *)(&TRISACLR + (port * 0x40)) = mask;
}

// *****************************************************************************
/* Function:
    void GPIO_PortInterruptEnable(GPIO_PORT port, uint32_t mask)

  Summary:
    Enables IO interrupt on selected IO pins of a port.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PortInterruptEnable(GPIO_PORT port, uint32_t mask)
{
    *(volatile uint32_t *)(&CNENASET + (port * 0x40)) = mask;
}

// *****************************************************************************
/* Function:
    void GPIO_PortInterruptDisable(GPIO_PORT port, uint32_t mask)

  Summary:
    Disables IO interrupt on selected IO pins of a port.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PortInterruptDisable(GPIO_PORT port, uint32_t mask)
{
    *(volatile uint32_t *)(&CNENACLR + (port * 0x40)) = mask;
}

// *****************************************************************************
// *****************************************************************************
// Section: GPIO APIs which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void GPIO_PinIntEnable(GPIO_PIN pin, GPIO_INTERRUPT_STYLE style)

  Summary:
    Enables IO interrupt of particular style on selected IO pins of a port.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PinIntEnable(GPIO_PIN pin, GPIO_INTERRUPT_STYLE style)
{
    GPIO_PORT port;
    uint32_t mask;

    port = (GPIO_PORT)(pin>>4);
    mask =  0x1 << (pin & 0xF);

    if (style == GPIO_INTERRUPT_ON_MISMATCH)
    {
        *(volatile uint32_t *)(&CNENASET + (port * 0x40)) = mask;
    }
    else if (style == GPIO_INTERRUPT_ON_RISING_EDGE)
    {
        *(volatile uint32_t *)(&CNENASET + (port * 0x40)) = mask;
        *(volatile uint32_t *)(&CNNEACLR + (port * 0x40)) = mask;
    }
    else if (style == GPIO_INTERRUPT_ON_FALLING_EDGE)
    {
        *(volatile uint32_t *)(&CNENACLR + (port * 0x40)) = mask;
        *(volatile uint32_t *)(&CNNEASET + (port * 0x40)) = mask;
    }
    else if (style == GPIO_INTERRUPT_ON_BOTH_EDGES)
    {
        *(volatile uint32_t *)(&CNENASET + (port * 0x40)) = mask;
        *(volatile uint32_t *)(&CNNEASET + (port * 0x40)) = mask;
    }
}

// *****************************************************************************
/* Function:
    void GPIO_PinIntDisable(GPIO_PIN pin)

  Summary:
    Disables IO interrupt on selected IO pins of a port.

  Remarks:
    See plib_gpio.h for more details.
*/
void GPIO_PinIntDisable(GPIO_PIN pin)
{
    GPIO_PORT port;
    uint32_t mask;
    
    port = (GPIO_PORT)(pin>>4);
    mask =  0x1 << (pin & 0xF);

    *(volatile uint32_t *)(&CNENACLR + (port * 0x40)) = mask;
    *(volatile uint32_t *)(&CNNEACLR + (port * 0x40)) = mask;
}
// *****************************************************************************
/* Function:
    bool GPIO_PinInterruptCallbackRegister(
        GPIO_PIN pin,
        const GPIO_PIN_CALLBACK callback,
        uintptr_t context
    );

  Summary:
    Allows application to register callback for configured pin.

  Remarks:
    See plib_gpio.h for more details.
*/
bool GPIO_PinInterruptCallbackRegister(
    GPIO_PIN pin,
    const GPIO_PIN_CALLBACK callback,
    uintptr_t context
)
{
    uint8_t i;
    uint8_t portIndex;

    portIndex = pin >> 4;

    for(i = portNumCb[portIndex]; i < portNumCb[portIndex +1]; i++)
    {
        if (portPinCbObj[i].pin == pin)
        {
            portPinCbObj[i].callback = callback;
            portPinCbObj[i].context  = context;
            return true;
        }
    }
    return false;
}

// *****************************************************************************
// *****************************************************************************
// Section: Local Function Implementation
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
/* Function:
    void CHANGE_NOTICE_C_InterruptHandler(void)

  Summary:
    Interrupt Handler for change notice interrupt for channel C.

  Remarks:
	It is an internal function called from ISR, user should not call it directly.
*/
    
void CHANGE_NOTICE_C_InterruptHandler(void)
{
    uint8_t i;
    uint32_t status;

    status  = CNSTATC;
    status &= CNENC;

    PORTC;
    IFS3CLR = _IFS3_CNCIF_MASK;

    /* Check pending events and call callback if registered */
    for(i = 0; i < 2; i++)
    {
        if((status & (1 << (portPinCbObj[i].pin & 0xF))) && (portPinCbObj[i].callback != NULL))
        {
            portPinCbObj[i].callback (portPinCbObj[i].pin, portPinCbObj[i].context);
        }
    }
}

// *****************************************************************************
/* Function:
    void CHANGE_NOTICE_K_InterruptHandler(void)

  Summary:
    Interrupt Handler for change notice interrupt for channel K.

  Remarks:
	It is an internal function called from ISR, user should not call it directly.
*/
    
void CHANGE_NOTICE_K_InterruptHandler(void)
{
    uint8_t i;
    uint32_t status;

    status  = CNSTATK;
    status &= CNENK;

    PORTK;
    IFS3CLR = _IFS3_CNKIF_MASK;

    /* Check pending events and call callback if registered */
    for(i = 2; i < 3; i++)
    {
        if((status & (1 << (portPinCbObj[i].pin & 0xF))) && (portPinCbObj[i].callback != NULL))
        {
            portPinCbObj[i].callback (portPinCbObj[i].pin, portPinCbObj[i].context);
        }
    }
}


/*******************************************************************************
 End of File
*/
