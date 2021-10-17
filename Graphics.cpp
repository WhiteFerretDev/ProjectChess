#include "Graphics.h"
#include "Pieces.h"
#include <iostream>
// TODO: remove
#include <bitset>


ChessWindow::ChessWindow(){
    status = 1;
    int success = Init();

    if(!success){
        LogSDLError("failed to initialize chess window");
    }

    ClearScreen();
}

int ChessWindow::Init(){

    // Initialize SDL with video system
    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        LogSDLError("failed to init video system");
        return -1;  
    }
    
    window = SDL_CreateWindow("ProjectChess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_RESIZABLE);

    if(!window){
        LogSDLError("window creation fail");
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        LogSDLError("render creation fail");
    }
    SDL_RenderSetLogicalSize(renderer, 640, 640);

    surface = SDL_GetWindowSurface(window);

    if(!surface){
        LogSDLError("error getting window surface");
    }

    return 1;
}

void ChessWindow::Start(Board* boardObject){
    Draw(boardObject);
}

void ChessWindow::Update(Board* boardObject){
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                Close();
                break;
            
            case SDL_WINDOWEVENT:
                switch (event.window.event){
                    case SDL_WINDOWEVENT_SIZE_CHANGED:
                        Draw(boardObject);
                        break;
                }
                break;
        }
    }
}

void ChessWindow::Close(){
    status = 0;
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void ChessWindow::ClearScreen(){
    SetSDLRenderColor(renderer, clearScreenColor);
    SDL_RenderClear(renderer);
}


void ChessWindow::Draw(Board* boardObject){

    ClearScreen();
    DrawBoard();
    DrawBoardPieces(boardObject);

    SDL_RenderPresent(renderer);
}


void ChessWindow::DrawBoard(){
    SDL_Rect viewport;

    // getting viewport rect
    SDL_RenderGetViewport(renderer, &viewport);
    int boardSize = std::min(viewport.w, viewport.h);

    DrawBoardBackground(&boardSize);
    DrawBoardSquares(&boardSize);    
}

void ChessWindow::DrawBoardBackground(int* boardSize){
    // drawing the black part of the board as one rect
    SDL_Rect backgroundRect;
    backgroundRect.w = *boardSize;
    backgroundRect.h = *boardSize;

    SetSDLRenderColor(renderer, blackColor);
    SDL_RenderFillRect(renderer, &backgroundRect);
}

void ChessWindow::DrawBoardSquares(int * boardSize){
    // drawing the white squares on the board
    SDL_Rect squareRect;
    int squareSize = *boardSize/8;

    squareRect.w = squareSize;
    squareRect.h = squareSize;

    SetSDLRenderColor(renderer, whiteColor);

    for(int row = 0; row < 8; row++){
        // offsetting every second line starting with the first to get chess board pattern
        int col = 1 - row % 2;
        
        for( ; col < 8; col += 2){
            squareRect.x = col * squareSize;
            squareRect.y = row * squareSize;

            SDL_RenderFillRect(renderer, &squareRect);
        }
    }
}

void ChessWindow::DrawBoardPieces(Board* boardObject){
    for(int i = 0; i < 64; i++){
        // check if field is not empty
        if((boardObject->fields[i] & Piece::EMPTY) != Piece::EMPTY){
            DrawPiece(&boardObject->fields[i], &i);
        }
    }
}

void ChessWindow::DrawPiece(unsigned char* piece, int* pos){
    std::cout << std::bitset<8>(*piece) << std::endl;
}

int ChessWindow::GetStatus(){
    return status;
}