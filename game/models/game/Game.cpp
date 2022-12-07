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

void Game::addAnimal(Animal* animal) {
    Node<Animal> *newAnimal = new Node<Animal>(animal);

    if(this->animals == NULL) {
        this->animals = newAnimal;
    }else{
        Node<Animal> *tail = this->animals->getTail();
        tail->next = newAnimal;
    }

    if ( this->matrix[animal->position.column][animal->position.row].animals == NULL) {
        this->matrix[animal->position.column][animal->position.row].animals = newAnimal;
    } else {
       this->matrix[animal->position.column][animal->position.row].animals->next = newAnimal;
    }
}

void Game::addFood(Food* food) {
    Node<Food> *newFood = new Node<Food>(food);

    if(this->foods == NULL) {
        this->foods = newFood;
    }else{
        Node<Food> *tail = this->foods->getTail();
        tail->next = newFood;
    }
    if ( this->matrix[food->position.column][food->position.row].foods == NULL) {
        this->matrix[food->position.column][food->position.row].foods = newFood;
    } else {
        this->matrix[food->position.column][food->position.row].foods->next = newFood;
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