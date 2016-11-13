#include "board.h"
#include <iostream>

Board::Board() {
  for (auto &row : m_board) {
    for (auto &col : row) {
      col = nullptr;
    }
  }
}

bool Board::insertPiece(Piece::Color color, int col) {
  int index = NUM_ROWS - 1;
  if (m_board.at(index).at(col) != nullptr) {
    return false;
  } else {
    while (index > 0 && m_board.at(index - 1).at(col) == nullptr) {
      --index;
    }
    m_board.at(index).at(col) = new Piece(color);
    return true;
  }
}

bool Board::isGameOver() const {
  for (int i = 0; i < NUM_ROWS; ++i) {
    for (int j = 0; j < NUM_COLS; ++j) {
      if (m_board.at(i).at(j) == nullptr) {
        break;
      } else {
        if (m_board.at(i).at(j)->getColor() == Piece::Color::RED) {
          if (scan(Piece::Color::RED, i, j)) {
            return true;
          }
        } else { 
          if (scan(Piece::Color::BLUE, i, j)) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool Board::scan(Piece::Color color, int startRow, int startCol) const {
  return  scanRight(color, startRow, startCol) > 3 ||
          scanUp(color, startRow, startCol) > 3 || 
          scanUpRight(color, startRow, startCol) > 3 || 
          scanUpLeft(color, startRow, startCol) > 3;
}

auto Board::scanRight(Piece::Color color, int startRow, int startCol) const -> int {
  int numPieces = 1;
  while (startCol < NUM_COLS - 1) {
    if (m_board.at(startRow).at(startCol + 1) == nullptr || m_board.at(startRow).at(startCol + 1)->getColor() != color) {
      return numPieces;
    } else {
      ++numPieces;
      ++startCol;
    }
  }
  return numPieces;
}

auto Board::scanUp(Piece::Color color, int startRow, int startCol) const -> int {
  int numPieces = 1;
  while (startRow < NUM_ROWS - 1) {
    if (m_board.at(startRow + 1).at(startCol) == nullptr || m_board.at(startRow + 1).at(startCol)->getColor() != color) {
      return numPieces;
    } else {
      ++numPieces;
      ++startRow;
    }
  }
  return numPieces;
}

auto Board::scanUpRight(Piece::Color color, int startRow, int startCol) const -> int {
  int numPieces = 1;
  while (startRow < NUM_ROWS - 1 && startCol < NUM_COLS - 1) {
    if (m_board.at(startRow + 1).at(startCol + 1) == nullptr || m_board.at(startRow + 1).at(startCol + 1)->getColor() != color) {
      return numPieces;
    } else {
      ++numPieces;
      ++startRow;
      ++startCol;
    }
  }
  return numPieces;
}

auto Board::scanUpLeft(Piece::Color color, int startRow, int startCol) const -> int {
  int numPieces = 1;
  while (startRow < NUM_ROWS - 1 && startCol > 0) {
    if (m_board.at(startRow + 1).at(startCol - 1) == nullptr || m_board.at(startRow + 1).at(startCol - 1)->getColor() != color) {
      return numPieces;
    } else {
      ++numPieces;
      ++startRow;
      --startCol;
    }
  }
  return numPieces;
}

Board::~Board() {
  for (auto x : m_board) {
    for (auto y : x) {
      if (y != nullptr) {
        delete y;
      }
    }
  }
}

// seems to have an error here if you dereference it
std::ostream& operator<< (std::ostream &out, const Board board) {
  out << "  1   2   3   4   5   6   7 " << std::endl;
  out << "-----------------------------" << std::endl;
  for (int i = board.NUM_ROWS - 1; i > -1; --i) {
    for (int j = 0; j < board.NUM_COLS; ++j) {
      out << "| ";
      if (board.m_board.at(i).at(j) != nullptr) {
        if (board.m_board.at(i).at(j)->getColor() == Piece::Color::RED) {
          out << "R ";
        } else {
          out << "B ";
        } 
      } else {
        out << "  ";
      }
    }
    out << "|" << std::endl;
    out << "-----------------------------" << std::endl;
  }
  return out;
}

void Board::printBoard() {
  std::cout << "  1   2   3   4   5   6   7 " << std::endl;
  std::cout << "-----------------------------" << std::endl;
  for (int i = NUM_ROWS - 1; i > -1; --i) {
    for (int j = 0; j < NUM_COLS; ++j) {
      std::cout << "| ";
      if (m_board.at(i).at(j) != nullptr) {
        if (m_board.at(i).at(j)->getColor() == Piece::Color::RED) {
          std::cout << "R ";
        } else {
          std::cout << "B ";
        } 
      } else {
        std::cout << "  ";
      }
    }
    std::cout << "|" << std::endl;
    std::cout << "-----------------------------" << std::endl;
  }
}
