#include <IRremote.h>

#define IR_RECEIVER_PIN  11

IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // Print the received value in hexadecimal
    irrecv.resume(); // Receive the next value
  }
}
