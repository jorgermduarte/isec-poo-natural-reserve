//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_COMMANDS_H
#define POO_NATURAL_RESERVE_COMMANDS_H

#include <unordered_map>
#include <string>
#include <vector>
#include "../models/game/Game.h"

void exec_command_kill(std::vector<std::string> args);
void exec_command_killid(std::vector<std::string> args);
void exec_command_empty(std::vector<std::string> args);

void exec_command_store(std::vector<std::string> args);
void exec_command_restore(std::vector<std::string> args);

void exec_command_n(std::vector<std::string> args);
#endif //POO_NATURAL_RESERVE_COMMANDS_H
