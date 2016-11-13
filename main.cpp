#include <iostream>
#include "lib/game/game.h"

int main() {
  Game game;
  game.showBoard();
  while (!game.isGameOver()) {
    game.makeMove(game.getMove());
    game.showBoard();
  }
  std::cout << (game.getWinner() == Piece::Color::RED ? "Red" : "Blue") << " wins!" << std::endl;
  
  return 0;
}
