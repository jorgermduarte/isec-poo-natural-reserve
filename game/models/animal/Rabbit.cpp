//
// Created by duarte on 10-11-2022.
//
#include <iostream>
#include "Rabbit.h"
#include "../enums/Smell.h"
#include "../../commands/NoFoodCommand.h"
#include "../../commands/KillCommand.h"

int Rabbit::configMaxHP = 0;
int Rabbit::configMaxIterations = 0;

Rabbit::Rabbit() {
    this->identifierEmoji = "\U0001f407";
    this->weight =  1 + (rand() % 4 + 1);
    this->currentHP = Rabbit::configMaxHP;
    this->maxIterations = Rabbit::configMaxIterations;
    this->maxHP = currentHP;
    this->identifier = 'C';
}

void Rabbit::reproduce(Game* game) {
    if(this->reprodutionCounter >= 8){
        int random = rand() % 100 + 1;
        if(random > 50){
            Position position = this->position;

            position.row = position.row + (rand() % 10 + 1);
            position.column = position.column + (rand() % 10 + 1);

            if(position.row >= game->configuration.size.rows){
                position.row = game->configuration.size.rows -1;
            }
            if(position.column >= game->configuration.size.cols){
                position.column = game->configuration.size.cols -1;
            }

            Rabbit* rabbit = new Rabbit();
            rabbit->setPosition(position.row,position.column);
            game->addAnimal(rabbit);
        }

        //reset counter
        this->reprodutionCounter = 0;
    }

}

void Rabbit::fight(Game* game,Animal *animal) {
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    int radius = 0;
    if(this->hunger  < 10){
        radius = 1 + (rand() % 2 + 1);
    }else if(this->hunger  < 20){
        radius =  1 + (rand() % 3 + 1);
    }else{
        radius =  1 + (rand() % 4 + 1);
    }

    std::vector<MatrixCell> cells = game->getMatrixCellsByArea(radius, this->position );
    std::vector<MatrixCell> escapeCells = std::vector<MatrixCell>();
    for (MatrixCell cell : cells) {
        if(cell.position.row == this->position.row || cell.position.column == this->position.column){
            if(cell.position.row != this->position.row || cell.position.column != this->position.column){
                escapeCells.push_back(cell);
            }
        }
    }

    // based on the possible escape cells assuming that there coming from a 2d matrix (torus)
    // we can calculate the distance from the position on the escape cell to the position of the animal
    // the matrix is a torus, so we can calculate the distance in 2 ways
    // 1 - if the distance is less than the half of the matrix size we can calculate the distance
    // 2 - if the distance is greater than the half of the matrix size we can calculate the distance by subtracting the distance from the matrix size
    // the distance is calculated by the formula abs(x1 - x2) + abs(y1 - y2)
    // where x1 and y1 are the position of the animal and x2 and y2 are the position of the escape cell
    // the cell with the highest distance is the one that the rabbit will escape
    // if there is more than one cell with the same distance the rabbit will escape to the first one
    int maxDistance = 0;
    MatrixCell escapeCell = escapeCells[0];
    for (MatrixCell cell : escapeCells) {
        int distance = 0;
        if(abs(cell.position.row - animal->position.row) > game->configuration.size.rows/2){
            distance = game->configuration.size.rows - abs(cell.position.row - animal->position.row);
        }else{
            distance = abs(cell.position.row - animal->position.row);
        }

        if(abs(cell.position.column - animal->position.column) > game->configuration.size.cols/2){
            distance = distance + (game->configuration.size.cols - abs(cell.position.column - animal->position.column));
        }else{
            distance = distance + abs(cell.position.column - animal->position.column);
        }

        if(distance > maxDistance){
            maxDistance = distance;
            escapeCell = cell;
        }
    }

    //set the new position
    this->position = escapeCell.position;

    std::cout << "          > The " <<  this->identifierEmoji << " is trying to avoid the " << animal->identifierEmoji << "  with id: " << animal->id  << " [Radius: "<< std::to_string(radius) << "]moving the rabbit to [" <<  std::to_string(this->position.row) << std::to_string(this->position.column) <<  "]"  << std::endl;
    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);

}

void Rabbit::move(Game* game,Position position) {
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    //calculate distances
    int radius = 0;
    if(this->hunger  < 10){
        radius = 1 + (rand() % 2 + 1);
    }else if(this->hunger  < 20){
        radius =  1 + (rand() % 3 + 1);
    }else{
        radius =  1 + (rand() % 4 + 1);
    }

    std::vector<MatrixCell> possible = game->getMatrixCellsByArea(radius, this->position );
    std::vector<MatrixCell> filteredCells = std::vector<MatrixCell>();
    for (MatrixCell cell : possible) {
        if(cell.position.row == this->position.row || cell.position.column == this->position.column){
            if(cell.position.row != this->position.row || cell.position.column != this->position.column){
                filteredCells.push_back(cell);
            }
        }
    }

    // find the closer cell to the position passed as parameter
    // assume that there is at least one cell in the vector filteredCells
    // assume that there is always one cell closer to the position passed as parameter
    // assume that the position passed as parameter is not always in the filteredCells vector
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

    std::cout << "     > Rabbit position updated [not random] : [Radius:" << std::to_string(radius) <<  "] ";
    this->display();
    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);
}

//random move
void Rabbit::move(Game* game) {
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    int radius = 0;

    if(this->hunger  < 10){
        radius = 1 + (rand() % 2 + 1);
    }else if(this->hunger  < 20){
        radius =  1 + (rand() % 3 + 1);
    }else{
        radius =  1 + (rand() % 4 + 1);
    }
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

        std::cout << "          > Rabbit position updated [random][Radius:" + std::to_string(radius) + "]: ";
        this->display();
    }

    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);
}

void Rabbit::eat(Game* game,Food *food) {
    Animal::feed(food->nutritiveValue,food->toxicity);
    this->hunger -= food->nutritiveValue;
    if(this->hunger < 0)
        this->hunger = 0;
    NoFoodCommand::deleteFoodById(game,food->id);
}

void Rabbit::verifications(Game* game) {
    this->reproduce(game);

    this->currentIterations++;
    this->reprodutionCounter++;
    this->hunger++;

    if(this->hunger < 20){
        this->currentHP--;
    }else{
        this->currentHP -= 2;
    }

    if (this->currentIterations >= this->maxIterations){
        this->currentHP = 0;

    }

    if(this->currentHP <= 0){
        //remove the rabbit from the matrix
        KillCommand::deleteAnimalFromMatrix(game,this->id);
    }
}

void Rabbit::do_iteration(Game* game) {
    std::cout << "      > Rabbit iteration: ";
    this->display();

    // - get cells by area ( 4 positions around )
    std::vector<MatrixCell> cells = game->getMatrixCellsByArea(4, this->position);
    std::vector<Animal*> predators = {};
    std::vector<Food*> foods = {};
    bool foodInCurrentPosition = false;

    // iterate each cell to find a predator or food
    for (const auto &item: cells){

        if(item.animals != NULL){
            Node<Animal> *current = item.animals;
            while (current != NULL){
                if(current->value->weight > 10){
                    std::cout << "          > Rabbit detected a predator: ";
                    current->value->display();
                    predators.push_back(current->value);
                    break;
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
                    if(cSmell == Smell::ENUM_Grass){
                        smellsDetected.push_back(cSmell);
                        std::cout << "          > Rabbit detected a smell: ";
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
        //escape the predator
        this->fight(game,predators[0]);
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

    this->verifications(game);
}