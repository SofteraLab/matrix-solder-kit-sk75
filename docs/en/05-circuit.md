---
id: circuit
title: Circuit cards
sidebar_position: 5
description: MAX7219 schematic, 8×8 multiplexing, and full block diagram for Matrix Solder Kit SK-75.
---

<p className="brand-kicker">Circuit</p>

# Circuit cards

Training slides for the kit: SPI drive, DIG/SEG multiplexing, and cascading.

## Schematic — MAX7219 + LED matrix

![Schematic MAX7219 + LED matrix](../assets/images/en/schematic-max7219.png)

USB **5 V** feeds the **ATtiny** (TinyXX) and **MAX7219**. The MCU talks SPI (**CS · DIN · SCK**). The driver scans the matrix with **DIG0–DIG7** (rows) and **SEG0–SEG7** (columns). **RSET** sets segment current.

## 8×8 multiplexing

![8×8 matrix multiplexing](../assets/images/en/multiplexing.png)

- **DIG** = rows (scanning)  
- **SEG** = columns (segments)  
- MAX7219 switches rows fast — the eye sees a solid image  
- The MCU does **not** drive each LED individually  

## Complete block diagram

![Complete kit block diagram](../assets/images/en/block-diagram.png)

Cascade extra matrices with **OUT → IN** (up to **8**). Brightness is set via **RSET**.

:::caution Intellectual property
These cards explain the purchased kit. Full manufacturing schematics and Gerbers are not published.
:::
