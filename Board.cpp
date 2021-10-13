#include "Board.h"
#include <iostream>
#include <bitset>
#include "Pieces.h"


unsigned char standardStartBoard[64] = {
    Piece::BLACK_ROOK, Piece::BLACK_KNIGHT, Piece::BLACK_BISHOP, Piece::BLACK_QUEEN, Piece::BLACK_KING, Piece::BLACK_BISHOP, Piece::BLACK_KNIGHT, Piece::BLACK_ROOK,
    Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN, Piece::BLACK_PAWN,
    Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY,
    Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY,
    Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY,
    Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY,
    Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, Piece::WHITE_PAWN, 
    Piece::WHITE_ROOK, Piece::WHITE_KNIGHT, Piece:: WHITE_BISHOP, Piece::WHITE_QUEEN, Piece::WHITE_KING, Piece::WHITE_BISHOP, Piece::WHITE_KNIGHT, Piece::WHITE_ROOK

};



Board::Board(){
    InitBoard();
}

// Set field to standardStartBoard
void Board::InitBoard(){
    for(int i = 0; i < 64; i++){
        fields[i] = standardStartBoard[i];
    }
}



void Board::SetField(int row, int col, unsigned char* pieceData){
    SetField(row * 8 + col, pieceData);
}

void Board::SetField(int index, char unsigned* pieceData){
    fields[index] = *pieceData;
}

void Board::LogFieldBits(int row, int col){
    char bits = fields[row * 8 + col];
    std::cout << std::bitset<8>(bits) << std::endl;
}