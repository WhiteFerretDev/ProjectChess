#include <SDL2/SDL.h>


#define LogSDLError(message) SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, message  ": %s\n", SDL_GetError());
#define LogSDLInfo(message) SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, message);
#define SetSDLRenderColor(renderer, color) SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);


class ChessWindow{

    private:
    // status of chess window, 1 = running, 0 = quit, -1 = error
    int status;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;

    SDL_Color whiteColor = {.r = 255, .g = 255, .b = 255, .a = 255};
    SDL_Color blackColor = {.r = 0, .g = 0, .b = 0, .a = 255};
    SDL_Color clearScreenColor = {.r = 130, .g = 0, .b = 20, .a = 255};

    int Init();

    void ClearScreen();

    void Draw();
    void DrawBoard();

    void DrawBoardBackground(int* boardSize);
    void DrawBoardSquares(int* boardSize);

    public:
    ChessWindow();

    void Start();
    void Update();
    void Close();

    int GetStatus();

};
