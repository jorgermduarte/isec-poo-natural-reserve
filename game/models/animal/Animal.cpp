//
// Created by duarte on 10-11-2022.
//

#include <iostream>
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

void Animal::definePosition(int row, int line) {
    this->position.row = row;
    this->position.column = line;
}


void Animal::displayPosition() {
    std::cout << "Animal position: L->" << this->position.row << " C->" << this->position.column << std::endl;
}

void Animal::display() {
    std::cout << "[" + std::to_string(this->id)+ "] [" + std::to_string(this->position.row) + std::to_string(this->position.column) + "] " + this->identifierEmoji + " HP: " + std::to_string(this->currentHP) << std::endl;
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

