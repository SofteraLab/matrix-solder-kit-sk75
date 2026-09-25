---
id: hardware-overview
title: Огляд плати
sidebar_position: 1
description: Матриця 8×8 LED 1206, ATtiny, MAX7219, USB-C, ISP і розширення Matrix Solder Kit SK-75.
---

<p className="brand-kicker">Апаратна частина</p>

# Огляд плати

**Matrix Solder Kit · SK-75** — навчальна плата Softera Lab, яка після збірки стає програмованою LED-матрицею.

![Як працює Matrix Solder Kit](./assets/images/uk/how-it-works.png)

## Блок-схема

```mermaid
flowchart LR
  usb["USB Type-C 5 В"] --> sw["Вимикач"]
  sw --> mcu["ATtiny85/45/25"]
  mcu --> drv["MAX7219"]
  drv --> mat["8×8 LED 1206"]
  mcu --> isp["Роз'єм ISP / RST"]
  drv --> exp["Роз'єм розширення"]
```

| Блок | Роль |
| --- | --- |
| USB Type-C | Живлення 5 В |
| ATtiny85 / 45 / 25 | МК із демо-прошивкою; можна перепрограмувати |
| MAX7219 | Драйвер LED-матриці |
| Матриця | 64 × SMD LED **1206**, сітка **8×8** |
| ISP / RST | Окремий роз’єм для перепрограмування МК |
| Розширення | Підключення додаткових матриць |

## Лицьова сторона

![Огляд плати](./assets/images/uk/board-overview.png)

| Зона | Вміст |
| --- | --- |
| Центр | Площадки 8×8 під LED 1206 |
| Ліворуч | USB Type-C |
| Верх ліворуч | Роз’єм програмування ISP / RST |
| Верхній край | Площадки додаткової матриці |

## Тильна сторона

![Електроніка з тильної сторони](./assets/images/uk/board-back.png)

| Зона | Вміст |
| --- | --- |
| MAX7219 | Драйвер матриці |
| ATtiny | МК SOIC-8 (85 / 45 / 25) |
| Обв’язка | R1–R5, C1–C3 |
| USB-C + вимикач | Ланцюг живлення |
| Розширення | GND · OUT · 5V · CS · IN · SCK |
| ISP | Роз’єм програмування |

## Комплектація

![Що в наборі](./assets/images/uk/kit-contents.png)

:::caution Інтелектуальна власність
Публічні матеріали описують роботу купленого набору. Файли KiCad / Gerber у цей репозиторій не входять.
:::
