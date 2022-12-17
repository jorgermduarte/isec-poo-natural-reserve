//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Kangaroo.h"
#include "../game/MatrixCell.h"
#include "../game/Game.h"
#include "../food/Body.h"
#include "../../commands/KillCommand.h"
#include "../../commands/InfoCommand.h"

int Kangaroo::configMaxHP = 0;
int Kangaroo::configMaxIterations = 0;

Kangaroo::Kangaroo() {
    this->identifierEmoji = "\U0001f998";
    this->weight = 10;
    this->currentHP = Kangaroo::configMaxHP;
    this->maxIterations = Kangaroo::configMaxIterations;
    this->maxHP = currentHP;
    this->identifier = 'G';
}

void Kangaroo::reproduce(Game* game) {
    // Faz nascer outro Canguru a cada 30 instantes. O novo Canguru aparece a uma distância igual
    //ou inferior a 3 (linha e coluna).
    if (this->currentIterations > 10 && this->currentIterations % 30 == 0) {
        std::cout << "              > Kangaroo is reproducing" << std::endl;
        std::vector<MatrixCell> cells = game->getMatrixCellsByArea(3, this->position );
        //select one random cell from the cells list
        MatrixCell cell = cells[rand() % cells.size()];
        //create a new kangaroo
        Kangaroo* kangaroo = new Kangaroo();
        kangaroo->progenitorId = this->id;
        kangaroo->setPosition(cell.position.row, cell.position.column);

        //add the kangaroo to the game
        game->addAnimal(kangaroo);
    }


}

void Kangaroo::move(Game* game) {
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    int radius = 1;

    std::vector<MatrixCell> cells = game->getMatrixCellsByArea(radius, this->position );

    std::vector<MatrixCell> filteredCells = std::vector<MatrixCell>();
    for (MatrixCell cell : cells) {
        if(cell.position.row == this->position.row || cell.position.column == this->position.column){
            if(cell.position.row != this->position.row || cell.position.column != this->position.column){
                filteredCells.push_back(cell);
            }
        }
    }

    if(filteredCells.size() > 0){
        int random = rand() % filteredCells.size();
        this->position.row = filteredCells[random].position.row;
        this->position.column = filteredCells[random].position.column;

        std::cout << "          > Kangaroo position updated [random][Radius:" + std::to_string(radius) + "]: ";
        this->display();
    }

    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);
}

void Kangaroo::move(Game* game, Position position) {
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    if(this->progenitorId >= 0){
        // get progenitorId
        Animal *progenitor = InfoCommand::getAnimalById(game,this->progenitorId);
        if(progenitor != NULL){
            position = progenitor->position;
        }
    }

    //calculate distances
    int radius = 1;

    if(this->currentIterations < 10){
        std::vector<MatrixCell> checkPredators = game->getMatrixCellsByArea(7, this->position );
        bool detectedOtherAnimal = false;

        for (MatrixCell cell : checkPredators) {
            if(cell.animals != NULL){
                Node<Animal> *currentAnimal = cell.animals;
                while (currentAnimal != NULL) {
                    if(currentAnimal->value->id != this->id && currentAnimal->value->id != this->progenitorId){
                        detectedOtherAnimal = true;
                        break;
                    }
                    currentAnimal = currentAnimal->next;
                }
            }
        }

        if(detectedOtherAnimal) {
            radius = 2;
        }
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

    std::cout << "     > Kangaroo position updated [not random] : [Radius:" << std::to_string(radius) <<  "] ";
    this->display();

    // if progenitor position equals current Kangaroo position
    // enter the marsupial
    if(this->progenitorId >= 0 && this->position.row == position.row && this->position.column == position.column && this->currentIterations < 10){
        Animal *progenitor = InfoCommand::getAnimalById(game,this->progenitorId);
        if(progenitor != NULL){
            if(progenitor->position.row == this->position.row && progenitor->position.column == this->position.column){
                std::cout << "          > Kangaroo entered the marsupial: ";
                progenitor->display();
                this->onMarsupial = true;
                this->onMarsupialInstants = 0;
            }
        }
    }

    if(!this->onMarsupial){
        //add to the matrix in the new position
        game->addAnimalToTheMatrix(this);
    }

}


void Kangaroo::eat(Game* game, Food *food) {

}

void Kangaroo::fight(Game* game,Animal *animal) {

}

void Kangaroo::verifications(Game* game) {
    this->currentIterations += 1;

    if(this->currentIterations > 20){
        this->weight = 20;
    }

    if(this->onMarsupial){
        this->onMarsupialInstants += 1;
    }

    if(this->currentIterations >= this->maxIterations || this->currentHP <= 0){
        this->currentHP = 0;
        Position position = this->position;

        //spawn a new body closer to the kangaroo
        int radius = 1;
        std::vector<MatrixCell> cells = game->getMatrixCellsByArea(radius, position);
        //select one radom cell from the cells list
        int randomIndex = rand() % cells.size();
        MatrixCell cell = cells[randomIndex];

        Body *body = new Body();
        body->position = cell.position;
        body->nutritiveValue = 15;
        body->toxicity = 5;
        game->addFood(body);

        std::cout << "               > The " <<  this->identifierEmoji << " is dead [id: " << this->id << "] and spawned a new body " <<  body->identifierEmoji << " [id: " << body->id << "] in [" <<  std::to_string(body->position.row) << std::to_string(body->position.column) <<  "]"  << std::endl;
        KillCommand::deleteAnimalFromMatrix(game,this->id);

    }
}

void Kangaroo::do_iteration(Game* game) {
    std::cout << "      > Kangaroo iteration: ";
    Animal::display();

    // - get cells by area ( 5 positions around )
    std::vector<MatrixCell> cells = game->getMatrixCellsByArea(7, this->position);
    std::vector<Animal*> predators = {};
    Animal *progenitor = InfoCommand::getAnimalById(game,this->progenitorId);

    if(this->onMarsupial == true && this->currentIterations < 10){
        if(progenitor != NULL){
            this->position = progenitor->position;
        }
    }else if(currentIterations >= 10 && this->onMarsupial == true){
        if(progenitor != NULL){
            this->position = progenitor->position;
        }
        this->onMarsupial = false;
        // because it was removed from the matrix
        game->addAnimalToTheMatrix(this);
    }

    if(onMarsupial){
        if(this->onMarsupialInstants >= 5){
            //max 5 instants on marsupial reached removing it from the pocket
            this->onMarsupial = false;
            game->addAnimalToTheMatrix(this);
        }
    }

    if(!this->onMarsupial){
        // iterate each cell to find a predator
        for (const auto &item: cells){
            if(item.animals != NULL){
                Node<Animal> *current = item.animals;
                while (current != NULL){
                    if(current->value->weight >= 15){
                        if(current->value->id != this->id){
                            std::cout << "          > Kangaroo detected a animal: ";
                            current->value->display();
                            predators.push_back(current->value);
                        }
                    }
                    current = current->next;
                }
            }
        }

        if(this->currentIterations < 10 ){

            if(predators.size() > 0){
                if(this->progenitorId >= 0){
                    // move 2 positions at a time
                    this->move(game, this->position);

                }else{
                    // is the first kangaroo of the family ( there is not progenitor )
                    this->move(game);
                }

            }else{
                if(this->progenitorId >= 0){
                    //always move closer to the progenitor ( 1 instance at a time )
                    this->move(game, this->position);
                }else{
                    this->move(game);
                }

            }
        }else {
            // move one position at a time randomly
            this->move(game);
        }
    }

    this->reproduce(game);
    this->verifications(game);
}

