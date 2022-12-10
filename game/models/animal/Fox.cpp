//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Fox.h"
int Fox::configMaxHP = 0;
int Fox::configMaxIterations = 0;

Fox::Fox() {
    this->identifierEmoji = "\U0001f98a";
    this->weight =  20 + (rand() % 25 + 1);
    this->currentHP = Fox::configMaxHP;
    this->maxIterations = Fox::configMaxIterations;
    this->maxHP = currentHP;
    this->identifier = 'm';
}

void Fox::reproduce() {
}

void Fox::move() {
}

void Fox::perception() {
}

void Fox::eat() {
}

void Fox::fight() {
}

void Fox::verifications() {
}

void Fox::do_iteration() {
    std::cout << "      > Fox iteration: ";
    Animal::display();
}