# Morse-Code-Transmitter-and-Receiver

This project aims to create a Morse Code Transmitter and Receiver using the following equipments:
1. Arduino Nano
2. NRF24L01 Module
3. OLED Display
4. Breadboard
5. Jumper Wires
6. Switch
7. LEDs(Light Emitting Diodes)
8. Buzzer

I have used an extension(Platform IO) for VSCode to write the code. So please install the necessary tools before making this project.

# Circuit Description

1. Arduino Nano boards:

    Connect the GND pins on both Arduinos to the breadboard's GND rail.
    Connect the 5V pin on one Arduino to the breadboard's +5V rail.
    Connect the 5V pin on the other Arduino to the breadboard's +3.3V rail.
    
2. NRF24L01 wireless modules:

    For each module, connect the VCC pin to the breadboard's +3.3V rail.
    Connect the GND pin to the breadboard's GND rail.
    Connect the CE pin to the following digital pins on the first Arduino:
    D9 for the transmitter module
    D9 for the receiver module
    Connect the CSN pin to the following digital pins on the first Arduino:
    D10 for the transmitter module
    D10 for the receiver module
    Connect the SCK pin to the following digital pins on the first Arduino:
    D13 for the transmitter module
    D13 for the receiver module
    Connect the MOSI pin to the following digital pins on the first Arduino:
    D11 for the transmitter module
    D11 for the receiver module
    Connect the MISO pin to the following digital pins on the first Arduino:
    D12 for the transmitter module
    D12 for the receiver module
    
3. OLED displays:

    For each display, connect the VCC pin to the breadboard's +5V rail.
    Connect the GND pin to the breadboard's GND rail.
    Connect the SDA pin to the following analog pins on the first Arduino:
    A4 for the transmitter display
    A4 for the receiver display
    Connect the SCL pin to the following analog pins on the first Arduino:
    A5 for the transmitter display
    A5 for the receiver display
    
4. Buzzer module:

    Connect the positive (+) pin of the buzzer to a digital output pin on the first Arduino:
    D2 for the transmitter buzzer
    Connect the negative (-) pin of the buzzer to the breadboard's GND rail.
    
5. Push button switch:

    Connect one leg of the switch to a digital input pin on the first Arduino:
    D3 for the transmitter button
    Connect the other leg of the switch to the breadboard's GND rail.
    
6. Green and red LEDs:

    Connect the anode (positive, longer leg) of the green LED to a digital output pin on the first Arduino:
    D4 for the transmitter LED
    Connect the anode of the red LED to a digital output pin on the second Arduino:
    D4 for the receiver LED
    Connect the cathode (negative, shorter leg) of both LEDs to the breadboard's GND rail.
