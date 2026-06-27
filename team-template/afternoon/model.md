<!-- workshop-header -->
<img width="1347" height="127" alt="Coding Thailand 2026 header" src="https://github.com/user-attachments/assets/ba5cf267-f460-4fb0-b69b-c461ae061a3b" />

# Afternoon — Model

- **Input ที่ใช้:** Image (กล้อง)
- **Classes:** with_mask, no_mask
- **จำนวนตัวอย่าง/class:** 80 images
- **วิธีเชื่อมเข้า Edge Impulse:** [/] กล้อง/ไมค์ (`edge-impulse-linux`)  [/] Modulino (`data-forwarder`)

## V1
- Accuracy (ใน Studio): 60%
- F1 score ราย class (class : F1): with_mask : 0.75 | no_mask : 0.75
- class ที่ F1 ต่ำสุด: with_mask (มี simple31 ผิด, F1 = 0%)
- รูป Confusion Matrix: ![cm-v1](../assets/cm-v1.png)
- อ่านแล้วเห็นอะไร (class ไหนสับสนกับ class ไหน): with_mask สับสนกับ no_mask

## V2 (ถ้าทัน)
- แก้อะไรจาก V1: เพิ่มรูป no_mask ใน test set / เพิ่ม training data
- Accuracy V2: 70% | ดีขึ้น/แย่ลงตรงไหน: ค่าความแม่นยำเพิ่มมากขึ้น

## รันบนบอร์ด
- [/] วิธีรัน: [/] กล้อง/ไมค์ → `edge-impulse-linux-runner` (Web UI :4912)  [ ] Modulino → Arduino library ในสเก็ตช์
- [/] ป้อน input จริงแล้ว prediction เปลี่ยนตาม (inferencing time: 	633  ms)
- คลิป/รูปตอนรัน: ![run](../assets/run.jpg)

## (ต่อยอด) Output logic
- threshold ที่ใช้: confidence ≥ 0.7
- map class → output: no_mask (≥ 0.7) → "เตือน": Buzzer ดัง + Pixels แดง
                      with_mask (≥ 0.7) → "ผ่าน": Pixels เขียว (ไม่สั่ง buzzer)
                      ต่ำกว่า 0.7 ทั้งคู่ → "ไม่แน่ใจ": Pixels เหลือง (ไม่สั่ง buzzer)
