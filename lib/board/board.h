#ifndef LIB_BOARD_H
#define LIB_BOARD_H

//#include "../piece/piece.h"
#include <array>
#include <ostream>

struct Piece {
  enum class Color {
    RED,
    BLUE
  } color;
};

class Board {
  public:
    enum class Direction {
      RIGHT,
      UP,
      UP_RIGHT,
      UP_LEFT
    };
    Board();
    bool insertPiece(Piece::Color color, int col);
    bool isGameOver() const;
    void printBoard();
    friend std::ostream& operator<< (std::ostream &out, const Board board);
    Piece::Color findWinner();
    ~Board();

  private:
    bool scan(Piece::Color color, int startRow, int startCol) const;
    auto scan(Piece::Color color, int startRow, int startCol, Board::Direction dir) const -> int;
    auto scanRight(Piece::Color color, int startRow, int startCol) const -> int;
    auto scanUp(Piece::Color color, int startRow, int startCol) const -> int;
    auto scanUpRight(Piece::Color color, int startRow, int startCol) const -> int;
    auto scanUpLeft(Piece::Color color, int startRow, int startCol) const -> int;
    auto scan(Piece::Color color, int startRow, int startCol, int direction) const -> int;
    std::array<std::array<Piece*, 7>, 7> m_board;
    const int NUM_ROWS = 7;
    const int NUM_COLS = 7;
};
#endif
