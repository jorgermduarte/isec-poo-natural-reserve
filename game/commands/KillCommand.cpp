//
// Created by duarte on 09-12-2022.
//

#include <iostream>
#include "KillCommand.h"
#include "../utils/utils.h"

void KillCommand::deleteAnimalFromMatrix(Game *game, int id) {
    Node<Animal>* foodAnimalList = game->findAnimalNode(id);
    if(foodAnimalList != NULL){
        //remove the food from the matrix
        Node<Animal> *AnimalMatrixCell = game->matrix[foodAnimalList->value->position.column][foodAnimalList->value->position.row].animals;
        while(AnimalMatrixCell != NULL){

            if(AnimalMatrixCell->value->id == id){
                //std::cout << "  > Removing the animal from the matrix cell" << std::endl;

                if(AnimalMatrixCell->prev == NULL && AnimalMatrixCell->next == NULL) { //only one element(working)
                    game->matrix[AnimalMatrixCell->value->position.column][AnimalMatrixCell->value->position.row].animals = NULL;
                }
                else if(AnimalMatrixCell->prev == NULL && AnimalMatrixCell->next != NULL){ // first element(working)
                    game->matrix[AnimalMatrixCell->value->position.column][AnimalMatrixCell->value->position.row].animals = AnimalMatrixCell->next;
                    AnimalMatrixCell->next->prev = NULL;
                }
                else if(AnimalMatrixCell->prev != NULL && AnimalMatrixCell->next == NULL){ //last element (working)
                    AnimalMatrixCell->prev->next = NULL;
                }
                else if(AnimalMatrixCell->prev != NULL && AnimalMatrixCell->next != NULL){ //middle element (working)
                    AnimalMatrixCell->prev->next = AnimalMatrixCell->next;
                    AnimalMatrixCell->next->prev = AnimalMatrixCell->prev;
                }
                break;
            }
            AnimalMatrixCell = AnimalMatrixCell->next;
        }
    }
}

void KillCommand::deleteAnimalFromList(Game *game, int id) {
    Node<Animal>* foodAnimalList = game->findAnimalNode(id);

    //remove the animal from the animal list
    while(foodAnimalList != NULL){
        if(foodAnimalList->value->id == id){
            std::cout << "  > Removing the animal from the animal list" << std::endl;

            if(foodAnimalList->prev == NULL && foodAnimalList->next == NULL) { //only one element(working)
                game->animals = NULL;
            }
            else if(foodAnimalList->prev == NULL && foodAnimalList->next != NULL){ // first element(working)
                game->animals = foodAnimalList->next;
                foodAnimalList->next->prev = NULL;
            }
            else if(foodAnimalList->prev != NULL && foodAnimalList->next == NULL){ //last element (working)
                foodAnimalList->prev->next = NULL;
            }
            else if(foodAnimalList->prev != NULL && foodAnimalList->next != NULL){ //middle element (working)
                foodAnimalList->prev->next = foodAnimalList->next;
                foodAnimalList->next->prev = foodAnimalList->prev;
            }
            break;
        }
        foodAnimalList = foodAnimalList->next;
    }
}

void KillCommand::deleteAnimalById(Game *game, int id) {
    Node<Animal>* foodAnimalList = game->findAnimalNode(id);

    if(foodAnimalList != NULL && foodAnimalList->value != NULL){

        std::cout << "  > Removing the following animal from the game: "<< std::endl;
        std::cout << "      > ";
        foodAnimalList->value->display();

        //remove the food from the matrix
        Node<Animal> *AnimalMatrixCell = game->matrix[foodAnimalList->value->position.column][foodAnimalList->value->position.row].animals;
        while(AnimalMatrixCell != NULL){

            if(AnimalMatrixCell->value->id == id){
                //std::cout << "  > Removing the animal from the matrix cell" << std::endl;

                if(AnimalMatrixCell->prev == NULL && AnimalMatrixCell->next == NULL) { //only one element(working)
                    game->matrix[AnimalMatrixCell->value->position.column][AnimalMatrixCell->value->position.row].animals = NULL;
                }
                else if(AnimalMatrixCell->prev == NULL && AnimalMatrixCell->next != NULL){ // first element(working)
                    game->matrix[AnimalMatrixCell->value->position.column][AnimalMatrixCell->value->position.row].animals = AnimalMatrixCell->next;
                    AnimalMatrixCell->next->prev = NULL;
                }
                else if(AnimalMatrixCell->prev != NULL && AnimalMatrixCell->next == NULL){ //last element (working)
                    AnimalMatrixCell->prev->next = NULL;
                }
                else if(AnimalMatrixCell->prev != NULL && AnimalMatrixCell->next != NULL){ //middle element (working)
                    AnimalMatrixCell->prev->next = AnimalMatrixCell->next;
                    AnimalMatrixCell->next->prev = AnimalMatrixCell->prev;
                }
                break;

            }
            AnimalMatrixCell = AnimalMatrixCell->next;
        }

        //remove the animal from the animal list
        while(foodAnimalList != NULL){
            if(foodAnimalList->value->id == id){
                //std::cout << "  > Removing the food from the food list" << std::endl;

                if(foodAnimalList->prev == NULL && foodAnimalList->next == NULL) { //only one element(working)
                    game->animals = NULL;
                }
                else if(foodAnimalList->prev == NULL && foodAnimalList->next != NULL){ // first element(working)
                    game->animals = foodAnimalList->next;
                    foodAnimalList->next->prev = NULL;
                }
                else if(foodAnimalList->prev != NULL && foodAnimalList->next == NULL){ //last element (working)
                    foodAnimalList->prev->next = NULL;
                }
                else if(foodAnimalList->prev != NULL && foodAnimalList->next != NULL){ //middle element (working)
                    foodAnimalList->prev->next = foodAnimalList->next;
                    foodAnimalList->next->prev = foodAnimalList->prev;
                }
                break;
            }
            foodAnimalList = foodAnimalList->next;
        }

        std::cout << "  > Removed successfully the animal with the id: " + std::to_string(id) << std::endl;

    }else{
        std::cout << "  > Sorry, couldn't find any animal with the ID provided" << std::endl;
    }
}


void KillCommand::execute() {
    std::cout << "  > Executing the kill command" << std::endl;

    if (args.size() == 3){
        //kill entities at a given position args[1] and args[2]

        if (isNumber(args[1]) && isNumber(args[2])) {

            int line = std::stoi(args[1]);
            int column = std::stoi(args[2]);

            std::cout << "  > killing the animals in the position: l: " + args[1] + " c:" + args[2] << std::endl;

            if(this->game->matrix[line][column].animals != NULL){
                Node<Animal> *current = this->game->matrix[line][column].animals;
                while(current != NULL){
                    KillCommand::deleteAnimalById(this->game, current->value->id);
                    current = current->next;
                }
            }


        } else {
            std::cout << "  > Invalid command provided, the line and columns arguments must be integers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the kill command can be kill <line> <column>> " << std::endl;
    }
}