# Tic Tac Toe Game in C++

## Overview

This is a complete implementation of the classic Tic Tac Toe (Three in a Row) game in C++. The game features an unbeatable AI opponent that uses the **Minimax algorithm** to make optimal moves. Players can choose between a **console interface** or a **graphical interface** for gameplay.

## Features

### Shared Features (Both Versions)
- **Unbeatable AI**: Uses minimax algorithm with depth-based optimization
- **Input Validation**: Robust error handling for invalid moves
- **Game State Management**: Tracks wins, losses, and draws
- **Smart Decision Making**: AI plays optimally

### Console Version
- **Interactive Text Interface**: User-friendly menu-driven gameplay
- **Clear Board Display**: ASCII representation of the game board
- **Keyboard Input**: Type numbers 1-9 to place marks

### Graphical Version
- **Modern GUI**: Built with SFML (Simple and Fast Multimedia Library)
- **Mouse Interaction**: Click directly on board cells
- **Visual Marks**: Color-coded X (Red) and O (Blue) marks
- **Real-time Rendering**: 60 FPS smooth graphics
- **Instant Restart**: Press SPACE to play again
- **Status Messages**: Clear on-screen feedback

## Project Structure

```
prueba-de-programación/
├── src/                    # Source code
│   ├── main.cpp            # Console entry point
│   ├── main-gui.cpp        # GUI entry point
│   ├── TicTacToe.h         # Game logic declaration
│   ├── TicTacToe.cpp       # Game logic implementation
│   ├── GUI.h               # GUI declaration
│   └── GUI.cpp             # GUI implementation
├── tests/                  # Tests and data
│   └── input.txt           # Test input
├── docs/                   # Documentation
│   └── ALGORITHM_DOCUMENTATION.md
├── CMakeLists.txt          # Build configuration
├── README.md               # This file
├── CONTRIBUTING.md         # Contribution guidelines
└── LICENSE                 # License
```

## File Descriptions

### Game Core

**src/TicTacToe.h**
- Header file with game logic class declaration
- Defines the `TicTacToe` class interface
- Documents all public methods

**src/TicTacToe.cpp**
- Implementation of the `TicTacToe` class
- Contains the minimax algorithm for AI
- Implements board management and game state evaluation

### Console Version

**src/main.cpp**
- Entry point for console application
- Contains game loop and text-based user interface
- Handles keyboard input and menu navigation
- Displays game board using ASCII characters

### Graphical Version

**src/main-gui.cpp**
- Entry point for GUI application
- Initializes game and passes it to GUI renderer

**src/GUI.h**
- Header file for graphical interface class
- Defines `TicTacToeGUI` class using SFML library
- Documents all rendering and input handling methods

**src/GUI.cpp**
- Implementation of graphical interface
- Handles SFML rendering, window management, and events
- Draws game board, marks, and status information
- Processes mouse clicks and keyboard input

### Build & Configuration

**CMakeLists.txt**
- Build configuration for cross-platform compilation
- Supports C++11 standard
- Automatically detects and links SFML if available
- Builds both console and GUI versions

### Documentation

**README.md** (this file)
- Complete project overview and usage guide

**docs/ALGORITHM_DOCUMENTATION.md**
- Technical explanation of minimax algorithm
- Game theory background
- Performance analysis and optimizations

## Quick Start

### Console Version (Windows)

```cmd
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación
mkdir build
cd build
cmake ..
cmake --build .
bin\TicTacToe.exe
```

### Console Version (Linux/macOS)

```bash
cd ~/path/to/prueba-de-programación
mkdir build
cd build
cmake ..
cmake --build .
./bin/TicTacToe
```

### Direct Compilation (All Platforms)

**Console version only:**
```cmd
g++ -std=c++11 -o TicTacToe src/main.cpp src/TicTacToe.cpp
TicTacToe.exe
```

## Compilation Guide

### Prerequisites
- **C++ Compiler**: g++, MSVC, or Clang (C++11 or later)
- **CMake**: Version 3.10 or higher
- **SFML** (optional, for GUI): See GUI Installation below

### Using Visual Studio with CMake (Recommended)

1. **Open the project folder in Visual Studio**
   - File → Open → Folder
   - Navigate to: `C:\Users\Jorge\Documents\GitHub\prueba-de-programación`

2. **Configure CMake**
   - Visual Studio will automatically detect CMakeLists.txt
   - A notification bar will appear asking to configure the project
   - Click "Yes" or go to: Project → Configure TicTacToe

3. **Build the project**
   - Build → Build All (Ctrl+Shift+B)
   - Or right-click on CMakeLists.txt → Build

4. **Run the executable**
   - Build → Run Local Debugger (F5)
   - Or navigate to the build folder and run TicTacToe.exe

### Using MinGW (g++) with Command Line

1. **Install MinGW** (if not already installed)
   - Download from: https://sourceforge.net/projects/mingw/
   - Install components: mingw32-base-bin, mingw32-gcc-g++-bin, mingw32-make-bin
   - Add `C:\MinGW\bin` to your PATH

2. **Compile**
   ```cmd
   cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación
   g++ -std=c++11 -o TicTacToe src/main.cpp src/TicTacToe.cpp
   ```

3. **Run**
   ```cmd
   TicTacToe.exe
   ```

### Using CMake (Cross-Platform)

```bash
# Navigate to project
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación

# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build
cmake --build .

# Run (Windows)
bin\TicTacToe.exe

# Run (Linux/macOS)
./bin/TicTacToe
```

### Using WSL (Windows Subsystem for Linux)

1. **Open PowerShell as Administrator**
   ```powershell
   wsl --install
   ```

2. **Setup build tools in WSL**
   ```bash
   sudo apt update
   sudo apt install build-essential cmake
   ```

3. **Compile in WSL**
   ```bash
   cd /mnt/c/Users/Jorge/Documents/GitHub/prueba-de-programación
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ./bin/TicTacToe
   ```

## GUI Installation

### SFML Installation

#### Windows

**Using vcpkg (Recommended):**
```cmd
# Clone vcpkg
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat

# Install SFML
.\vcpkg install sfml:x64-windows

# Integrate with CMake
.\vcpkg integrate install
```

**Using Chocolatey:**
```cmd
choco install sfml
```

**Manual Installation:**
1. Download SFML from: https://www.sfml-dev.org/download.php
2. Extract to `C:\SFML`
3. Add to System PATH: `C:\SFML\lib`

#### Linux (Ubuntu/Debian)

```bash
sudo apt-get update
sudo apt-get install libsfml-dev
```

#### Linux (Fedora/RHEL)

```bash
sudo dnf install SFML-devel
```

#### macOS

```bash
brew install sfml
```

### Building GUI Version

Once SFML is installed, the CMake build will automatically detect it and build both versions:

```bash
mkdir build
cd build
cmake ..
cmake --build .

# Run GUI version
bin\TicTacToe-GUI.exe  # Windows
./bin/TicTacToe-GUI    # Linux/macOS
```

### GUI Controls

| Action | Key/Mouse |
|--------|-----------|
| Place Mark | Click on cell |
| New Game | Press SPACE |
| Close Game | Click window X or Alt+F4 |

### GUI Features

✅ **Interactive Board** - Click on cells to place your mark
✅ **Real-time Rendering** - Smooth 60 FPS graphics
✅ **Visual Feedback** - Color-coded marks (Red X, Blue O)
✅ **Status Display** - Clear messages about game state
✅ **Game Over Screen** - Beautiful end-game display
✅ **Play Again** - Press SPACE to restart instantly

### GUI Troubleshooting

**Problem: "SFML not found" during CMake**
```cmd
# With vcpkg toolchain
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:\path\to\vcpkg\scripts\buildsystems\vcpkg.cmake

# Or manual SFML path
cmake .. -DSFML_DIR="C:\SFML\lib\cmake\SFML"
```

**Problem: Linker errors or DLL not found**
- Ensure correct SFML version for your architecture (64-bit recommended)
- Add SFML bin directory to PATH: `C:\SFML\bin`

**Problem: Window doesn't open**
- Check that graphics drivers are updated
- Verify system supports OpenGL 1.4+

