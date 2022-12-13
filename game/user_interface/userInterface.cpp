//
// Created by duarte on 10-11-2022.
//
#include <iostream>
#include "userInterface.h"

void displayNaturalReserveAux(Game &game, int x, int visibleCols, int displayVisibleCol){
    for(int i = 0; i < game.configuration.size.cols; i++){
        if( i < visibleCols && i >= game.configuration.screenPosition.column) {
            std::vector<MatrixCell> col = game.matrix[i];
            if(col[x].animals != NULL){
                std::cout << (col[x].animals->value)->identifierEmoji << " ";
            }
            else if(col[x].foods != NULL){
                std::cout << (col[x].foods->value)->identifierEmoji << " ";
            }
            else{
                std::cout << " # ";
            }
        }else{
            std::cout << "###";
        }

    }
}

void displayNaturalReserve(Game &game){
    std::cout << "=============================================================================== " << std::endl;

    int currentDisplayAreaRows = game.configuration.size.rows * DISPLAY_AREA_PERCENTAGE;
    currentDisplayAreaRows += game.configuration.screenPosition.row;

    int currentDisplayAreaCols = game.configuration.size.cols * DISPLAY_AREA_PERCENTAGE;
    currentDisplayAreaCols += game.configuration.screenPosition.column;

    for(int i = 0; i < game.configuration.size.rows; i++){
        if(i < currentDisplayAreaRows && i >= game.configuration.screenPosition.row){
            displayNaturalReserveAux(game,i,currentDisplayAreaCols,game.configuration.screenPosition.column);
        }else{
            for(int i = 0; i < game.configuration.size.cols; i++){
                std::cout << "###";
            }
        }
        std::cout << std::endl;
    }
}

void displayAnimals(Game &game){
    std::cout << "=============================== | ANIMALS | =================================== " << std::endl;
    if(game.animals != NULL){
        Node<Animal> *current = game.animals->getHead();
        while(current != NULL){
            current->value->display();
            current = current->next;
        }
    }
}