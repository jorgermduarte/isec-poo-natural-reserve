//
// Created by duarte on 10-11-2022.
//
#include <iostream>
#include <jmorecfg.h>
#include "Rabbit.h"
#include "../enums/Smell.h"
#include "../../commands/NoFoodCommand.h"
#include "../../commands/KillCommand.h"
#include "../game/GameSingleton.h"

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

void Rabbit::reproduce() {
    Game* game = GameSingleton::getGame();
    if(this->reprodutionCounter >= 8){
        int random = rand() % 100 + 1;
        if(random > 50){
            Position position = this->position;

            //TODO: correct the randomness of the position
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

void Rabbit::fight(Animal *animal) {
    //TODO: escape the predator
}

void Rabbit::move(Position position) {
    Game* game = GameSingleton::getGame();
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);

    //calculate distances
    int distance = 0;
    if(this->hunger  < 10){
        distance = 1 + (rand() % 2 + 1);
    }else if(this->hunger  < 20){
        distance =  1 + (rand() % 3 + 1);
    }else{
        distance =  1 + (rand() % 4 + 1);
    }
    if(this->position.row > position.row){
        int distanceLeft = this->position.row - position.row;
        if(distanceLeft > distance)
            this->position.row -= distance;
        else
            this->position.row -= distanceLeft;
    }else if(this->position.row < position.row){
        int distanceLeft = position.row - this->position.row;
        if(distanceLeft > distance)
            this->position.row += distance;
        else
            this->position.row += distanceLeft;
    }else if(this->position.column > position.column){
        int distanceLeft = this->position.column - position.column;
        if(distanceLeft > distance)
            this->position.column -= distance;
        else
            this->position.column -= distanceLeft;
    }else if(this->position.column < position.column){
        int distanceLeft = position.column - this->position.column;
        if(distanceLeft > distance)
            this->position.column += distance;
        else
            this->position.column += distanceLeft;
    }


    if(this->position.row < 0)
        this->position.row = 0;
    if(this->position.column < 0)
        this->position.column = 0;

    if(this->position.row  >= game->configuration.size.rows)
        this->position.row = game->configuration.size.rows - 1;

    if(this->position.column >= game->configuration.size.cols)
        this->position.column = game->configuration.size.cols -1;

    std::cout << "     > Rabbit position updated [not random]: ";
    Animal::display();
    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);
}

//random move
void Rabbit::move() {

    Game* game = GameSingleton::getGame();
    //remove from the matrix
    KillCommand::deleteAnimalFromMatrix(game,this->id);


    int distance = 0;
    if(this->hunger  < 10){
        distance = 1 + (rand() % 2 + 1);
    }else if(this->hunger  < 20){
        distance =  1 + (rand() % 3 + 1);
    }else{
        distance =  1 + (rand() % 4 + 1);
    }

    int direction = rand() % 4 + 1;
    switch (direction) {
        case 1:
            this->position.setX(this->position.getX() + distance);
            break;
        case 2:
            this->position.setX(this->position.getX() - distance);
            break;
        case 3:
            this->position.setY(this->position.getY() + distance);
            break;
        case 4:
            this->position.setY(this->position.getY() - distance);
            break;

    }


    if(this->position.row < 0)
        this->position.row = 0;
    if(this->position.column < 0)
        this->position.column = 0;

    if(this->position.row  >= game->configuration.size.rows)
        this->position.row = game->configuration.size.rows - 1;

    if(this->position.column >= game->configuration.size.cols)
        this->position.column = game->configuration.size.cols -1;

    std::cout << "          > Rabbit position updated: ";
    Animal::display();
    //add to the matrix in the new position
    game->addAnimalToTheMatrix(this);
    std::cout << "          > Rabbit position updated successfully" << std::endl;
}

void Rabbit::eat(Food *food) {
    Game* game = GameSingleton::getGame();
    Animal::feed(food->nutritiveValue,food->toxicity);
    this->hunger -= food->nutritiveValue;
    if(this->hunger < 0)
        this->hunger = 0;
    NoFoodCommand::deleteFoodById(game,food->id);
}

void Rabbit::verifications() {
    Game* game = GameSingleton::getGame();
    this->reproduce();

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

void Rabbit::do_iteration() {
    std::cout << "      > Rabbit iteration: ";
    Animal::display();

    Game* game = GameSingleton::getGame();

    // - get cells by area ( 4 positions around )
    std::vector<MatrixCell> cells = game->getMatrixCellsByArea(4, this->position);
    std::vector<Animal> predators = {};
    std::vector<Food> foods = {};
    boolean foodInCurrentPosition = false;

    // iterate each cell to find a predator or food
    for (const auto &item: cells){

        if(item.animals != NULL){
            Node<Animal> *current = item.animals;
            while (current != NULL){
                if(current->value->weight > 10){
                    std::cout << "      > Rabbit detected a predator: ";
                    current->value->display();
                    predators.push_back(*current->value);
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
                        std::cout << "      > Rabbit detected a smell: ";
                        current->value->display();
                        foods.push_back(*current->value);
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
        this->fight(&predators[0]);
    }else{

        if(foods.size() > 0) {
            //eat the food
            if (foodInCurrentPosition) {
                this->eat(&foods[0]);
            } else {
                //move to the food
                this->move(foods[0].position);
            }
        }else{
            //if he does not perceive food or predator moves randomly
            this->move();
        }
    }

    this->verifications();
}