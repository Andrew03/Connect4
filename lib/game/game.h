#ifndef LIB_GAME_H
#define LIB_GAME_H

#include "../board/board.h"
#include "../piece/piece.h"

class Game {
  public:
    Game();
    void makeMove(int col);
    void showBoard() const;
    bool isGameOver() const;
    auto getMove() const -> int;
    auto getWinner() const -> Piece::Color;
    virtual ~Game();

  private:
    Piece::Color m_player;
    Board *const m_board;
};
#endif
