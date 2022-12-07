//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_DEFAULTCOMMAND_H
#define POO_NATURAL_RESERVE_DEFAULTCOMMAND_H

#include <string>
#include <vector>
#include "../game/Game.h"

class DefaultCommand {
public:
    std::vector<std::string> args;
    Game* game;
    explicit DefaultCommand(Game* game);
    explicit DefaultCommand(Game* game,std::vector<std::string> args);
    virtual void execute();
};

#endif //POO_NATURAL_RESERVE_DEFAULTCOMMAND_H
