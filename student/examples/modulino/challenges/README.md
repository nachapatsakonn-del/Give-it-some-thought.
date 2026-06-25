<!-- workshop-header -->
<img width="1347" height="127" alt="Coding Thailand 2026 header" src="https://github.com/user-attachments/assets/ba5cf267-f460-4fb0-b69b-c461ae061a3b" />

# 🏆 Sensor Challenges — เชื่อมเช้า → บ่าย

ลองครบ 7 ตัวแล้ว? มาลองต่อจริงอีกขั้น 2 โจทย์นี้
วิธีรันบน UNO Q เหมือนเดิม (App Lab อย่างเดียว) — ดู [../README.md](../README.md)

---

## Challenge A — Proximity Alarm (Sensor → Buzzer)

> 📁 [challenge-a-proximity-buzzer/](challenge-a-proximity-buzzer/)
> ใช้: Modulino **Distance + Buzzer + Pixels**

ของเข้าใกล้กว่า threshold → Pixels แดง + Buzzer ร้อง · ไกล → Pixels เขียว

นี่คือหัวใจของ prototype: **input → ตัดสินใจ (logic) → output**

**ลองทำ:**
1. รันแล้วเอามือเข้า-ออก ดูไฟ/เสียงเปลี่ยน
2. ปรับ `threshold` (ค่าเริ่ม 150 มม.) แล้วดูพฤติกรรมเปลี่ยน
3. ท้าทาย: เปลี่ยน Distance เป็น Movement (สั่นแรง → ร้อง) ดูไหม?

> ✅ **ผ่านเมื่อ:** ของเข้าใกล้แล้วเตือนได้จริง และอธิบาย logic ได้
> 💡 บ่ายนี้ "ตัดสินใจ" จะเปลี่ยนจาก threshold ธรรมดา → ผลทำนายของ AI

---

## Challenge B — เก็บ Movement เป็น CSV (เตรียม data ไปเทรน)

> 📁 [challenge-b-movement-csv/](challenge-b-movement-csv/)
> ใช้: Modulino **Movement**

อ่าน x,y,z แล้วพิมพ์เป็น CSV ทาง Serial (~50 Hz) → ได้ข้อมูลจริงไป upload เข้า Edge Impulse ตอนบ่าย

**ลองทำ — เก็บทีละ "ท่า" (class):**
1. รันสเก็ตช์ → เปิด Serial Monitor (baud 9600)
2. เลือกท่าที่จะเก็บ เช่น `circle` / `shake` / `still`
3. ทำท่านั้นค้างไว้ ~10 วินาที → ก็อปข้อความ CSV ออกมา
4. วางลงไฟล์ `circle.csv` (1 ท่า = 1 ไฟล์) เก็บไว้ใน repo ทีม
5. ทำซ้ำกับท่าอื่นๆ ให้ครบทุก class

```
x,y,z
0.02,0.98,0.10
0.05,0.97,0.12
...
```

> ✅ **ผ่านเมื่อ:** มีไฟล์ CSV อย่างน้อย 2 ท่า เก็บแยกไฟล์ชัดเจน
> 💡 เก็บให้สม่ำเสมอ (อัตราคงที่ ท่าชัด) = data สะอาด → AI เรียนรู้ง่ายตอนบ่าย
> ⚠️ อย่าเก็บจากคนเดียว/แบบเดียว — สลับคน/ความเร็ว กันโดน bias (ดูสไลด์บ่าย S15)
