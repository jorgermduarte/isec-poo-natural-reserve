//
// Created by duarte on 07-12-2022.
//

#include "Wolf.h"
int Wolf::configMaxHP = 0;

Wolf::Wolf() {
    this->identifierEmoji = "\U0001f43a";
    this->weight =  30 + (rand() % 40 + 1); // todo: change it to the correct value
    this->currentHP = Wolf::configMaxHP;
    this->maxHP = currentHP;
    this->identifier = 'L';
}

void Wolf::reproduce() {
}

void Wolf::triggerInstant() {

}

void Wolf::perceive() {

}

void Wolf::move() {

}
