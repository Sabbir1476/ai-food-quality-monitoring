
# 🤖 AI Food Quality Monitoring

## 💡 Overview

A TinyML-based system that detects food freshness using IoT sensors and machine learning.

---

## 🧠 Model

* Built with Edge Impulse
* Exported as TensorFlow Lite model
* Runs on microcontrollers

---

## 🛠 Tech Stack

* Arduino / ESP32
* TinyML (TensorFlow Lite)
* IoT Sensors (Gas, Temperature, Humidity)

---

## 📂 Project Structure

* `model/` → ML model files
* `src/` → inference logic
* `main.ino` → main execution file

---

## ⚙️ How It Works

1. Sensors collect environmental data
2. Data is passed into ML model
3. Model predicts freshness
4. Output shown via Serial Monitor

---

## ▶️ How to Run

1. Open Arduino IDE
2. Add this project as a library
3. Upload `main.ino`
4. Open Serial Monitor

---

## 👤 Author
Shabir Rahman
