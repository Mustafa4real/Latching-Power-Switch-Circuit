# Latching Power Switch with Auto On/Off using LDR and Button

In this project I make a **latching power switch** using an **Arduino Uno**, a **push button (digital sensor)**, and an **LDR (analog light sensor)**. It controls an **LED** to simulate powering a system ON or OFF based on light levels and user input. It includes **automatic timeout** (for battery saving), **state retention**, and **visual feedback** (LED flashes).


## Features

- **Button toggle:** Press to toggle LED ON/OFF
- **LDR trigger:** Covering the LDR (dim) powers the LED ON
- **Auto OFF:** If LDR detects light after turning ON, LED turns OFF after 5 seconds
- **Visual feedback:** LED flashes 3 times every time it's turned ON
- **Combined logic:** Button and LDR interact to toggle power intelligently


## Components

| Component      | Quantity |
|----------------|----------|
| Arduino Uno    | 1        |
| LED            | 1        |
| 220Ω resistor  | 1        |
| Push button    | 1        |
| LDR            | 1        |
| 10kΩ resistor  | 1        |
| Breadboard     | 1        |
| Jumper wires   | 8        |


## How to Use

1. Upload the code to your Arduino Uno using the Arduino IDE.
2. Wire the components according to the circuit instructions.
3. Power the Arduino.
4. Cover the LDR or press the button to turn ON the LED.
5. Watch the LED behavior change with light conditions and button presses.


## Demo
https://github.com/user-attachments/assets/fc844b86-c32e-49a2-87be-f37a4c0f51f3

