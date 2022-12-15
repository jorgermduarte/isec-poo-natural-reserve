//
// Created by duarte on 07-12-2022.
//
#include <iostream>
#include "Body.h"
#include "../enums/Smell.h"
int Body::configMaxIterations = 0;

Body::Body() {
    this->nutritiveValue = 0;
    this->toxicity = 0;
    this->maxIterations = Body::configMaxIterations;
    this->smells.push_back(ENUM_Meat);
    this->identifierEmoji = "\u2B55";
    this->identifier = 'p';
    this->position = { 0,0 };
}

void Body::reproduce(Game* game) {

}

void Body::verifications(Game* game) {
    //each iteration the nutritive values decreases 1 unit and the toxicity increases 1 unit
    //the toxicity stops increasing when the toxicity is bigger by 2 times the nutritive value
    if (this->toxicity < this->nutritiveValue * 2) {
        this->toxicity++;
    }
    this->nutritiveValue--;

    if(nutritiveValue <= 0){
        nutritiveValue = 0;
    }
    this->currentIterations += 1;
}

void Body::do_iteration(Game* game) {
    std::cout << "      > Body iteration: ";
    Food::display();
    this->verifications(game);
}