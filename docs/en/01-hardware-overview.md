---
id: hardware-overview
title: Board overview
sidebar_position: 1
description: 8×8 LED 1206 matrix, ATtiny, MAX7219, USB-C, ISP and expansion on Matrix Solder Kit SK-75.
---

<p className="brand-kicker">Hardware</p>

# Board overview

**Matrix Solder Kit · SK-75** is a Softera Lab soldering practice board that becomes a programmable LED matrix after assembly.

![How the Matrix Solder Kit works](../assets/images/en/how-it-works.png)

## Block diagram

```mermaid
flowchart LR
  usb["USB Type-C 5V"] --> sw["Power switch"]
  sw --> mcu["ATtiny85/45/25"]
  mcu --> drv["MAX7219"]
  drv --> mat["8×8 LED 1206"]
  mcu --> isp["ISP / RST header"]
  drv --> exp["Expansion header"]
```

| Block | Role |
| --- | --- |
| USB Type-C | 5 V power input |
| ATtiny85 / 45 / 25 | MCU with demo firmware; reprogrammable |
| MAX7219 | LED matrix driver |
| LED matrix | 64 × SMD LED **1206**, grid **8×8** |
| ISP / RST | Separate header to reprogram the MCU |
| Expansion | Daisy-chain additional matrices |

## Front side

![Board overview](../assets/images/en/board-overview.png)

| Zone | Contents |
| --- | --- |
| Center | 8×8 footprints for LED 1206 |
| Left | USB Type-C silkscreen / connector |
| Top-left | ISP / RST programming header |
| Top edge | Expansion pads for extra matrix |

## Back side

![Electronics on the back](../assets/images/en/board-back.png)

| Zone | Contents |
| --- | --- |
| MAX7219 | Matrix driver IC |
| ATtiny | SOIC-8 MCU (85 / 45 / 25) |
| Passives | R1–R5, C1–C3 |
| USB-C + switch | Power path |
| Expansion | GND · OUT · 5V · CS · IN · SCK |
| ISP | Programming header |

## Kit contents

![What's inside the kit](../assets/images/en/kit-contents.png)

:::caution Intellectual property
Public docs describe how to use the purchased kit. KiCad / Gerber files are not part of this repository.
:::
