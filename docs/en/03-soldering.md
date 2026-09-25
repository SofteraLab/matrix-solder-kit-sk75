---
id: soldering
title: Soldering the LED matrix
sidebar_position: 3
description: Technique for 64 × LED 1206 and SOIC parts on Matrix Solder Kit SK-75.
---

<p className="brand-kicker">Soldering</p>

# Soldering the LED matrix

The matrix is **64 × LED 1206**. Work row by row. Do not rush polarity checks.

## LED 1206 method

1. Put a little solder on one pad of the footprint.  
2. Place the LED with tweezers; reheat so it sits flat.  
3. Solder the second pad with minimal solder.  
4. Confirm cathode orientation against the silkscreen before moving on.

:::note Heat
LEDs heat faster than resistors. A short touch is enough. Long heating can kill a pixel before the first power-on.
:::

## ICs

| Ref | Part | Notes |
| --- | --- | --- |
| — | MAX7219 | Match pin 1; clear bridges between pins |
| — | ATtiny85 / 45 / 25 | SOIC-8; pin 1 to silkscreen mark |

SOIC placement: tack two diagonal pins, check alignment, then solder the rest. Clear bridges with braid + flux.

## Headers

Solder the **ISP / RST** programming header and the **expansion** pads after the matrix is populated. Keep flux off the USB-C cavity.
