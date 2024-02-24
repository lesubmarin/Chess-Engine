# Simple Chess Engine

This is a simple console-based chess engine implemented in C++. The engine provides basic functionality for representing a chessboard, making moves, and validating moves. It serves as a foundation upon which a complete chess game could be built.

## Features

- Representation of a chessboard.
- Piece movement validation.
- Ability to print the current state of the board.

## How to Use

1. Clone or download the repository to your local machine.
2. Compile the source code (`main.cpp` and `Board.hpp`) using a C++ compiler.
3. Run the compiled executable.
4. The engine will initialize a chessboard and print its initial state.
5. Modify the `main.cpp` file or create a new program to interact with the chess engine, implementing game logic, user input, and any additional features you desire.

## How to Compile

Compile the source code using a C++ compiler. For example, using g++:

```bash
g++ main.cpp -o chess_engine
```

This will create an executable file named `chess_engine` in the current directory.

## Usage
Run the compiled executable to initialize the chess engine:
    
    ```bash
    ./chess_engine
    ```

## To Do
- Make it a complete chess game with user input.
- Implement more advanced chess rules and features.
- Add support for castling, en passant, and pawn promotion.
