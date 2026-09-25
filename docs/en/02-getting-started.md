---
id: getting-started
title: Assembly
sidebar_position: 2
description: Assembly order for Matrix Solder Kit SK-75.
---

<p className="brand-kicker">Build</p>

# Assembly

Follow the kit card order. Passives and ICs first, then the LED matrix, then headers and power-on check.

![Assembly order](../assets/images/en/assembly-order.png)

## Tools

- Soldering iron ~300–350 °C, fine tip  
- Antistatic tweezers  
- Flux and thin solder (0.3–0.5 mm)  
- IPA for cleaning  
- Board stand  

## Steps

| Step | Action |
| --- | --- |
| 1 | Solder passives **R1–R5**, **C1–C3** |
| 2 | Solder **MAX7219** driver |
| 3 | Solder **ATtiny** MCU (85 / 45 / 25) — match pin 1 |
| 4 | Solder **USB Type-C** |
| 5 | Solder **power switch** |
| 6 | Solder **LED 1206** × 64 — **polarity** on every LED |
| 7 | Solder **ISP** and **expansion** headers |
| 8 | Power on via USB-C → check demo animation |

```mermaid
flowchart TD
  s1["1. Passives"] --> s2["2. MAX7219"]
  s2 --> s3["3. ATtiny"]
  s3 --> s4["4. USB-C"]
  s4 --> s5["5. Switch"]
  s5 --> s6["6. LED matrix"]
  s6 --> s7["7. Headers"]
  s7 --> s8["8. Power check"]
```

:::caution LED polarity
Each 1206 LED has a cathode mark. Wrong orientation leaves that pixel dark. Match the silkscreen “T” / pad mark before soldering the second pad.
:::

:::info After step 8
Use [soldering technique](./03-soldering.md) for LED tips. If something fails, open [troubleshooting](./04-troubleshooting.md).
:::
