//
// Created by duarte on 10-11-2022.
//

#include "Animal.h"
int Animal::maxHP = 0;

Animal::Animal() {
    this->id = Entity::defineNewId();
}

int Animal::getCurrentHP() {
    return this->currentHP;
}

void Animal::setCurrentHP(int value) {
    this->currentHP = value;
}

void Animal::setPosition(int row, int column) {
    this->position.column = column;
    this->position.row = row;
}

void Animal::defineRandomPosition(int maxRow,int maxLine) {
    int row = rand() % (maxRow);
    int col = rand() % (maxLine);
    this->position.row = row;
    this->position.column = col;
}

void Animal::feedAnimal() {

}

void Animal::move() {

}

void Animal::perceive() {

}

void Animal::reproduce() {

}

void Animal::triggerInstant() {

}