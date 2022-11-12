//
// Created by duarte on 11-11-2022.
//

#include <iostream>
#include "GameConfiguration.h"

void GameConfiguration::setMatrixSize(int height, int length) {
    this->size.cols = length;
    this->size.rows = height;
}

void GameConfiguration::displayMatrixSize() {
    std::cout << "Defined configurations -> [length(cols)]:" + std::to_string(this->size.cols) + " [height(rows)]: " + std::to_string(this->size.rows) << std::endl;
}