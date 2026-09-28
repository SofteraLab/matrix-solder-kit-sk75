# Firmware · Matrix Solder Kit · SK-75

On-board MCU: **ATtiny85 / 45 / 25** (SOIC-8) · driver: **MAX7219** · matrix: **8×8**.

These sketches are demo / learning firmware you can flash over the **ISP / RST** header.

## SoftSPI pin map

| MAX7219 signal | ATtiny pin | Arduino (ATTinyCore) |
| --- | --- | --- |
| **DIN** (IN) | **PB0** | D0 |
| **CS** | **PB3** | D3 |
| **CLK** (SCK) | **PB2** | D2 |

Power: **USB-C 5 V** + power switch. Expansion: **GND · OUT · 5V · CS · IN · SCK** (daisy-chain **OUT → IN**).

If the matrix stays blank after a correct upload, try swapping `PIN_DIN` / `PIN_CS` in the sketch to match your PCB routing, then reflash.

## Sketches

| Folder | What it does |
| --- | --- |
| [`SK75_Demo`](SK75_Demo/) | Heart / smile + rain, sparkle, snake, scanner, expand |
| [`SK75_Patterns`](SK75_Patterns/) | Checker / cross / border + bouncing pixel (good first test) |
| [`SK75_Scroll`](SK75_Scroll/) | Scrolling text `SK75 SOFTERA` |

Shared driver: [`SoftteraMax7219/SoftteraMax7219.h`](SoftteraMax7219/SoftteraMax7219.h) (also copied next to each `.ino`).

## How to flash

1. Install [Arduino IDE](https://www.arduino.cc/en/software) + **ATTinyCore** (or another ATtiny85 board package)  
2. Board: **ATtiny85**, clock: **Internal 8 MHz** (recommended; 45/25 also work if flash fits)  
3. Connect **USBasp** / Arduino-as-ISP to the **ISP / RST** header  
4. Open a sketch → **Upload Using Programmer**  

No extra libraries required.

## Notes

- Prefer **ATtiny85** (8 KB flash) for `SK75_Demo` / `SK75_Scroll`.  
- Set `NUM_DEVICES` when cascading extra matrices.  
- Brightness: `matrix.begin(0…15)`.  

© Softera Lab. Demo firmware for the purchased kit.
