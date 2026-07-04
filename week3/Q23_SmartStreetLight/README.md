# Q23 - Smart Street Light

## Components
- Arduino UNO
- LDR Sensor
- PIR Motion Sensor
- LED
- 220Ω Resistor

## Connections
- LDR AO → A0
- LDR VCC → 5V
- LDR GND → GND
- PIR OUT → D2
- PIR VCC → 5V
- PIR GND → GND
- LED (+) → D3 through 220Ω resistor
- LED (-) → GND

## Features
- Detects day and night using LDR.
- Turns LED ON when motion is detected at night.
- Dims LED after 30 seconds if no motion is detected.
- Turns LED OFF during daylight.
