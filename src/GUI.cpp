/**
 * @file GUI.cpp
 * @brief Implementation of the graphical user interface for Tic Tac Toe
 * 
 * Uses SFML library for graphics rendering and event handling.
 */

#include "GUI.h"
#include <iostream>
#include <cmath>

/**
 * @brief Constructor - initializes the GUI window and colors
 * @param gameReference Reference to the TicTacToe game object
 */
TicTacToeGUI::TicTacToeGUI(TicTacToe& gameReference)
    : window(sf::VideoMode(static_cast<unsigned int>(WINDOW_WIDTH),
                           static_cast<unsigned int>(WINDOW_HEIGHT)), 
             "Tic Tac Toe - AI Game"),
      game(gameReference),
      fontLoaded(false),
      gameRunning(true),
      gameOver(false),
      gameResult(0),
      aiThinking(false),
      moveCounter(0) {
    
    window.setFramerateLimit(60);
    initializeColors();
    loadFont();
    
    // Initialize last board state
    lastBoardState.fill(std::array<int, 3>{});
}

/**
 * @brief Destructor - closes the window
 */
TicTacToeGUI::~TicTacToeGUI() {
    if (window.isOpen()) {
        window.close();
    }
}

/**
 * @brief Initializes color scheme
 */
void TicTacToeGUI::initializeColors() {
    backgroundColor = sf::Color(30, 30, 40);      // Dark blue-gray
    gridColor = sf::Color(100, 150, 200);         // Steel blue
    cellColor = sf::Color(50, 60, 80);            // Slightly lighter
    textColor = sf::Color(255, 255, 255);         // White
}

/**
 * @brief Attempts to load a font for text rendering
 * 
 * Buscamos la fuente en una carpeta local relativa al ejecutable.
 */
void TicTacToeGUI::loadFont() {
    // Buscamos la fuente en una carpeta local relativa al ejecutable
    if (font.loadFromFile("assets/font.ttf")) {
        fontLoaded = true;
        return;
    }
    
    // Si falla, avisamos por consola, pero aquí ya deberías 
    // plantearte si arrancar la app sin texto tiene sentido.
    std::cerr << "Error crítico de UX: No se encuentra 'assets/font.ttf'.\n";
    fontLoaded = false;
}

/**
 * @brief Draws the game board grid lines
 */
void TicTacToeGUI::drawBoard() {
    // Draw horizontal lines
    for (int i = 1; i < 3; i++) {
        sf::RectangleShape line(sf::Vector2f(BOARD_SIZE, LINE_THICKNESS));
        line.setPosition(BOARD_OFFSET_X, BOARD_OFFSET_Y + i * CELL_SIZE);
        line.setFillColor(gridColor);
        window.draw(line);
    }
    
    // Draw vertical lines
    for (int i = 1; i < 3; i++) {
        sf::RectangleShape line(sf::Vector2f(LINE_THICKNESS, BOARD_SIZE));
        line.setPosition(BOARD_OFFSET_X + i * CELL_SIZE, BOARD_OFFSET_Y);
        line.setFillColor(gridColor);
        window.draw(line);
    }
    
    // Draw board border
    sf::RectangleShape border(sf::Vector2f(BOARD_SIZE, BOARD_SIZE));
    border.setPosition(BOARD_OFFSET_X, BOARD_OFFSET_Y);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(gridColor);
    border.setOutlineThickness(3.0f);
    window.draw(border);
}

/**
 * @brief Draws all marks on the board
 */
void TicTacToeGUI::drawMarks() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int mark = game.getCell(row, col);
            if (mark == 1) {
                drawXMark(row, col);
            } else if (mark == 2) {
                drawOMark(row, col);
            }
        }
    }
}

/**
 * @brief Helper to draw marks - fetches actual marks from game
 * @param row Row index
 * @param col Column index
 * @param mark 1 for X, 2 for O
 */
void TicTacToeGUI::drawMark(int row, int col, int mark) {
    // This method is kept for compatibility but uses getCell internally
    mark = game.getCell(row, col);
    
    if (mark == 1) {
        drawXMark(row, col);
    } else if (mark == 2) {
        drawOMark(row, col);
    }
}

/**
 * @brief Draws an X mark at position
 * @param row Row index (0-2)
 * @param col Column index (0-2)
 */
void TicTacToeGUI::drawXMark(int row, int col) {
    float centerX = BOARD_OFFSET_X + col * CELL_SIZE + CELL_SIZE / 2;
    float centerY = BOARD_OFFSET_Y + row * CELL_SIZE + CELL_SIZE / 2;
    float offset = CELL_SIZE * 0.35f;
    
    // Draw X as two diagonal lines
    sf::RectangleShape line1(sf::Vector2f(offset * 2.828f, 5.0f));
    line1.setPosition(centerX - offset * 1.414f, centerY - offset);
    line1.setFillColor(sf::Color::Red);
    line1.setRotation(45.0f);
    window.draw(line1);
    
    sf::RectangleShape line2(sf::Vector2f(offset * 2.828f, 5.0f));
    line2.setPosition(centerX - offset * 1.414f, centerY + offset);
    line2.setFillColor(sf::Color::Red);
    line2.setRotation(-45.0f);
    window.draw(line2);
}

/**
 * @brief Draws an O mark at position
 * @param row Row index (0-2)
 * @param col Column index (0-2)
 */
void TicTacToeGUI::drawOMark(int row, int col) {
    float centerX = BOARD_OFFSET_X + col * CELL_SIZE + CELL_SIZE / 2;
    float centerY = BOARD_OFFSET_Y + row * CELL_SIZE + CELL_SIZE / 2;
    float radius = CELL_SIZE * 0.35f;
    
    sf::CircleShape circle(radius);
    circle.setPosition(centerX - radius, centerY - radius);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::Blue);
    circle.setOutlineThickness(5.0f);
    window.draw(circle);
}

/**
 * @brief Draws text on screen
 * @param text Text to display
 * @param x X position
 * @param y Y position
 * @param size Font size
 * @param color Text color
 * @param centerX Whether to center horizontally
 */
void TicTacToeGUI::drawText(const std::string& text, float x, float y,
                             unsigned int size, const sf::Color& color, bool centerX) {
    if (!fontLoaded) return;
    
    sf::Text sfText(text, font, size);
    sfText.setFillColor(color);
    
    if (centerX) {
        sfText.setPosition(x - sfText.getGlobalBounds().width / 2, y);
    } else {
        sfText.setPosition(x, y);
    }
    
    window.draw(sfText);
}

/**
 * @brief Draws the UI elements (title, status, instructions)
 */
void TicTacToeGUI::drawUI() {
    // Title
    drawText("TIC TAC TOE", WINDOW_WIDTH / 2, 20, 40, sf::Color::Yellow, true);
    
    // Status text
    if (gameOver) {
        if (gameResult == 1) {
            drawText("YOU WIN!", WINDOW_WIDTH / 2, 90, 30, sf::Color::Green, true);
        } else if (gameResult == 2) {
            drawText("AI WINS!", WINDOW_WIDTH / 2, 90, 30, sf::Color::Red, true);
        } else if (gameResult == 3) {
            drawText("IT'S A DRAW!", WINDOW_WIDTH / 2, 90, 30, sf::Color::Yellow, true);
        }
        drawText("Press SPACE for new game", WINDOW_WIDTH / 2, 120, 14, sf::Color::White, true);
    } else if (aiThinking) {
        drawText("AI is thinking...", WINDOW_WIDTH / 2, 90, 24, sf::Color::Cyan, true);
    } else {
        drawText("Your turn (Click to place X)", WINDOW_WIDTH / 2, 90, 16, sf::Color::Cyan, true);
    }
}

/**
 * @brief Draws the game over screen
 */
void TicTacToeGUI::drawGameOverScreen() {
    // Semi-transparent overlay
    sf::RectangleShape overlay(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    overlay.setFillColor(sf::Color(0, 0, 0, 100));
    window.draw(overlay);
    
    // Game over message
    std::string message;
    sf::Color messageColor;
    
    if (gameResult == 1) {
        message = "You Win!";
        messageColor = sf::Color::Green;
    } else if (gameResult == 2) {
        message = "AI Wins!";
        messageColor = sf::Color::Red;
    } else {
        message = "Draw!";
        messageColor = sf::Color::Yellow;
    }
    
    drawText(message, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 30, 48, messageColor, true);
    drawText("Press SPACE to play again", WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 40, 18, 
            sf::Color::White, true);
}

/**
 * @brief Converts mouse coordinates to board position
 * @param mouseX X coordinate
 * @param mouseY Y coordinate
 * @param row Output row (0-2 or -1)
 * @param col Output column (0-2 or -1)
 */
void TicTacToeGUI::getPositionFromMouse(float mouseX, float mouseY, int& row, int& col) {
    // Check if click is within board bounds
    if (mouseX < BOARD_OFFSET_X || mouseX > BOARD_OFFSET_X + BOARD_SIZE ||
        mouseY < BOARD_OFFSET_Y || mouseY > BOARD_OFFSET_Y + BOARD_SIZE) {
        row = -1;
        col = -1;
        return;
    }
    
    // Convert to grid coordinates
    col = static_cast<int>((mouseX - BOARD_OFFSET_X) / CELL_SIZE);
    row = static_cast<int>((mouseY - BOARD_OFFSET_Y) / CELL_SIZE);
    
    // Clamp to valid range
    if (row < 0 || row > 2) row = -1;
    if (col < 0 || col > 2) col = -1;
}

/**
 * @brief Handles mouse click events
 * @param mouseX X coordinate of click
 * @param mouseY Y coordinate of click
 */
void TicTacToeGUI::handleMouseClick(float mouseX, float mouseY) {
    if (gameOver || aiThinking) return;
    
    int row, col;
    getPositionFromMouse(mouseX, mouseY, row, col);
    
    if (row == -1 || col == -1) return;
    
    // Try to make move
    if (game.makeMove(row, col)) {
        gameResult = game.checkGameState();
        
        if (gameResult == 0) {
            // Game continues - AI's turn
            aiThinking = true;
        } else {
            // Game over
            gameOver = true;
        }
    }
}

/**
 * @brief Main game loop - handles rendering and events
 */
void TicTacToeGUI::run() {
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        handleMouseClick(static_cast<float>(event.mouseButton.x),
                                       static_cast<float>(event.mouseButton.y));
                    }
                    break;
                
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Space && gameOver) {
                        newGame();
                    }
                    break;
                
                default:
                    break;
            }
        }
        
        // AI move
        if (aiThinking) {
            game.makeAIMove();
            gameResult = game.checkGameState();
            
            if (gameResult != 0) {
                gameOver = true;
            }
            
            aiThinking = false;
        }
        
        // Render
        window.clear(backgroundColor);
        
        drawBoard();
        drawMarks();
        drawUI();
        
        if (gameOver) {
            drawGameOverScreen();
        }
        
        window.display();
    }
}

/**
 * @brief Checks if the window is still running
 * @return True if window is open
 */
bool TicTacToeGUI::isRunning() const {
    return window.isOpen();
}

/**
 * @brief Resets the game for a new round
 */
void TicTacToeGUI::newGame() {
    game.resetGame();
    gameRunning = true;
    gameOver = false;
    gameResult = 0;
    aiThinking = false;
    moveCounter = 0;
    lastBoardState.fill(std::array<int, 3>{});
}
