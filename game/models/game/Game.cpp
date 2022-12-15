//
// Created by duarte on 11-11-2022.
//
#include <iostream>
#include "Game.h"

int Game::matrixGetNumRows() {
    return this->matrix.size();
}

int Game::matrixGetNumColumns() {
    if(this->matrixGetNumRows() > 0){
        return this->matrix[0].size();
    }
    return 0;
}

void Game::addAnimalToTheList(Animal *animal) {
    Node<Animal> *newAnimalList = new Node<Animal>(animal);
    if(this->animals == NULL) {
        this->animals = newAnimalList;
    }else{
        Node<Animal> *tail = this->animals->getTail();
        tail->next = newAnimalList;
        newAnimalList->prev = tail;
    }
}

void Game::addAnimalToTheMatrix(Animal *animal) {
    Node<Animal> *newAnimalMatrixCell = new Node<Animal>(animal);
    if ( this->matrix[animal->position.column][animal->position.row].animals == NULL) {
        this->matrix[animal->position.column][animal->position.row].animals = newAnimalMatrixCell;
    } else {
        Node<Animal> *tail = this->matrix[animal->position.column][animal->position.row].animals->getTail();
        tail->next = newAnimalMatrixCell;
        newAnimalMatrixCell->prev = tail;
    }
}

void Game::addAnimal(Animal* animal) {
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

void Game::addFoodToTheList(Food *food) {
    Node<Food> *newFoodList = new Node<Food>(food);

    if(this->foods == NULL) {
        this->foods = newFoodList;
    }else{
        Node<Food> *tail = this->foods->getTail();
        tail->next = newFoodList;
        newFoodList->prev = tail;
    }
}

void Game::addFoodToTheMatrix(Food *food) {
    Node<Food> *newFoodMatrixCell = new Node<Food>(food);

    if ( this->matrix[food->position.column][food->position.row].foods == NULL) {
        this->matrix[food->position.column][food->position.row].foods = newFoodMatrixCell;
        //std::cout << "     > Food added to matrix cell - empty list" << std::endl;
    } else {
        Node<Food> *tail = this->matrix[food->position.column][food->position.row].foods->getTail();
        tail->next = newFoodMatrixCell;
        newFoodMatrixCell->prev = tail;
    }
}

void Game::addFood(Food* food) {

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

void Game::displayAnimals() {
    Node<Animal> *current = this->animals;
    while(current != NULL){
        current->value->display();
        current = current->next;
    }
}

void Game::displayFoods() {
    Node<Food> *current = this->foods;
    while(current != NULL){
        current->value->display();
        current = current->next;
    }
}

Node<Food>* Game::findFoodNode(int id) {
    Node<Food> *current = this->foods;
    while(current != NULL){
        if(current->value->id == id){
            break;
        }
        current = current->next;
    }
    return current;
}

Node<Animal>* Game::findAnimalNode(int id) {
    Node<Animal> *current = this->animals;
    while(current != NULL){
        if(current->value->id == id){
            return current;
        }
        current = current->next;
    }
    return NULL;
}


std::vector<MatrixCell> Game::getMatrixCellsByArea(int radius, Position position) {
    std::vector<MatrixCell> neighbors;

    for (int i = position.column - radius; i <= position.column + radius; i++) {
        for (int j = position.row - radius; j <= position.row + radius; j++) {
            int x = i;
            int y = j;
            if (x < 0) {
                x = this->configuration.size.cols + x;
            }
            if (y < 0) {
                y = this->configuration.size.rows + y;
            }
            if (x >= this->configuration.size.cols) {
                x = x - this->configuration.size.cols;
            }
            if (y >= this->configuration.size.rows) {
                y = y - this->configuration.size.rows;
            }
            //if( x != position.column || y != position.row) {
                //std::cout << " Cell on radius provided: column: " << std::to_string(x) << " line:" << std::to_string(y) << std::endl;
                neighbors.push_back(this->matrix[x][y]);
            //}
        }
    }

    return neighbors;
}
