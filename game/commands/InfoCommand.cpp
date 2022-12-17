//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include "InfoCommand.h"
#include "../utils/utils.h"

Animal *InfoCommand::getAnimalById(Game* game, int id) {
    Animal* response = NULL;

    if(game->animals != NULL){
        Node<Animal>* item = game->animals->getHead();

        while(item != NULL){
            if(item->value != NULL){
                if(item->value->id == id){
                    response = item->value;
                }
            }
            item = item->next;
        }
    }

    return response;
}

void InfoCommand::execute() {
    std::cout << "  > Executing the info command" << std::endl;
    if(this->args.size() == 2){
        if(isNumber(args[1])){
            bool found = false;
            int id = atoi(args[1].c_str());


            if(game->animals != NULL){
                Node<Animal>* item = game->animals->getHead();

                while(item != NULL){
                    if(item->value != NULL){
                        if(item->value->id == id){
                            found = true;
                            item->value->display();
                        }
                    }
                    item = item->next;
                }
            }


            if(!found){
                if(game->foods != NULL){
                    Node<Food>* itemFoods = game->foods->getHead();

                    while(itemFoods != NULL){
                        if(itemFoods->value != NULL){
                            if(itemFoods->value->id == id){
                                found = true;
                                itemFoods->value->display();
                            }
                        }
                        itemFoods = itemFoods->next;
                    }
                }
            }

            if(!found){
                std::cout << "  > Sorry, couldn't find any entity for the ID specified..." << std::endl;
            }

        }else{
            std::cout << "  > Invalid command provided, the id argument in the info command must be a number" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the info command must contain at least 1 argument info <ID>" << std::endl;
    }
}