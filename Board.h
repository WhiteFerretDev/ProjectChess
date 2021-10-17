
#include <iostream>

extern unsigned char standardStartBoard[];

class Board{
    private:
        

        void InitBoard();

    public:
        // storing the data of the curretn piece for each of the 64 fields 
        // starting top left (black side), first rows then colls
        // bit 0-3 -> piece 
        // bit 4   -> is field empty
        unsigned char fields[64];
        
        Board();
        void SetField(int row, int col, unsigned char* fieldData);
        void SetField(int index, unsigned char* fieldData);
        void LogFieldBits(int row, int col);
};