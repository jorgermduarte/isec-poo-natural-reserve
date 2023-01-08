//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_GAMECONFIGURATION_H
#define POO_NATURAL_RESERVE_GAMECONFIGURATION_H

#include "MatrixSize.h"
#include "../Position.h"

const static double DISPLAY_AREA_PERCENTAGE = 0.8;
const static double MAX_ARGUMENTS_SIZE = 5;

class GameConfiguration {
public:
    Position screenPosition = { 0,0 };
    MatrixSize size = { 0 ,0 };
    void setMatrixSize(int height, int length);
    void displayMatrixSize();
    void moveScreenDisplayPosition(std::string direction, int target);
};


#endif //POO_NATURAL_RESERVE_GAMECONFIGURATION_H
