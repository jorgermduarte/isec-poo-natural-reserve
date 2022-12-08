//
// Created by duarte on 08-12-2022.
//

#ifndef POO_NATURAL_RESERVE_ANIMALCOMMAND_H
#define POO_NATURAL_RESERVE_ANIMALCOMMAND_H

#include "../models/commands/DefaultCommand.h"

class AnimalCommand: public DefaultCommand
{
public:
    AnimalCommand(Game* game,std::vector<std::string> args): DefaultCommand(game,args){}
    void execute() override;
};

#endif //POO_NATURAL_RESERVE_ANIMALCOMMAND_H
