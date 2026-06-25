<!-- workshop-header -->
<img width="1347" height="127" alt="Coding Thailand 2026 header" src="https://github.com/user-attachments/assets/ba5cf267-f460-4fb0-b69b-c461ae061a3b" />

# 📷 Camera Example — USB Webcam (ฝั่ง Linux)

กล้องอ่านจาก **ฝั่ง Linux** ของ UNO Q เป็น **Python App** (ไม่ใช่ Arduino Sketch เหมือน Modulino)

> ⚠️ ตอนใช้กล้อง บอร์ดต้องอยู่บน **Wi-Fi** — **อย่าต่อบอร์ดเข้าคอมโดยตรง** ไม่งั้นจะหากล้องไม่เจอ

เสียบกล้องเข้า powered USB hub (hub ต้องมีสาย power):

<img src="../../assets/usb-hub-wiring.jpg" alt="ต่อกล้อง/ไมค์ผ่าน powered USB hub" width="380" />

---

## วิธีที่ 1 — ใช้ example ของ App Lab (แนะนำ ง่ายสุด)

1. App Lab → **+ New** App → เลือกหมวด **Camera / Vision** ในตัวอย่าง (Examples)
2. กด **Run** → เห็นภาพสด / ผลจากกล้อง

## วิธีที่ 2 — รันสคริปต์นี้เอง

1. App Lab → New App → ส่วน **Python** (ฝั่ง Linux)
2. ก็อปโค้ดจาก [camera_check.py](camera_check.py) วางลงไป
3. กด **Run** → ดู Console: ค่า brightness ของแต่ละเฟรม
4. **เอามือบังกล้อง** → ตัวเลข brightness ลดลง = กล้องทำงาน
5. ได้ไฟล์ `snapshot.jpg` ไว้ดูภาพที่ถ่าย

เช็กบน shell (`>_`) ได้ว่ากล้องขึ้นไหม: `lsusb` · `ls /dev/video*`

> ✅ **ผ่านเมื่อ:** เห็นภาพสด หรือค่า brightness ขยับเมื่อบังกล้อง
> 💡 บ่ายนี้: กล้องตัวเดียวกันนี้จะเป็น input ของ AI (เช่น แยกประเภทภาพ)
