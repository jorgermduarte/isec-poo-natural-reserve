//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_COMMANDS_H
#define POO_NATURAL_RESERVE_COMMANDS_H

#include <unordered_map>
#include <string>
#include <vector>
#include "../game/game/Game.h"

const static std::unordered_map<std::string,int> allowedCommands{
        {"animal",0},
        {"kill",1},
        {"food",2},
        {"feed",3},
        {"feedid",4},
        {"nofood",5},
        {"empty",6},
        {"see",7},
        {"info",8},
        {"n",9},
        {"anim",10},
        {"visanim",11},
        {"store",12},
        {"restore",13},
        {"load",14},
        {"slide",15}
};

void exec_command_animal(std::vector<std::string> args);
void exec_command_kill(std::vector<std::string> args);
void exec_command_food(std::vector<std::string> args);
void exec_command_feed(std::vector<std::string> args);
void exec_command_feedid(std::vector<std::string> args);
void exec_command_nofood(std::vector<std::string> args);
void exec_command_empty(std::vector<std::string> args);
void exec_command_see(std::vector<std::string> args);
void exec_command_info(std::vector<std::string> args, Game* game);
void exec_command_n();
void exec_command_n(std::vector<std::string> args);
void exec_command_anim(Game* game);
void exec_command_visanim();
void exec_command_store(std::vector<std::string> args);
void exec_command_restore(std::vector<std::string> args);
void exec_command_load(std::vector<std::string> args, Game* game);
void exec_command_slide(std::vector<std::string> args, Game* game);

#endif //POO_NATURAL_RESERVE_COMMANDS_H
