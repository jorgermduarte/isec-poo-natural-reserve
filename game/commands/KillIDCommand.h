//
// Created by duarte on 09-12-2022.
//

#ifndef POO_NATURAL_RESERVE_KILLIDCOMMAND_H
#define POO_NATURAL_RESERVE_KILLIDCOMMAND_H

#include "../models/commands/DefaultCommand.h"

class KillIDCommand: public DefaultCommand {
public:
    KillIDCommand(Game* game, std::vector<std::string> args): DefaultCommand(game, args){}
    static void deleteAnimalById(Game* game, int id);
    void execute() override;
};

#endif //POO_NATURAL_RESERVE_KILLIDCOMMAND_H
