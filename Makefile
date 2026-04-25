"""
Makefile for Tic Tac Toe Game
Supports compilation with g++ on Windows, macOS, and Linux

Usage:
  make              - Compiles the project
  make run          - Compiles and runs the game
  make clean        - Removes compiled files
  make help         - Shows this help message
"""

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
OUTPUT = TicTacToe

# Source files
SOURCES = main.cpp TicTacToe.cpp
HEADERS = TicTacToe.h
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
.PHONY: all run clean help

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(OBJECTS)
	@echo "Build successful! Executable: $(OUTPUT)"

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f $(OBJECTS) $(OUTPUT)
	@echo "Clean complete!"

help:
	@echo "Makefile targets:"
	@echo "  make          - Compile the project"
	@echo "  make run      - Compile and run the game"
	@echo "  make clean    - Remove compiled files"
	@echo "  make help     - Show this help message"
