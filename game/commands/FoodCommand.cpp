﻿//
// Created by duarte on 08-12-2022.
//

#include <iostream>
#include "FoodCommand.h"
#include "../models/food/Grass.h"
#include "../models/food/Carrot.h"
#include "../models/food/Beef.h"
#include "../models/food/Blueberries.h"
#include "../utils/utils.h"

void spawnFood(std::string type, bool randomCoordinates, int col, int row, Game* game) {
    Food* food;
    bool validType = false;
    if(type == "r"){
        food = new Grass();
        validType = true;
    }else if(type == "t"){
        food = new Carrot();
        validType = true;
    }else if( type == "b"){
        food = new Beef();
        validType = true;
    }else if (type == "a"){
        food = new Blueberries();
        validType = true;
    }

    if(validType){
        if(randomCoordinates){
            food->defineRandomPosition(game->configuration.size.rows-1,game->configuration.size.cols-1);
        }else{
            food->position.column = col;
            food->position.row = row;
        }
        game->addFood(food);
    }else{
        std::cout << "  > Invalid food type provided" << std::endl;
    }
}

void FoodCommand::execute() {
    std::cout << "  > Executing the food command" << std::endl;
    if(this->args.size() == 2){
        //execute food on a random position
        spawnFood(this->args[1],true,0,0,this->game);
    }else if(this->args.size() == 4) {
        //execute a animal on a given position
        if (isNumber(this->args[2]) && isNumber(this->args[3])) {
            int line = std::stoi(args[2]);
            int col = std::stoi(args[3]);

            if(isNumbersValidOnMatrix(this->game,line,col)){
                spawnFood(this->args[1], false, col,line, this->game);
            }else{
                std::cout << "      > Invalid coordinates provided, the numbers should not exceed the max rows and columns, remind that it starts on 0." << std::endl;
            }
        } else {
            std::cout << "  > Invalid command provided, the line and columns arguments must be integers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the food command must contain at least 1 argument (food <type: r / t / b / a>) or <type: r / t / b / a> <line> <column>" << std::endl;
    }
}