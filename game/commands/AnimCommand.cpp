//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "AnimCommand.h"

void AnimCommand::execute() {
    std::cout << "  > Executing the anim command" << std::endl;

    Node<Animal>* item = game->animals->getHead();

    while(item != NULL){
        if(item->value != NULL){
            item->value->display();
            item = item->next;
        }
    }
}