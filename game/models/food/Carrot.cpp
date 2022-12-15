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
    this->position = { 0,0 };
}

void Carrot::reproduce(Game* game) {

}

void Carrot::verifications(Game* game) {
    //from 10 to 10 iteration, the toxicity of the carrot will increase by 1 to the max of 3
    if (this->currentIterations % 10 == 0 && this->currentIterations != 0) {
        if (this->toxicity < 3) {
            this->toxicity++;
            std::cout << "          > The toxicity of the carrot increased to " << this->toxicity << std::endl;
        }
    }
    this->currentIterations += 1;
}

void Carrot::do_iteration(Game* game) {
    std::cout << "      > Carrot iteration: ";
    Food::display();
    this->verifications(game);
}
