**12 RGB LED Ring Clock Demo - Yet another Arduino LED clock ;)**
=================================================================

__Yet another Arduino LED clock: A *decorative* desktop / wall clock featring *internet time * via WiFi and *one-touch-activation* ... ;)__

This little project was an excercise / homework for the German [openHPI](https://open.hpi.de/)-Kurs [Wie programmiere ich meinen ersten Mini-Computer?](https://open.hpi.de/courses/mikrocontroller2019/resume). ('How do I program my first mini computer?').

The original project description (in German) is [here](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/%23mikrocontroller2019%20-%20'Physical%20Computing'-Projekt.md). / Die ursprüngliche Beschreibung, das Anschlussschema, Fotos und der Quellcode (für Ardublockly und die Arduino IDE) sind [hier](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo) zu finden.

The course featured a [customized version](https://github.com/Daniel-Amadeus/ardublockly) of [Ardublockly](https://ardublockly.embeddedlog.com/) (a visual programming editor for Arduino based on Google's Blockly) and the task was to implement and describe a physical computing project soley by using this tool.

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/miscellaneous/Project%20Cover.jpg)

# BOM

## Components

* ESP32 microcontroller development board (e.g. the ESP-32 Dev Kit C) 
* 12Bit RGB LED ring WS2812 (e.g. the NeoPixel Ring - 12 x 5050 RGB LED with Integrated Drivers)
* Breadboard, half-size 
* Jumper wires
* Battery (e.g. a 5V power pack)

## Addition material

* Picture frame (deep enough to house the device - e.g. the RIBBA frame by IKEA)
* One-cent-coin
* Glue (e.g. hot glue)

# Assembly

## Wiring

Connect the LED ring with the ESP32 board as follows:

| ESP32 pin   | LED ring connector | Wire |
|:-------------:|:--------------------:|:-----------:|
| 5V            | PWR                  | red         |
| GND           | GND                  | orange      |
| G12           | DI                   | green        |

###  @ 12bit RGB LED ring WS2812
Connect 
* a **red** wire to ***PWR*** connector
* an **orange** wire to ***GND*** connector
* a **green** wire to  ***DI*** connector
.

### @ ESP32 board 

Connect

* the **red** to pin ***5V***
* the **orange** to pin ***GND***
* the **green** to pin ***G12***
* a **yellow** to pin ***G14***

via the breadboard.

The yellow wire will be connected to the *touch sensor* (i.e. the one-cent-coint).

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Fritzing%20-%2012_RGB_LED_Ring_Clock_bb.png)

## Casing

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Photo%2001%20-%20Material%2C%20Setup%20%26%20Wiring.jpg)

* Create, print and cut in size a nice picture for the clock face regarding the diameter of the LED ring. (e.g. like [this](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/'Artwork'%20-%20Rose%20Clock%20Face.png) one).
* Place the picture into the frame.
* Place the LED ring on the back side of the picture and fix it there with glue.
* Place/glue also the breadboard with ESP32 board inside the frame.
* *Connect* the **yellow** wire (connected to pin ***G14***) to the one-cent-coin and fix the coin on a back corner at the frame. 

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Photo%2005%20-%20Setup%20(1).jpg)

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Photo%2008%20-%20Setup%20(4).jpg)

## Programming

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Ardublockly%20-%20Blocks.jpg)

### Ardublockly

If you want to use Ardublockly, open the file
 `12_RGB_LED_Ring_Clock.xml` ([here](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/src/12_RGB_LED_Ring_Clock.xml)) in Ardubockly and click the IDE button.

* Since Ardublocky somtimes f.cks up some variable identfiers it might be necessary to change the identifier `myLedRing` with in the  *Setup led strip* back to it's correct value.
* The blocks regarding serial communication should be only activated for debugging purposes, since the use of Serial might interfere with the Neopixel library's functions.

or

### Arduino IDE

Open the file `12_RGB_LED_Ring_Clock.ino` ([here](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/src/12_RGB_LED_Ring_Clock.ino)) with the Arduino IDE, compile and transfer to device.


# Operating

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Photo%2009%20-%20Setup%20(5).jpg)

After powering-on the device, it ...

* tries to establish the configured WiFi connection,
* tries to receive the current time via NTP,
* displays the time for about 15 seconds 
* and then switches of all LEDs.

When the coin is touched it will display the current time again. After one minute the display will go dark again till the next activation by touch.

Time will be displayed by the light colours of the 12 LEDs:

### Clock face

| | | | | | | |
|----	|----	|----	|----	|----	|----	|----	|
|    	|    	|    	| 00 	|    	|    	|    	|
|    	|    	|    	| 12 	|    	|    	|    	|
|    	|    	| 11 	|    	| 01 	|    	|    	|
|    	| 10 	|    	|    	|    	| 02 	|    	|
| 09 	|    	|    	|    	|    	|    	| 03 	|
|    	| 08 	|    	|    	|    	| 04 	|    	|
|    	|    	| 07 	|    	| 05 	|    	|    	|
|    	|    	|    	| 06 	|    	|    	|    	|

### Hands

| 'Hand'   | LED colour     |
|:--------:|:--------------:|
| Hours    | **R**ED        |
| Minutes  | **G**REEN      |
| Seconds  | **B**LUE       |

* Hands between two positions (1-hour / 5-minutes / 5-seconds) are displayed on two neighbouring LEDs with adjusted brigthness.
* Hands *covering each other* will be displayed by mixed colours.

### Example

21:15:40 (09:14:40 pm)

| | | | | | | |
|-------	|-------	|----	|----	|----	|----	|-------	|
|       	|       	|    	| 12 	|    	|    	|       	|
|       	|       	| 11 	|    	| 01 	|    	|       	|
|       	| 10    	|    	|    	|    	| 02 	|       	|
| **R** 	|       	|    	|    	|    	|    	| **G** 	|
|       	| **B** 	|    	|    	|    	| 04 	|       	|
|       	|       	| 07 	|    	| 05 	|    	|       	|
|       	|       	|    	| 06 	|    	|    	|       	|

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Photo%2014%20-%20Clock%20%20(light).jpg)

### Better than words:

[Video](https://youtu.be/2-kaJKGSo0A) showing the clock in action.
