//
// Created by duarte on 09-12-2022.
//
#include "SaveGame.h"
#include <iostream>

Node<Food>* SaveGame::findFoodNode(int id) {
    Node<Food> *current = this->foods;
    while(current != NULL){
        if(current->value->id == id){
            break;
        }
        current = current->next;
    }
    return current;
}

Node<Animal>* SaveGame::findAnimalNode(int id) {
    Node<Animal> *current = this->animals;
    while(current != NULL){
        if(current->value->id == id){
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void SaveGame::addAnimal(Animal* animal) {
    Node<Animal> *newAnimalList = new Node<Animal>(animal);
    Node<Animal> *newAnimalMatrixCell = new Node<Animal>(animal);

    if(this->animals == NULL) {
        this->animals = newAnimalList;
    }else{
        Node<Animal> *tail = this->animals->getTail();
        tail->next = newAnimalList;
        newAnimalList->prev = tail;
    }

    if ( this->matrix[animal->position.column][animal->position.row].animals == NULL) {
        this->matrix[animal->position.column][animal->position.row].animals = newAnimalMatrixCell;
    } else {
        Node<Animal> *tail = this->matrix[animal->position.column][animal->position.row].animals->getTail();
        tail->next = newAnimalMatrixCell;
        newAnimalMatrixCell->prev = tail;
    }
}

void SaveGame::addFood(Food* food) {

    Node<Food> *newFoodList = new Node<Food>(food);
    Node<Food> *newFoodMatrixCell = new Node<Food>(food);

    if(this->foods == NULL) {
        this->foods = newFoodList;
    }else{
        Node<Food> *tail = this->foods->getTail();
        tail->next = newFoodList;
        newFoodList->prev = tail;
    }

    if ( this->matrix[food->position.column][food->position.row].foods == NULL) {
        this->matrix[food->position.column][food->position.row].foods = newFoodMatrixCell;
        //std::cout << "     > Food added to matrix cell - empty list" << std::endl;
    } else {
        Node<Food> *tail = this->matrix[food->position.column][food->position.row].foods->getTail();
        tail->next = newFoodMatrixCell;
        newFoodMatrixCell->prev = tail;
    }
}

void SaveGame::setSaveGameName(std::string saveName) {
    this->name = saveName;
}

std::string SaveGame::getSaveGameName() {
    return this->name;
}

void SaveGame::saveAnimals(Node<Animal> *animals) {
    while(animals != NULL){
        if(animals->value != NULL){
            Animal* animal = new Animal();
            *animal = *animals->value;

            this->addAnimal(animal);
            animals = animals->next;
        }
    }
}

void SaveGame::saveFoods(Node<Food> *foods) {
    while(foods != NULL){
        if(foods->value != NULL){
            Food* food = new Food();
            *food = *foods->value;

            this->addFood(food);
            foods = foods->next;
        }
    }
}

void SaveGame::initializeMatrix(std::vector<std::vector<MatrixCell>> matrix,MatrixSize *matrixSize){
    int x,y;
    for( x = 0; x < matrixSize->cols; x++){
        std::vector<MatrixCell> col = {};
        for(y = 0; y < matrixSize->rows; y++){
            col.push_back(MatrixCell(x,y));
        }
        this->matrix.push_back(col);
    }
}
