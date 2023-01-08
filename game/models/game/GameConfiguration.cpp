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

void GameConfiguration::moveScreenDisplayPosition(std::string direction, int target) {
    if(direction == "up"){
        if(this->screenPosition.row > 0){
            this->screenPosition.row -= target;
            if(this->screenPosition.row < 0){
                this->screenPosition.row = 0;
            }
        }
    }
    else if(direction == "down"){
        int total = ((this->size.rows) * 0.8) + this->screenPosition.row + target;

        if(this->screenPosition.row >= 0 && total <= this->size.rows){
            this->screenPosition.row += target;
            if(this->screenPosition.row >= this->size.rows){
                this->screenPosition.row = this->size.rows -1;
            }
        }
    }

    else if(direction == "left") {
        if (this->screenPosition.column > 0) {
            this->screenPosition.column -= target;
            if (this->screenPosition.column < 0) {
                this->screenPosition.column = 0;
            }
        }
    }
    else if(direction == "right"){
        int total = ((this->size.cols) * 0.8) + this->screenPosition.column + target;
        if(this->screenPosition.column >= 0 && total <= this->size.cols){
            this->screenPosition.column += target;
            if( this->screenPosition.column >= this->size.cols){
                this->screenPosition.column = this->size.cols -1;
            }
        }
    }

    std::cout << "   > Current configuration: cols->" + std::to_string(this->screenPosition.column) + " lines->" +
            std::to_string(this->screenPosition.row) << std::endl;
}