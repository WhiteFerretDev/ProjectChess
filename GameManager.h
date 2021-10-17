#include "Graphics.h"

class GameManager{
    private:
    // game manager status, 1 = fine, 0 = quit, -1 = error
    int status;
    Board chessBoard;
    ChessWindow gameWindow;
    void Init();
    void Run();

    public:
    GameManager();
    void Start();
};