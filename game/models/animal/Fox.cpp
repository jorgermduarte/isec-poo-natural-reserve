//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Fox.h"
#include "../game/MatrixCell.h"
#include "../game/Game.h"
#include "../enums/Smell.h"
#include "../../commands/NoFoodCommand.h"
#include "../../commands/KillCommand.h"

int Fox::configMaxHP = 0;
int Fox::configMaxIterations = 0;

Fox::Fox() {
    this->identifierEmoji = "\U0001f98a";
    this->weight =  10 + (rand() % 15 + 1);
    this->currentHP = Fox::configMaxHP;
    this->maxIterations = Fox::configMaxIterations;
    this->maxHP = currentHP;
    this->identifier = 'm';
}

void Fox::reproduce(Game* game) {
    if(this->reprodutionCounter >= 15){
        int random = rand() % 100 + 1;
        if(random < 40){
            Position position = this->position;

            position.row = position.row + (rand() % 10 + 1);
            position.column = position.column + (rand() % 10 + 1);

            if(position.row >= game->configuration.size.rows){
                position.row = game->configuration.size.rows -1;
            }
            if(position.column >= game->configuration.size.cols){
                position.column = game->configuration.size.cols -1;
            }

            Fox* fox = new Fox();
            fox->setPosition(position.row,position.column);
            game->addAnimal(fox);
        }

        //reset counter
        this->reprodutionCounter = 0;
    }

}

void Fox::eat(Game* game,Food *food) {
    Animal::feed(food->nutritiveValue,food->toxicity);
    this->hunger -= food->nutritiveValue;
    if(this->hunger < 0)
        this->hunger = 0;
    NoFoodCommand::deleteFoodById(game,food->id);
}

void Fox::verifications(Game* game) {

    this->currentIterations++;
    this->reprodutionCounter++;
    this->hunger++;

    if(this->hunger > 10){
        this->currentHP -= 1;
    }
    if (this->currentIterations >= this->maxIterations){
        this->currentHP = 0;

    }

    if(this->currentHP <= 0){
        //remove the fox from the matrix
        KillCommand::deleteAnimalFromMatrix(game,this->id);
    }
}

void Fox::move(Game* game) {
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    int radius = 3;

    // get the perceptions based on radius ( all rabbit movements allowed in the matrix based on the radius)
    std::vector<MatrixCell> cells = game->getMatrixCellsByArea(radius, this->position );

    // filter the cells with only cells that have the same column or row
    // the rabbit can not move diagonally 'so' we need to filter the cells
    // the rabbit can not move to the same position
    std::vector<MatrixCell> filteredCells = std::vector<MatrixCell>();
    for (MatrixCell cell : cells) {
        if(cell.position.row == this->position.row || cell.position.column == this->position.column){
            if(cell.position.row != this->position.row || cell.position.column != this->position.column){
                filteredCells.push_back(cell);
            }
        }
    }

    //get a random cell from the filtered cells
    if(filteredCells.size() > 0){
        int random = rand() % filteredCells.size();
        this->position.row = filteredCells[random].position.row;
        this->position.column = filteredCells[random].position.column;

        std::cout << "          > Fox position updated [random][Radius:" + std::to_string(radius) + "]: ";
        this->display();
    }

    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);
}

void Fox::move(Game* game,Position position) {
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    //calculate distances
    int radius = 3;

    std::vector<MatrixCell> possible = game->getMatrixCellsByArea(radius, this->position );
    std::vector<MatrixCell> filteredCells = std::vector<MatrixCell>();
    for (MatrixCell cell : possible) {
        if(cell.position.row == this->position.row || cell.position.column == this->position.column){
            if(cell.position.row != this->position.row || cell.position.column != this->position.column){
                filteredCells.push_back(cell);
            }
        }
    }

    MatrixCell closerCell = filteredCells[0];

    for (MatrixCell cell : filteredCells) {
        if(cell.position.row == position.row && cell.position.column == position.column){
            closerCell = cell;
            break;
        }
        if(cell.position.row == position.row){
            if(cell.position.column < position.column){
                if(closerCell.position.column < cell.position.column){
                    closerCell = cell;
                }
            }else{
                if(closerCell.position.column > cell.position.column){
                    closerCell = cell;
                }
            }
        }else if(cell.position.column == position.column){
            if(cell.position.row < position.row){
                if(closerCell.position.row < cell.position.row){
                    closerCell = cell;
                }
            }else{
                if(closerCell.position.row > cell.position.row){
                    closerCell = cell;
                }
            }
        }
    }

    //set the new position
    this->position = closerCell.position;

    std::cout << "     > Fox position updated [not random] : [Radius:" << std::to_string(radius) <<  "] ";
    this->display();
    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);
}

void Fox::fight(Game* game,Animal *animal) {

}

void Fox::do_iteration(Game* game) {
    std::cout << "      > Fox iteration: ";
    Animal::display();

    std::vector<MatrixCell> cells = game->getMatrixCellsByArea(6, this->position);


    std::vector<Animal*> predators = {};
    std::vector<Food*> foods = {};
    bool foodInCurrentPosition = false;

    // iterate each cell to find a predator or food
    for (const auto &item: cells){

        if(item.animals != NULL){
            Node<Animal> *current = item.animals;
            while (current != NULL){
                if(current->value->id != this->id){
                    std::cout << "          > Fox detected another animal: ";
                    current->value->display();
                    predators.push_back(current->value);
                }
                current = current->next;
            }
        }

        if(item.foods != NULL){
            Node<Food> *current = item.foods;
            while (current != NULL){
                //verify if the food type is grass
                std::vector<int> smellsDetected = {};
                for (int cSmell : current->value->smells) {
                    if(cSmell == Smell::ENUM_Vegetables){
                        smellsDetected.push_back(cSmell);
                        std::cout << "          > Fox detected a smell: ";
                        current->value->display();
                        foods.push_back(current->value);
                        if(this->position.row == current->value->position.row && this->position.column == current->value->position.column){
                            foodInCurrentPosition = true;
                        }
                    }
                }
                current = current->next;
            }
        }

    }

    if(predators.size() > 0){
        // gets scared and moves randomly
        this->move(game);
    }else{

        if(foods.size() > 0) {
            //eat the food
            if (foodInCurrentPosition) {
                this->eat(game,foods[0]);
            } else {
                //move to the food
                this->move(game,foods[0]->position);
            }
        }else{
            //if he does not perceive food or predator moves randomly
            this->move(game);
        }
    }

    this->reproduce(game);
    this->verifications(game);
}