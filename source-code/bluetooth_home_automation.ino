#include <Servo.h>

// Create one servo object
Servo gate;

// LED pins
int bedroomLED = 11;
int sittingroomLED = 12;
int kitchenLED = 13;
int restroomLED = A0;
int diningroomLED = A1;

// Variable for Bluetooth data
char val;

void setup() {

  // Set LED pins as OUTPUT
  pinMode(bedroomLED, OUTPUT);
  pinMode(sittingroomLED, OUTPUT);
  pinMode(kitchenLED, OUTPUT);
  pinMode(restroomLED, OUTPUT);
  pinMode(diningroomLED, OUTPUT);

  // Turn OFF all LEDs initially
  digitalWrite(bedroomLED, LOW);
  digitalWrite(sittingroomLED, LOW);
  digitalWrite(kitchenLED, LOW);
  digitalWrite(restroomLED, LOW);
  digitalWrite(diningroomLED, LOW);

  // Attach only ONE servo motor
  gate.attach(9);

  // Initial servo position
  gate.write(180);

  // Start serial communication
  Serial.begin(9600);

  Serial.println("Bluetooth Home Automation Ready");
}

void loop() {

  // Check if Bluetooth data is available
  if (Serial.available() > 0) {

    val = Serial.read();

    Serial.print("Received: ");
    Serial.println(val);

    // BEDROOM LIGHT
    if (val == '1') {
      digitalWrite(bedroomLED, HIGH);
      Serial.println("Bedroom Light ON");
    }

    else if (val == '0') {
      digitalWrite(bedroomLED, LOW);
      Serial.println("Bedroom Light OFF");
    }

    // SITTING ROOM LIGHT
    else if (val == '3') {
      digitalWrite(sittingroomLED, HIGH);
      Serial.println("Sitting Room Light ON");
    }

    else if (val == '4') {
      digitalWrite(sittingroomLED, LOW);
      Serial.println("Sitting Room Light OFF");
    }

    // KITCHEN LIGHT
    else if (val == '5') {
      digitalWrite(kitchenLED, HIGH);
      Serial.println("Kitchen Light ON");
    }

    else if (val == '6') {
      digitalWrite(kitchenLED, LOW);
      Serial.println("Kitchen Light OFF");
    }

    // RESTROOM LIGHT
    else if (val == '7') {
      digitalWrite(restroomLED, HIGH);
      Serial.println("Restroom Light ON");
    }

    else if (val == '8') {
      digitalWrite(restroomLED, LOW);
      Serial.println("Restroom Light OFF");
    }

    // DINING ROOM LIGHT
    else if (val == '9') {
      digitalWrite(diningroomLED, HIGH);
      Serial.println("Dining Room Light ON");
    }

    else if (val == 'A') {
      digitalWrite(diningroomLED, LOW);
      Serial.println("Dining Room Light OFF");
    }

    // SERVO MOTOR CONTROL
    else if (val == 'B') {
      gate.write(90);
      Serial.println("Servo Opened");
    }

    else if (val == 'C') {
      gate.write(180);
      Serial.println("Servo Closed");
    }

    delay(100);
  }
}