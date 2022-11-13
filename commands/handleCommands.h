//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_HANDLECOMMANDS_H
#define POO_NATURAL_RESERVE_HANDLECOMMANDS_H

#include <iostream>
#include <vector>
#include "../game/game/Game.h"

using namespace std;

void handleCommands(Game* game);

void executeCommand(std::string &command,Game* game);

#endif //POO_NATURAL_RESERVE_HANDLECOMMANDS_H
