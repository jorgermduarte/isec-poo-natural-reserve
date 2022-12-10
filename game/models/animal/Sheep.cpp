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

void Sheep::reproduce() {

}

void Sheep::move() {

}

void Sheep::perception() {

}

void Sheep::eat() {

}

void Sheep::fight() {

}

void Sheep::verifications() {

}

void Sheep::do_iteration() {
    std::cout << "      > Sheep iteration: ";
    Animal::display();
}