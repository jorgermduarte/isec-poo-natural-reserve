//
// Created by duarte on 09-12-2022.
//

#include <iostream>
#include "StoreCommand.h"

void StoreCommand::execute() {
    if(args.size() == 2){
        std::string filename = args[1];
        std::cout << "  > Executing the store command with the name: " + filename << std::endl;

        std::cout << "  > Saving the game in memory with the name: " + filename << std::endl;
        SaveGame *newSave = new SaveGame();

        newSave->setSaveGameName(filename);
        std::cout << "  > Creating a matrix shallow copy: " + filename << std::endl;
        newSave->initializeMatrix(this->game->matrix, &this->game->configuration.size);
        std::cout << "  > Creating animals copies" << std::endl;
        newSave->saveAnimals(this->game->animals);
        std::cout << "  > Creating foods copies" << std::endl;
        newSave->saveFoods(this->game->foods);

        std::cout << "  > Saving the game in memory with the name: " + filename << std::endl;
        this->game->savedGames.push_back(newSave);

        std::cout << "  > Saved successfully" << std::endl;

    }else{
        std::cout << "   > The store command requires only 1 argument, example: store <name>" << std::endl;
    }
}

