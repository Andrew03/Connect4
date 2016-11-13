#include "piece.h"

Piece::Piece(Color color) : m_color(color) {

}

auto Piece::getColor() const -> Piece::Color {
  return m_color;
}

Piece::~Piece() {

}
