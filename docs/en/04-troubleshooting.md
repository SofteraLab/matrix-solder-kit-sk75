---
id: troubleshooting
title: Troubleshooting
sidebar_position: 4
description: Dark pixels, no animation, ISP and daisy-chain issues on Matrix Solder Kit SK-75.
---

<p className="brand-kicker">Fix</p>

# Troubleshooting

| Symptom | Check |
| --- | --- |
| Nothing lights | USB-C cable supplies 5 V; power switch on; no short near USB |
| Demo animation missing | ATtiny orientation; MAX7219 joints; firmware present |
| Single dark LED | Polarity of that 1206; both pads soldered; LED not overheated |
| Whole row / column dark | MAX7219 bridges or cold joints; matrix row/col solder |
| Board gets hot | Remove USB immediately; inspect bridges on MAX7219 / ATtiny / USB-C |
| Cannot reprogram | ISP cable orientation (RST mark); power present during programming |
| Second matrix dark | Expansion wiring GND · OUT · 5V · CS · IN · SCK; both boards powered correctly |

:::caution Power
If the board heats right after plugging USB, unplug first. Then look for solder bridges.
:::

When asking for help, send: kit code **SK-75**, what fails (animation / pixel / ISP / daisy-chain), and clear photos of both sides.
