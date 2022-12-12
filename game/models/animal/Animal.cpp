//
// Created by duarte on 10-11-2022.
//

#include <iostream>
#include "Animal.h"
int Animal::configMaxHP = 0;
int Animal::configMaxIterations = 0;

Animal::Animal() {
    this->id = Entity::defineNewId();
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

    std::cout << " > Animal " << this->id << " is being placed in the position: line: " << row << " col:" << col << std::endl;

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
    std::cout << "[" + std::to_string(this->id)+ "] [" + std::to_string(this->position.row) + std::to_string(this->position.column) + "] " + this->identifierEmoji + + " MHP: " +
            std::to_string(this->maxHP) + " CHP: " + std::to_string(this->currentHP) + " Weight: " + std::to_string(this->weight) + " IC: " +
            std::to_string(this->currentIterations) + " IM: " + std::to_string(this->maxIterations) << std::endl;
}

void Animal::feed(int nutritivePoints, int toxicityPoints) {
    this->currentHP -= toxicityPoints;
    this->currentHP += nutritivePoints;

    if(this->currentHP > Animal::maxHP){
        this->currentHP = Animal::maxHP;
    }

    if(this->currentHP < 0){
        this->currentHP = 0;
    }
}

void Animal::do_iteration() {}
void Animal::move() {}
void Animal::move(Position position) {}
void Animal::reproduce() {}
void Animal::eat( Food *food) {}
void Animal::fight( Animal *animal) {}
void Animal::verifications() {}
