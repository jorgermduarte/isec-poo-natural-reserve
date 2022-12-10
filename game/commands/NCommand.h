//
// Created by duarte on 10-12-2022.
//

#ifndef POO_NATURAL_RESERVE_NCOMMAND_H
#define POO_NATURAL_RESERVE_NCOMMAND_H

#include "../models/commands/DefaultCommand.h"

class NCommand: public DefaultCommand {
public:
    NCommand(Game* game,std::vector<std::string> args): DefaultCommand(game,args){}
    void execute() override;
};


#endif //POO_NATURAL_RESERVE_NCOMMAND_H
