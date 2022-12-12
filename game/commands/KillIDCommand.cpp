//
// Created by duarte on 09-12-2022.
//

#include <iostream>
#include "KillIDCommand.h"
#include "../utils/utils.h"

void KillIDCommand::deleteAnimalById(Game *game, int id) {
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

void KillIDCommand::execute() {
    std::cout << "  > Executing the killid command" << std::endl;
    if(args.size()== 2){
        if(isNumber(args[1])){
            //kill an entity id on args[1];
            std::cout << "  > killing the animal with id: " + args[1] << std::endl;
            KillIDCommand::deleteAnimalById(game, std::stoi(args[1]));
        }else{
            std::cout << "  > Invalid command provided, the id must be an integer" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the killid command should be be killid <id> " << std::endl;
    }
}