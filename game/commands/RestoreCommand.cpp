//
// Created by duarte on 10-12-2022.
//

#include <iostream>
#include "RestoreCommand.h"

//TODO: Implement the restore command
void RestoreCommand::execute() {
    if(args.size() == 2){
        std::string filename = args[1];
        std::cout << "  > Executing the restore command with the name: " + filename << std::endl;

        //find save game with the filename provided
        SaveGame *saveGame = NULL;
        for(int i = 0; i < this->game->savedGames.size(); i++){
            if(this->game->savedGames[i]->getSaveGameName() == filename){
                saveGame = this->game->savedGames[i];
                break;
            }
        }

        if(saveGame != NULL){
            std::cout << "  > Restoring the game from memory with the name: " + filename << std::endl;
            std::cout << "  > Restoring the matrix" << std::endl;
            this->game->matrix = saveGame->matrix;
            std::cout << "  > Restoring the animals" << std::endl;
            this->game->animals = saveGame->animals;
            std::cout << "  > Restoring the foods" << std::endl;
            this->game->foods = saveGame->foods;
            std::cout << "  > Restored successfully" << std::endl;

        }else{
            std::cout << "   > We couldn't find any save file with the name provided to restore..." << std::endl;
        }

    }else{
        std::cout << "   > The restore command requires only 1 argument, example: restore <name>" << std::endl;
    }

}