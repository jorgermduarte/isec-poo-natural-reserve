//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_LOADCOMMAND_H
#define POO_NATURAL_RESERVE_LOADCOMMAND_H


#include "../models/commands/DefaultCommand.h"

class LoadCommand: public DefaultCommand {
public:
    LoadCommand(Game* game,std::vector<std::string> args): DefaultCommand(game,args){}
    void execute() override;
};

#endif //POO_NATURAL_RESERVE_LOADCOMMAND_H
