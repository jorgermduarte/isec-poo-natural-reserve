//
// Created by duarte on 07-12-2022.
//

#include "Fox.h"
int Fox::maxHP = 0;

Fox::Fox() {
    this->identifierEmoji = "\U0001f98a";
    this->weight = rand() % 4 + 1;
    this->currentHP = Fox::maxHP;
    this->identifier = 'f';
}

void Fox::reproduce() {
}

void Fox::triggerInstant() {

}

void Fox::perceive() {

}

void Fox::move() {

}
