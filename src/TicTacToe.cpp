/**
 * @file TicTacToe.cpp
 * @brief Implementation of the Tic Tac Toe game class
 * 
 * This file contains the implementation of all game logic, board management,
 * and the minimax algorithm for AI decision making.
 */

#include "TicTacToe.h"

/**
 * @brief Constructor - initializes a new game board (3x3 filled with 0s)
 */
TicTacToe::TicTacToe() : humanPlayer(1), aiPlayer(2), currentPlayer(1) {
    board.assign(3, std::vector<int>(3, 0));
}

/**
 * @brief Displays the current game board in a user-friendly format
 * 
 * Board representation:
 * - Empty cells show position numbers (1-9)
 * - 'X' represents human player moves
 * - 'O' represents AI player moves
 */
void TicTacToe::displayBoard() const {
    std::cout << "\n";
    std::cout << "     |     |     \n";
    
    for (int i = 0; i < 3; i++) {
        std::cout << "  ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                std::cout << (i * 3 + j + 1);  // Show position numbers 1-9
            } else if (board[i][j] == humanPlayer) {
                std::cout << "X";
            } else {
                std::cout << "O";
            }
            
            if (j < 2) std::cout << "  |  ";
        }
        std::cout << "\n";
        
        if (i < 2) {
            std::cout << "-----------+-----------+-----------\n";
        }
    }
    
    std::cout << "     |     |     \n\n";
}

/**
 * @brief Attempts to place a mark at the specified position
 * @param row Row index (0-2)
 * @param col Column index (0-2)
 * @return True if move was successful, false if cell already occupied
 */
bool TicTacToe::makeMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    
    if (board[row][col] != 0) {
        return false;
    }
    
    board[row][col] = currentPlayer;
    currentPlayer = (currentPlayer == humanPlayer) ? aiPlayer : humanPlayer;
    return true;
}

/**
 * @brief Checks if a cell is empty
 * @param row Row index (0-2)
 * @param col Column index (0-2)
 * @return True if cell contains 0 (empty), false otherwise
 */
bool TicTacToe::isEmpty(int row, int col) const {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    return board[row][col] == 0;
}

/**
 * @brief Counts the total number of moves made so far
 * @return Number of non-empty cells on the board
 */
int TicTacToe::getMoveCount() const {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

/**
 * @brief Evaluates the board state and assigns a score
 * 
 * Scoring:
 * - +10: AI has won
 * - -10: Human has won
 * - 0: Game is a draw or still ongoing
 * 
 * @return The evaluated score
 */
int TicTacToe::evaluate() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == aiPlayer) return 10;
            else if (board[i][0] == humanPlayer) return -10;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == aiPlayer) return 10;
            else if (board[0][j] == humanPlayer) return -10;
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == aiPlayer) return 10;
        else if (board[0][0] == humanPlayer) return -10;
    }
    
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == aiPlayer) return 10;
        else if (board[0][2] == humanPlayer) return -10;
    }
    
    // No winner yet
    return 0;
}

/**
 * @brief Minimax algorithm for finding the optimal AI move
 * 
 * This recursive algorithm explores all possible game states and evaluates them.
 * It uses alpha-beta pruning concepts to find the best move for the AI.
 * 
 * @param depth Current recursion depth (used for move prioritization)
 * @param isMaximizing True when evaluating AI move (maximizing), false for human (minimizing)
 * @return The minimax score for this game state
 */
int TicTacToe::minimax(int depth, bool isMaximizing) {
    int score = evaluate();
    
    // Terminal states: AI wins, Human wins, or board full
    if (score == 10) return score - depth;  // Prefer quicker wins
    if (score == -10) return score + depth;  // Prefer slower losses
    if (getMoveCount() == 9) return 0;  // Draw
    
    if (isMaximizing) {
        // AI's turn - maximize score
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = aiPlayer;
                    int currentScore = minimax(depth + 1, false);
                    board[i][j] = 0;
                    bestScore = std::max(bestScore, currentScore);
                }
            }
        }
        return bestScore;
    } else {
        // Human's turn - minimize score
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = humanPlayer;
                    int currentScore = minimax(depth + 1, true);
                    board[i][j] = 0;
                    bestScore = std::min(bestScore, currentScore);
                }
            }
        }
        return bestScore;
    }
}

/**
 * @brief Makes the optimal AI move using the minimax algorithm
 * 
 * This function finds the best possible move for the AI player and executes it.
 * The board must have an even number of moves before calling this function.
 */
void TicTacToe::makeAIMove() {
    int bestScore = -1000;
    int bestRow = -1, bestCol = -1;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = aiPlayer;
                int score = minimax(0, false);
                board[i][j] = 0;
                
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    
    if (bestRow != -1 && bestCol != -1) {
        makeMove(bestRow, bestCol);
    }
}

/**
 * @brief Checks the current game state
 * 
 * Determines if the game is won, lost, or drawn.
 * 
 * @return 0 if game is ongoing
 *         1 if human player (X) has won
 *         2 if AI player (O) has won
 *         3 if the game is a draw
 */
int TicTacToe::checkGameState() {
    int score = evaluate();
    
    if (score == 10) return 2;  // AI wins
    if (score == -10) return 1;  // Human wins
    if (getMoveCount() == 9) return 3;  // Draw (board full)
    
    return 0;  // Game ongoing
}

/**
 * @brief Resets the game board for a new game
 * 
 * Clears all cells and resets the current player to human (1)
 */
void TicTacToe::resetGame() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
    currentPlayer = humanPlayer;
}

/**
 * @brief Gets the mark at a specific board position
 * @param row Row index (0-2)
 * @param col Column index (0-2)
 * @return 0 if empty, 1 if human player, 2 if AI player
 */
int TicTacToe::getCell(int row, int col) const {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return 0;
    }
    return board[row][col];
}
