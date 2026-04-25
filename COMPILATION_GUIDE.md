/**
 * COMPILATION_GUIDE.md
 * Step-by-step guide for compiling the Tic Tac Toe game on Windows
 */

# Tic Tac Toe Game - Compilation Guide for Windows

This guide provides detailed instructions for compiling the Tic Tac Toe game on Windows systems.

## Option 1: Using Visual Studio with CMake (Recommended)

### Prerequisites
- **Visual Studio 2019** or later with C++ development tools
- **CMake** (version 3.10 or higher) - Can be installed via Visual Studio Installer

### Steps

1. **Open the project folder in Visual Studio**
   - Open Visual Studio
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
   - Go to: Build → Run Local Debugger (F5)
   - Or navigate to the build folder and double-click TicTacToe.exe

### Output Location
The compiled executable will be in:
```
C:\Users\Jorge\Documents\GitHub\prueba-de-programación\out\build\x64-Debug\bin\TicTacToe.exe
```

---

## Option 2: Using MinGW (g++) with Command Line

### Prerequisites
- **MinGW** (Minimalist GNU for Windows) installed
- **Make** tool (usually included with MinGW)

### Installation of MinGW

1. Download from: https://sourceforge.net/projects/mingw/
2. Run the installer
3. Select components:
   - mingw32-base-bin
   - mingw32-gcc-g++-bin
   - mingw32-make-bin
4. Install to default location (C:\MinGW)

### Add MinGW to Windows PATH

1. Open Start Menu → Environment Variables
2. Click "Edit the system environment variables"
3. Click "Environment Variables" button
4. Under "System variables", select "Path" and click "Edit"
5. Click "New" and add: `C:\MinGW\bin`
6. Click OK on all dialogs
7. Restart Command Prompt for changes to take effect

### Compilation Steps

1. **Open Command Prompt (cmd) or PowerShell**

2. **Navigate to the project directory**
   ```cmd
   cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación
   ```

3. **Compile using g++ directly**
   ```cmd
   g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
   ```

4. **Run the game**
   ```cmd
   TicTacToe.exe
   ```
   or simply:
   ```cmd
   TicTacToe
   ```

### Using Makefile

If Makefile is present:

1. **In the project directory, run:**
   ```cmd
   make
   ```

2. **To run immediately after compilation:**
   ```cmd
   make run
   ```

3. **To clean compiled files:**
   ```cmd
   make clean
   ```

### Output
The compiled executable will be created as:
```
C:\Users\Jorge\Documents\GitHub\prueba-de-programación\TicTacToe.exe
```

---

## Option 3: Using Windows Subsystem for Linux (WSL)

### Prerequisites
- **Windows 10/11** with WSL2 installed
- **G++** and **Make** installed in WSL

### Setup WSL

1. Open PowerShell as Administrator
2. Run: `wsl --install`
3. Restart your computer
4. Open Ubuntu terminal (or your chosen Linux distro)

### Install Build Tools in WSL

```bash
sudo apt update
sudo apt install build-essential cmake
```

### Compile in WSL

1. **Navigate to your project folder**
   ```bash
   cd /mnt/c/Users/Jorge/Documents/GitHub/prueba-de-programación
   ```

2. **Compile with CMake**
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ./TicTacToe
   ```

   Or compile with g++ directly:
   ```bash
   g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
   ./TicTacToe
   ```

---

## Option 4: Using MSBuild with Visual Studio Project Files

### Prerequisites
- **Visual Studio 2019** or later
- Visual C++ development tools

### Create Visual Studio Project (One-time)

1. **Open Developer Command Prompt for Visual Studio**
   - Start Menu → Type "Developer Command Prompt"

2. **Navigate to project folder**
   ```cmd
   cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación
   ```

3. **Create project files**
   ```cmd
   mkdir build
   cd build
   cmake .. -G "Visual Studio 16 2019"
   ```

4. **Build using MSBuild**
   ```cmd
   msbuild TicTacToe.sln
   ```

---

## Troubleshooting

### Problem: "g++: command not found"
**Solution**: 
- MinGW is not installed or not in PATH
- Add C:\MinGW\bin to your PATH variable
- Restart Command Prompt

### Problem: "cmake: command not found"
**Solution**:
- Install CMake from: https://cmake.org/download/
- Add to PATH: C:\Program Files\CMake\bin

### Problem: Compilation errors about `#include`
**Solution**:
- Ensure all files (main.cpp, TicTacToe.cpp, TicTacToe.h) are in the same directory
- Check file paths are correct

### Problem: The program doesn't run
**Solution**:
- Make sure you're in the correct directory
- Use: `.\TicTacToe.exe` (with dot-slash for PowerShell)
- Or: `TicTacToe.exe` (in Command Prompt)

### Problem: "permission denied"
**Solution**:
- On Windows, this shouldn't occur. If in WSL, run: `chmod +x TicTacToe`

---

## Quick Reference

### For Command Line Users (Fastest)

```cmd
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación

REM Compile
g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp

REM Run
TicTacToe.exe
```

### For Visual Studio Users (Most Integrated)

1. Open folder in Visual Studio
2. Build → Build All (Ctrl+Shift+B)
3. Debug → Run Without Debugging (Ctrl+F5)

### For CMake Users (Most Portable)

```cmd
mkdir build
cd build
cmake ..
cmake --build .
TicTacToe.exe
```

---

## Performance Notes

- **First compilation**: 1-5 seconds depending on your system
- **Subsequent compilations**: 1-2 seconds (only changed files recompile)
- **Game execution**: Executable is about 50-100 KB
- **Memory usage**: Minimal (less than 10 MB during gameplay)

---

## Version Information

- **C++ Standard**: C++11 (compatible with C++14, C++17, C++20)
- **Tested Compilers**:
  - Microsoft Visual C++ 2019+
  - g++ 9.0+
  - Clang 10.0+

---

## Next Steps

After successful compilation:
1. Read the main menu instructions in the game
2. Try to beat the AI (spoiler: you probably can't!)
3. Review the source code to understand the minimax algorithm
4. Check ALGORITHM_DOCUMENTATION.md for technical details

---

**Happy Coding!**

For additional help, refer to:
- README.md - Game instructions and features
- ALGORITHM_DOCUMENTATION.md - Algorithm details
- Source code comments - Inline documentation
