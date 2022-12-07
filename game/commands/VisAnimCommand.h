//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_VISANIMCOMMAND_H
#define POO_NATURAL_RESERVE_VISANIMCOMMAND_H


#include "../models/commands/DefaultCommand.h"

class VisAnimCommand: public DefaultCommand {
public:
    VisAnimCommand(Game* game): DefaultCommand(game) {}
    VisAnimCommand(Game* game,std::vector<std::string> args): DefaultCommand(game,args){}
    void execute() override;
};


#endif //POO_NATURAL_RESERVE_VISANIMCOMMAND_H
