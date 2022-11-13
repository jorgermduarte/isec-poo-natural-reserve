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

void GameConfiguration::moveScreenDisplayPosition(std::string direction, std::string target) {
    if(direction == "up"){
        if(target == "columns"){
            if(this->screenPosition.row > 0){
                this->screenPosition.row--;
            }
        }
        if(target == "lines"){
            if(this->screenPosition.row > 0){
                this->screenPosition.row--;
            }
        }
    }
    else if(direction == "down"){
        int total = ((this->size.rows) * 0.8) + this->screenPosition.row + 1;
        if(target == "columns"){
            if(this->screenPosition.row >= 0 && total <= this->size.rows){
                this->screenPosition.row++;
            }
        }
        if(target == "lines"){
            if(this->screenPosition.row >= 0 && total <= this->size.rows){
                this->screenPosition.row++;
            }
        }
    }
    else if(direction == "left"){
        if(target == "columns"){
            if(this->screenPosition.column > 0){
                this->screenPosition.column--;
            }
        }
        if(target == "lines"){
            if(this->screenPosition.column > 0 ){
                this->screenPosition.column--;
            }
        }
    }
    else if(direction == "right"){
        int total = ((this->size.cols) * 0.8) + this->screenPosition.column + 1;
        if(target == "columns"){
            if(this->screenPosition.column >= 0 && total <= this->size.cols){
                this->screenPosition.column++;
            }
        }
        if(target == "lines"){
            if(this->screenPosition.column >= 0 && total <= this->size.cols){
                this->screenPosition.column++;
            }
        }
    }

    std::cout << "   > Current configuration: cols->" + std::to_string(this->screenPosition.column) + " lines->" +
            std::to_string(this->screenPosition.row) << std::endl;
}