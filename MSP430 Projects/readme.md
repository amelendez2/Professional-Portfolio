Texas Instruments MSP430 Microcontroller
==========

This repository will show the projects I created using the MSP430
-----------------

### Introduction to the MSP430

> ## Texas Instruments
>
> please visit their website: http://www.ti.com/ww/en/launchpad/launchpads-msp430-msp-exp430g2.html#tabs

### Guide for this Project

> ##Analog to Digital Converter and LCD - [main.c](https://github.com/amelendez2/Professional-Portfolio/blob/master/MSP430%20Projects/Analog%20to%20Digital%20Convrter%20and%20LCD/main.c)
>
> MCU waits for an analog signal to be received through the ADC pin
> That value is stored to a buffer then used to display the value on the LCD

> ##Interrupts and Pulse Width Modulation - [main.c](https://github.com/amelendez2/Professional-Portfolio/blob/master/MSP430%20Projects/Interrupts%20and%20Pulse%20Width%20Modulation/main.c)
>
> This project uses interrupts to wake the processor out of low power mode
> It also uses PWM to change LEDs based off duty cycle

> ##Serial Communication
>
> This project has 2 folders, one for Tx (transmit) and the other for Rx(receive)
> In this project we pass values form one MSP430 to another using UART(universal asynchronous receiver/transmitter)
> We pass a single character and verify that it is received on the other end by turning on a LED

> ##Final Project
>
> This project was very challenging as it entailed using all the knowledge from our Micro Architecture course
> Also, it required innovative thinking as the project would require 2 persons to use the game simultaneously on one MSP430
> The game Displays a direction on the LCD then requires both players to move a controller (with an accelerometer) in the
> direction displayed. The game progressively displays the direction faster and expects a quicker response until one player moves
> the controller in the wrong direction.



The linked files are the main C programs; however feel free to browse through all the supporting files as well.