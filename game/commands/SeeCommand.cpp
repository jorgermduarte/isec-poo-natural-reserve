//
// Created by duarte on 08-12-2022.
//

#include <iostream>
#include "SeeCommand.h"
#include "../utils/utils.h"

void SeeCommand::execute() {
    if(args.size() == 3){
        if(isNumber(args[1]) && isNumber(args[2])) {
            int line = std::stoi(args[1]);
            int column = std::stoi(args[2]);

            if(isNumbersValidOnMatrix(this->game,line,column)){
                std::cout << "  > Executing the see command for line: " + std::to_string(line) + " and column: " + std::to_string(column) << std::endl;

                Node<Food> *currentFood = game->matrix[column][line].foods;
                Node<Animal> *currentAnimal = game->matrix[column][line].animals;

                std::cout << "  > Foods in the current position: " << std::endl;
                while(currentFood != NULL){
                    std::cout << "      > ";
                    currentFood->value->display();
                    currentFood = currentFood->next;
                }

                std::cout << "  > Animals in the current position: " << std::endl;
                while(currentAnimal != NULL){
                    std::cout << "      > ";
                    currentAnimal->value->display();
                    currentAnimal = currentAnimal->next;
                }

            }else{
                std::cout << "      > Invalid coordinates provided, the numbers should not exceed the max rows and columns, remind that it starts on 0." << std::endl;
            }
        }
    }else{
        std::cout << "  > Invalid command provided, the see command must contain only 2 arguments, example: see <line> <column>" << std::endl;
    }
}