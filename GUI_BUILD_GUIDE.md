/**
 * GUI_BUILD_GUIDE.md
 * Instructions for building and running the graphical version
 */

# Tic Tac Toe GUI - Build and Installation Guide

## Overview

The graphical version of Tic Tac Toe uses **SFML** (Simple and Fast Multimedia Library) to provide a modern, interactive user interface.

## Features of the Graphical Version

✅ **Interactive Board** - Click on cells to place your mark
✅ **Real-time Rendering** - Smooth 60 FPS graphics
✅ **Visual Feedback** - Color-coded marks (Red X, Blue O)
✅ **Status Display** - Clear messages about game state
✅ **Game Over Screen** - Beautiful end-game display
✅ **Play Again** - Press SPACE to restart instantly

## Installation Requirements

### Step 1: Install SFML Library

#### Windows

**Option A: Using vcpkg (Recommended)**

```cmd
# Install vcpkg if you haven't already
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat

# Install SFML
.\vcpkg install sfml:x64-windows

# Integrate with CMake (run once)
.\vcpkg integrate install
```

**Option B: Using Chocolatey**

```cmd
choco install sfml
```

**Option C: Manual Installation**

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

### Step 2: Verify SFML Installation

**Windows (Command Prompt)**
```cmd
cd C:\SFML\include
dir
# Should show SFML directory
```

**Linux/macOS (Terminal)**
```bash
pkg-config --modversion sfml-all
# Should output SFML version
```

## Building the GUI Version

### Method 1: Using CMake (Cross-Platform)

```cmd
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación

# Create build directory
mkdir build
cd build

# Generate build files (CMake will find SFML automatically)
cmake ..

# Build both console and GUI versions
cmake --build .

# Run the GUI version
bin\TicTacToe-GUI.exe
```

### Method 2: Direct g++ Compilation

```cmd
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación

# Compile with SFML libraries
g++ -std=c++11 -o TicTacToe-GUI main-gui.cpp GUI.cpp TicTacToe.cpp ^
    -I"C:\SFML\include" ^
    -L"C:\SFML\lib" ^
    -lsfml-graphics -lsfml-window -lsfml-system

# Run
TicTacToe-GUI.exe
```

### Method 3: Using Visual Studio

1. Open the project folder in Visual Studio
2. Visual Studio should automatically detect CMakeLists.txt
3. If CMake is installed with SFML:
   - Build → Build All (Ctrl+Shift+B)
4. The GUI executable will be in the output directory

## Troubleshooting

### Problem: "SFML not found" during CMake

**Possible causes:**
1. SFML not installed
2. CMake can't locate SFML

**Solutions:**

**On Windows with vcpkg:**
```cmd
# Make sure you ran this before CMake
vcpkg integrate install

# Rebuild with vcpkg toolchain
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:\path\to\vcpkg\scripts\buildsystems\vcpkg.cmake
```

**On Linux:**
```bash
# Update CMake package database
sudo update-alternatives --install /usr/bin/cmake cmake /usr/bin/cmake 1

# Install pkg-config
sudo apt-get install pkg-config
```

**Manual SFML path (Windows):**
```cmd
cmake .. -DSFML_DIR="C:\SFML\lib\cmake\SFML"
```

### Problem: Linker errors (undefined reference to sfml...)

**Causes:**
- SFML libraries not linked
- Wrong architecture (32-bit vs 64-bit mismatch)
- Missing .dll files

**Solutions:**

Ensure the correct SFML version for your system:
```cmd
# For 64-bit (recommended)
vcpkg install sfml:x64-windows

# Or verify installed version
vcpkg list | findstr sfml
```

Add required .dll files to your PATH:
```
C:\SFML\bin
```

### Problem: DLL not found when running GUI

**Cause:** SFML runtime libraries not in PATH

**Solution:**

Copy SFML DLLs to the executable directory or add to PATH:
```
C:\SFML\bin\sfml-graphics-2.dll
C:\SFML\bin\sfml-window-2.dll
C:\SFML\bin\sfml-system-2.dll
```

### Problem: Window doesn't open or crashes

**Check:**
1. Font files can be found (check COMPILATION_GUIDE.md)
2. Graphics card drivers are updated
3. System supports OpenGL 1.4+

## Running the GUI Application

### Basic Launch

```cmd
TicTacToe-GUI.exe
```

### From Build Directory

```cmd
cd build\bin
TicTacToe-GUI.exe
```

## GUI Controls

| Action | Key/Mouse |
|--------|-----------|
| Place Mark | Click on cell |
| New Game | Press SPACE |
| Close Game | Click window X or Alt+F4 |

## Screen Layout

```
┌─────────────────────────────────┐
│     TIC TAC TOE (title)         │
│ Your turn (Click to place X)    │
├─────────────────────────────────┤
│                                 │
│      1 │ 2 │ 3                  │
│      ──┼───┼──                  │
│      4 │ 5 │ 6                  │
│      ──┼───┼──                  │
│      7 │ 8 │ 9                  │
│                                 │
├─────────────────────────────────┤
│  Click to place X               │
└─────────────────────────────────┘
```

## Performance Notes

- **First Launch**: May take 1-2 seconds to initialize SFML
- **Frame Rate**: 60 FPS (smooth and responsive)
- **Memory Usage**: 30-50 MB
- **Window Resizable**: No (fixed 600x700 pixels)

## File Structure

```
prueba-de-programación/
├── main-gui.cpp          ← Entry point for GUI
├── GUI.h                 ← GUI class declaration
├── GUI.cpp               ← GUI implementation
├── TicTacToe.h           ← Game logic (shared)
├── TicTacToe.cpp         ← Game logic (shared)
├── CMakeLists.txt        ← Build configuration
└── GUI_BUILD_GUIDE.md    ← This file
```

## Console Version Still Available

The console version is also built:

```cmd
# Run console version
bin\TicTacToe.exe
```

Both versions share the same game logic (TicTacToe.cpp/h).

## SFML Version Information

- **Tested with**: SFML 2.5 and 2.6
- **Graphics Renderer**: OpenGL 1.4+
- **Window Backend**: Windows: Win32 API, Linux: X11, macOS: Cocoa

## Features Comparison

| Feature | Console | GUI |
|---------|---------|-----|
| Play Game | ✓ | ✓ |
| Interactive Board | Limited | ✓ |
| Visual Graphics | ✗ | ✓ |
| AI Opponent | ✓ | ✓ |
| Keyboard Input | ✓ | ✗ |
| Mouse Input | ✗ | ✓ |
| Instant Restart | ✗ | ✓ (SPACE) |
| Scalable | ✗ | ✗ (Fixed size) |

## Future Enhancements

- [ ] Resizable window with dynamic scaling
- [ ] Animation for mark placement
- [ ] Sound effects
- [ ] Game statistics overlay
- [ ] Difficulty selection menu
- [ ] Theme customization
- [ ] High score tracking

## Support for Different Platforms

### Windows 10/11
- Full support with Visual Studio or MinGW
- Fastest with MSVC compiler

### Linux
- Full support
- SFML easily available through package managers

### macOS
- Full support with Homebrew
- Native Cocoa window backend

## Additional Resources

- **SFML Documentation**: https://www.sfml-dev.org/documentation/
- **CMake Documentation**: https://cmake.org/cmake/help/latest/
- **vcpkg Packages**: https://vcpkg.io/

---

**Need Help?** Check the troubleshooting section above or review the main README.md file.

**Last Updated**: April 25, 2026
