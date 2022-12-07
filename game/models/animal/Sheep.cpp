//
// Created by duarte on 11-11-2022.
//

#include "Sheep.h"
int Sheep::maxHP = 0;

Sheep::Sheep() {
    this->identifierEmoji = "\U0001f411";
    this->weight = rand() % 4 + 1;
    this->currentHP = Sheep::maxHP;
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
