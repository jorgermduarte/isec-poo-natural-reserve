//
// Created by duarte on 07-12-2022.
//

#include "Fox.h"
int Fox::configMaxHP = 0;

Fox::Fox() {
    this->identifierEmoji = "\U0001f98a";
    this->weight =  20 + (rand() % 25 + 1);
    this->currentHP = Fox::configMaxHP;
    this->maxHP = currentHP;
    this->identifier = 'm';
}

void Fox::reproduce() {
}

void Fox::triggerInstant() {

}

void Fox::perceive() {

}

void Fox::move() {

}
