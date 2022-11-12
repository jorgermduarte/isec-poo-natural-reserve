//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_GAME_H
#define POO_NATURAL_RESERVE_GAME_H

#include <vector>
#include "../animal/Animal.h"
#include "../food/Food.h"
#include "MatrixCell.h"
#include "GameConfiguration.h"

class Game {
private:
    static int uniqueIdentifier;
public:
    // the matrix is used for we know the positions of the animals and food on the natural reserve
    // that's why the MatrixCell lists only contain the pointers
    std::vector<std::vector<MatrixCell>> matrix = {};
    std::list<Animal> animals = {};
    std::list<Food> foods = {};
    int matrixGetNumRows();
    int matrixGetNumColumns();
    GameConfiguration configuration;

    void addAnimal(Animal animal);
    void addFood(Food food);
};

#endif //POO_NATURAL_RESERVE_GAME_H
