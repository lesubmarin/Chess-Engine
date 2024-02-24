#ifndef BOARD_HPP
#define BOARD_HPP

#include "Pieces.hpp"

class Board {
public:
    Board() : pieces(8, std::vector<Piece*>(8, nullptr)) {
        // Initialize the board with pieces
        initializePieces();
    }

    ~Board() {
        // Clean up dynamically allocated memory
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                delete pieces[i][j];
            }
        }
    }

    void movePiece(int fromX, int fromY, int toX, int toY) {
        if (isValidMove(fromX, fromY, toX, toY)) {
            pieces[toX][toY] = pieces[fromX][fromY];
            pieces[fromX][fromY] = nullptr; // Reset the original position
            std::cout << "Moved piece from (" << fromX << ", " << fromY << ") to (" << toX << ", " << toY << ")." << std::endl;
        } else {
            std::cout << "Invalid move!" << std::endl;
        }
    }

    void printBoard() const {
        std::cout << "  a b c d e f g h" << std::endl;
        std::cout << " +-----------------" << std::endl;
        for (int i = 0; i < 8; ++i) {
            std::cout << 8 - i << "|";
            for (int j = 0; j < 8; ++j) {
                if (pieces[i][j]) {
                    if (pieces[i][j]->getColor() == Color::White)
                        std::cout << "w ";
                    else
                        std::cout << "b ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << " +-----------------" << std::endl;
    }

    bool isValidMove(int fromX, int fromY, int toX, int toY) const {
        // Retrieve the piece at the source position
        Piece* piece = pieces[fromX][fromY];

        // Check if there is a piece at the source position
        if (!piece) {
            return false;
        }

        // Check if the move is valid for the piece
        return piece->isValidMove(fromX, fromY, toX, toY);
    }

private:
    std::vector<std::vector<Piece*>> pieces;

    void initializePieces() {
        // Initialize the board with pieces
        // Place pawns on initial positions
        for (int i = 0; i < 8; ++i) {
            pieces[1][i] = new Pawn(Color::White);
            pieces[6][i] = new Pawn(Color::Black);
        }

        // Place rooks on initial positions
        pieces[0][0] = new Rook(Color::White);
        pieces[0][7] = new Rook(Color::White);

        pieces[7][0] = new Rook(Color::Black);
        pieces[7][7] = new Rook(Color::Black);

        // Place knights on initial positions
        pieces[0][1] = new Knight(Color::White);
        pieces[0][6] = new Knight(Color::White);

        pieces[7][1] = new Knight(Color::Black);
        pieces[7][6] = new Knight(Color::Black);

        // Place bishops on initial positions
        pieces[0][2] = new Bishop(Color::White);
        pieces[0][5] = new Bishop(Color::White);

        pieces[7][2] = new Bishop(Color::Black);
        pieces[7][5] = new Bishop(Color::Black);

        // Place queens on initial positions
        pieces[0][3] = new Queen(Color::White);
        pieces[7][3] = new Queen(Color::Black);

        // Place kings on initial positions
        pieces[0][4] = new King(Color::White);
        pieces[7][4] = new King(Color::Black);
    }


bool isEnPassantMove(int fromX, int fromY, int toX, int toY) const {
    // Check if the move is an en passant move
    Piece* piece = pieces[fromX][fromY];

    // Ensure that the piece is a pawn
    Pawn* pawn = dynamic_cast<Pawn*>(piece);
    if (!pawn) {
        return false;
    }

    // Check if the move is a diagonal move
    if (abs(fromY - toY) != 1) {
        return false;
    }

    // Check if the target square is empty
    if (!pieces[toX][toY]) {
        // Assuming en passant is only possible immediately after a pawn moves two squares forward
        // Here, you need to implement logic to track the last move.
        // For simplicity, I'll assume en passant is always possible.
        return true;
    }

    return false;
}

bool areKingsAdjacent() const {
    // Find the positions of both kings
    std::pair<int, int> whiteKingPos, blackKingPos;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = pieces[i][j];
            if (piece) {
                if (dynamic_cast<King*>(piece)) {
                    if (piece->getColor() == Color::White) {
                        whiteKingPos = {i, j};
                    } else {
                        blackKingPos = {i, j};
                    }
                }
            }
        }
    }

    // Check if kings are adjacent
    return abs(whiteKingPos.first - blackKingPos.first) <= 1 && abs(whiteKingPos.second - blackKingPos.second) <= 1;
}

bool isKingInCheck(Color color) const {
    // Find the position of the king of the given color
    std::pair<int, int> kingPos;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece* piece = pieces[i][j];
            if (piece) {
                if (dynamic_cast<King*>(piece) && piece->getColor() == color) {
                    kingPos = {i, j};
                    break;
                }
            }
        }
    }

    // Check if the king is under attack by any opponent's pieces
    // Here, you need to implement the logic to check if a king is under attack by opponent's pieces
    // This involves iterating through all opponent's pieces and checking if any can attack the king's position
    // For simplicity, I'll return false as a placeholder
    return false;
}


};

#endif // BOARD_HPP