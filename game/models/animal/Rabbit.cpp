//
// Created by duarte on 10-11-2022.
//
#include "Rabbit.h"
int Rabbit::configMaxHP = 0;

Rabbit::Rabbit() {
    this->identifierEmoji = "\U0001f407";
    this->weight =  1 + (rand() % 9 + 1);
    this->currentHP = Rabbit::configMaxHP;
    this->maxHP = currentHP;
    this->identifier = 'C';
}

void Rabbit::reproduce() {
}

void Rabbit::triggerInstant() {

}

void Rabbit::perceive() {

}

void Rabbit::move() {

}
