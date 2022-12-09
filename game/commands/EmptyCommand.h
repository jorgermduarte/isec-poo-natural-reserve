//
// Created by duarte on 09-12-2022.
//

#ifndef POO_NATURAL_RESERVE_EMPTYCOMMAND_H
#define POO_NATURAL_RESERVE_EMPTYCOMMAND_H

#include "../models/commands/DefaultCommand.h"

class EmptyCommand: public DefaultCommand {
public:
    EmptyCommand(Game* game, std::vector<std::string> args): DefaultCommand(game, args){}
    void execute() override;
};



#endif //POO_NATURAL_RESERVE_EMPTYCOMMAND_H
