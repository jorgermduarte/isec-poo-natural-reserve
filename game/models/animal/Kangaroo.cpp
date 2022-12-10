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

void Kangaroo::reproduce() {
}

void Kangaroo::move() {
}

void Kangaroo::perception() {
}

void Kangaroo::eat() {
}

void Kangaroo::fight() {
}

void Kangaroo::verifications() {
}

void Kangaroo::do_iteration() {
    std::cout << "      > Kangaroo iteration: ";
    Animal::display();
}