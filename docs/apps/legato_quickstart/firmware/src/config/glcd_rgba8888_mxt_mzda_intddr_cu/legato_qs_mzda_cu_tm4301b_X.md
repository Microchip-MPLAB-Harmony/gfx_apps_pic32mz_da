||
|![Logo](mhgs.png)|MPLAB® Harmony Graphics Suite|

-   [Examples and Demonstrations](ExamplesDemonstrations.html)
-   [Legato Applications](LegatoApplications.html)
-   [Quickstart](LegatoQuickstart.html)

legato\_qs\_mzda\_cu\_tm4301b.X

### Table of Contents

-   [Defining the Architecture](#autotoc_md194)
    -   [Demonstration Features](#autotoc_md195)
-   [Creating the Project Graph](#autotoc_md196)
-   [Building the Application](#autotoc_md197)
-   [Configuring the Hardware](#autotoc_md198)
-   [Running the Demonstration](#autotoc_md199)

Defining the Architecture
-------------------------

![](legato_qs_mzda_cu_tm4301b_arch.png)

This configuration runs on the PIC32MZ DA Curiosity 2.0 with RGB565 GFX Interface board and WQVGA display. A 16-bit RGB565 frame buffer is stored in the internal SRAM, and the Low Cost Controller-less (LCC) display driver is used to manage the DMA that transfers the framebuffer contents to the display via the EBI peripheral.

User touch input on the display panel is received thru the PCAP capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library thru the Input System Service.

### Demonstration Features

-   Legato Graphics Library
-   Input system service and touch driver
-   Time system service, timer-counter peripheral library and driver
-   GLCD display driver
-   32-bit RGBA8888 color depth support
-   I2C peripheral library and driver
-   JPEG image stored in internal flash

Creating the Project Graph
--------------------------

![](legato_qs_mzda_cu_wvga_pg.png)

The Project Graph diagram shows the Harmony components that are included in this application. Lines between components are drawn to satisfy components that depend on a capability that another component provides.

Adding the **PIC32MZ DA Curiosity 2.0 BSP** and **Legato Graphics w/ PDA TM4301B Display** Graphics Template component into the project graph will automatically add the components needed for a graphics project and resolve their dependencies. It will also configure the pins needed to drive the external peripherals like the display and the touch controller.

Building the Application
------------------------

The parent directory for this application is gfx/apps/legato\_quickstart. To build this application, use MPLAB X IDE to open the gfx/apps/legato\_quickstart/firmware/legato\_qs\_mzef\_cu\_tm4301b.X project file.

The following table lists configuration properties:

|Project Name|BSP Used|Graphics Template Used|Description|
|:-----------|:-------|:---------------------|:----------|
|legato\_qs\_mzef\_cu\_tm4301b.X|PIC32MZ DA Curiosity 2.0|Legato Graphics w/ PDA TM4301B Display|PIC32MZ EF Curiosity 2.0 with RGB565 GFX Interface and 4.3" WQVGA PCAP Touch display|

> \*\*\_NOTE:\_\*\* This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

Configuring the Hardware
------------------------

The final setup should be:

Configure the hardware as follows:

-   Attach the RGB565 GFX Interface Card to the J601 connector on the PIC32MZ DA Curiosity 2.0 board.
-   Connect the ribbon cable from the WQVGA display to the J2 connector on the RGB565 GFX Interface card.
-   Connect a USB cable from the host computer to the DEBUG USB port on the PIC32MZ DA Curiosity 2.0 board. This USB connection is used for power, code download and debugging. The final hardware setup should be:

![](https://microchip-mplab-harmony.github.io/gfx_apps/lcc_rgb565_mxt_mzef_cu_cf1.png)

Running the Demonstration
-------------------------

When power-on is successful, the demonstration will display a similar menu to that shown in the following figure (different configurations may have slight variation in the screen aspect ratio):

![](legato_qs_e70_xu_tm4301b_run1.png)

When Make changes. Generate. Run. is touched, the button will toggle with each individual touch.

![](legato_qs_e70_xu_tm4301b_run2.png)

* * * * *

 
