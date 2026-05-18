#include <Arduino.h>
#include <MPU6050.h>
MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
float pitch_cf, roll_cf;
unsigned long previousMillis = 0;
float dt;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing MPU6050...");
  Wire.begin();
  mpu.initialize();
  }

void loop() {
    unsigned long currentMillis = millis();
    dt = (currentMillis - previousMillis) / 1000.0; 
    previousMillis = currentMillis;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  float pitch, roll;
pitch = atan2(ay, az) * 180 / PI;
roll = atan2(-ax, az) * 180 / PI;
pitch_cf = 0.98 * (pitch_cf + (gx / 131.0) * dt) + 0.02 * pitch;
roll_cf = 0.98 * (roll_cf + (gy / 131.0) * dt) + 0.02 * roll;
  Serial.print("Pitch: ");
Serial.println(pitch_cf);
  Serial.print("Roll: ");
Serial.println(roll_cf);
delay(10);
}
