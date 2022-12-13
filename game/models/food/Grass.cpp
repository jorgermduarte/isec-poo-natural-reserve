//
// Created by duarte on 10-11-2022.
//

#include <iostream>
#include "Grass.h"
#include "../enums/Smell.h"
#include "../game/Game.h"

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
}

void Grass::reproduce(Game* game) {

    bool shouldReproduce = this->currentIterations >= (this->maxIterations * 0.75);
    if(shouldReproduce){
        //TODO: calculate between 4-8 positions (random position) of distance in the matrix and add a new food

        //if any food already exists in that position, don't add it
    }
}

void Grass::verifications(Game* game) {
    this->currentIterations++;
}

void Grass::do_iteration(Game* game) {
    std::cout << "      > Grass iteration: ";
    Food::display();
    this->reproduce(game);
    this->verifications(game);
}