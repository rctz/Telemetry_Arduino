# Arduino Radio Telemetry Emergency System

A two-part Arduino telemetry system for wireless emergency signal transmission between sensor units and a receiver.

## Overview

This project consists of two Arduino components:
- **Sender**: Reads multiple digital sensors and an emergency button, transmits status via radio telemetry
- **Receiver**: Receives telemetry data and controls an emergency relay based on sensor status

## Components

### Sender Unit
- **Purpose**: Monitors digital sensors and emergency button states
- **Communication**: Sends data via Serial1 (radio telemetry module) at 57600 baud
- **Sensors**: 4 digital sensor pins (22, 24, 26, 28) with internal pullup resistors
- **Emergency Button**: Digital pin 50 with internal pullup resistor
- **Logic**: Activates emergency signal if ANY sensor is triggered OR emergency button is pressed

### Receiver Unit
- **Purpose**: Receives telemetry data and controls emergency relay
- **Communication**: Receives data via Serial1 at 57600 baud
- **Output**: Controls emergency relay on pin 30
- **Logic**: Sets relay HIGH when emergency signal received (value = 1), LOW otherwise

## Hardware Requirements

### Sender Unit
- Arduino board with multiple hardware serial ports (Arduino Mega, etc.)
- Radio telemetry module connected to Serial1
- 4 digital sensors (normally open connections to ground)
- Emergency button (normally open connection to ground)
- Power supply

### Receiver Unit
- Arduino board with multiple hardware serial ports
- Radio telemetry module connected to Serial1
- Relay module or emergency indicator on pin 30
- Power supply

## Wiring

### Sender
- Sensor 1: Pin 22 → Ground (when active)
- Sensor 2: Pin 24 → Ground (when active)
- Sensor 3: Pin 26 → Ground (when active)
- Sensor 4: Pin 28 → Ground (when active)
- Emergency Button: Pin 50 → Ground (when pressed)
- Radio Module: TX1/RX1 pins (Serial1)

### Receiver
- Emergency Relay: Pin 30 → Relay control input
- Radio Module: TX1/RX1 pins (Serial1)

## Operation

1. **Sender** continuously checks sensor states every 200ms
2. **Emergency Logic**: Any sensor activation OR emergency button press triggers emergency condition
3. **Data Transmission**: Sends "1" for emergency, "0" for normal operation
4. **Receiver** continuously listens for incoming data
5. **Relay Control**: Activates emergency relay when "1" is received

## Features

- Real-time monitoring of multiple sensor inputs
- Emergency button override capability
- Wireless telemetry communication
- Simple binary signaling (emergency/normal states)
- Internal pullup resistors for reliable sensor reading
- 200ms update cycle for responsive operation

## Technical Specifications

- **Communication Speed**: 57600 baud
- **Update Rate**: 200ms (5 Hz)
- **Logic Level**: Active LOW (sensors pull to ground when active)
- **Power**: Standard Arduino operating voltage
- **Range**: Determined by radio telemetry module capabilities

## Installation

1. Upload `sender/sender.ino` to the sender Arduino
2. Upload `receiver/receiver.ino` to the receiver Arduino
3. Connect hardware according to wiring diagram
4. Power on both units
5. Monitor serial output at 9600 baud for debugging

## Troubleshooting

- Ensure radio modules are properly paired
- Check baud rate compatibility (57600 for telemetry, 9600 for debug)
- Verify sensor connections and pullup resistor configuration
- Test emergency relay independently
