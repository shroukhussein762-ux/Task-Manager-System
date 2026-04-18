# 🚀 Task Management System (C++)

A professional console-based application designed to manage complex workflows through Users, Projects, and Tasks using **Object-Oriented Programming (OOP)**. This project demonstrates high-level software architecture and efficient data handling.

## 🌟 Key Features
- **Hierarchical Structure:** Manage data across three organized levels: User ➡️ Project ➡️ Task.
- **Smart ID Recycling:** Implements a custom logic to reuse IDs from deleted entities to keep the database optimized.
- **Data Persistence:** Automatically saves and loads all data via `database.txt` using C++ File I/O.
- **Clean Architecture:** Separated Headers and Implementation files with a nested directory structure for scalability.
- **Robust Validation:** Full protection against invalid user inputs to prevent system crashes.

## 📂 Project Structure
```text
├── Header/                # Shared header files (.h)
│   ├── Project.h
│   ├── Task.h
│   ├── TaskManager.h
│   └── User.h
├── Source/                # Detailed implementations (.cpp)
│   ├── Project/           # Project-related functions
│   ├── Task/              # Task-related functions
│   ├── TaskManager/       # TaskManager-related functions
│   └── User/              # User-related functions
├── .gitignore             # Git exclusion rules
├── database.txt           # Persistent storage (Auto-generated)
└── Main.cpp               # System entry point