#include "GameManager.h"

GameManager::GameManager(){
    Init();
}

void GameManager::Init(){

}

void GameManager::Start(){
    Run();
}

void GameManager::Run(){
    while(gameWindow.GetStatus()){
        gameWindow.Update();
    }
}
