//
// Created by duarte on 11-11-2022.
//

#include <iostream>
#include "Sheep.h"
int Sheep::configMaxHP = 0;
int Sheep::configMaxIterations = 0;

Sheep::Sheep() {
    this->identifierEmoji = "\U0001f411";
    this->weight =  15 + (rand() % 25 + 1);
    this->currentHP = Sheep::configMaxHP;
    this->maxIterations = Sheep::configMaxIterations;
    this->maxHP = currentHP;
    this->identifier = 'O';
}

void Sheep::reproduce(Game* game) {

}

void Sheep::move(Game* game) {

}

void Sheep::move(Game* game,Position position) {

}

void Sheep::eat(Game* game,Food *food) {

}

void Sheep::fight(Game* game,Animal *animal) {

}

void Sheep::verifications(Game* game) {

}

void Sheep::do_iteration(Game* game) {
    std::cout << "      > Sheep iteration: ";
    Animal::display();
}