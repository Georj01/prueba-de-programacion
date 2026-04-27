/**
 * CMakeLists.txt
 * Build configuration for the Tic Tac Toe game
 * 
 * Supports both console and graphical versions
 * 
 * Usage:
 *   mkdir build
 *   cd build
 *   cmake ..
 *   cmake --build .
 */

cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Common source files
set(COMMON_SOURCES
    src/TicTacToe.cpp
    src/TicTacToe.h
)

# Console version executable
set(CONSOLE_SOURCES
    src/main.cpp
    ${COMMON_SOURCES}
)

add_executable(TicTacToe ${CONSOLE_SOURCES})
set_target_properties(TicTacToe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Try to find SFML for graphical version
find_package(SFML 2.5 COMPONENTS graphics window system QUIET)

if(SFML_FOUND)
    # GUI version executable
    set(GUI_SOURCES
        src/main-gui.cpp
        src/GUI.cpp
        src/GUI.h
        ${COMMON_SOURCES}
    )
    
    add_executable(TicTacToe-GUI ${GUI_SOURCES})
    target_link_libraries(TicTacToe-GUI sfml-graphics sfml-window sfml-system)
    
    set_target_properties(TicTacToe-GUI PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
    
    message(STATUS "SFML found - Building both console and GUI versions")
else()
    message(STATUS "SFML not found - Building console version only")
    message(STATUS "To build GUI version, install SFML:")
    message(STATUS "  Windows: vcpkg install sfml")
    message(STATUS "  Linux: sudo apt-get install libsfml-dev")
    message(STATUS "  macOS: brew install sfml")
endif()

