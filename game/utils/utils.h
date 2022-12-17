//
// Created by duarte on 13-11-2022.
//

#ifndef POO_NATURAL_RESERVE_UTILS_H
#define POO_NATURAL_RESERVE_UTILS_H

#include <vector>
#include <string>
#include "../models/game/Game.h"

void displayStringsList(std::vector<std::string> args);
bool isNumber(const std::string& s);
bool isNumbersValidOnMatrix(Game*game, int row, int col);

#endif //POO_NATURAL_RESERVE_UTILS_H
