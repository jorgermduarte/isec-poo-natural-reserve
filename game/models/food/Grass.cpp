//
// Created by duarte on 10-11-2022.
//

#include <iostream>
#include "Grass.h"
#include "../enums/Smell.h"
#include "../../commands/NoFoodCommand.h"

int Grass::configMaxIterations = 0;

Grass::Grass() {
    this->nutritiveValue = 3;
    this->maxIterations = Grass::configMaxIterations;
    this->toxicity = 0;
    this->smells.push_back(ENUM_Grass);
    this->smells.push_back(ENUM_Vegetables);
    this->identifierEmoji = "\U0001f33f";
    this->identifier = 'r';
    this->position = { 0,0 };
    this->currentIterations = 0;
}

void Grass::reproduce(Game* game) {

    bool shouldReproduce = false;

    if(shouldReproduce){
        //TODO: calculate between 4-8 positions (random position) of distance in the matrix and add a new food
    }
}

void Grass::verifications(Game* game) {
    this->currentIterations += 1;
    if(this->currentIterations >= this->maxIterations){
        NoFoodCommand::deleteFoodFromMatrix(game, this->id);
    }
}

void Grass::do_iteration(Game* game) {
    std::cout << "      > Grass iteration: ";
    Food::display();
    this->reproduce(game);
    this->verifications(game);

}