//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_GAMESERVICE_H
#define POO_NATURAL_RESERVE_GAMESERVICE_H

#include <iostream>
#include "../game/Position.h"
#include "../game/game/Game.h"

class GameService {
private:
    //TODO: this property will be used to change the board preview limitations on screen
    Position screenPosition = { 0,0 };
    Game game;
    void defineNaturalReserveConfiguration();
    void initializeMatrix();
public:
    void initialize();
};


#endif //POO_NATURAL_RESERVE_GAMESERVICE_H
