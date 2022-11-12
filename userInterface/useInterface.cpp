//
// Created by duarte on 10-11-2022.
//
#include <iostream>
#include "useInterface.h"


void displayNaturalReserveAux(Game &game, int x){
    for(auto & col : game.matrix)
    {
        if(col[x].animals.size() > 0){
            std::cout << col[x].animals.begin()->identifier + " ";
        }else{
            std::cout << std::to_string(col[x].position.row)  + std::to_string(col[x].position.column) + " ";
        }
    }
}

void displayNaturalReserve(Game &game){
    std::cout << "=============================================================================== " << std::endl;
    for(int i = 0; i < game.configuration.size.rows; i++){
        displayNaturalReserveAux(game,i);
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