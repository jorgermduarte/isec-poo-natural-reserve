//
// Created by duarte on 08-12-2022.
//

#include <iostream>
#include "NoFoodCommand.h"
#include "../utils/utils.h"

void NoFoodCommand::deleteFoodFromList(Game *game, int id) {
    Node<Food>* foodNodeList = game->findFoodNode(id);

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

}

void NoFoodCommand::deleteFoodFromMatrix(Game *game, int id) {

    Node<Food>* foodNodeList = game->findFoodNode(id);
    if(foodNodeList != NULL){
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
    }

}

void NoFoodCommand::deleteFoodById(Game *game, int id) {
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

void NoFoodCommand::execute() {
    if(args.size() == 3){
        if(isNumber(args[1]) && isNumber(args[2])){
            int line = stoi(args[1]);
            int column = stoi(args[2]);
            std::cout << "  > Executing the nofood command for the line: " + std::to_string(line) +" and column: " + std::to_string(column) << std::endl;

            if(game->matrix[column][line].foods != NULL) {
                Node<Food> *foodMatrixCell = game->matrix[column][line].foods;
                while(foodMatrixCell != NULL){
                    NoFoodCommand::deleteFoodById(game, foodMatrixCell->value->id);
                    foodMatrixCell = foodMatrixCell->next;
                }
            }

        }else{
            std::cout << "  > Invalid command provided, the nofood command arguments should be numbers" << std::endl;
        }
    }else if(args.size() == 2){
        if(isNumber(args[1])){
            int id = std::stoi(args[1]);
            NoFoodCommand::deleteFoodById(this->game, id);
        }else{
            std::cout << "  > Invalid command provided, the nofood command arguments should be numbers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the nofood command must contain 2 arguments, example: nofood <ID>, or nofood <line> <column>" << std::endl;
    }
}