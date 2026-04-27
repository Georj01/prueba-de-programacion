/**
 * @file main.cpp
 * @brief Main program for the Tic Tac Toe game
 * 
 * This file contains the game loop and user interface for playing Tic Tac Toe
 * against an unbeatable AI using the minimax algorithm.
 * 
 * @author Jorge
 * @version 1.0
 * @date 2026
 */

#include "TicTacToe.h"
#include <iostream>
#include <string>

/**
 * @brief Displays the main menu
 */
void displayMenu() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════╗\n";
    std::cout << "║     TIC TAC TOE - MAIN MENU    ║\n";
    std::cout << "╚════════════════════════════════╝\n";
    std::cout << "\n";
    std::cout << "1. Play New Game\n";
    std::cout << "2. Instructions\n";
    std::cout << "3. Exit\n";
    std::cout << "\nSelect an option (1-3): ";
}

/**
 * @brief Displays game instructions
 */
void displayInstructions() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    GAME INSTRUCTIONS                           ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════╝\n";
    std::cout << "\nHow to Play:\n";
    std::cout << "1. You play as 'X', the AI plays as 'O'\n";
    std::cout << "2. The board positions are numbered 1-9 as follows:\n";
    std::cout << "   1 | 2 | 3\n";
    std::cout << "   ---------\n";
    std::cout << "   4 | 5 | 6\n";
    std::cout << "   ---------\n";
    std::cout << "   7 | 8 | 9\n";
    std::cout << "\n3. Enter a number (1-9) to place your mark\n";
    std::cout << "4. Get three marks in a row (horizontal, vertical, or diagonal) to win\n";
    std::cout << "5. The AI plays optimally and is unbeatable (best outcome is a draw)\n";
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::getline(std::cin, std::string());
}

/**
 * @brief Gets and validates human player input
 * @param game Reference to the TicTacToe game object
 * @return True if input was valid and move was made, false otherwise
 */
bool getPlayerInput(TicTacToe& game) {
    int position;
    
    std::cout << "Enter your move (1-9): ";
    
    if (!(std::cin >> position)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input! Please enter a number between 1-9.\n";
        return false;
    }
    
    if (position < 1 || position > 9) {
        std::cout << "Invalid position! Please enter a number between 1-9.\n";
        return false;
    }
    
    // Convert position (1-9) to row and column (0-2)
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    
    if (!game.makeMove(row, col)) {
        std::cout << "That cell is already occupied! Try another position.\n";
        return false;
    }
    
    return true;
}

/**
 * @brief Main game loop - handles game flow and user interaction
 */
void playGame() {
    TicTacToe game;
    int gameState = 0;  // 0: ongoing, 1: human wins, 2: AI wins, 3: draw
    
    std::cout << "\n";
    std::cout << "╔════════════════════════════════╗\n";
    std::cout << "║   Welcome to TIC TAC TOE!      ║\n";
    std::cout << "║   You are X, AI is O           ║\n";
    std::cout << "╚════════════════════════════════╝\n";
    
    // Main game loop
    while (gameState == 0) {
        game.displayBoard();
        
        // Human player move
        bool validMove = false;
        while (!validMove) {
            validMove = getPlayerInput(game);
        }
        
        gameState = game.checkGameState();
        if (gameState != 0) break;
        
        // AI player move
        std::cout << "\nAI is thinking...\n";
        game.makeAIMove();
        
        gameState = game.checkGameState();
    }
    
    // Display final board
    game.displayBoard();
    
    // Display result
    std::cout << "╔════════════════════════════════╗\n";
    if (gameState == 1) {
        std::cout << "║      YOU WIN! Congratulations! ║\n";
    } else if (gameState == 2) {
        std::cout << "║        AI WINS! Better luck     ║\n";
        std::cout << "║         next time!             ║\n";
    } else if (gameState == 3) {
        std::cout << "║         IT'S A DRAW!           ║\n";
        std::cout << "║    Well played!                ║\n";
    }
    std::cout << "╚════════════════════════════════╝\n";
}

/**
 * @brief Entry point of the program
 * 
 * Displays menu, handles user selection, and manages program flow.
 * 
 * @return 0 on successful execution
 */
int main() {
    int choice = 0;
    bool running = true;
    
    std::cout << "\n" << std::string(40, '=') << "\n";
    std::cout << "   TIC TAC TOE GAME IN C++\n";
    std::cout << std::string(40, '=') << "\n";
    
    while (running) {
        displayMenu();
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please try again.\n";
            continue;
        }
        
        switch (choice) {
            case 1:
                playGame();
                break;
            
            case 2:
                displayInstructions();
                break;
            
            case 3:
                std::cout << "\nThank you for playing! Goodbye!\n\n";
                running = false;
                break;
            
            default:
                std::cout << "\nInvalid option! Please select 1, 2, or 3.\n";
        }
    }
    
    return 0;
}
