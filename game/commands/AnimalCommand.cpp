//
// Created by duarte on 08-12-2022.
//

#include <iostream>
#include "AnimalCommand.h"
#include "../models/animal/Rabbit.h"
#include "../models/animal/Wolf.h"
#include "../models/animal/Fox.h"
#include "../models/animal/Kangaroo.h"
#include "../models/animal/Sheep.h"
#include "../utils/utils.h"

void spawnAnimal(std::string type, bool randomCoordinates, int col, int row, Game* game) {
    Animal* animal;
    bool validType = false;
    if(type == "c"){
        animal = new Rabbit();
        validType = true;
    }else if(type == "l"){
        animal = new Wolf();
        validType = true;
    }else if( type == "m"){
        animal = new Fox();
        validType = true;
    }else if (type == "g"){
        animal = new Kangaroo();
        validType = true;
    }else if (type == "o"){
        animal = new Sheep();
        validType = true;
    }

    if(validType){
        if(randomCoordinates){
            animal->defineRandomPosition(game->configuration.size.rows-1,game->configuration.size.cols-1);
        }else{
            animal->position.column = col;
            animal->position.row = row;
        }
        game->addAnimal(animal);
    }else{
        std::cout << "  > Invalid animal type provided" << std::endl;
    }
}

void AnimalCommand::execute() {
    std::cout << "  > Executing the animal command" << std::endl;
    if(this->args.size() == 2){
        //execute a animal on a random position
        spawnAnimal(this->args[1],true,0,0,this->game);
    }else if(this->args.size() == 4) {
        //execute a animal on a given position
        if (isNumber(this->args[2]) && isNumber(this->args[3])) {
            if(isNumbersValidOnMatrix(this->game,std::stoi(this->args[2]),std::stoi(this->args[3]))){
                spawnAnimal(this->args[1], false, std::stoi(this->args[3]), std::stoi(this->args[2]), this->game);
            }else{
                std::cout << "      > Invalid coordinates provided, the numbers should not exceed the max rows and columns, remind that it starts on 0." << std::endl;
            }
        } else {
            std::cout << "      > Invalid command provided, the line and columns arguments must be integers" << std::endl;
        }
    }else{
        std::cout << "      > Invalid command provided, the animal command must contain at least 1 argument <specie: c / o / l / g / m> or <specie: c / o / l / g / m> <line> <column>" << std::endl;
    }
}