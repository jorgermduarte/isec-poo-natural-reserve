//
// Created by duarte on 09-12-2022.
//

#include <iostream>
#include "EmptyCommand.h"
#include "../utils/utils.h"


void deleteAnimalByIdEmpty(Game* game, int id){
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
                    game->foods = NULL;
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


void deleteFoodByIdEmpty(Game* game, int id){
    Node<Food>* foodNodeList = game->findFoodNode(id);

    if(foodNodeList != NULL && foodNodeList->value != NULL){

        std::cout << "  > Removing the following food from the game: "<< std::endl;
        std::cout << "      > ";
        foodNodeList->value->display();

        //remove the food from the matrix
        Node<Food> *foodMatrixCell = game->matrix[foodNodeList->value->position.column][foodNodeList->value->position.row].foods;
        while(foodMatrixCell != NULL){

            if(foodMatrixCell->value->id == id){
                //std::cout << "  > Removing the food from the matrix cell" << std::endl;

                if(foodMatrixCell->prev == NULL && foodMatrixCell->next == NULL) { //only one element(working)
                    game->matrix[foodNodeList->value->position.column][foodNodeList->value->position.row].foods = NULL;
                }
                else if(foodMatrixCell->prev == NULL && foodMatrixCell->next != NULL){ // first element(working)
                    game->matrix[foodNodeList->value->position.column][foodNodeList->value->position.row].foods = foodMatrixCell->next;
                    foodMatrixCell->next->prev = NULL;
                }
                else if(foodMatrixCell->prev != NULL && foodMatrixCell->next == NULL){ //last element (working)
                    foodMatrixCell->prev->next = NULL;
                }
                else if(foodMatrixCell->prev != NULL && foodMatrixCell->next != NULL){ //middle element (working)
                    foodMatrixCell->prev->next = foodMatrixCell->next;
                    foodMatrixCell->next->prev = foodMatrixCell->prev;
                }
                break;

            }
            foodMatrixCell = foodMatrixCell->next;
        }

        //remove the food from the food list
        while(foodNodeList != NULL){
            if(foodNodeList->value->id == id){
                //std::cout << "  > Removing the food from the food list" << std::endl;

                if(foodNodeList->prev == NULL && foodNodeList->next == NULL) { //only one element(working)
                    game->foods = NULL;
                }
                else if(foodNodeList->prev == NULL && foodNodeList->next != NULL){ // first element(working)
                    game->foods = foodNodeList->next;
                    foodNodeList->next->prev = NULL;
                }
                else if(foodNodeList->prev != NULL && foodNodeList->next == NULL){ //last element (working)
                    foodNodeList->prev->next = NULL;
                }
                else if(foodNodeList->prev != NULL && foodNodeList->next != NULL){ //middle element (working)
                    foodNodeList->prev->next = foodNodeList->next;
                    foodNodeList->next->prev = foodNodeList->prev;
                }
                break;
            }
            foodNodeList = foodNodeList->next;
        }

        std::cout << "  > Removed successfully the food with the id: " + std::to_string(id) << std::endl;

    }else{
        std::cout << "  > Sorry, couldn't find any food with the ID provided" << std::endl;
    }
}

void EmptyCommand::execute() {
    if(args.size() == 3){
        if(isNumber(args[1]) && isNumber(args[2])){

            int line = stoi(args[1]);
            int column = stoi(args[2]);

            if(this->game->matrix[line][column].animals != NULL){
                Node<Animal> *current = this->game->matrix[line][column].animals;
                while(current != NULL){
                    deleteAnimalByIdEmpty(this->game, current->value->id);
                    current = current->next;
                }
            }

            if(this->game->matrix[line][column].foods != NULL){
                Node<Food> *current = this->game->matrix[line][column].foods;
                while(current != NULL){
                    deleteFoodByIdEmpty(this->game, current->value->id);
                    current = current->next;
                }
            }


            std::cout << "  > Executing the empty command for line: " + args[1] + " and column: " + args[2] << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the empty command arguments should be numbers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the empty command must contain only 2 arguments, example: empty <line> <column>" << std::endl;
    }
}