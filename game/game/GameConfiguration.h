//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_GAMECONFIGURATION_H
#define POO_NATURAL_RESERVE_GAMECONFIGURATION_H

#include "MatrixSize.h"
#include "../Position.h"

class GameConfiguration {
public:
    Position screenPosition = { 0,0 };
    MatrixSize size = { 0 ,0 };
    void setMatrixSize(int height, int length);
    void displayMatrixSize();
};


#endif //POO_NATURAL_RESERVE_GAMECONFIGURATION_H
