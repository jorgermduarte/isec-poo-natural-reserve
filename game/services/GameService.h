//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_GAMESERVICE_H
#define POO_NATURAL_RESERVE_GAMESERVICE_H

#include <iostream>
#include "../models/Position.h"
#include "../models/game/Game.h"

class GameService {
private:
    Game game;
    void defineNaturalReserveConfiguration();
    void initializeMatrix();
    void readConstantsFile();
public:
    void initialize();
};


#endif //POO_NATURAL_RESERVE_GAMESERVICE_H
