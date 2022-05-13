# POV Mill

DotStar 144LED / m

```
   Red - 5v       -> 5v
Yellow - Ci Clock -> SCK
 Green - Di Data  -> MOSI
 Black - GND      -> GND
```

```
            +-------------------+
            | O    | USB |    O |
            |      -------   ---|
       ~RST | o     3.7/4.2V |  |
        3V3 | o  LiPoly Batt |  |
         NC | o   USB charge |  |
        GND | o              ---|
  A0 / DAC2 | o               o | VBAT
  A1 / DAC1 | o               o | EN
    A2 / 34 | o               o | VUSB
    A3 / 39 | o               o | 13  / A12
    A4 / 36 | o               o | 12  / A11
    A5 /  4 | o               o | 27  / A10
   SCK /  5 | o               o | 33  / A9
  MOSI / 18 | o               o | 15  / A8
  MISO / 19 | o               o | 32  / A7
    RX / 16 | o               o | 14  / A6
    TX / 17 | o               o | SCL / 22
         21 | o               o | SDA / 23
            |                   |
            | O               O |
            +-------------------+
```
