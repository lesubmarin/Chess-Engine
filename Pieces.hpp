#include <iostream>
#include <vector>

enum class Color { White, Black };

class Piece {
public:
    Piece(Color color) : color(color) {}
    virtual void move() = 0;
    virtual ~Piece() = default;
    virtual bool isValidMove(int fromX, int fromY, int toX, int toY) = 0;
    virtual Color getColor() {
        return color;
    }
protected:
    Color color;
};

class Pawn : public Piece {
public:
    Pawn(Color color) : Piece(color) {}
    void move() override {
        std::cout << (color == Color::White ? "White " : "Black ") << "Pawn moves forward" << std::endl;
    }

    bool isValidMove(int fromX, int fromY, int toX, int toY) override {
        if (color == Color::White) {
            if (fromX == 1) {
                if (toX == 2 || toX == 3) {
                    return true;
                }
            } else {
                if (toX == fromX + 1) {
                    return true;
                }
            }
        } else {
            if (fromX == 6) {
                if (toX == 5 || toX == 4) {
                    return true;
                }
            } else {
                if (toX == fromX - 1) {
                    return true;
                }
            }
        }
        return false;
    }

};

class Rook : public Piece {
public:
    Rook(Color color) : Piece(color) {}
    void move() override {
        std::cout << (color == Color::White ? "White " : "Black ") << "Rook moves horizontally or vertically" << std::endl;
    }

    bool isValidMove(int fromX, int fromY, int toX, int toY) override {
        return fromX == toX || fromY == toY;
    }

};

class Bishop : public Piece {
public:
    Bishop(Color color) : Piece(color) {}
    void move() override {
        std::cout << (color == Color::White ? "White " : "Black ") << "Bishop moves diagonally" << std::endl;
    }

    bool isValidMove(int fromX, int fromY, int toX, int toY) override {
        return abs(fromX - toX) == abs(fromY - toY);
    }

};

class Knight : public Piece {
public:
    Knight(Color color) : Piece(color) {}
    void move() override {
        std::cout << (color == Color::White ? "White " : "Black ") << "Knight moves in an L shape" << std::endl;
    }

    bool isValidMove(int fromX, int fromY, int toX, int toY) override {
        return (abs(fromX - toX) == 2 && abs(fromY - toY) == 1) || (abs(fromX - toX) == 1 && abs(fromY - toY) == 2);
    }

};

class Queen : public Piece {
public:
    Queen(Color color) : Piece(color) {}
    void move() override {
        std::cout << (color == Color::White ? "White " : "Black ") << "Queen moves horizontally, vertically, or diagonally" << std::endl;
    }

    bool isValidMove(int fromX, int fromY, int toX, int toY) override {
        return (fromX == toX || fromY == toY) || (abs(fromX - toX) == abs(fromY - toY));
    }

};

class King : public Piece {
public:
    King(Color color) : Piece(color) {}
    void move() override {
        std::cout << (color == Color::White ? "White " : "Black ") << "King moves one square in any direction" << std::endl;
    }

    bool isValidMove(int fromX, int fromY, int toX, int toY) override {
        return abs(fromX - toX) <= 1 && abs(fromY - toY) <= 1;
    }

};
