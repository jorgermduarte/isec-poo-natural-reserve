//
// Created by duarte on 12-12-2022.
//

#ifndef POO_NATURAL_RESERVE_GAMESINGLETON_H
#define POO_NATURAL_RESERVE_GAMESINGLETON_H


#include "Game.h"

class GameSingleton {
private:
    static Game* game;
public:
    static void setGame(Game* game);
    static void removeGame();
    static Game* getGame();
};


#endif //POO_NATURAL_RESERVE_GAMESINGLETON_H
