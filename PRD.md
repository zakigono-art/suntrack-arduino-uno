# PRD: Light-Balancing Servo System

## Overview
Arduino-based solar tracker using 4 LDR sensors and 2 continuous rotation servos. The system detects light imbalance from sensors and moves servos to balance (equalize) the readings from opposing sensor pairs.

## Hardware
- Arduino Uno
- 4× LDR sensors on analog pins A0, A1, A2, A3
- 2× 360° continuous rotation servos (digital pins 8, 9)

## Sensor Layout (viewed from top)
```
       TOP
    A0     A1
L           R
    A3     A2
      BOTTOM
```
- **Top pair**: A0, A1
- **Bottom pair**: A2, A3
- **Left pair**: A0, A3
- **Right pair**: A1, A2

## Servo Mapping
| Servo | Pin | Axis | Compared Groups | CW (brighter) | CCW (darker) |
|-------|-----|------|-----------------|---------------|--------------|
| Horizontal | 8 | Left ↔ Right | `(A1+A2)/2` vs `(A0+A3)/2` | Right brighter | Left brighter |
| Vertical | 9 | Top ↔ Bottom | `(A0+A1)/2` vs `(A2+A3)/2` | Bottom brighter | Top brighter |

## Control Logic
1. Read all 4 analog sensors.
2. For **Pin 8 (Horizontal)**:
   - `avgRight = (A1 + A2) / 2`
   - `avgLeft = (A0 + A3) / 2`
   - `diffH = avgRight - avgLeft`
   - If `abs(diffH) > DEADZONE`:
     - `diffH > 0` → CW (toward right/brighter)
     - `diffH < 0` → CCW (toward left/brighter)
   - Else → STOP (90)
3. For **Pin 9 (Vertical)**:
   - `avgTop = (A0 + A1) / 2`
   - `avgBottom = (A2 + A3) / 2`
   - `diffV = avgTop - avgBottom`
   - If `abs(diffV) > DEADZONE`:
     - `diffV > 0` → CW (toward top/brighter)
     - `diffV < 0` → CCW (toward bottom/brighter)
   - Else → STOP (90)

## Parameters
| Parameter | Value | Description |
|-----------|-------|-------------|
| `STOP` | 90 | Neutral value (servo stopped) |
| `DEADZONE` | 5–10 | Minimum difference to trigger movement |
| `MIN_SPEED` | 83 | Slowest CCW speed |
| `MAX_SPEED` | 97 | Slowest CW speed |
| `READ_INTERVAL` | 10s | Sensor read rate |

## Serial Debug Output
Print every loop:
```
A0:xxx A1:xxx A2:xxx A3:xxx | diffH:xxx diffV:xxx | pin8:xx pin9:xx
```

## File to Edit
- `ldr_reader/src/main.cpp`

## Platform
- Arduino Uno (ATmega328P)
- PlatformIO build system
- Serial baud: 9600
