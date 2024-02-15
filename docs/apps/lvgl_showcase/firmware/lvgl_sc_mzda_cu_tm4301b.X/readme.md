
![](../../../../images/mhgs.png) lvgl\_sc\_mzda\_cu\_tm4301b.X

Defining the Architecture
-------------------------

![](../../../../images/legato_qs_mzda_cu_arch.png)

This application demonstrates basic single-layer, WQVGA graphics on the PIC32MZ MCU.

User touch input on the display panel is received thru the PCAP capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library thru the Input System Service.

### Demonstration Features

-   LVGL Graphics Library
-   Reference application for the PIC32MZ DAR/DAS devices with Internal DDR
-   16-bit color, single-layer, WQVGA (480x272) screen design
-   Graphics Acceleration using integrated display controller (GLCD)

Creating the Project Graph
--------------------------

![](../../../../images/lvgl_sc_mzda_cu_wvga_pg.png)

The Project Graph diagram shows the Harmony components that are included in this application. Lines between components are drawn to satisfy components that depend on a capability that another component provides.

Building the Application
------------------------

The parent directory for this application is gfx/apps/lvgl\_showcase. To build this application, use MPLAB X IDE to open the gfx/apps/legato\_showcase/firmware/lvgl\_sc\_mzda\_cu\_tm4301b.X project file.

The following table lists configuration properties:

|Project Name|BSP Used|Graphics Template Used|Description|
|:-----------|:-------|:---------------------|:----------|
|lvgl\_sc\_mzda\_cu\_tm4301b.X|PIC32MZ DA Curiosity|Legato Graphics w/ PDA TM4301b Display|PIC32MZ DA Curiosity with RGBA8888 GFX Interface and 4.3" WQVGA PCAP Touch display|

> \*\*\_NOTE:\_\*\* This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

Configuring the Hardware
------------------------

The final setup should be:

Configure the hardware as follows:

-   Attach the 24-bit passthrough graphics interface card to the J601 connector on the PIC32MZ DA Curiosity board.
-   Connect the ribbon cable from the WQVGA display to the J2 connector on the 24-bit passthrough graphics interface card.
-   Connect a USB cable from the host computer to the DEBUG USB port on the PIC32MZ DA Curiosity board. This USB connection is used for power, code download and debugging.

**Note:** Ensure the Slider switch S1 in 24bit Passthrough Graphics Interface card is maintained at **Position 1**

The final hardware setup should be:

![](../../../../images/legato_qs_mzda_cu_tm5000_conf1.png)

Running the Demonstration
-------------------------

When power-on is successful, the demonstration will display a similar menu to that shown in the following figure.

![](../../../../images/lvgl_showcase.png)

* * * * *
