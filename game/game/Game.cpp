//
// Created by duarte on 11-11-2022.
//

#include "Game.h"

int Game::matrixGetNumRows() {
    return this->matrix.size();
}

int Game::matrixGetNumColumns() {
    if(this->matrixGetNumRows() > 0){
        return this->matrix[0].size();
    }
}

void Game::addAnimal(Animal animal) {
    this->animals.push_back(animal);
    this->matrix[animal.position.column][animal.position.row].animals.push_back(animal);
}

void Game::addFood(Food food) {
    this->foods.push_back(food);
    this->matrix[food.position.column][food.position.row].foods.push_back(food);
}