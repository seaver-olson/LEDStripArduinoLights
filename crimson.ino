#include <IRremote.h>
#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    150

#define IR_RECEIVER_PIN  11

CRGB leds[NUM_LEDS];

IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned long value = results.value;

    // Change this value to match the IR code you want to use
    if (value == 0xFFA25D) { // Example IR code
      // Toggle the LED strip
      toggleLEDStrip();
    }
    Serial.println(value);
    irrecv.resume(); // Receive the next value
  }
}

void toggleLEDStrip() {
  static bool ledState = false; // Initial state is off

  if (ledState) {
    // Turn off the LED strip
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    ledState = false;
  } else {
    // Turn on the LED strip
    fill_solid(leds, NUM_LEDS, CRGB::White);
    FastLED.show();
    ledState = true;
  }
}
