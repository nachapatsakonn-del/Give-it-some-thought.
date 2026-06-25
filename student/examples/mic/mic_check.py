# Mic test — อัดเสียง 3 วินาทีจาก USB mic เพื่อเช็กว่าไมค์ทำงาน
# รันฝั่ง Linux ของ UNO Q ผ่าน App Lab (Python App)
#
# ใช้ arecord (ALSA) ที่มีอยู่แล้วบน Linux side

import subprocess

# ถ้ามีไมค์หลายตัว ดูชื่อ card ก่อนด้วย: arecord -l
print("กำลังอัดเสียง 3 วินาที... พูดใส่ไมค์ได้เลย 🎤")

result = subprocess.run(
    ["arecord", "-d", "3", "-f", "cd", "test.wav"],
    capture_output=True, text=True
)

if result.returncode == 0:
    print("เสร็จ! ได้ไฟล์ test.wav — ลองเปิดฟัง หรือเช็กขนาดไฟล์")
else:
    print("อัดไม่สำเร็จ — เช็กว่าเสียบ mic เข้า powered hub แล้ว")
    print("ลองสั่ง: arecord -l  เพื่อดูว่าเจอ card ไมค์ไหม")
    print(result.stderr)
