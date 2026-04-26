# Contributing to Tic Tac Toe Game

Thank you for your interest in contributing! Contributions are very welcome.

## How to Contribute

### Report Bugs

If you find a bug, please create an **Issue** describing:
- What you did
- What happened
- What you expected to happen
- Your operating system and C++ version

### Suggest Improvements

Have an idea to improve the project? Open an **Issue** with the `enhancement` label explaining:
- The proposed improvement
- Why it would be useful
- Examples of how it would work

### Create a Pull Request

1. **Fork** the repository
2. **Create a branch** for your feature:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. **Make your changes** and write clean code
4. **Test your code**:
   ```bash
   g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
   ./TicTacToe
   ```
5. **Make commits** with clear messages:
   ```bash
   git commit -m "Add: description of what you added"
   git commit -m "Fix: description of the bug you fixed"
   ```
6. **Push** to your fork:
   ```bash
   git push origin feature/your-feature-name
   ```
7. **Open a Pull Request** describing what changes you made

## Style Guides

### C++ Code
- Use **camelCase** for variables and functions: `getWinner()`
- Use **PascalCase** for classes: `TicTacToe`
- Comment complex code
- Keep lines under 80 characters
- Use spaces (2 or 4) for indentation, NOT tabs

### Commits
- Messages in English
- First line: maximum 50 characters
- If necessary, add description after a blank line
- Examples:
  - `Add minimax optimization for AI`
  - `Fix: incorrect winner detection on diagonal`
  - `Refactor: simplify board evaluation logic`

### Documentation
- Comment public functions with Doxygen style
- Keep README.md updated
- Document important changes in ALGORITHM_DOCUMENTATION.md

## Contribution Areas

### Easy (for beginners)
- Improve documentation
- Add code comments
- Fix typos
- Improve error messages

### Intermediate
- Add improved input validation
- Optimize minimax algorithm
- Add more AI comments
- Improve user interface

### Advanced
- Implement difficulty levels (Easy, Medium, Hard)
- Alpha-beta pruning
- Enhanced GUI
- Unit tests

## Review Process

1. A maintainer will review your PR
2. There might be change requests
3. Once approved, it will be merged
4. Your contribution will be in the project!

## Code of Conduct

- Be respectful to other contributors
- No spam
- Focus on content, not people
- Help others learn

## Questions or Doubts

If you have questions, open a **Discussion** or an **Issue** with the `question` label.

---

Thank you for contributing! 🎉
