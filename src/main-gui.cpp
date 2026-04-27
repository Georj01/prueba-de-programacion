/**
 * @file main-gui.cpp
 * @brief Main program for the graphical version of Tic Tac Toe
 * 
 * This file contains the entry point for the graphical Tic Tac Toe game
 * using SFML library for rendering and input handling.
 * 
 * @author Jorge
 * @version 1.0 Graphical Edition
 * @date 2026
 */

#include "TicTacToe.h"
#include "GUI.h"
#include <iostream>

/**
 * @brief Entry point of the graphical program
 * 
 * Creates a TicTacToe game instance and passes it to the GUI for rendering.
 * The GUI handles all user interaction, rendering, and event loops.
 * 
 * @return 0 on successful execution
 */
int main() {
    try {
        // Create the game logic object
        TicTacToe game;
        
        // Create and run the GUI
        TicTacToeGUI gui(game);
        gui.run();
        
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
