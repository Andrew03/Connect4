#ifndef LIB_PIECE_H
#define LIB_PIECE_H

class Piece {
  public:
    enum class Color {
      RED,
      BLUE
    };
    Piece(Color color);
    auto getColor() const -> Color; 
    ~Piece();
  private:
    Color m_color;
};
#endif
