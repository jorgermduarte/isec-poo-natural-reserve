//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "Wolf.h"
#include "../../utils/Node.h"
#include "../game/MatrixCell.h"
#include "../game/Game.h"
#include "../enums/Smell.h"
#include "../../commands/KillCommand.h"
#include "../../commands/NoFoodCommand.h"
#include "../food/Body.h"

int Wolf::configMaxHP = 0;
int Wolf::configMaxIterations = 0;

Wolf::Wolf() {
    this->identifierEmoji = "\U0001f43a";
    this->weight = 15;
    this->currentHP = Wolf::configMaxHP;
    this->maxIterations = Wolf::configMaxIterations;
    this->maxHP = currentHP;
    this->identifier = 'L';
}


void Wolf::reproduce(Game* game) {
    // one wolf one brings another wolf to life one time.
    // the instant is random in the wolf lifetime.
    // the new wolf appears in max 15 cells away from the parent wolf.

}

void Wolf::move(Game* game) {
    //only moves one position at a time ( didn't detected anything good ( prey or smell ) )
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    int radius = 0;
    if(this->hunger > 15){
        radius = 2;
    }else{
        radius =  1;
    }

    // get the perceptions based on radius ( all wolf movements allowed in the matrix based on the radius)
    std::vector<MatrixCell> cells = game->getMatrixCellsByArea(radius, this->position );

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

        std::cout << "          > Wolf position updated [random][Radius:" + std::to_string(radius) + "]: ";
        this->display();
    }

    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);
}

void Wolf::move(Game* game, Position position) {
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    //calculate distances
    int radius = 0;
    if(this->hunger  > 15){
        radius = 2;
    }else{
        radius = 1;
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

    std::cout << "     > Wolf position updated [not random] : [Radius:" << std::to_string(radius) <<  "] ";
    this->display();
    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);
}

void Wolf::eat(Game* game,Food *food) {
    Animal::feed(food->nutritiveValue,food->toxicity);
    this->hunger -= food->nutritiveValue;
    if(this->hunger < 0)
        this->hunger = 0;
    NoFoodCommand::deleteFoodById(game,food->id);
}

//fight only one animal at a time
void Wolf::fight(Game* game,Animal *animal) {
    // try to approach the prey detected
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    //calculate distances
    int radius = 0;
    if(this->hunger > 15){
        radius = 3;
    }else{
        radius = 2;
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

    std::cout << "     > Wolf is following a prey ( " << animal->identifierEmoji << " detected ) [not random] : [Radius:" << std::to_string(radius) <<  "] ";
    this->display();

    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);

}

void Wolf::verifications(Game* game) {
    this->hunger += 2;
    this->currentIterations += 1;

    if(this->hunger >= 25){
        this->currentHP -= 2;
    }
    else if(this->hunger > 15){
        this->currentHP -= 1;
    }

    if (this->currentIterations >= this->maxIterations){
        this->currentHP = 0;
    }

    if(this->currentHP <= 0){
        //spawn a new body closer to the wolf
        std::vector<MatrixCell> cells = game->getMatrixCellsByArea(5, position);
        //select one random cell from the cells list
        int randomIndex = rand() % cells.size();
        MatrixCell cell = cells[randomIndex];

        Body *body = new Body();
        body->position = cell.position;
        body->nutritiveValue = 10;
        body->toxicity = 0;
        game->addFood(body);

        std::cout << "               > The " <<  this->identifierEmoji << " is dead [id: " << this->id << "] and spawned a new body " <<  body->identifierEmoji << " [id: " << body->id << "] in [" <<  std::to_string(body->position.row) << std::to_string(body->position.column) <<  "]"  << std::endl;
        //remove the wolf from the matrix
        KillCommand::deleteAnimalFromMatrix(game,this->id);
    }
}

void Wolf::do_iteration(Game* game) {
    std::cout << "      > Wolf iteration: ";
    Animal::display();

    // - get cells by area ( 5 positions around )
    std::vector<MatrixCell> cells = game->getMatrixCellsByArea(5, this->position);
    std::vector<Animal*> prays = {};
    std::vector<Food*> foods = {};
    bool foodInCurrentPosition = false;
    bool preyInCurrentPosition = false;

    // iterate each cell to find a prey or food
    for (const auto &item: cells){

        if(item.animals != NULL){
            Node<Animal> *current = item.animals;
            while (current != NULL){
                //don't detect the self animal
                if(current->value->id != this->id){
                    std::cout << "          > Wolf detected a prey: ";
                    current->value->display();

                    prays.push_back(current->value);
                    if(this->position.row == current->value->position.row && this->position.column == current->value->position.column){
                        preyInCurrentPosition = true;
                    }
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
                    if(cSmell == Smell::ENUM_Meat){
                        smellsDetected.push_back(cSmell);
                        std::cout << "          > Wolf detected a smell: ";
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

    if(prays.size() > 0){
        bool dead = false;
        //if the wolf is in the same position as a heavier animal 1 dies randomly.
        if(preyInCurrentPosition){
            // get the heavier animal
            Animal* heavierAnimal = prays[0];
            for (Animal* animal : prays) {
                if(animal->weight > heavierAnimal->weight){
                    heavierAnimal = animal;
                }
            }

            // decide randomly who dies
            int random = rand() % 2;
            if(random == 0) {
                //the wolf dies
                this->currentHP = 0;
                dead = true;
                std::cout << "          > Wolf died fighting another animal: ";
                heavierAnimal->display();
            }else{
                //the animal dies
                std::cout << "          > Wolf killed one heavier animal: ";
                heavierAnimal->display();
                KillCommand::deleteAnimalFromMatrix(game,heavierAnimal->id);
            }
        }

        if(!dead){
            //verify kill small animals < this.weight automatically radius - 1
            std::vector<MatrixCell> cells = game->getMatrixCellsByArea(1, this->position);
            std::vector<int> animalIdsToKill = {};
            for (const auto &item: cells){
                if(item.animals != NULL){
                    Node<Animal> *current = item.animals;
                    while (current != NULL){
                        if(current->value->weight < this->weight){
                            std::cout << "          > Wolf killed a small prey: ";
                            current->value->display();
                            animalIdsToKill.push_back(current->value->id);
                            this->currentHP = 0;
                        }
                        current = current->next;
                    }
                }
            }

            //kill the animals
            if(animalIdsToKill.size() > 0){
                for (int animalId : animalIdsToKill) {
                    KillCommand::deleteAnimalFromMatrix(game,animalId);
                }
            }


            // if there is multiple prays follow the heaviest
            //only one animal
            if(prays.size() == 1){
                this->fight(game,prays[0]);
            }else if(prays.size() >= 2){
                // get the heaviest animal from the prays list
                Animal* heaviest = prays[0];
                for (Animal* prey : prays) {
                    if(prey->weight > heaviest->weight){
                        heaviest = prey;
                    }
                }
                this->fight(game,heaviest);
            }


        }
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