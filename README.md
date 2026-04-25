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

### Graphical Version (NEW!)
- **Modern GUI**: Built with SFML (Simple and Fast Multimedia Library)
- **Mouse Interaction**: Click directly on board cells
- **Visual Marks**: Color-coded X (Red) and O (Blue) marks
- **Real-time Rendering**: 60 FPS smooth graphics
- **Instant Restart**: Press SPACE to play again
- **Status Messages**: Clear on-screen feedback

## Project Structure

```
prueba-de-programación/
├── Game Logic Files
├── main.cpp                 # Console version entry point
├── main-gui.cpp             # GUI version entry point
├── TicTacToe.h              # Game logic class declaration
├── TicTacToe.cpp            # Game logic implementation
├── GUI.h                    # Graphical interface declaration
├── GUI.cpp                  # Graphical interface implementation
├── CMakeLists.txt           # Build configuration
├── Makefile                 # Traditional make build
├── README.md                # This file
├── GUI_BUILD_GUIDE.md       # SFML setup instructions
├── COMPILATION_GUIDE.md     # Windows compilation guide
├── ALGORITHM_DOCUMENTATION.md  # Minimax algorithm details
└── PROJECT_SUMMARY.md       # Project overview
```

## File Descriptions

### Game Core (Shared by Both Versions)

**TicTacToe.h**
- Header file with game logic class declaration
- Defines the `TicTacToe` class interface
- Documents all public methods and functions

**TicTacToe.cpp**
- Implementation of the `TicTacToe` class
- Contains the minimax algorithm for AI
- Implements board management and game state evaluation

### Console Version

**main.cpp**
- Entry point for console application
- Contains game loop and text-based user interface
- Handles keyboard input and menu navigation
- Displays game board using ASCII characters

### Graphical Version (NEW!)

**main-gui.cpp**
- Entry point for GUI application
- Initializes game and passes it to GUI renderer

**GUI.h**
- Header file for graphical interface class
- Defines `TicTacToeGUI` class using SFML library
- Documents all rendering and input handling methods

**GUI.cpp**
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

**Makefile**
- Traditional Unix make build script
- Alternative to CMake for simple compilation

### Documentation

**README.md** (this file)
- Complete project overview and usage guide

**GUI_BUILD_GUIDE.md** (NEW!)
- Instructions for installing SFML
- Platform-specific build procedures
- Troubleshooting guide

**COMPILATION_GUIDE.md**
- Detailed Windows compilation instructions
- Multiple compilation methods

**ALGORITHM_DOCUMENTATION.md**
- Technical explanation of minimax algorithm
- Game theory background
- Performance analysis

**PROJECT_SUMMARY.md**
- Project statistics and highlights
- Feature matrix and comparisons

## Compilation

### Quick Start (Console Version)

**Windows (Command Prompt)**
```cmd
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación
g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
TicTacToe.exe
```

**Linux/macOS (Terminal)**
```bash
cd ~/path/to/prueba-de-programación
g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
./TicTacToe
```

### Building Both Versions with CMake

#### Prerequisites
- **C++ Compiler**: g++, MSVC, or Clang (C++11 or later)
- **CMake**: Version 3.10 or higher
- **SFML** (optional, for GUI): See GUI_BUILD_GUIDE.md for installation

#### Build Steps

```bash
# Navigate to project
cd prueba-de-programación

# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Compile
cmake --build .

# Result: Both TicTacToe and TicTacToe-GUI executables
```

#### Console Version Only

```bash
cd build
./bin/TicTacToe          # Linux/macOS
bin\TicTacToe.exe        # Windows
```

#### GUI Version

For GUI version, first **install SFML** (see GUI_BUILD_GUIDE.md), then:

```bash
cd build
./bin/TicTacToe-GUI      # Linux/macOS
bin\TicTacToe-GUI.exe    # Windows
```

### Manual Compilation with g++

```bash
cd prueba-de-programación
g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
./TicTacToe
```

#### Using Visual Studio (Windows)

```bash
# In the project directory
mkdir build
cd build
cmake ..

# This generates Visual Studio project files
# Open the generated .sln file in Visual Studio and build
```

## How to Play

### Game Rules

1. **Players**: You play as 'X' and the AI plays as 'O'
2. **Board**: The game board consists of a 3x3 grid with positions numbered 1-9:
   ```
   1 | 2 | 3
   ---------
   4 | 5 | 6
   ---------
   7 | 8 | 9
   ```

3. **Objective**: Be the first to get three of your marks in a row (horizontal, vertical, or diagonal)
4. **Gameplay**: 
   - Enter a number (1-9) to place your mark at that position
   - The AI will then make its move
   - The game continues until there is a winner or the board is full (draw)

### Strategy Tips

- The center (position 5) is often a strategic starting position
- Corners are valuable for blocking diagonal wins
- The AI uses optimal play, so draw is the best you can achieve

## Algorithm Explanation

### Minimax Algorithm

The AI uses the **Minimax algorithm**, a decision-making algorithm that:

1. **Recursively explores** all possible future game states
2. **Evaluates terminal states**: Assigns +10 for AI win, -10 for human win, 0 for draw
3. **Maximizes** when it's the AI's turn (choosing the highest score)
4. **Minimizes** when it's the human's turn (choosing the lowest score from the AI's perspective)
5. **Selects** the move that leads to the best outcome

**Depth-Based Optimization**: The algorithm prefers faster wins and delays losses by adjusting scores based on recursion depth.

### Time Complexity

- **Worst case**: O(9!) - explores all possible game states
- **Average case**: Much faster due to early game termination and pruning

## Code Documentation

The entire codebase includes:
- **Doxygen-style comments** for comprehensive documentation
- **Function documentation** with parameter and return value descriptions
- **Class documentation** explaining purpose and design
- **Algorithm explanation** within the code

## Example Game Session

```
═══════════════════════════════════════════
   TIC TAC TOE GAME IN C++
═══════════════════════════════════════════

╔════════════════════════════════╗
║     TIC TAC TOE - MAIN MENU    ║
╚════════════════════════════════╝

1. Play New Game
2. Instructions
3. Exit

Select an option (1-3): 1

╔════════════════════════════════╗
║   Welcome to TIC TAC TOE!      ║
║   You are X, AI is O           ║
╚════════════════════════════════╝

     |     |     
  1  |  2  |  3  
-----------+-----------+-----------
  4  |  5  |  6  
-----------+-----------+-----------
  7  |  8  |  9  
     |     |     

Enter your move (1-9): 5

     |     |     
  1  |  2  |  3  
-----------+-----------+-----------
  4  |  X  |  6  
-----------+-----------+-----------
  7  |  8  |  9  
     |     |     

AI is thinking...

     |     |     
  1  |  O  |  3  
-----------+-----------+-----------
  4  |  X  |  6  
-----------+-----------+-----------
  7  |  8  |  9  
     |     |     

... (game continues)
```

## Possible Improvements

- Add difficulty levels (Easy, Medium, Hard)
- Implement alpha-beta pruning for faster computation
- Add GUI with graphical board
- Support two-player mode (no AI)
- Add game statistics and score tracking
- Implement opening book for faster AI moves
- Add undo/redo functionality

## System Requirements

- **OS**: Windows, macOS, Linux
- **C++ Standard**: C++11 or higher
- **Memory**: Minimal (less than 1 MB)
- **CPU**: Any modern processor

## License

This project is provided as-is for educational and recreational purposes.

## Author

Jorge

## Version

1.0 - Initial release

## Support & Troubleshooting

### Q: The AI seems slow on the first move
A: The first move computation explores many possibilities. This is normal and the AI settles on the center as optimal.

### Q: The program won't compile
A: Ensure you have:
- A C++11 compatible compiler
- CMake installed (if using CMake)
- All three source files (main.cpp, TicTacToe.h, TicTacToe.cpp) in the same directory

### Q: Can I beat the AI?
A: The AI is unbeatable when it goes first and should only be drawable when you go first and play optimally.

---

**Enjoy the game!**
