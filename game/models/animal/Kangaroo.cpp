//
// Created by duarte on 07-12-2022.
//

#include "Kangaroo.h"
int Kangaroo::configMaxHP = 0;

Kangaroo::Kangaroo() {
    this->identifierEmoji = "\U0001f998";
    this->weight = 100 + (rand() % 150 + 1); // todo: change it to the correct value
    this->currentHP = Kangaroo::configMaxHP;
    this->maxHP = currentHP;
    this->identifier = 'G';
}

void Kangaroo::reproduce() {
}

void Kangaroo::triggerInstant() {

}

void Kangaroo::perceive() {

}

void Kangaroo::move() {

}