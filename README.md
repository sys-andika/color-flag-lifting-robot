# COLOR FLAG LIFTING MISSION ROBOT

![Arduino](https://img.shields.io/badge/Arduino-Robot-blue)
![Status](https://img.shields.io/badge/Project-Completed-success)
![Year](https://img.shields.io/badge/Year-2025-orange)

Robot berbasis Bluetooth yang dirancang untuk menyelesaikan misi pengangkatan bendera berdasarkan deteksi warna arena menggunakan sensor warna dan mekanisme servo. Proyek ini merupakan tugas akhir Basic Training KOMBO (Komunitas Robotika) Universitas Airlangga tahun 2025.

---

## 📌 Project Overview

Robot membawa tiga bendera dengan warna berbeda (merah, hijau, dan putih) di dalam mekanisme internalnya. Robot dikendalikan secara manual melalui Bluetooth, namun pengangkatan bendera harus menyesuaikan warna arena yang dideteksi oleh sensor warna.

Misi utama robot:
- Mendeteksi warna arena
- Mengangkat bendera yang sesuai
- Berpindah ke pos dengan warna yang sama
- Menyelesaikan seluruh misi hingga zona finish

---

## 🎯 Mission Rules

### Pos Merah
Robot harus mengangkat bendera merah ketika berada di area merah.

### Pos Hijau
Robot harus mengangkat bendera hijau pada area hijau.

### Pos Putih
Robot harus mengangkat bendera putih pada area putih.

### Zona Finish
Robot melakukan pengangkatan final pada area abu-abu sebagai tanda penyelesaian misi.

---

## ⚙️ Features

- Bluetooth-based robot control
- Color detection system
- Servo flag lifting mechanism
- Multi-zone mission handling
- Real-time operator navigation
- Embedded system integration

---

## 🛠️ Hardware Components

- Arduino Uno / Nano
- HC-05 Bluetooth Module
- Servo Motor
- DC Motor Driver
- Color Sensor
- Robot Chassis
- Li-ion Battery
- Wheels & Gear Motor

---

## 💻 Technologies Used

- Arduino IDE
- Embedded C++
- Bluetooth Communication
- Sensor Integration
- Servo Control System

---

## 🔄 System Workflow

1. Robot membaca warna arena menggunakan sensor warna.
2. Operator mengendalikan arah robot melalui Bluetooth.
3. Robot menentukan bendera yang harus diangkat.
4. Servo mengangkat bendera sesuai warna arena.
5. Robot melanjutkan perjalanan ke pos berikutnya.
6. Robot menyelesaikan misi pada zona finish.

---

## 📂 Project Structure

```bash
color-flag-lifting-robot/
│
├── README.md
├── docs/
│   ├── arena-design.png
│   ├── robot-photo.jpg
│   ├── wiring-diagram.png
│   └── flowchart.png
│
├── arduino/
│   └── main.ino
│
├── bluetooth-controller/
│   └── app-reference.md
│
├── hardware/
│   └── components-list.md
│
└── media/
    └── demo-video.mp4