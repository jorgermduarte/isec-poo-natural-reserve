//
// Created by duarte on 10-11-2022.
//
#include "Rabbit.h"
int Rabbit::maxHP = 0;

Rabbit::Rabbit() {
    this->identifier = "\U0001f407";
    this->weight = rand() % 4 + 1;
    this->currentHP = Rabbit::maxHP;
}

void Rabbit::reproduce() {
}

void Rabbit::triggerInstant() {

}

void Rabbit::perceive() {

}

void Rabbit::move() {

}
