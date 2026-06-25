# Camera test — ถ่ายภาพจาก USB webcam เพื่อเช็กว่ากล้องทำงาน
# รันฝั่ง Linux ของ UNO Q ผ่าน App Lab (Python App)
#
# ลองเล่น: เอามือบังกล้อง → ค่า brightness จะลดลง

import cv2

cap = cv2.VideoCapture(0)   # /dev/video0

if not cap.isOpened():
    print("หากล้องไม่เจอ — เช็ก powered USB hub และบอร์ดต้องอยู่บน Wi-Fi (อย่าต่อบอร์ดเข้าคอม)")
    raise SystemExit

frame = None
for i in range(30):
    ret, frame = cap.read()
    if not ret:
        print("อ่านภาพไม่ได้ ลองเสียบกล้องใหม่")
        break
    brightness = frame.mean()
    print(f"frame {i:2d}: brightness = {brightness:.1f}")

if frame is not None:
    cv2.imwrite("snapshot.jpg", frame)
    h, w = frame.shape[:2]
    print(f"OK! เซฟ snapshot.jpg ขนาด {w}x{h}")

cap.release()
