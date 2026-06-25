// Challenge B — เก็บ Movement เป็น CSV เพื่อเอาไปเทรนบ่ายนี้
// อ่านความเร่ง x,y,z แล้วพิมพ์เป็น CSV ทาง Serial (~50 Hz)
//
// เป้าหมาย: ได้ไฟล์ข้อมูลของ "ท่า" หรือ "การเคลื่อนไหว" แต่ละแบบ
//          เอาไป upload เข้า Edge Impulse ตอนบ่าย
//
// ต้องมี: Modulino Movement

#include <Modulino.h>

ModulinoMovement movement;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  movement.begin();
  Serial.println("x,y,z");   // header ของ CSV
}

void loop() {
  movement.update();
  Serial.print(movement.getX());
  Serial.print(",");
  Serial.print(movement.getY());
  Serial.print(",");
  Serial.println(movement.getZ());
  delay(20);                  // 20 ms = ~50 ตัวอย่าง/วินาที
}
