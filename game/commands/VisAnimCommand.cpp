//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "VisAnimCommand.h"

void VisAnimCommand::execute() {
    std::cout << "  > Executing the visanim command" << std::endl;
    int defaultPresentationCols = game->configuration.size.cols * DISPLAY_AREA_PERCENTAGE;
    int defaultPresentationRows = game->configuration.size.rows * DISPLAY_AREA_PERCENTAGE;


    int currentMaxCols = defaultPresentationCols + game->configuration.screenPosition.column - 1;
    int currentMaxRows = defaultPresentationRows + game->configuration.screenPosition.row - 1;
    int minCols = game->configuration.screenPosition.column;
    int minRows = game->configuration.screenPosition.row;

    if(game->animals != NULL){
        Node<Animal>* item = game->animals->getHead();

        while(item != NULL){
            if(item->value != NULL){
                if( item->value->position.row >= minRows && item->value->position.column >= minCols
                    && item->value->position.row <= currentMaxRows && item->value->position.column <= currentMaxCols){
                    item->value->display();
                }
                item = item->next;
            }
        }
    }

}
