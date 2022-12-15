//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Beef.h"
#include "../enums/Smell.h"
#include "../game/Game.h"
#include "../../commands/NoFoodCommand.h"

int Beef::configMaxIterations = 0;

Beef::Beef() {
    this->maxIterations = Beef::configMaxIterations;
    this->nutritiveValue = 10;
    this->toxicity = 2;
    this->smells.push_back(ENUM_Meat);
    this->smells.push_back(ENUM_Ketchup);
    this->identifierEmoji = "\U0001f969";
    this->identifier = 'b';
    this->position = { 0,0 };
}

void Beef::reproduce(Game* game) {

}

void Beef::verifications(Game* game) {
    this->currentIterations += 1;
    if(this->currentIterations >= this->maxIterations){
        //delete the food from the game
        NoFoodCommand::deleteFoodFromMatrix(game, this->id);
    }else{
        if(this->nutritiveValue > 0){
            this->nutritiveValue--;
        }
    }
}

void Beef::do_iteration(Game* game) {
    std::cout << "      > Beef iteration: ";
    Food::display();
    this->verifications(game);
}
