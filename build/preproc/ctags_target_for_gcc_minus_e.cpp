# 1 "/Users/mlorenz/Personal/pov-mill/src/src.ino"
// Simple strand test for Adafruit Dot Star RGB LED strip.
// This is a basic diagnostic tool, NOT a graphics demo...helps confirm
// correct wiring and tests each pixel's ability to display red, green
// and blue and to forward data down the line.  By limiting the number
// and color of LEDs, it's reasonably safe to power a couple meters off
// the Arduino's 5V pin.  DON'T try that with other code!

# 9 "/Users/mlorenz/Personal/pov-mill/src/src.ino" 2
# 10 "/Users/mlorenz/Personal/pov-mill/src/src.ino" 2



// Here's how to control the LEDs from any two pins:


// Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
Adafruit_DotStar strip(144 / 2 /* Number of LEDs in strip*/, (1 | (0 << 2) | (2 << 4)) /*|< Transmit as G,R,B*/);

void setup() {
  strip.begin(); // Initialize pins for output
  strip.show(); // Turn all LEDs off ASAP
}

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int head = 0, tail = -10; // Index of first 'on' and 'off' pixels
uint32_t color = 0xFF0000; // 'On' color (starts red)

void loop() {

  strip.setPixelColor(head, color); // 'On' pixel at head
  strip.setPixelColor(tail, 0); // 'Off' pixel at tail
  strip.show(); // Refresh strip
  delay(20); // Pause 20 milliseconds (~50 FPS)

  if(++head >= 144 / 2 /* Number of LEDs in strip*/) { // Increment head index.  Off end of strip?
    head = 0; //  Yes, reset head index to start
    if((color >>= 8) == 0) //  Next color (R->G->B) ... past blue now?
      color = 0xFF0000; //   Yes, reset to red
  }
  if(++tail >= 144 / 2 /* Number of LEDs in strip*/) tail = 0; // Increment, reset tail index
}