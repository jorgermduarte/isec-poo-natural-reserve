//
// Created by duarte on 08-12-2022.
//

#include <iostream>
#include "FeedIDCommand.h"
#include "../utils/utils.h"


void FeedIDCommand::execute() {
    if(args.size() == 4){
        //line col, nutritive_value toxicity_points
        if(isNumber(args[1]) && isNumber(args[2]) && isNumber(args[3])){
            int id = std::stoi(args[1]);
            std::string nutritivePoints = args[2];
            std::string toxicityPoints = args[3];

            bool foundAnimal = 0;

            if(game->animals != NULL){
                Node<Animal> *current = game->animals;
                while(current != NULL){
                    if(current->value->id == id){
                        foundAnimal = 1;
                        current->value->feed(std::stoi(nutritivePoints), std::stoi(toxicityPoints));
                        break;
                    }
                    current = current->next;
                }
            }

            if(foundAnimal){
                std::cout << "  > Executed the feedid command for id " + std::to_string(id) + ", nutritive value: " + nutritivePoints + ", toxicity points: "+ toxicityPoints  + " successfully!"  << std::endl;
            }else{
                std::cout << "  > Sorry, couldn't find any animal with the ID: " + std::to_string(id)  << std::endl;
            }

        }else{
            std::cout << "  > Invalid command provided, the feedid command arguments should be all numbers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the feedid command must contain 3 arguments, example: feed <id> <nutritive points> <toxicty points> " << std::endl;
    }
}