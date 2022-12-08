//
// Created by duarte on 11-11-2022.
//

#include "Sheep.h"
int Sheep::configMaxHP = 0;

Sheep::Sheep() {
    this->identifierEmoji = "\U0001f411";
    this->weight =  15 + (rand() % 25 + 1);
    this->currentHP = Sheep::configMaxHP;
    this->maxHP = currentHP;
    this->identifier = 'O';
}

void Sheep::reproduce() {

}

void Sheep::triggerInstant() {

}

void Sheep::perceive() {

}

void Sheep::move() {

}
