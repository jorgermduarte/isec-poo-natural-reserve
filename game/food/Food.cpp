//
// Created by duarte on 10-11-2022.
//

#include "Food.h"

void Food::incrementLifeTick() {

}


void Food::isFoodAvailable() {

}

void Food::defineRandomPosition(int maxRow, int maxLine) {
    int row = rand() % (maxRow);
    int col = rand() % (maxLine);
    this->position.row = row;
    this->position.column = col;
}