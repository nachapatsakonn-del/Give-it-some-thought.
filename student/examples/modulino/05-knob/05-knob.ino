// Modulino Knob — หมุน (ตำแหน่ง) + กดได้
// หมุนซ้าย/ขวา และลองกด แล้วดูค่าใน Serial Monitor
// AI idea: ปรับ threshold, เลือกโหมดการทำงาน

#include <Modulino.h>

ModulinoKnob knob;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  knob.begin();
}

void loop() {
  Serial.print("position: ");
  Serial.print(knob.get());
  if (knob.isPressed()) {
    Serial.print("   [pressed]");
  }
  Serial.println();
  delay(100);
}
