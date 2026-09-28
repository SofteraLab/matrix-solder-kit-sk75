# Прошивка · Matrix Solder Kit · SK-75

МК на платі: **ATtiny85 / 45 / 25** (SOIC-8) · драйвер: **MAX7219** · матриця: **8×8**.

Скетчі — демо / навчання; прошивка через роз’єм **ISP / RST**.

## SoftSPI

| Сигнал MAX7219 | Висновок ATtiny | Arduino (ATTinyCore) |
| --- | --- | --- |
| **DIN** (IN) | **PB0** | D0 |
| **CS** | **PB3** | D3 |
| **CLK** (SCK) | **PB2** | D2 |

Живлення: **USB-C 5 В** + вимикач. Розширення: **GND · OUT · 5V · CS · IN · SCK** (каскад **OUT → IN**).

Якщо після прошивки матриця темна — спробуйте поміняти `PIN_DIN` / `PIN_CS` у скетчі під розводку плати.

## Скетчі

| Папка | Що робить |
| --- | --- |
| [`SK75_Demo`](SK75_Demo/) | Серце / смайл + дощ, іскри, змійка, сканер, кільця |
| [`SK75_Patterns`](SK75_Patterns/) | Шахівниця / хрест / рамка + м’ячик (перший тест) |
| [`SK75_Scroll`](SK75_Scroll/) | Біжучий рядок `SK75 SOFTERA` |

Драйвер: [`SoftteraMax7219/SoftteraMax7219.h`](SoftteraMax7219/SoftteraMax7219.h).

## Як прошити

1. Arduino IDE + пакет **ATTinyCore**  
2. Плата: **ATtiny85**, такт: **Internal 8 MHz**  
3. Програматор на **ISP / RST** → **Upload Using Programmer**  

Зовнішні бібліотеки не потрібні.

© Softera Lab. Демо-прошивка для купленого набору.
