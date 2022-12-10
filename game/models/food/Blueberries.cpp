//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Blueberries.h"
#include "../enums/Smell.h"

int Blueberries::configMaxIterations = 0;

Blueberries::Blueberries() {
    this->maxIterations = Blueberries::configMaxIterations;
    this->nutritiveValue = 15;
    this->toxicity = 0;
    this->smells.push_back(ENUM_Vegetables);
    this->identifierEmoji = "\U0001fad0";
    this->identifier = 'a';

    //TODO: for now the food is spawning at 0,0 for test purposes
    // we need to implement a way to spawn the food in a random position in the matrix
    // if there's any command that specify the position of the food, we can create a new constructor for that purpose
    this->position = { 0,0 };
}

void Blueberries::reproduce() {

}

void Blueberries::verifications() {

}

void Blueberries::do_iteration() {
    std::cout << "      > Blueberries iteration: ";
    Food::display();
}
