//
// Created by duarte on 11-11-2022.
//

#include "Sheep.h"
int Sheep::maxHP = 0;

Sheep::Sheep() {
    this->identifier = "\U0001f411";
    this->weight = rand() % 4 + 1;
    this->currentHP = Sheep::maxHP;
}

void Sheep::reproduce() {

}

void Sheep::triggerInstant() {

}

void Sheep::perceive() {

}

void Sheep::move() {

}
