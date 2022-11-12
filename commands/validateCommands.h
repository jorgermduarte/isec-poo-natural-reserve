//
// Created by duarte on 10-11-2022.
//
#ifndef POO_NATURAL_RESERVE_VALIDATECOMMANDS_H
#define POO_NATURAL_RESERVE_VALIDATECOMMANDS_H

#include <vector>
#include <iostream>
#include <array>
#include <unordered_map>

using namespace std;

vector<string> getCommandArguments(string &command);

bool validateArgumentsSize(string &command);

bool validateCommand(string &command);

#endif //POO_NATURAL_RESERVE_VALIDATECOMMANDS_H
