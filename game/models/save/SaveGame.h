//
// Created by duarte on 09-12-2022.
//

#ifndef POO_NATURAL_RESERVE_SAVEGAME_H
#define POO_NATURAL_RESERVE_SAVEGAME_H

#include "../animal/Animal.h"
#include "../food/Food.h"
#include <vector>
#include "../game/MatrixCell.h"
#include "../game/MatrixSize.h"
#include "../../utils/Node.h"

class SaveGame{
private:
    std::string name;
public:
    std::vector<std::vector<MatrixCell>> matrix = {};
    Node<Animal> *animals = NULL;
    Node<Food> *foods = NULL;

    void addAnimal(Animal* animal);
    void addFood(Food* food);
    Node<Food>* findFoodNode(int id);
    Node<Animal>* findAnimalNode(int id);

    std::string getSaveGameName();
    void setSaveGameName(std::string saveGame);
    void saveAnimals(Node<Animal> *animals);
    void saveFoods(Node<Food> *foods);
    void initializeMatrix(std::vector<std::vector<MatrixCell>> matrix,MatrixSize *matrixSize);
};


#endif //POO_NATURAL_RESERVE_SAVEGAME_H
