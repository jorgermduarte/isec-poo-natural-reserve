//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_MATRIXCELL_H
#define POO_NATURAL_RESERVE_MATRIXCELL_H


#include "../Position.h"
#include "../food/Food.h"
#include "../animal/Animal.h"

class MatrixCell {
public:
    Position position = {0,0};
    std::list<Animal> animals = {};
    std::list<Food> foods = {};
    MatrixCell(int col, int line);
};


#endif //POO_NATURAL_RESERVE_MATRIXCELL_H
