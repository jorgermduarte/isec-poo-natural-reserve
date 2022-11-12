//
// Created by duarte on 10-11-2022.
//

#include "Animal.h"

Animal::Animal() {

}

void Animal::feedAnimal() {

}

void Animal::move() {

}

void Animal::perceive() {

}

void Animal::triggerInstant() {

}

void Animal::reproduce() {

}

int Animal::getCurrentLifetime() {
    return this->currentLifetime;
}

void Animal::defineRandomPosition(int maxRow,int maxLine) {
    int row = rand() % (maxRow);
    int col = rand() % (maxLine);
    this->position.row = row;
    this->position.column = col;
}