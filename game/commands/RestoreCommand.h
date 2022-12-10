//
// Created by duarte on 10-12-2022.
//

#ifndef POO_NATURAL_RESERVE_RESTORECOMMAND_H
#define POO_NATURAL_RESERVE_RESTORECOMMAND_H

#include "../models/commands/DefaultCommand.h"

class RestoreCommand : public DefaultCommand {
public:
    RestoreCommand(Game* game,std::vector<std::string> args): DefaultCommand(game,args){}
    void execute() override;
};



#endif //POO_NATURAL_RESERVE_RESTORECOMMAND_H
