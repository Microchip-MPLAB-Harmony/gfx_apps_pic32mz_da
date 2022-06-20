---
parent: Example Applications
title: Legato Flash
nav_order: 5
---

# Legato Flash

![](./../../docs/images/legato_flash.png)

The legato_flash demonstration application serves as an external memory programmer to flash the off-chip non-volatile memory with the resources held on an Memory Storage Device (MSD), such as an USB MSD, which can then be accessed by other applications saving on-chip memory for other programs and resources.

The application [legato_quickstart_external_resources](../legato_quickstart_ext_res/readme.md) in MPLAB Harmony needs to use preloaded images/fonts from QSPI flash external non-volatile memory. This would require legato_flash to flash the required image and font resources onto the QSPI flash. Refer to [legato_quickstart_external_resources](../legato_quickstart_ext_res/readme.md) for usage model information.

![](./../../docs/images/external_resources_flash_reader_diagram.png)


|MPLABX Configuration|Board Configuration|
|:-------------------|:------------------|
|[legato_fl_mzda_cu_tm4301b.X](./firmware/legato_fl_mzda_cu_tm4301b.X/readme.md)|[PIC32MZ DA Curiosity Development Board](https://www.microchip.com/en-us/development-tool/EV87D54A) using GLCD peripheral display controller to drive the [High-Performance 4.3" WQVGA Display Module with maXTouch® Technology](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/AC320005-4)|
|[legato_fl_mzda_intddr_sk_meb2_tm4301b.X](./firmware/legato_fl_mzda_intddr_sk_meb2_tm4301b.X/readme.md)|PIC32MZ DAR Internal DDR Starter Kit with Multimedia Expansion Board II using GLCD internal graphics controller to drive the [High-Performance 4.3" WQVGA Display Module with maXTouch® Technology](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/AC320005-4)|
