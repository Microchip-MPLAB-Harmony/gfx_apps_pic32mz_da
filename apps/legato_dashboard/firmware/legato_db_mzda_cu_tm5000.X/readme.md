
![](../../../../docs/images/mhgs.png) legato\_db\_mzda\_cu\_tm5000.X

Defining the Architecture
-------------------------

![](../../../../docs/html/legato_db_arch.png)

The demo uses pre-rotated, RAW needle sprite images in DDR to show two rotating needles overlaid on top of a dashboard background image. These images are pre-processed and drawn into DDR using the Legato Graphics library. The application code uses the Graphics Canvas library to configure sprite animation and overlay of the needles using the GLCD layers. User touch input on the display panel is received thru the PCAP capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library thru the Input System Service. The needles are rotated based on the location of the touch events on the screen.

### Demonstration Features

-   Legato Graphics Library and Graphics Canvas
-   Two interactive, touch-enabled Vehicle Dashboard User Interface designs
-   Signature application for the PIC32MZ DAR/DAS devices with Internal DDR
-   24-bit color, multi-layer, WVGA (800x480) screen design
-   16-bit RGB565 color depth support (65535 unique colors)
-   Graphics Acceleration using integrated display controller (GLCD)
-   Uses pre-rotated need images and GLCD layers to accelerate needle animation

Creating the Project Graph
--------------------------

![](../../../../docs/html/legato_db_mzda_cu_tm5000_pg.png)

Adding the **PIC32MZ DA TM5000** and **Legato Graphics w/ MXT Curiosity Pro Display** Graphics Template component into the project graph will automatically add the components needed for a graphics project and resolve their dependencies. It will also configure the pins needed to drive the external peripherals like the display.

The Graphics Canvas component is added between the GLCD and the Legato Graphics library to enable the use of the GLCD layers to overlay multiple layers, frames and to perform the sprite animation of the needle images. Inside the Canvas component, six canvas objects are configured to manage the overlay of the background, splash screen logo, left needle, right needle and the information page frame.

The OCMP1 and TMR2 components are added to enable brightness controller of the display backlight using PWM. The corresponding backlight control pin on the PIC32MZ DA is also configured to OCMP1 instead of GPIO.

**Graphics Canvas**

Graphics Canvas component is configured with 6 canvas objects to reference the following frames

-   Background
-   Information Page
-   Microchip Logo
-   MPLAB® Harmony Graphics Logo
-   Left Needle
-   Right Needle

![](../../../../docs/html/legato_db_mzda_cu_tm5000_pg1.png)

**Backlight Control**

-   The OCMP1 and TMR2 components are added into the project for backlight control
-   The OCMP1 and TMR2 components are configured as shown

![](../../../../docs/html/legato_db_mzda_cu_tm5000_pg2.png)

-   Pin RD0 is set to OC1 function to generate the PWM backlight signal. The OCMP1 and TMR2 components are added into the project for backlight control and configured as shown. Using the pin manager, pin RD0 is set to OC1 function so that it's driven as a PWM signal.

![](../../../../docs/html/legato_db_mzda_cu_tm5000_pg3.png)

Building the Application
------------------------

The parent directory for this application is gfx/apps/legato\_dashboard. To build this application, use MPLAB X IDE to open the gfx\_apps/apps/legato\_dashboard/firmware/legato\_db\_mzda\_cu\_tm5000.X project file.

The following table lists configuration properties:

|Project Name|BSP Used|Graphics Template Used|Description|
|:-----------|:-------|:---------------------|:----------|
|legato\_db\_mzda\_cu\_tm5000\_X|PIC32MZ DA Curiosity 2.0|Legato Graphics w/ PDA TM5000 Display|PIC32MZ DA Curiosity 2.0 with RGBA8888 GFX Interface and 5" WVGA PCAP Touch display|

> \*\*\_NOTE:\_\*\* This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

Configuring the Hardware
------------------------

The final setup should be:

Configure the hardware as follows:

-   Attach the 24-bit passthrough graphics interface card to the J601 connector on the PIC32MZ DA Curiosity 2.0 board.
-   Connect the ribbon cable from the WQVGA display to the J2 connector on the 24-bit passthrough graphics interface card.
-   Connect a USB cable from the host computer to the DEBUG USB port on the PIC32MZ DA Curiosity 2.0 board. This USB connection is used for power, code download and debugging.

The final hardware setup should be:

![](../../../../docs/html/legato_qs_mzda_cu_tm5000_conf1.png)

Running the Demonstration
-------------------------

![](../../../../docs/html/legato_db_splash_screen.png)

The demo first boots to a splash screen. While the splash screen is shown, the application pre-processes the needle images to DDR and renders the dashboard screens.

![](../../../../docs/html/legato_dashboard.png))

The demo will automtically transition to the main the primary dashboard screen.

-   The primary dashboard screen is displayed with an **Information Page** overlaid on top.
-   Touch the Information Page to dismiss.
-   Touching the screen to animate the needles.
-   When idle the backlight will dim, and then run Self-Demonstration mode after more idle period.
-   Swiping down from top will show the information page.
-   Swiping left or right from the edge will switch between the Primary and Secondary screens

User Interface Guide
--------------------

**Interactions**

![](../../../../docs/html/legato_db_mzda_cu_tm5000_ui1.png)

![](../../../../docs/html/legato_db_mzda_cu_tm5000_ui2.png)

**Canvas**

-   The application uses the Graphics Canvas to demonstrate advanced graphics effects thru the display controller layer functions. These effects include layer fade in/out, layer slide in/out and sprite animation.
-   Canvas objects are used to reference frames in DDR. The Graphics Canvas is used to assign a canvas frame to each GLCD layer and generate the composited frame. Effects such as fade and motion can be applied to each canvas object.

![](../../../../docs/html/legato_db_mzda_cu_tm5000_ui3.png)

**Sprite Animation**

-   A series of pre-rotated needle images are pre-processed and stored in DDR
-   GLCD layers 1 and 2 are used to display the left and right needles
-   To run the needle animation, the GLCD layer start address is set to the location of the images in DDR
-   The GLCD layer position is also adjusted to show the needles at the correct location on the screen
-   The image address in DDR, image size and position on the screen are stored in an array in order based on the angle position
-   This array is used by the application to reference the image address, size and position and sets these values to GLCD layer
-   The application uses the graphics canvas to configure the GLCD for image sprite animation

![](../../../../docs/html/legato_db_mzda_cu_tm5000_ui4.png)

* * * * *

 
