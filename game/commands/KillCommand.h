//
// Created by duarte on 09-12-2022.
//

#ifndef POO_NATURAL_RESERVE_KILLCOMMAND_H
#define POO_NATURAL_RESERVE_KILLCOMMAND_H

#include "../models/commands/DefaultCommand.h"

class KillCommand: public DefaultCommand {
public:
    KillCommand(Game* game, std::vector<std::string> args): DefaultCommand(game, args){}
    static void deleteAnimalById(Game* game, int id);
    static void deleteAnimalFromMatrix(Game* game, int id);
    static void deleteAnimalFromList(Game* game, int id);
    void execute() override;
};

#endif //POO_NATURAL_RESERVE_KILLCOMMAND_H
