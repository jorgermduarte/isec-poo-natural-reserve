//
// Created by duarte on 07-12-2022.
//

#include "Wolf.h"
int Wolf::maxHP = 0;

Wolf::Wolf() {
    this->identifierEmoji = "\U0001f43a";
    this->weight = 200; // todo: change it to the correct value
    this->currentHP = Wolf::maxHP;
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
