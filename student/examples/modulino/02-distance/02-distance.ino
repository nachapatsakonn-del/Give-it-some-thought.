// Modulino Distance (Time-of-Flight) — วัดระยะเป็นมิลลิเมตร
// เอามือ/วัตถุเข้าใกล้-ออกห่าง แล้วดูค่าขยับ
// AI idea: นับคนผ่าน, gesture เลื่อนมือ, ตรวจของเข้าใกล้

#include <Modulino.h>

ModulinoDistance distance;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  distance.begin();
}

void loop() {
  if (distance.available()) {
    Serial.print("distance: ");
    Serial.print(distance.get());
    Serial.println(" mm");
  }
  delay(50);
}
