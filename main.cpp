#include <iostream>
#include "lib/board/board.h"
#include "lib/piece/piece.h"
#include "lib/game/game.h"

int main() {
  
  Game game;
  game.showBoard();
  while (!game.isGameOver()) {
    int col = game.getMove();
    game.makeMove(col);
    game.showBoard();
  }
  std::cout << (game.getWinner() == Piece::Color::RED ? "Red" : "Blue") << " wins!" << std::endl;
  
  return 0;
}
