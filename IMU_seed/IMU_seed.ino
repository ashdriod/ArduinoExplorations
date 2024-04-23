#include <Wire.h>
#include "LSM6DS3.h"

// Create an instance of the LSM6DS3
// Assuming you are using the I2C protocol with the standard I2C address
LSM6DS3 imuSensor(I2C_MODE, 0x6A);

void setup() {
  // Start the serial communication
  Serial.begin(115200);
  while (!Serial); // Wait for the serial port to connect - only needed for Leonardo, etc.

  // Initialize the IMU sensor
  if (imuSensor.begin() != 0) {
    Serial.println("Problem starting the sensor!");
  } else {
    Serial.println("IMU sensor initialized correctly.");
  }
}

void loop() {
  // Read accelerometer and gyroscope values
  float accelX = imuSensor.readFloatAccelX();
  float accelY = imuSensor.readFloatAccelY();
  float accelZ = imuSensor.readFloatAccelZ();
  float gyroX = imuSensor.readFloatGyroX();
  float gyroY = imuSensor.readFloatGyroY();
  float gyroZ = imuSensor.readFloatGyroZ();

  // Print the accelerometer values
  Serial.print("Acc X: ");
  Serial.print(accelX);
  Serial.print(" g, ");
  Serial.print("Acc Y: ");
  Serial.print(accelY);
  Serial.print(" g, ");
  Serial.print("Acc Z: ");
  Serial.print(accelZ);
  Serial.println(" g");

  // Print the gyroscope values
  Serial.print("Gyro X: ");
  Serial.print(gyroX);
  Serial.print(" dps, ");
  Serial.print("Gyro Y: ");
  Serial.print(gyroY);
  Serial.print(" dps, ");
  Serial.print("Gyro Z: ");
  Serial.print(gyroZ);
  Serial.println(" dps");

  // Delay before the next data read
  delay(5000000);
}
