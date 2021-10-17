#include <map>

// 0 bit -> color (0 = black, 1 = white)
// 1 bit -> is Pawn
// 2 bit -> is Knight
// 3 bit -> is Bishop
// 4 bit -> is Rook
// 5 bit -> is Queen
// 6 bit -> is King
// 7 bit -> is Empty

enum Piece : unsigned char{
    EMPTY           = 0b00000001,
    BLACK_PIECE     = 0b00000000,
    BLACK_PAWN      = 0b01000000,
    BLACK_KNIGHT    = 0b00100000,
    BLACK_BISHOP    = 0b00010000,
    BLACK_ROOK      = 0b00001000,
    BLACK_QUEEN     = 0b00000100,
    BLACK_KING      = 0b00000010,
    WHITE_PIECE     = 0b10000000,
    WHITE_PAWN      = 0b11000000,
    WHITE_KNIGHT    = 0b10100000,
    WHITE_BISHOP    = 0b10010000,
    WHITE_ROOK      = 0b10001000,
    WHITE_QUEEN     = 0b10000100,
    WHITE_KING      = 0b10000010
};