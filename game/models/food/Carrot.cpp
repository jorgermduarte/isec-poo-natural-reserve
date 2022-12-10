//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Carrot.h"
#include "../enums/Smell.h"

int Carrot::configMaxIterations = 0;

Carrot::Carrot() {
    this->nutritiveValue = 4;
    this->maxIterations = Carrot::configMaxIterations;
    this->toxicity = 0;
    this->smells.push_back(ENUM_Vegetables);
    this->identifierEmoji = "\U0001f955";
    this->identifier = 't';

    //TODO: for now the food is spawning at 0,0 for test purposes
    // we need to implement a way to spawn the food in a random position in the matrix
    // if there's any command that specify the position of the food, we can create a new constructor for that purpose
    this->position = { 0,0 };
}

void Carrot::reproduce() {

}

void Carrot::verifications() {

}

void Carrot::do_iteration() {
    std::cout << "      > Carrot iteration: ";
    Food::display();
}
