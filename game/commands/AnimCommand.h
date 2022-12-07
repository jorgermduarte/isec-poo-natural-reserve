//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_ANIMCOMMAND_H
#define POO_NATURAL_RESERVE_ANIMCOMMAND_H


#include "../models/commands/DefaultCommand.h"

class AnimCommand: public DefaultCommand
{
public:
    AnimCommand(Game* game): DefaultCommand(game) {}
    void execute() override;
};


#endif //POO_NATURAL_RESERVE_ANIMCOMMAND_H
