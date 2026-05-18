#include <Arduino.h>
#include <MPU6050.h>
MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;



void setup() {
  Serial.begin(9600);
  Serial.println("Initializing MPU6050...");
  Wire.begin();
  mpu.initialize();
  
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  float pitch, roll;
pitch = atan2(ay, az) * 180 / PI;
roll = atan2(-ax, az) * 180 / PI;
  Serial.print("Pitch: ");
Serial.println(pitch);
  Serial.print("Roll: ");
Serial.println(roll);
delay(500);
}