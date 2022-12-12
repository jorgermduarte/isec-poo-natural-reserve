//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Wolf.h"
int Wolf::configMaxHP = 0;
int Wolf::configMaxIterations = 0;

Wolf::Wolf() {
    this->identifierEmoji = "\U0001f43a";
    this->weight =  30 + (rand() % 40 + 1); // todo: change it to the correct value
    this->currentHP = Wolf::configMaxHP;
    this->maxIterations = Wolf::configMaxIterations;
    this->maxHP = currentHP;
    this->identifier = 'L';
}


void Wolf::reproduce(Game* game) {

}

void Wolf::move(Game* game) {

}

void Wolf::move(Game* game, Position position) {

}

void Wolf::eat(Game* game,Food *food) {

}

void Wolf::fight(Game* game,Animal *animal) {

}

void Wolf::verifications(Game* game) {

}

void Wolf::do_iteration(Game* game) {
    std::cout << "      > Wolf iteration: ";
    Animal::display();
}