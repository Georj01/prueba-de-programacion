/**
 * QUICK_START_GUI.md
 * Quick start guide for the graphical version on Windows
 */

# Quick Start Guide - Tic Tac Toe GUI (Windows)

## 30-Second Setup

### Option 1: Using g++ (Fastest if g++ is installed)

```cmd
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación
g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
TicTacToe.exe
```

**⚠️ Note:** This builds the console version. For the GUI, you need SFML.

### Option 2: Using Visual Studio (If you have it)

1. Open the folder in Visual Studio
2. Press `Ctrl+Shift+B` to build
3. Press `F5` to run
4. Select TicTacToe-GUI if available

## Setting Up GUI Version (5-10 minutes)

### Step 1: Install SFML

Choose one method:

**Method A: Using Chocolatey (Easiest)**
```cmd
choco install sfml
```

**Method B: Using vcpkg (Recommended for developers)**
```cmd
# Install vcpkg (one time)
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat

# Install SFML
.\vcpkg install sfml:x64-windows

# Integrate with CMake (one time)
.\vcpkg integrate install
```

**Method C: Manual Download**
1. Go to https://www.sfml-dev.org/download.php
2. Download SFML for Visual Studio
3. Extract to `C:\SFML`
4. Add `C:\SFML\bin` to your Windows PATH

### Step 2: Build GUI Version

```cmd
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación

mkdir build
cd build

cmake ..

cmake --build .

# Run the GUI version
bin\TicTacToe-GUI.exe
```

## Playing the GUI Game

### Controls
- **Click on board** - Place your X mark
- **SPACE key** - Start new game after game ends
- **Close window** - Exit game

### Game Flow
1. You are X (Red)
2. AI is O (Blue)
3. Click a cell to play
4. AI automatically makes its move
5. First to get 3 in a row wins!
6. On draw, press SPACE to replay

## If GUI Won't Build

### "SFML not found" Error

**Option 1: Use console version instead**
```cmd
cd build
bin\TicTacToe.exe
```

**Option 2: Help CMake find SFML**
```cmd
# If you installed SFML manually at C:\SFML
cmake .. -DSFML_DIR="C:\SFML\lib\cmake\SFML"
cmake --build .
```

**Option 3: Try with vcpkg**
```cmd
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:\path\to\vcpkg\scripts\buildsystems\vcpkg.cmake
cmake --build .
```

### "Linker Error" or DLL Not Found

Make sure SFML DLLs are accessible:
```cmd
# Add to PATH (temporarily in this command prompt)
set PATH=C:\SFML\bin;%PATH%

# Then run the GUI
bin\TicTacToe-GUI.exe
```

## Console Version (Always Available)

If GUI gives trouble, the console version works without SFML:

```cmd
bin\TicTacToe.exe
```

Same game, same unbeatable AI, just text-based interface.

## Complete Installation Example

**From scratch with vcpkg:**

```cmd
REM 1. Install vcpkg
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install

REM 2. Install SFML
.\vcpkg install sfml:x64-windows

REM 3. Build project
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación
mkdir build
cd build
cmake ..
cmake --build .

REM 4. Run GUI
bin\TicTacToe-GUI.exe
```

## Troubleshooting Quick Tips

| Problem | Solution |
|---------|----------|
| "g++: command not found" | Install MinGW or Visual Studio |
| "cmake: command not found" | Install CMake from cmake.org |
| "SFML not found" | Install SFML (see Setup section) |
| GUI won't open | Run console version instead |
| DLL errors | Add SFML\bin to PATH |

## Next Steps

- **Read GUI_BUILD_GUIDE.md** for detailed setup
- **Check README.md** for game rules
- **See ALGORITHM_DOCUMENTATION.md** to understand the AI
- **Review GUI_UPDATE.md** for what's new

## What to Expect

✅ **Console Window** - Starts up in ~1 second
✅ **Game Board** - 3x3 grid with nice styling
✅ **Your Turn** - Click where you want to play
✅ **AI Response** - Instant decision making
✅ **Game Over** - Clear winner message
✅ **Replay** - Press SPACE immediately

## One-Liner Build & Run

**If everything is installed:**
```cmd
cd build && cmake .. && cmake --build . && bin\TicTacToe-GUI.exe
```

---

**Need more help?** Check GUI_BUILD_GUIDE.md for comprehensive instructions.

**Just want to play?** Run `bin\TicTacToe.exe` for the console version!

Enjoy the game! 🎮
