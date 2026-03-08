# 📒 Notes App

A simple command-line notes application written in C++.

## Features

- Add notes with title and content
- List all saved notes
- View a specific note by ID
- Delete notes
- Search notes by keyword
- Data is saved to a local file (persists after closing)

## How to Build

Make sure you have `g++` installed.
```bash
g++ main.cpp notes.cpp -o notes_app
```

## How to Run
```bash
./notes_app        # Linux / Mac
.\notes_app.exe    # Windows
```

## Usage

| Option | Action |
|--------|--------|
| 1 | Add a new note |
| 2 | List all notes |
| 3 | View a note by ID |
| 4 | Delete a note by ID |
| 5 | Search notes by keyword |
| 0 | Exit |

## Project Structure
```
cpp-notes-app/
├── main.cpp      # Entry point and menu logic
├── notes.h       # NoteManager class definition
├── notes.cpp     # NoteManager class implementation
└── notes_data.txt  # Auto-generated data file
```

## Built With

- C++17
- Standard Library only (no external dependencies)