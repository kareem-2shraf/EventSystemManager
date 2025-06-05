# 🎟️ Event Management System — C++ Console-Based Organizer 📅🎤

A dynamic C++ event management system that allows users to create, modify, and manage events and their attendees. Designed with linked lists, stacks, and queues, it includes undo functionalities, attendee tracking, and smart console output — perfect for efficiently running tech or student-led events.

---

## 📌 Table of Contents

1. [Overview](#overview)  
2. [Features](#features)  
3. [Technologies Used](#technologies-used)  
4. [System Design](#system-design)  
5. [Installation & Setup](#installation--setup)  
6. [Usage](#usage)  
7. [Code Highlights](#code-highlights)  
8. [How It Works](#how-it-works)  
9. [Project Structure](#project-structure)  
10. [Team & Acknowledgements](#team--acknowledgements)  
11. [License](#license)

---

## 🧠 Overview

The **Event Management System** is a console application that manages:

- Event creation and deletion  
- Attendee registration and removal  
- Undo functionalities for both events and attendees  
- Attendee search per event

This system provides practical use for student events, clubs, and competitions requiring structured logistics and participant handling.

---

## ✨ Features

- 📌 **Add Events**: Add events at the start, end, or a specific position  
- ❌ **Delete Events**: Remove events by ID with undo support  
- 🧾 **Print Events**: View a live-listed schedule  
- 🧍 **Manage Attendees**:
  - Add/remove attendees by event
  - Display or search for attendees
  - Undo attendee removal  
- ↩️ **Undo Operations**:
  - Undo last event deletion
  - Undo last attendee deletion per event  
- ⏳ **Console Visual Feedback** with color-coded output and delays

---

## 🧰 Technologies Used

- **Language**: C++  
- **Data Structures**: Singly Linked List, Linked Stack, Linked Queue, File Handling, Header FiLes.
- **Libraries**:  
  - `<iostream>`, `<string>`, `<chrono>`, `<thread>`  
  - Custom: `stack.h`, `queue.h`, `event.h`, `utilities.h`  
- **Terminal Enhancements**: ANSI color codes

---

## 🧱 System Design

```
main.cpp
 ├── Displays welcome screen
 ├── Calls enterEvents() → user inputs events
 └── Calls manageEvents() → menu to manipulate events

event.h / event.cpp
 ├── Linked List: Stores event nodes
 ├── Stack: Undo history for event deletions and attendee removals
 ├── Queue: Used inside attendee tracking (if implemented in headers)
 └── Functions:
     • addfirst, addlast, addAtPos
     • remove_event, undo
     • insertAttendto_event, delAttendfrom_event, disAttendin_event, findAttendat_event
     • undo_last_attendee
```

---

## 🛠️ Installation & Setup

1. **Clone the repository**:

   ```bash
   git clone https://github.com/<your-username>/event-management-system.git
   cd event-management-system
   ```

2. **Compile the files** using any C++ compiler (e.g., g++):

   ```bash
   g++ main.cpp event.cpp stack.cpp queue.cpp -o eventManager
   ```

3. **Run the executable**:

   ```bash
   ./eventManager
   ```

---

## ▶️ Usage

1. Run the app → Welcome message appears.  
2. Enter events (name + ID).  
3. Manage events through the menu:
   - Add/remove events
   - Add/delete/search/display attendees
   - Undo actions  
4. Console displays colorful, timed messages for feedback.

---

## 🔍 Code Highlights

### 🧱 Adding Event at a Specific Position

```cpp
void linkedlist::addAtPos(string name, string id, int pos) {
    if (pos < 0 || pos > length) {
        cout << "Out of Range!" << endl;
        return;
    }
    // Adds event using custom logic
}
```

### 🧍‍♂️ Attendee Management

```cpp
void linkedlist::insertAttendto_event(string id, string attendee) {
    // Adds attendee to given event ID
}
```

### ↩️ Undo Deletion of Event

```cpp
void linkedlist::undo() {
    if (undo_event.isEmpty()) {
        cout << "Nothing to undo!" << endl;
        return;
    }
    // Re-adds last deleted event
}
```

---

## 🔄 How It Works

1. **Startup**: Welcomes the user and collects event input.  
2. **Linked List**: Stores events in memory with ID and name.  
3. **Stack**: Tracks undo history for event deletions and attendee removals.  
4. **Queue / Custom Class**: Handles attendee lists internally.  
5. **UI**: Console-based navigation with color-coded output and short delays.

---

## 🗂️ Project Structure

```
event-management-system/
├── event.cpp         # Linked list & logic implementation
├── event.h           # Event class and structure definitions
├── main.cpp          # Entry point of the application
├── queue.cpp / stack.cpp # Supporting data structures
├── queue.h / stack.h # Supporting data structures
├── utilities.h       # Delay and UI utilities
├── utilities.cpp     # Delay and UI utilities
├── README.md         # Project documentation
```

---

## 👥 Team & Acknowledgements

**Developers**: Kareem Ashraf, Mohamed Amasha

**Special Thanks**:  
- Our C++ instructors and colleagues  
- Open-source communities for reference ideas
  
---

## 📄 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for terms.
