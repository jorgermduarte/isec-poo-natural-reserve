//
// Created by duarte on 08-12-2022.
//

#include <iostream>
#include "FeedCommand.h"
#include "../utils/utils.h"

void FeedCommand::execute() {
    if(args.size() == 5){
        //line col, nutritive_value toxicity_points
        if(isNumber(args[1]) && isNumber(args[2]) && isNumber(args[3]) && isNumber(args[4])){
            int line = std::stoi(args[1]);
            int col = std::stoi(args[2]);
            std::string nutritivePoints = args[3];
            std::string toxicityPoints = args[4];
            std::cout << "  > Executing the feed command for line " + std::to_string(line) + ", col "+ std::to_string(col) + ", nutritive value: " + nutritivePoints + ", toxicity points: "+ toxicityPoints   << std::endl;
            
            if( this->game->matrix[line][col].animals != NULL){
                
                Node<Animal> *current = this->game->matrix[line][col].animals;
                while(current != NULL){
                    current->value->feed(std::stoi(nutritivePoints), std::stoi(toxicityPoints));
                    current = current->next;
                }
            }
            
        }else{
            std::cout << "  > Invalid command provided, the feed command arguments should be all numbers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the feed command must contain 4 arguments, example: feed <line> <column> <nutritive points> <toxicty points> " << std::endl;
    }
}