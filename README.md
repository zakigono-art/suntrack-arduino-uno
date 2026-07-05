# SunTrack Arduino Uno

A light-balancing solar tracker system using 4 LDR sensors and 2 continuous rotation servos. The system dynamically adjusts the orientation of the servos to equalize light intensity across the sensor array.

## Features
- **4-Sensor Array**: Detects light intensity from Top, Bottom, Left, and Right.
- **Dual-Axis Balancing**:
  - **Horizontal (Pin 8)**: Balances Left vs. Right light intensity.
  - **Vertical (Pin 9)**: Balances Top vs. Bottom light intensity.
- **Hysteresis/Deadzone**: Prevents jitter by ignoring small light fluctuations.
- **Similarity Threshold**: Stops movement when light levels are balanced across all sensors.
- **Configurable Timing**: Adjustable movement pulse duration and wait intervals.

## Hardware Requirements
- Arduino Uno
- 4× LDR (Light Dependent Resistors)
- 2× 360° Continuous Rotation Servos
- Resistors (for LDR voltage dividers)

## Pinout
| Component | Pin |
|-----------|-----|
| LDR A0    | A0  |
| LDR A1    | A1  |
| LDR A2    | A2  |
| LDR A3    | A3  |
| Servo H   | 8   |
| Servo V   | 9   |

## Installation
1. Clone this repository.
2. Open in VS Code with the PlatformIO extension.
3. Build and upload using PlatformIO.

## Configuration
Adjust parameters in `ldr_reader/src/main.cpp`:
- `DEADZONE`: Sensitivity threshold.
- `PULSE_MS`: Movement duration (controls degrees of rotation).
- `WAIT_MS`: Delay between movements.
- `SIMILARITY_THRESHOLD`: Light balance threshold to stop movement.
