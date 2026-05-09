# Bluetooth Controller Reference

Robot dikendalikan menggunakan koneksi Bluetooth melalui modul HC-05 yang terhubung dengan mikrokontroler Arduino. Operator mengontrol arah gerak robot secara manual menggunakan aplikasi Bluetooth Controller pada smartphone Android.

---

## Control System

| Button | Function |
|--------|----------|
| Forward | Robot bergerak maju |
| Backward | Robot bergerak mundur |
| Left | Robot berbelok kiri |
| Right | Robot berbelok kanan |
| Stop | Menghentikan pergerakan robot |

---

## Bluetooth Configuration

| Parameter | Value |
|-----------|------|
| Module | HC-05 |
| Communication | Bluetooth Serial |
| Baud Rate | 9600 |
| Connection Range | ±10 meter |

---

## Operational Notes

- Operator hanya mengontrol arah pergerakan robot.
- Pengangkatan bendera dilakukan berdasarkan hasil pembacaan sensor warna.
- Robot wajib mengikuti aturan arena dan mekanisme pertandingan.

---

## System Workflow

1. Robot terhubung ke smartphone melalui Bluetooth.
2. Operator mengarahkan robot menuju area tertentu.
3. Sensor warna membaca warna arena.
4. Sistem menentukan bendera yang harus diangkat.
5. Servo mengangkat bendera sesuai warna yang terdeteksi.
6. Robot melanjutkan misi ke area berikutnya.