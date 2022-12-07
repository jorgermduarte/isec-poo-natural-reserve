//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include <unordered_map>
#include "SlideCommand.h"
#include "../models/commands/allowedCommands.h"

void SlideCommand::execute() {
    std::cout << "  > Executing the slide command" << std::endl;

    std::unordered_map<std::string,int> allowedDirections = {
            {"up",1},
            {"down", 2},
            {"left", 3},
            {"right", 4}
    };

    std::unordered_map<std::string,int> allowedSecondArgument = {
            {"lines",1},
            {"columns", 2},
    };

    if(args.size() == 3){
        //validate  the first argument
        std::unordered_map<std::string,int>::const_iterator got = allowedDirections.find(args[1]);

        bool allowedDirection = false;
        bool allowedTarget = false;

        if(got != allowedCommands.end()){
            allowedDirection = true;
        }
        std::unordered_map<std::string,int>::const_iterator got2 = allowedSecondArgument.find(args[2]);
        if(got2 != allowedSecondArgument.end()){
            allowedTarget = true;
        }

        if(allowedDirection == true && allowedTarget == true){
            game->configuration.moveScreenDisplayPosition(args[1],args[2]);
            std::cout << "  > Moved the natural reserve display correctly" << std::endl;
        }else{
            std::cout << "  > Please verify your arguments, remind that the second argument must be <lines/columns> and the first <direction: up/down/right/left>" << std::endl;
        }

    }else{
        std::cout << "  > Failed to execute the slide command, please follow the sintax: slide <direction: up/down/right/left> <lines/columns> " << std::endl;
    }
}