#include <Servo.h>
#include <SoftwareSerial.h>

// Bluetooth (Pin 0 & 1)
SoftwareSerial BTSerial(0, 1); 

// Sensor Warna TCS3200
#define TCS_S0 6
#define TCS_S1 7
#define TCS_S2 8
#define TCS_S3 9
#define TCS_OUT 10

// Motor Driver
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// Servo
Servo servo1; // Merah
Servo servo2; // Hijau
Servo servo3; // Putih

// Variabel
int R, G, B;
String warnaTerdeteksi = "UNKNOWN";

void setup() {
  Serial.begin(9600);   // Laptop
  BTSerial.begin(38400); // Bluetooth (PENTING: 38400 sesuai HC-06)

  // Sensor Setup
  pinMode(TCS_S0, OUTPUT); pinMode(TCS_S1, OUTPUT);
  pinMode(TCS_S2, OUTPUT); pinMode(TCS_S3, OUTPUT);
  pinMode(TCS_OUT, INPUT);

  // Scaling 20%
  digitalWrite(TCS_S0, HIGH);
  digitalWrite(TCS_S1, LOW);

  // Motor Setup
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);

  // Servo Setup
  servo1.attach(A0);
  servo2.attach(A1);
  servo3.attach(A2);

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);

  Serial.println("ROBOT SIAP: Data Kalibrasi Sudah Masuk!");
}

// BACA WARNA
int readPulse(uint8_t s2, uint8_t s3) {
  digitalWrite(TCS_S2, s2);
  digitalWrite(TCS_S3, s3);
  delay(15); 
  return pulseIn(TCS_OUT, LOW);
}

void readRGB() {
  R = readPulse(LOW, LOW);
  G = readPulse(HIGH, HIGH);
  B = readPulse(LOW, HIGH);
}

String detectColor() {
  readRGB();

  // Print ke Laptop buat mantau
  Serial.print("R:"); Serial.print(R);
  Serial.print(" G:"); Serial.print(G);
  Serial.print(" B:"); Serial.print(B);

  String hasil = "UNKNOWN";

  // DETEKSI PUTIH
  if (R < 90 && G < 90 && B < 90) {
    hasil = "PUTIH";
  }
  
  // DETEKSI ABU
  else if (R > 90 && R < 180 && G > 90 && G < 180) {
    hasil = "ABU";
  }

  // DETEKSI MERAH
  else if (R < 120 && G > 200 && B > 200) {
    hasil = "MERAH";
  }

  // DETEKSI HIJAU
  else if (G < 180 && R > 200 && B > 200) {
    hasil = "HIJAU";
  }

  Serial.print(" -> "); Serial.println(hasil);
  return hasil;
}

// BENDERA
void aturBendera(String warna) {
  if (warna == "MERAH") {
    servo1.write(90); 
    servo2.write(0);
    servo3.write(0);
  } 
  else if (warna == "HIJAU") {
    servo1.write(0);
    servo2.write(90); 
    servo3.write(0);
  } 
  else if (warna == "PUTIH") {
    servo1.write(0);
    servo2.write(0);
    servo3.write(90); 
  } 
  else if (warna == "ABU") {
    // Abu: Semua Hormat
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
  } 
  else {
    // Unknown: Semua Turun
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
  }
}

// MOTOR
void maju() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}
void mundur() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}
void kiri() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}
void kanan() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}
void stopMotor() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}

void loop() {
  // Cek Warna
  warnaTerdeteksi = detectColor();
  
  // Atur Bendera
  aturBendera(warnaTerdeteksi);

  // Cek Bluetooth
  if (BTSerial.available()) {
    char cmd = BTSerial.read();
    // Serial.println(cmd); // Debug
    
    if (cmd == 'F') maju();
    else if (cmd == 'B') mundur();
    else if (cmd == 'L') kiri();
    else if (cmd == 'R') kanan();
    else if (cmd == 'S') stopMotor();
  }
  
  delay(30); 
}