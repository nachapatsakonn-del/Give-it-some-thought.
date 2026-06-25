// Challenge A — Proximity Alarm: Sensor -> Logic -> Output
// Modulino Distance วัดระยะ → ถ้าใกล้กว่า threshold: Pixels แดง + Buzzer ร้อง
//                              ถ้าไกล: Pixels เขียว เงียบ
//
// นี่คือหัวใจของ prototype: input -> ตัดสินใจ -> output
// ลองปรับ threshold แล้วดูว่าพฤติกรรมเปลี่ยนยังไง
//
// ต้องมี: Modulino Distance + Buzzer + Pixels (ต่อ daisy-chain)

#include <Modulino.h>

ModulinoDistance distance;
ModulinoBuzzer   buzzer;
ModulinoPixels   pixels;

ModulinoColor RED(255, 0, 0);
ModulinoColor GREEN(0, 255, 0);

int threshold = 150;   // มิลลิเมตร — ลองปรับค่านี้!

void setLeds(ModulinoColor color) {
  for (int i = 0; i < 8; i++) {
    pixels.set(i, color, 30);
  }
  pixels.show();
}

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  distance.begin();
  buzzer.begin();
  pixels.begin();
}

void loop() {
  if (distance.available()) {
    int d = distance.get();
    Serial.println(d);

    if (d < threshold) {
      setLeds(RED);
      buzzer.tone(880, 150);   // ร้องสั้นๆ เมื่อมีของเข้าใกล้
    } else {
      setLeds(GREEN);
    }
  }
  delay(50);
}
