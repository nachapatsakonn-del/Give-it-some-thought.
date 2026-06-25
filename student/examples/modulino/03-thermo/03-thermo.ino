// Modulino Thermo — อุณหภูมิ + ความชื้น
// เอามือครอบ/หายใจรดเซนเซอร์ แล้วดูค่าขยับ
// AI idea: เฝ้าอุณหภูมิห้อง/ตู้, แยกสถานะ ร้อน/ปกติ/เย็น

#include <Modulino.h>

ModulinoThermo thermo;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  thermo.begin();
}

void loop() {
  Serial.print("temp: ");
  Serial.print(thermo.getTemperature());
  Serial.print(" C   humidity: ");
  Serial.print(thermo.getHumidity());
  Serial.println(" %");
  delay(1000);
}
