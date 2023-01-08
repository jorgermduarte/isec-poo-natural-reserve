//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include <unordered_map>
#include "SlideCommand.h"
#include "../models/commands/allowedCommands.h"
#include "../utils/utils.h"

void SlideCommand::execute() {
    std::cout << "  > Executing the slide command" << std::endl;

    std::unordered_map<std::string,int> allowedDirections = {
            {"up",1},
            {"down", 2},
            {"left", 3},
            {"right", 4}
    };

    if(args.size() == 3){

        //validate  the first argument
        std::unordered_map<std::string,int>::const_iterator got = allowedDirections.find(args[1]);

        bool allowedDirection = false;

        if(got != allowedCommands.end()){
            allowedDirection = true;
        }

        if(isNumber(args[2])){
            if(allowedDirection == true){
                std::cout << "  > Moved the natural reserve display correctly" << std::endl;

                int target = std::stoi(args[2]);
                game->configuration.moveScreenDisplayPosition(args[1],target);
            }else{
                std::cout << "  > Please verify your arguments, remind that the second argument must be a number and the first <direction: up/down/right/left>" << std::endl;
            }
        }else{
            std::cout << "  > Please verify your arguments, remind that the second argument must be a number and the first <direction: up/down/right/left>" << std::endl;
        }
    }else{
        std::cout << "  > Failed to execute the slide command, please follow the sintax: slide <direction: up/down/right/left> number " << std::endl;
    }
}