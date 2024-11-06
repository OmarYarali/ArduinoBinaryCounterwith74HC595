#define latchPin 11     // Pin connected to ST_CP (Latch Pin) of 74HC595
#define clockPin 9      // Pin connected to SH_CP (Shift Register Clock) of 74HC595
#define dataPin 12      // Pin connected to DS (Data Pin) of 74HC595

void setup() {
  pinMode(latchPin, OUTPUT);  // Set latch pin as output
  pinMode(clockPin, OUTPUT);  // Set clock pin as output
  pinMode(dataPin, OUTPUT);   // Set data pin as output
  Serial.begin(9600);         // Start serial communication at 9600 baud rate
}

void loop() {
  // Loop through values from 0 to 255 to create a binary counting pattern
  for (int i = 0; i < 256; ++i) { 
    digitalWrite(latchPin, LOW);         // Begin data transfer by setting latch LOW
    shiftOut(dataPin, clockPin, MSBFIRST, i); // Send the current count to the shift register
    digitalWrite(latchPin, HIGH);        // Complete data transfer by setting latch HIGH
    
    Serial.println(i, BIN);              // Print the binary representation of the current count to Serial Monitor
    delay(500);                          // Delay for half a second before the next count
  }
}
