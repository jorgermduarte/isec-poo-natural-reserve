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
#include "../save/SaveGame.h"

class Game {
public:
    std::vector<std::vector<MatrixCell>> matrix = {};
    Node<Animal> *animals = NULL;
    Node<Food> *foods = NULL;
    GameConfiguration configuration;
    std::vector<SaveGame*> savedGames = {};

    int matrixGetNumRows();
    int matrixGetNumColumns();
    void addAnimal(Animal* animal);
    void addFood(Food* food);
    Node<Food>* findFoodNode(int id);
    Node<Animal>* findAnimalNode(int id);

    void addAnimalToTheMatrix(Animal* animal);
    void addAnimalToTheList(Animal* animal);
    void addFoodToTheMatrix(Food* food);
    void addFoodToTheList(Food* food);

    void displayAnimals();
    void displayFoods();
    std::vector<MatrixCell> getMatrixCellsByArea(int i, Position position);
};

#endif //POO_NATURAL_RESERVE_GAME_H
