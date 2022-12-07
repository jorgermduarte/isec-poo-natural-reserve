//
// Created by duarte on 07-12-2022.
//

#include "Kangaroo.h"
int Kangaroo::maxHP = 0;

Kangaroo::Kangaroo() {
    this->identifierEmoji = "\U0001f998";
    this->weight = 200; // todo: change it to the correct value
    this->currentHP = Kangaroo::maxHP;
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