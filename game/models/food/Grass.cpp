//
// Created by duarte on 10-11-2022.
//

#include <iostream>
#include "Grass.h"
#include "../enums/Smell.h"
#include "../../commands/NoFoodCommand.h"

int Grass::configMaxIterations = 0;

Grass::Grass() {
    this->nutritiveValue = 3;
    this->maxIterations = Grass::configMaxIterations;
    this->toxicity = 0;
    this->smells.push_back(ENUM_Grass);
    this->smells.push_back(ENUM_Vegetables);
    this->identifierEmoji = "\U0001f33f";
    this->identifier = 'r';
    this->position = { 0,0 };
    this->currentIterations = 0;
}

void Grass::reproduce(Game* game) {
    bool shouldReproduce = false;

    if(this->currentIterations >= this->maxIterations * 0.50){
        shouldReproduce = true;
    }

    if(shouldReproduce) {
        int direction = 4 + rand() % 5;
        int distance = rand() % 5 + 4;
        int newGrassRow = this->position.row;
        int newGrassColumn = this->position.column;

        switch (direction) {
            case 1:
                newGrassRow -= distance;
                newGrassColumn -= distance;
                break;
            case 2:
                newGrassRow -= distance;
                break;
            case 3:
                newGrassRow -= distance;
                newGrassColumn += distance;
                break;
            case 4:
                newGrassColumn -= distance;
                break;
            case 5:
                newGrassColumn += distance;
                break;
            case 6:
                newGrassRow += distance;
                newGrassColumn -= distance;
                break;
            case 7:
                newGrassRow += distance;
                break;
            case 8:
                newGrassRow += distance;
                newGrassColumn += distance;
                break;
        }

        if (newGrassRow < 0) {
            newGrassRow = 0;
        }

        if (newGrassColumn < 0) {
            newGrassColumn = 0;
        }

        if (newGrassRow >= game->configuration.size.rows || newGrassColumn >= game->configuration.size.cols) {
           return;
        }

        if (newGrassRow == this->position.row && newGrassColumn == this->position.column) {
            return;
        }

        Position newPosition = {newGrassRow, newGrassColumn};
        if (game->matrix[newGrassRow][newGrassColumn].foods == NULL) {
            Grass *newGrass = new Grass();
            newGrass->position = newPosition;
            game->addFood(newGrass);
        }
    }
}

void Grass::verifications(Game* game) {
    this->currentIterations += 1;
    if(this->currentIterations >= this->maxIterations){
        NoFoodCommand::deleteFoodFromMatrix(game, this->id);
    }
}

void Grass::do_iteration(Game* game) {
    std::cout << "      > Grass iteration: ";
    Food::display();
    this->reproduce(game);
    this->verifications(game);

}