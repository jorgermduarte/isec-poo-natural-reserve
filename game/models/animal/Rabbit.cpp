//
// Created by duarte on 10-11-2022.
//
#include <iostream>
#include "Rabbit.h"
int Rabbit::configMaxHP = 0;
int Rabbit::configMaxIterations = 0;

Rabbit::Rabbit() {
    this->identifierEmoji = "\U0001f407";
    this->weight =  1 + (rand() % 9 + 1);
    this->currentHP = Rabbit::configMaxHP;
    this->maxIterations = Rabbit::configMaxIterations;
    this->maxHP = currentHP;
    this->identifier = 'C';
}

void Rabbit::reproduce() {
}

void Rabbit::move() {
}

void Rabbit::perception() {
}

void Rabbit::eat() {
}

void Rabbit::fight() {
}

void Rabbit::verifications() {
}

void Rabbit::do_iteration() {
    std::cout << "      > Rabbit iteration: ";
    Animal::display();
}