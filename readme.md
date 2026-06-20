# 🚀 C++ Object-Oriented Space Shooter Engine

A dynamic, 2D arcade-style space shooter application built in **C++** using the **Simple and Fast Multimedia Library (SFML)**. This project implements advanced **Object-Oriented Programming (OOP)** design patterns to manage a real-time game loop, component lifecycles, and a responsive collision matrix.

Developed individually as part of the **Object-Oriented Programming (CS1004)** curriculum at **FAST-NUCES** (Spring 2023).

---

### 🎨 Key Core Engine Features

* **Polymorphic Enemy Hierarchies:** Utilizes inheritance structures to orchestrate multiple tier-based enemy behaviors:
  * *Invaders:* Implements custom attack frequencies tracking distinct projectile cooldowns for Alpha, Beta, and Gamma classes.
  * *Boss Entities (Monster & Dragon):* Custom behavioral states managing localized horizontal sweeps with continuous lightning beam animations or location-targeted directional zone fire.
* **Wrap-Around Coordinates & Vector Movement:** Handles Omnidirectional and diagonal tracking vectors alongside wrap-around screen boundaries for the player's ship.
* **Dynamic Add-On Lifecycle Management:** Tracks randomly dropping power-up states, including structural invincibility nodes, 7-way multidirectional weapon firing paths, danger-zone obstructions, and live-increment counters.
* **Progressive State & Phase Loading:** Maps a 3-tier difficulty structure featuring 3 distinct structural enemy coordinate formations (rectangles, crosses, filled combinations) per level alongside scaling velocity matrices.
* **Sorted File I/O Performance:** Features persistent file tracking that processes, validates, and ranks player histories in descending order to assign digital standing badges.
* **Polished Multi-Screen State Management:** Implements contextual UI wrappers for operational main menus, live player HUD text displays, instructions, and interactive pausing systems.

---

### 🛠️ Architecture & Core Principles
* **Object-Oriented Design:** Adheres strictly to clean encapsulation, inheritance, and runtime polymorphism across game entities.
* **Graphics & System Interfacing:** Managed via the SFML framework for tracking keyboard interrupts, rendering sprites, managing frame steps, and executing asset manipulations.

---

### 🚀 Compilation and Execution Instructions

To compile and execute this application with your local SFML installation, run the following sequential commands in your terminal:


# 1. Compile the source file into an object file
g++ -c main.cpp

# 2. Link object files and bind essential SFML dependencies
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

# 3. Execute the binary application
./sfml-app

