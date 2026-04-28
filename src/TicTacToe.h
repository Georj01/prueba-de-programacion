/**
 * @file TicTacToe.h
 * @brief Header file for the Tic Tac Toe game implementation
 * 
 * This file contains the declaration of the TicTacToe class which handles
 * all game logic including board management, move validation, and game state.
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <iostream>

/**
 * @class TicTacToe
 * @brief Main class for managing the Tic Tac Toe game
 * 
 * This class handles the game board, player moves, AI moves, and game logic.
 * The board is represented as a 3x3 grid with values:
 * - 0: Empty cell
 * - 1: Human player (X)
 * - 2: AI player (O)
 */
class TicTacToe {
private:
    std::vector<std::vector<int>> board;  ///< 3x3 game board
    int humanPlayer;                      ///< Value representing human player (1)
    int aiPlayer;                         ///< Value representing AI player (2)
    int currentPlayer;                    ///< Current turn (1 or 2)
    int humanWins;                        ///< Number of human wins
    int aiWins;                           ///< Number of AI wins
    int draws;                            ///< Number of draws

    /**
     * @brief Evaluates the current board state
     * @return Score: 10 if AI wins, -10 if human wins, 0 if draw/ongoing
     */
    int evaluate();

    /**
     * @brief Minimax algorithm with alpha-beta pruning
     * @param depth Current search depth in the game tree
     * @param isMaximizing True if maximizing player's turn, false for minimizing
     * @param alpha Best already explored option along path to the root for maximizer
     * @param beta Best already explored option along path to the root for minimizer
     * @return Best score for the current position
     */
    int minimax(int depth, bool isMaximizing, int alpha = -1000, int beta = 1000);

public:
    /**
     * @brief Constructor - initializes the game board
     * @param humanIsX True if human plays as X (goes first), false if human plays as O
     */
    TicTacToe(bool humanIsX = true);

    /**
     * @brief Displays the current state of the board
     */
    void displayBoard() const;

    /**
     * @brief Makes a move at the specified position
     * @param row Row index (0-2)
     * @param col Column index (0-2)
     * @return True if move is valid, false otherwise
     */
    bool makeMove(int row, int col);

    /**
     * @brief Generates and makes the optimal AI move
     */
    void makeAIMove();

    /**
     * @brief Checks if the game has ended
     * @return 0 if ongoing, 1 if human won, 2 if AI won, 3 if draw
     */
    int checkGameState();

    /**
     * @brief Checks if a cell is empty
     * @param row Row index
     * @param col Column index
     * @return True if cell is empty, false otherwise
     */
    bool isEmpty(int row, int col) const;

    /**
     * @brief Gets the total number of moves made
     * @return Number of non-empty cells on the board
     */
    int getMoveCount() const;

    /**
     * @brief Resets the game board for a new game
     * @param humanIsX True if human plays as X (goes first), false if human plays as O
     */
    void resetGame(bool humanIsX = true);

    /**
     * @brief Gets the mark at a specific board position
     * @param row Row index (0-2)
     * @param col Column index (0-2)
     * @return 0 if empty, 1 if human player, 2 if AI player
     */
    int getCell(int row, int col) const;

    /**
     * @brief Gets the number of human wins
     */
    int getHumanWins() const;

    /**
     * @brief Gets the number of AI wins
     */
    int getAIWins() const;

    /**
     * @brief Gets the number of draws
     */
    int getDraws() const;

    /**
     * @brief Records the result of a finished game
     * @param result 1 for human win, 2 for AI win, 3 for draw
     */
    void recordResult(int result);
};

#endif // TICTACTOE_H
