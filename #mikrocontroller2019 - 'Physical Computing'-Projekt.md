Dies ist ein Demo-Projekt als *Hausaufgabe* für den [openHPI](https://open.hpi.de/)-Kurs [Wie programmiere ich meinen ersten Mini-Computer?](https://open.hpi.de/courses/mikrocontroller2019/resume).

**12 RGB LED Ring Clock Demo**
=============================

__Eine *dekorative* ('Geschmacksache'), *nerdige* ('Ansichtssache') Tisch- oder Wanduhr mit *Internetzeit* via WiFi und *Touch-Bedienung* ... ;)__

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/miscellaneous/Project%20Cover.jpg)

Diese Beschreibung, das Anschlussschema, Fotos und der Quellcode (für Ardublockly und die Arduino IDE) sind auch in diesem [GitHub-Repository](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo) zu finden.

# Man nehme ..

## Komponenten

* ESP32-Mikrocontroller Development Board
* 12Bit RGB LED Ring WS2812
* Breadboard, halbe Größe / 400 Verbindungen 
* 4x Jumper-Kabel
* 5V Powerbank mit Micro-USB-Anschlusskabel

## Material

* Bilderrahmen 10x15cm - mit genügend Tiefe um die Elektronik unterzubringen  (z.B. der RIBBA Rahmen von IKEA), ggf. mit Passpartout
* 1-Cent-Münze
* Kleber, Klebeband etc.

# Und setze das Ganze zusammen ...

## Verkabelung und Anschlüsse

Die Anschlüsse des 12bit RGB LED Ring WS2812 wie folgt mit dem ESP32-Mikrocontroller auf einem Breadboard verbinden:

| ESP32 - Pin   | LED-Ring - Anschluss | Kabel-Farbe |
|:-------------:|:--------------------:|:-----------:|
| 5V            | PWR                  | rot         |
| GND           | GND                  | orange      |
| G12           | DI                   | grün        |

### Anschlüsse am 12bit RGB LED Ring WS2812

* Kabel **rot** an den Anschluss ***PWR***
* Kabel **orange** an den Anschluss ***GND***
* Kabel **grün** an den Anschluss ***DI***

anschließen bzw. anlöten.

### Pins am ESP32-Board

* Kabel **rot** an den Pin ***5V***
* Kabel **orange** an den Pin ***GND***
* Kabel **grün** an den  Pin ***G12***
* Kabel **gelb** an den Pin ***G14***

über das Breadboard verbinden.

Das **gelbe** Kabel am Pin  ***G14*** wird später mit *Touch-Sensor* verbunden.

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Fritzing%20-%2012_RGB_LED_Ring_Clock_bb.png)

## Zusammen-/Einbau

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Photo%2001%20-%20Material%2C%20Setup%20%26%20Wiring.jpg)

* Ein Bild für das Zifferblatt *passend* (für den Umfang des LED-Rings) gestalten (oder z.B. [dieses hier](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/'Artwork'%20-%20Rose%20Clock%20Face.png) verwenden), ausdrucken und für den Rahmen passend zuschneiden.
* Das Bild hinter dem Glas (und ggf. dem Passpartout) im Rahmen platzieren und befestigen.
* LED-Ring auf der Rückseite des Bildes platzieren: LEDs nach vorne, die erste LED (Index 0) nach oben (*auf die 12*) - und z.B. mit Klebebandstreifen fixieren.
* Breadboard mit dem ESP32-Mikrocontroller unten im Rahmen fixieren (z.B. Klebeband).
* Das Kabel (**gelb**), welches am Pin ***G14*** angeschlossen ist, an einer 1-Cent-Münze befestigen (löten, kleben etc.) und die Münze so an einer Ecke auf der Rückseite des Rahmens befestigen, dass die Ränder 1-2 mm über den Rand des Rahmens hervorstehen. 

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Photo%2005%20-%20Setup%20(1).jpg)

* Zum Fixieren des Ganzen kann ein z.B. ein Stück Styropor, Schaumstoff etc. passend zugeschnitten verwendet werden.

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Photo%2008%20-%20Setup%20(4).jpg)

## "Wie programmiere ich ...?"

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Ardublockly%20-%20Blocks.jpg)

### Ardublockly

Die Datei `12_RGB_LED_Ring_Clock.xml` ([hier](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/src/12_RGB_LED_Ring_Clock.xml)) nit [Ardublockly](https://ardublockly.embeddedlog.com/) öffnen und auf das ESP32-Board übertragen ...

* Ggf. muss der Variablenname `myLedRing` im *Setup led strip*-Block wieder korrigiert werden, da Ardublockly hier manchmal eine neue Variable beim Öffnen der Datei anlegt, statt den ursprünglichen Variablennamen zu verwenden.
* Die deaktivierten Blöcke zur seriellen Kommunikation sollten nur zum Debugging o.ä. verwendet werden. Im *Normalbetrieb* kann die serielle Kommunikation beim ESP32 zu *Timing-Problemen* mit dem WS2812-Treiber führen, die sich z.B. durch das ungewollte Aufleuchten der LED 0 in der Farbe grün manifestieren.

oder

### Arduino IDE

die Datei `12_RGB_LED_Ring_Clock.ino` ([hier](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/src/12_RGB_LED_Ring_Clock.ino)) nit der Arduino IDE öffnen, übersetzen  und auf das ESP32-Board übertragen.


# Und das kommt dabei heraus ...

![](https://github.com/mikrocontroller2019/12-RGB-LED-Ring-Clock-Demo/blob/master/images/Photo%2009%20-%20Setup%20(5).jpg)

Nach dem *Einschalten* der Stromversorgung ...

* Aufbau der WiFi-Verbindung ...
* Abrufen der Zeit via NTP ...
* Anzeige der Uhrzeit für 15 Sekunden ...
* Alle LEDs werden *ausgeschaltet* ...

Bei Berührung des *Touch-Sensors* (der Rand der 1-Cent-Münze) wird die Uhrzeit für die Dauer von einer Minute angezeigt, danach erlischt die Anzeige wieder bis zur nächsten Aktivierung des Sensors.

Die Uhrzeit wird auf den 12 LEDs wie folgt angezeigt:

### Zifferblatt

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

### Zeiger

| 'Zeiger' | LED-Farbe     |
|:--------:|:-------------:|
| Stunden  | **R**OT       |
| Minuten  | **G**RÜN      |
| Sekunden | **B**LAU      |

* Zeigerstände zwischen zwei Positionen (1-Stunde / 5-Minuten / 5-Sekunden) werden durch zwei benachbarte LED mit entsprechender Helligkeit angezeigt.
* *Übereinanderstehende Zeiger* werden als *Farbmix* dargestellt.

### Beispiel

21:15:40 Uhr

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

### Demo-Video

[hier](https://youtu.be/2-kaJKGSo0A)
