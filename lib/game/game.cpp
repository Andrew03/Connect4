#include "game.h"
#include <iostream>

Game::Game() : m_board(new Board()) {
  m_player = Piece::Color::RED;
}

void Game::makeMove(int col) {
  m_board->insertPiece(m_player, col);
  if (!isGameOver()) {
    m_player = (m_player == Piece::Color::RED ? Piece::Color::BLUE : Piece::Color::RED);
  }
}

auto Game::getMove() const -> int {
  std::cout << (m_player == Piece::Color::RED ? "Red" : "Blue") << " to move: ";
  int col;
  std::cin >> col;
  while (std::cin.fail() || col < 1 || col > 7) {
    std::cout << "Invalid column! Enter a number 1 through 7" << std::endl << std::endl;
    showBoard(); 
    std::cout << (m_player == Piece::Color::RED ? "Red" : "Blue") << " to move: ";
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cin >> col;
  }
  std::cout << std::endl; 
  return col - 1;
}

void Game::showBoard() const {
  // for some reason this will delete the pointer value
  //std::cout << *m_board << std::endl;
  m_board->printBoard();
}

bool Game::isGameOver() const {
  return m_board->isGameOver();
}

auto Game::getWinner() const -> Piece::Color {
  return m_player;
}

Game::~Game() {
  delete m_board;
}
