// Modulino Buzzer — เล่นโทนเสียง (เป็น output)
// สลับเสียงต่ำ/สูง เพื่อทดสอบว่าลำโพงทำงาน
// prototype idea: เตือนเสียงเมื่อ AI เจอเหตุการณ์สำคัญ

#include <Modulino.h>

ModulinoBuzzer buzzer;

void setup() {
  Modulino.begin();
  buzzer.begin();
}

void loop() {
  buzzer.tone(440, 250);   // ความถี่ 440 Hz นาน 250 ms
  delay(500);
  buzzer.tone(880, 250);   // เสียงสูงขึ้น
  delay(500);
}
