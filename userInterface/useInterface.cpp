//
// Created by duarte on 10-11-2022.
//
#include <iostream>
#include "useInterface.h"
#include "../game/game/GameConfiguration.h"

void displayNaturalReserveAux(Game &game, int x, int visibleCols, int displayVisibleCol){
    for(int i = displayVisibleCol; i < visibleCols; i++){
        std::vector<MatrixCell> col = game.matrix[i];

        if(col[x].animals.size() > 0){
            std::cout << col[x].animals.begin()->identifier + " ";
        }
        else if(col[x].foods.size() > 0){
            std::cout << col[x].foods.begin()->identifier + " ";
        }
        else{
            std::cout << std::to_string(col[x].position.row)  + std::to_string(col[x].position.column) + " ";
        }
    }
}

void displayNaturalReserve(Game &game){
    std::cout << "=============================================================================== " << std::endl;

    int currentDisplayAreaRows = game.configuration.size.rows * DISPLAY_AREA_PERCENTAGE;
    currentDisplayAreaRows += game.configuration.screenPosition.row;

    int currentDisplayAreaCols = game.configuration.size.cols * DISPLAY_AREA_PERCENTAGE;
    currentDisplayAreaCols += game.configuration.screenPosition.column;

    for(int i = game.configuration.screenPosition.row; i < currentDisplayAreaRows; i++){
        displayNaturalReserveAux(game,i,currentDisplayAreaCols,game.configuration.screenPosition.column);
        std::cout << std::endl;
    }
}

void displayAnimals(Game &game){
    std::cout << "=============================== | ANIMALS | =================================== " << std::endl;
    for (const auto &animal: game.animals){
        std::cout << "[" + std::to_string(animal.id)+ "] [" + std::to_string(animal.position.row) + std::to_string(animal.position.column) + "] " + animal.identifier + " HP: " + std::to_string(animal.currentHP) << std::endl;
    }
}