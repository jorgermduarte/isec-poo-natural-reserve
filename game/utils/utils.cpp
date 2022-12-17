//
// Created by duarte on 13-11-2022.
//
#include <iostream>
#include "utils.h"

void displayStringsList(std::vector<std::string> args){
    for(std::string arg: args){
        std::cout <<"  > Argument: " + arg << std::endl;
    }
}

//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool isNumbersValidOnMatrix(Game*game, int row, int col){
    return row >= 0 && row < game->configuration.size.rows && col >= 0 && col < game->configuration.size.cols;
}