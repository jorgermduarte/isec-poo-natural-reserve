//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Blueberries.h"
#include "../enums/Smell.h"
#include "../../commands/NoFoodCommand.h"

int Blueberries::configMaxIterations = 0;

Blueberries::Blueberries() {
    this->maxIterations = Blueberries::configMaxIterations;
    this->nutritiveValue = 15;
    this->toxicity = 0;
    this->smells.push_back(ENUM_Vegetables);
    this->identifierEmoji = "\U0001fad0";
    this->identifier = 'a';
    this->position = { 0,0 };
}

void Blueberries::reproduce(Game* game) {

}

void Blueberries::verifications(Game* game) {
    this->currentIterations++;
    if(this->currentIterations >= this->maxIterations) {
        NoFoodCommand::deleteFoodFromMatrix(game, this->id);
    }
}

void Blueberries::do_iteration(Game* game) {
    std::cout << "      > Blueberries iteration: ";
    Food::display();
    this->verifications(game);
}
