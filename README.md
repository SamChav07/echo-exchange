# 🔁 Echo-Exchange

**Echo-Exchange** is a terminal-based C++ application designed to manage a **loyalty rewards system** for clients. The platform allows administrators to register clients, log purchases, assign reward points, and enable clients to redeem points for gifts — all within an interactive and styled CLI.

Developed as a final project for the *Structured Programming and Methodology* course, this system follows clean logic, modular C++ design, and ANSI color-coded interface prompts for enhanced UX—especially tailored for **macOS terminals**.

---

## 🎯 Project Objectives

- 🧾 Register and manage clients.
- 💳 Track purchases and assign points (conversion: C$100 = 1 point).
- 🎁 Handle a rewards inventory with dynamic stock and cost per item.
- 🔐 Provide separate access for administrators and clients.
- 📜 Maintain a purchase history with date and point tracking.

---

## 🛠️ Key Features

### 👤 Admin Features
- Client CRUD (add, search, update, delete).
- Reward management (inventory CRUD).
- Purchase logging.
- Global point and history consultation.

### 👥 Client Features
- Login with ID.
- View accumulated points.
- Redeem points for rewards (with cash fallback if insufficient).
- View personal purchase history.

### 🔐 Login & Role-Based Access
- Admin login requires credentials.
- Clients access via their stored ID.
- Super-admin role allows choosing between access types at startup.

### 🎨 Terminal UX
- Color-coded menus (ANSI escape codes).
- Clean console layout for clarity.
- Input validation for names, emails, and phone numbers.

---

## 🧪 Tech Stack

- **Language:** C++
- **Interface:** CLI (macOS Terminal optimized)
- **Libraries Used:** `<iostream>`, `<cstring>`, `<iomanip>`, `<unistd.h>`, `<fstream>`

---

## 🚀 How to Compile & Run

```bash
# Compile
g++ base.cpp -o echo-exchange

# Run
./echo-exchange
