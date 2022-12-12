//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Kangaroo.h"
int Kangaroo::configMaxHP = 0;
int Kangaroo::configMaxIterations = 0;

Kangaroo::Kangaroo() {
    this->identifierEmoji = "\U0001f998";
    this->weight = 100 + (rand() % 150 + 1); // todo: change it to the correct value
    this->currentHP = Kangaroo::configMaxHP;
    this->maxIterations = Kangaroo::configMaxIterations;
    this->maxHP = currentHP;
    this->identifier = 'G';
}

void Kangaroo::reproduce(Game* game) {

}

void Kangaroo::move(Game* game) {

}

void Kangaroo::move(Game* game, Position position) {

}


void Kangaroo::eat(Game* game, Food *food) {

}

void Kangaroo::fight(Game* game,Animal *animal) {

}

void Kangaroo::verifications(Game* game) {

}

void Kangaroo::do_iteration(Game* game) {
    std::cout << "      > Kangaroo iteration: ";
    Animal::display();
}

