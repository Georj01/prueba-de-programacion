/**
 * ALGORITHM_DOCUMENTATION.md
 * Technical documentation of the Minimax algorithm and game logic
 */

# Minimax Algorithm Documentation

## Overview

The Minimax algorithm is a decision-making algorithm used in game theory to determine the best move for a player, assuming the opponent also plays optimally.

## How It Works

### 1. Game Tree Exploration

The algorithm creates a tree of all possible game states by:
- Generating all possible moves from the current position
- Recursively exploring each move to create child nodes
- Continuing until reaching terminal states (game over)

### 2. Terminal State Evaluation

Each leaf node (game ending) is assigned a score:
- **+10**: AI (maximizing player) wins
- **-10**: Human (minimizing player) wins
- **0**: Draw (board full, no winner)

### 3. Recursive Scoring

Moving up the tree, scores are propagated:
- **Maximizing nodes** (AI's turn): Select the highest child score
- **Minimizing nodes** (human's turn): Select the lowest child score

### 4. Best Move Selection

The algorithm returns the move leading to the highest score under optimal play.

## Implementation in This Project

```cpp
int minimax(int depth, bool isMaximizing) {
    // Evaluate terminal states
    int score = evaluate();
    if (score == 10) return score - depth;   // AI wins
    if (score == -10) return score + depth;  // Human wins
    if (isBoardFull()) return 0;             // Draw

    if (isMaximizing) {
        // AI's turn - find maximum score
        int bestScore = -1000;
        for (each empty cell) {
            place AI mark
            int score = minimax(depth + 1, false);
            remove AI mark
            bestScore = max(bestScore, score);
        }
        return bestScore;
    } else {
        // Human's turn - find minimum score
        int bestScore = 1000;
        for (each empty cell) {
            place human mark
            int score = minimax(depth + 1, true);
            remove human mark
            bestScore = min(bestScore, score);
        }
        return bestScore;
    }
}
```

## Depth-Based Optimization

The algorithm includes a depth-based adjustment:
- **Winning moves**: Prefer faster wins by subtracting depth (score - depth)
- **Losing moves**: Delay losses by adding depth (score + depth)

This encourages the AI to:
1. Win in fewer moves
2. Lose in more moves (delay inevitable defeat)

## Time Complexity Analysis

### Worst Case: O(9!)
- Evaluates all possible game progressions
- Early game requires exploring maximum possibilities

### Average Case: Much faster
- Games terminate early with winners
- Fewer moves available as board fills

### Example: First Move AI
- Explores ~9 × 8 × 7 × ... × 1 = 362,880 positions
- Reduces significantly with memoization or alpha-beta pruning

## Space Complexity

- **O(d)** where d is maximum recursion depth (9 for Tic Tac Toe)
- Recursive call stack depth limited by game tree

## Example Game Tree (Simplified)

```
                    Initial Position
                   /                \
              AI plays 1        AI plays 2
             /      |      \    /      |      \
        Human1  Human2  ...  Human1  Human2  ...
         / | \    / | \        / | \    / | \
        ...                    ...

Scores bubble up:
- At leaves: +10, -10, or 0
- At internal nodes: max (AI) or min (human)
- Final selection: Move with best score
```

## Why Minimax Works for Tic Tac Toe

1. **Perfect Information**: Both players see the entire board
2. **Deterministic**: No randomness or luck
3. **Finite Game**: Always terminates (max 9 moves)
4. **Small State Space**: Only 3^9 = 19,683 possible positions

## Optimizations (Future Improvements)

### 1. Alpha-Beta Pruning
Eliminates branches that cannot affect the final decision:
```cpp
if (score >= beta) return;  // Beta cutoff
if (score > alpha) alpha = score;  // Update alpha
```

### 2. Transposition Table
Cache evaluated positions to avoid recomputation:
```cpp
if (position in cache) return cached_score;
```

### 3. Move Ordering
Evaluate promising moves first to increase pruning:
- Center moves first
- Moves near existing pieces

### 4. Iterative Deepening
Search to increasing depths with time limits

## Comparison with Other AI Algorithms

| Algorithm | Tic Tac Toe | Chess | Go |
|-----------|-----------|-------|-----|
| Minimax | ✓ Feasible | ✗ Too slow | ✗ Impractical |
| Alpha-Beta | ✓ Fast | ✓ Common | ✗ Still limited |
| Monte Carlo Tree Search | ○ Possible | ✓ Fast | ✓ Good |
| Neural Networks | ○ Overkill | ✓ Strong | ✓ Very strong |

## Mathematical Foundation

### Minimax Theorem
For two-player, zero-sum games with perfect information:
- The first player can either win or force a draw
- An optimal strategy exists for both players

### Game Value
Every position has a "game value":
- Positive: First player advantage
- Negative: Second player advantage
- Zero: Draw with optimal play

## Practical Notes

### Move Ordering for AI
In this implementation:
1. **Center positions**: Preferred strategically
2. **Corner positions**: Good for control
3. **Edge positions**: Secondary choice

### Decision-Making
The AI evaluates all legal moves and selects:
- **Winning move** if available
- **Blocking move** if opponent can win
- **Optimal strategic move** otherwise

## Testing the Algorithm

### Test Cases
1. Can AI win: Place AI 2 in a row, verify it completes
2. Does AI block: Place human 2 in a row, verify it blocks
3. Can human force draw: Verify best human play results in draw
4. First move AI: Verify AI plays center or corner

### Performance Metrics
- First move: ~100-500ms (exploring ~362,880 positions)
- Mid-game: ~10-100ms
- Late-game: <10ms

## References

- Shannon, C. E. (1950). "Programming a Computer for Playing Chess"
- Neumann, J. v., & Morgenstern, O. (1944). "Theory of Games"
- Korf, R. E. (1985). "Depth-First Iterative-Deepening"

---

This documentation provides the mathematical and algorithmic foundation for understanding
the AI's decision-making process in the Tic Tac Toe game.
