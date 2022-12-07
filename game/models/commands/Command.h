//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_COMMAND_H
#define POO_NATURAL_RESERVE_COMMAND_H

#include <string>
#include "../game/Game.h"

class Command {
private:
    static bool validateArgumentsSize(std::string &command);
public:
    static bool validate(std::string &command);
    static std::vector<std::string> getArguments(std::string &command);
    static void execute(std::string &command, Game* game);
    static void handleCommands(Game* game);
};


#endif //POO_NATURAL_RESERVE_COMMAND_H
