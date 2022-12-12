//
// Created by duarte on 12-12-2022.
//

#include "GameSingleton.h"

Game *GameSingleton::game = NULL;

Game *GameSingleton::getGame() {
    return GameSingleton::game;
}


void GameSingleton::setGame(Game *game) {
    GameSingleton::game = game;
}

void GameSingleton::removeGame() {
    GameSingleton::game = NULL;
}



