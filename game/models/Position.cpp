//
// Created by duarte on 10-11-2022.
//

#include "Position.h"

Position::Position(int col, int row) {
    this->column = col;
    this->row = row;
}

void Position::setX(int col) {
    this->column = col;
}

int Position::getX() {
    return this->column;
}

void Position::setY(int row) {
    this->row = row;
}

int Position::getY() {
    return this->row;
}
