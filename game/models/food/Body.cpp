//
// Created by duarte on 07-12-2022.
//

#include "Body.h"
#include "../enums/Smell.h"

Body::Body() {
    this->maxLifetime = -1;
    this->nutritiveValue = 0;
    this->toxicity = 0;
    this->smells.push_back(ENUM_Meat);
    this->identifierEmoji = "\u2B55";
    this->identifier = 'p';

    //TODO: for now the food is spawning at 0,0 for test purposes
    // we need to implement a way to spawn the food in a random position in the matrix
    // if there's any command that specify the position of the food, we can create a new constructor for that purpose
    this->position = { 0,0 };
}
