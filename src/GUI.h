/**
 * @file GUI.h
 * @brief Header file for the graphical user interface of Tic Tac Toe
 * 
 * This file contains the declaration of the TicTacToeGUI class which handles
 * all graphical rendering and mouse input using SFML library.
 */

#ifndef GUI_H
#define GUI_H

#include "TicTacToe.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <array>

/**
 * @class TicTacToeGUI
 * @brief Graphical User Interface for the Tic Tac Toe game
 * 
 * Handles rendering, user input, and game state visualization using SFML.
 */
class TicTacToeGUI {
private:
    // Window and rendering
    sf::RenderWindow window;           ///< SFML render window
    sf::Color backgroundColor;         ///< Background color
    sf::Color gridColor;              ///< Grid line color
    sf::Color cellColor;              ///< Cell background color
    sf::Color textColor;              ///< Text color
    
    // Game references
    TicTacToe& game;                  ///< Reference to the game logic
    
    // Board dimensions
    static constexpr float WINDOW_WIDTH = 600.0f;   ///< Window width in pixels
    static constexpr float WINDOW_HEIGHT = 700.0f;  ///< Window height in pixels
    static constexpr float BOARD_SIZE = 450.0f;     ///< Size of game board
    static constexpr float BOARD_OFFSET_X = 75.0f;  ///< X position of board
    static constexpr float BOARD_OFFSET_Y = 150.0f; ///< Y position of board
    static constexpr float CELL_SIZE = 150.0f;      ///< Size of each cell
    static constexpr float LINE_THICKNESS = 3.0f;   ///< Grid line thickness
    
    // Fonts and text
    sf::Font font;                    ///< Font for rendering text
    bool fontLoaded;                  ///< Whether font was successfully loaded
    
    // Game state
    bool gameRunning;                 ///< Whether a game is in progress
    bool gameOver;                    ///< Whether the game has ended
    int gameResult;                   ///< 0: ongoing, 1: human wins, 2: AI wins, 3: draw
    bool aiThinking;                  ///< Whether AI is computing its move
    int moveCounter;                  ///< Counter for smooth animations
    
    // Cell states for animation
    std::array<std::array<int, 3>, 3> lastBoardState;  ///< Previous board state for change detection

    /**
     * @brief Initializes the colors and styles
     */
    void initializeColors();

    /**
     * @brief Loads the font for text rendering
     */
    void loadFont();

    /**
     * @brief Draws the game board grid
     */
    void drawBoard();

    /**
     * @brief Draws all marks (X and O) on the board
     */
    void drawMarks();

    /**
     * @brief Draws a single mark at a board position
     * @param row Row index (0-2)
     * @param col Column index (0-2)
     * @param mark 1 for X, 2 for O
     */
    void drawMark(int row, int col, int mark);

    /**
     * @brief Draws the title and current status
     */
    void drawUI();

    /**
     * @brief Draws the game over screen with result
     */
    void drawGameOverScreen();

    /**
     * @brief Converts mouse coordinates to board position
     * @param mouseX X coordinate of mouse
     * @param mouseY Y coordinate of mouse
     * @param row Output: row index (0-2) or -1 if outside board
     * @param col Output: column index (0-2) or -1 if outside board
     */
    void getPositionFromMouse(float mouseX, float mouseY, int& row, int& col);

    /**
     * @brief Handles mouse click events
     * @param mouseX X coordinate of click
     * @param mouseY Y coordinate of click
     */
    void handleMouseClick(float mouseX, float mouseY);

    /**
     * @brief Draws a text element
     * @param text Text to display
     * @param x X position
     * @param y Y position
     * @param size Font size
     * @param color Text color
     * @param centerX Whether to center horizontally
     */
    void drawText(const std::string& text, float x, float y, unsigned int size,
                  const sf::Color& color, bool centerX = false);

    /**
     * @brief Draws an X mark at the specified position
     * @param row Row index (0-2)
     * @param col Column index (0-2)
     */
    void drawXMark(int row, int col);

    /**
     * @brief Draws an O mark at the specified position
     * @param row Row index (0-2)
     * @param col Column index (0-2)
     */
    void drawOMark(int row, int col);

public:
    /**
     * @brief Constructor - initializes the GUI
     * @param gameReference Reference to the TicTacToe game object
     */
    explicit TicTacToeGUI(TicTacToe& gameReference);

    /**
     * @brief Destructor - closes the window
     */
    ~TicTacToeGUI();

    /**
     * @brief Main game loop
     * 
     * Handles rendering, events, and game logic until the window is closed
     */
    void run();

    /**
     * @brief Checks if the window is open
     * @return True if window is open and running
     */
    bool isRunning() const;

    /**
     * @brief Resets the GUI for a new game
     */
    void newGame();
};

#endif // GUI_H
