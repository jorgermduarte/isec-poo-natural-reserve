//
// Created by duarte on 10-11-2022.
//

#include "Grass.h"
#include "../enums/Smell.h"

int Grass::configMaxIterations = 0;

Grass::Grass() {
    this->nutritiveValue = 3;
    this->maxIterations = Grass::configMaxIterations;
    this->toxicity = 0;
    this->smells.push_back(ENUM_Grass);
    this->smells.push_back(ENUM_Vegetables);
    this->identifierEmoji = "\U0001f33f";
    this->identifier = 'r';

    //TODO: for now the food is spawning at 0,0 for test purposes
    // we need to implement a way to spawn the food in a random position in the matrix
    // if there's any command that specify the position of the food, we can create a new constructor for that purpose
    this->position = { 0,0 };
}

