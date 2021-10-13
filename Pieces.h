#include <map>

// 0 bit -> color (0 = black, 1 = white)
// 1-3 bit -> piece (000 = undef, 100 = pawn, 010 = knight, 110 = bishop, 001 = rook, 101 = queen, 011 = king)
enum Piece : unsigned char{
    EMPTY           = 0b00000000,
    BLACK_PAWN      = 0b01000000,
    BLACK_KNIGHT    = 0b00100000,
    BLACK_BISHOP    = 0b01100000,
    BLACK_ROOK      = 0b00010000,
    BLACK_QUEEN     = 0b01010000,
    BLACK_KING      = 0b00110000,
    WHITE_PAWN      = 0b11000000,
    WHITE_KNIGHT    = 0b10100000,
    WHITE_BISHOP    = 0b11100000,
    WHITE_ROOK      = 0b10010000,
    WHITE_QUEEN     = 0b11010000,
    WHITE_KING      = 0b10110000
};