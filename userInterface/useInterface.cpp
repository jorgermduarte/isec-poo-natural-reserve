//
// Created by duarte on 10-11-2022.
//
#include <iostream>
#include "useInterface.h"
#define DISPLAY_AREA_PERCENTAGE 0.8;

void displayNaturalReserveAux(Game &game, int x, int visibleCols){

    for(int i = 0; i < visibleCols; i++){
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

    /*for(auto & col : game.matrix)
    {
        if(col[x].animals.size() > 0){
            std::cout << col[x].animals.begin()->identifier + " ";
        }
        else if(col[x].foods.size() > 0){
            std::cout << col[x].foods.begin()->identifier + " ";
        }
        else{
            std::cout << std::to_string(col[x].position.row)  + std::to_string(col[x].position.column) + " ";
        }
    }*/
}

void displayNaturalReserve(Game &game){
    std::cout << "=============================================================================== " << std::endl;

    int currentDisplayAreaRows = game.configuration.size.rows * DISPLAY_AREA_PERCENTAGE;
    currentDisplayAreaRows += game.configuration.screenPosition.row;

    int currentDisplayAreaCols = game.configuration.size.cols * DISPLAY_AREA_PERCENTAGE;
    currentDisplayAreaCols += game.configuration.screenPosition.column;

    std::cout << "Visible cols: " + std::to_string(currentDisplayAreaCols) << std::endl;
    std::cout << "Visible rows: " + std::to_string(currentDisplayAreaRows) << std::endl;
    std::cout << "=============================================================================== " << std::endl;

    for(int i = 0; i < currentDisplayAreaRows; i++){
        displayNaturalReserveAux(game,i,currentDisplayAreaCols);
        std::cout << std::endl;
    }
}

void displayAnimals(Game &game){
    std::cout << "=============================== | ANIMALS | =================================== " << std::endl;
    for (const auto &animal: game.animals){
        std::cout << "[UID] [" + std::to_string(animal.position.row) + std::to_string(animal.position.column) + "] " + animal.identifier + " HP: " + std::to_string(animal.health) + " MAX AGE: " + std::to_string(animal.maxLifetime) <<
                std::endl;
    }
}