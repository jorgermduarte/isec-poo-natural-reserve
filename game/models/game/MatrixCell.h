//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_MATRIXCELL_H
#define POO_NATURAL_RESERVE_MATRIXCELL_H

#include "../Position.h"
#include "../food/Food.h"
#include "../animal/Animal.h"
#include "../../utils/Node.h"

class MatrixCell {
public:
    Position position = {0,0};
    Node<Animal> *animals = NULL;
    Node<Food> *foods = NULL;
    MatrixCell(int col, int line);
};

#endif //POO_NATURAL_RESERVE_MATRIXCELL_H
