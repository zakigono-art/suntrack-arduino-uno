# Sensor & Servo Configuration Notes

## Sensor Mapping
- **A0, A1**: Top Sensors
- **A2, A3**: Bottom Sensors
- **A0, A3**: Left Sensors
- **A1, A2**: Right Sensors

## Servo Logic (Balancing)
- **Goal**: Minimize difference between opposing sensor pairs.
- **Reaction Time**: 10 seconds (delay between reads).
- **Servo Pin 9 (Vertical)**:
  - Compares `(A0+A1)/2` (Top) vs `(A2+A3)/2` (Bottom).
  - Moves **CW** if Top > Bottom; **CCW** if Bottom > Top.
- **Servo Pin 8 (Horizontal)**:
  - Compares `(A0+A3)/2` (Left) vs `(A1+A2)/2` (Right).
  - Moves **CW** if Right > Left; **CCW** if Left > Right.
