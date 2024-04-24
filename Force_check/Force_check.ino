// Define the pin where the force sensor is connected
const int ForceSensorPin = 0; // Use the same pin number as defined in your setup

// Define the expected range of the sensor output
const int minValue = 10;  // example minimum value
const int maxValue = 1023; // example maximum value, assuming a 10-bit ADC with values from 0 to 1023

void setup() {
  // Initialize serial communication to output the results
  Serial.begin(115200); // Match the baud rate with your project settings
  
  // Set up the force sensor pin as input
  pinMode(ForceSensorPin, INPUT);
}

void loop() {
  // Read the value from the force sensor
  int sensorValue = analogRead(ForceSensorPin);

  // Output the read value to the Serial Monitor
  Serial.print("Force Sensor Value: ");
  Serial.println(sensorValue);

  // Check if the sensor value is in the plausible range
  if (sensorValue > minValue && sensorValue < maxValue) {
    Serial.println("Force Sensor is connected and functioning.");
  } else {
    Serial.println("Check Force Sensor connection.");
  }

  // Delay a bit before reading again
  delay(1000); // Change the delay as needed for your testing frequency
}
