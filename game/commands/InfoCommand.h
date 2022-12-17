//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_INFOCOMMAND_H
#define POO_NATURAL_RESERVE_INFOCOMMAND_H

#include <vector>
#include <string>
#include "../models/game/Game.h"
#include "../models/commands/DefaultCommand.h"

class InfoCommand: public DefaultCommand {
public:
    InfoCommand(Game* game,std::vector<std::string> args): DefaultCommand(game,args){}
    static Animal* getAnimalById(Game* game, int id);
    void execute() override;
};

#endif //POO_NATURAL_RESERVE_INFOCOMMAND_H
