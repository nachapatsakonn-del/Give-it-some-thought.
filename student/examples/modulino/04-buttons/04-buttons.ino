// Modulino Buttons — ปุ่ม A / B / C
// กดปุ่มแล้วดูว่าปุ่มไหนถูกกดใน Serial Monitor
// AI idea: ใช้ปุ่มกำกับ class ตอนเก็บ data, ปุ่มเริ่ม/หยุด

#include <Modulino.h>

ModulinoButtons buttons;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  buttons.begin();
}

void loop() {
  if (buttons.update()) {
    if (buttons.isPressed(0)) Serial.println("A");
    if (buttons.isPressed(1)) Serial.println("B");
    if (buttons.isPressed(2)) Serial.println("C");
  }
}
