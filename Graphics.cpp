#include "Graphics.h"
#include <iostream>


ChessWindow::ChessWindow(){
    status = 1;
    int success = Init();

    if(!success){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "failed to initialize Chess Window");
    }

    ClearScreen();
    DrawBoard();
}

int ChessWindow::Init(){

    // Initialize SDL with video system
    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "failed to init video system: %s\n", SDL_GetError());
        return -1;  
    }
    
    window = SDL_CreateWindow("ProjectChess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_RESIZABLE);

    if(!window){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "window creation fail: %s\n", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "renderer creation fail: %s\n", SDL_GetError());
    }

    surface = SDL_GetWindowSurface(window);

    if(!surface){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error getting window surface: %s\n", SDL_GetError());
    }

    return 1;
}

void ChessWindow::ClearScreen(){
    SetRendererColor(renderer, clearScreenColor);
    SDL_RenderClear(renderer);
}

void ChessWindow::SetRendererColor(SDL_Renderer* renderer, SDL_Color color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void ChessWindow::DrawBoard(){
    SDL_Rect viewport;
    SDL_Rect fieldRect;

    // getting viewport rect
    SDL_RenderGetViewport(renderer, &viewport);

    fieldRect.w = viewport.w / 8;
    fieldRect.h = viewport.h / 8;

    // Drawing white part
    
    SetRendererColor(renderer, whiteColor);

    for(int row = 0; row < 8; row++){
        // offsetting every second line starting with the first to get chess board pattern
        int col = 1 - row % 2;
        
        for( ; col < 8; col += 2){
            fieldRect.x = col * fieldRect.w;
            fieldRect.y = row * fieldRect.h;

            SDL_RenderFillRect(renderer, &fieldRect);
        }
    }

    SDL_RenderPresent(renderer);
    
}

void ChessWindow::Update(){
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
            Close();
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

int ChessWindow::GetStatus(){
    return status;
}