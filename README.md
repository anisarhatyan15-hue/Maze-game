#  Qt C++ Game Desktop Application

A modular 2D desktop application built using **C++**, **CMake**, and the **Qt Framework**. The project showcases a clean structural foundation for graphical user interfaces and real-time application loops.

---

##  Project Architecture & Components

The repository is designed with a highly modular structure, separating the core application lifecycle from experimental gameplay mechanics.

###  Active Core Engine
The active execution layer handles the main window rendering, UI components, and the CMake build pipeline:
* **`main.cpp`** — The primary entry point initializing the Qt application lifecycle.
* **`mainwindow.h/.cpp/.ui`** — Exploit's Qt's object-oriented UI controller pattern, managing scenes, core interactions, and layouts.
* **`CMakeLists.txt`** — Cross-platform meta-build configuration compiling the active executable layers.

###  Modular Blueprint Extensions (Future Rollouts)
To preserve architecture decoupling, separate engine sub-systems are structured as clean, isolated object models. These component files are structurally integrated and ready for upcoming iterative feature expansions:
* **Entity Systems:** `player.h/.cpp` & `enemy.h/.cpp` (Modular actor blueprints).
* **Projectiles & Collisions:** `bullet.h/.cpp` (Weapon mechanics placeholders).
* **Media Pipelines:** `openalengine.h/.cpp` (Dedicated OpenAL audio subsystem blueprint).

---

##  Getting Started

### Prerequisites
* **Qt 6.x / 5.x** (Desktop Kit, e.g., MinGW 64-bit)
* **CMake** 3.16+

### Build and Run
1. Open the project inside **Qt Creator** using the `CMakeLists.txt` file.
2. Select your active Desktop Kit (e.g., MinGW).
3. Build and execute the active core layout via **Ctrl + R**.

---

##  Tech Stack
* **Language:** C++ (C++17/C++20)
* **Framework:** Qt Widgets & Core Modules
* **Build System:** CMake
