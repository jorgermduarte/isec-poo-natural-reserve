//
// Created by duarte on 07-12-2022.
//

#include "Beef.h"
#include "../enums/Smell.h"

Beef::Beef() {
    this->maxLifetime = 30;
    this->nutritiveValue = 10;
    this->toxicity = 2;
    this->smells.push_back(ENUM_Meat);
    this->smells.push_back(ENUM_Ketchup);
    this->identifierEmoji = "\U0001f969";
    this->identifier = 'b';

    //TODO: for now the food is spawning at 0,0 for test purposes
    // we need to implement a way to spawn the food in a random position in the matrix
    // if there's any command that specify the position of the food, we can create a new constructor for that purpose
    this->position = { 0,0 };
}