
#include <iostream>

extern unsigned char standardStartBoard[];

class Board{
    private:
        // storing the data of the curretn piece for each of the 64 fields 
        // starting top left (black side), first rows then colls
        // bit 0-3 -> piece 
        // bit 4   -> is field empty
        unsigned char fields[64];

        void InitBoard();

    public:
        Board();
        void SetField(int row, int col, unsigned char* fieldData);
        void SetField(int index, unsigned char* fieldData);
        void SetBoard(unsigned char* board[]);
        void LogFieldBits(int row, int col);
};