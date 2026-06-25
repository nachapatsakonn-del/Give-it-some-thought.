// Modulino Pixels — LED RGB 8 ดวง (เป็น output)
// ไล่สีแดง/เขียว/น้ำเงิน เพื่อทดสอบว่าไฟติดครบ
// prototype idea: แสดงสีตาม class ที่ AI ทำนายได้

#include <Modulino.h>

ModulinoPixels pixels;

ModulinoColor RED(255, 0, 0);
ModulinoColor GREEN(0, 255, 0);
ModulinoColor BLUE(0, 0, 255);

void showAll(ModulinoColor color) {
  for (int i = 0; i < 8; i++) {
    pixels.set(i, color, 50);   // 50 = ความสว่าง (0-100)
  }
  pixels.show();
}

void setup() {
  Modulino.begin();
  pixels.begin();
}

void loop() {
  showAll(RED);   delay(500);
  showAll(GREEN); delay(500);
  showAll(BLUE);  delay(500);
}
