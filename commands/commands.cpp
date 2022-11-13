//
// Created by duarte on 11-11-2022.
//
#include <iostream>
#include <fstream>
#include "commands.h"
#include "../utils/utils.h"
#include "../game/game/Game.h"
#include "handleCommands.h"

using namespace std;

void exec_command_animal(std::vector<std::string> args){
    std::cout << "  > Executing the animal command" << std::endl;
    //displayStringsList(args);

    if(args.size() < 2){
        std::cout << "  > Invalid command provided, the animal command must contain at least 1 argument <specie: c / o / l / g / m> or <specie: c / o / l / g / m> <line> <column>" << std::endl;
    }else if(args.size() == 2){
        std::cout << "  > Spawning the specie of type " + args[1] +  " in a random position" << std::endl;
    }else if(args.size() == 4){
        std::string line = args[2];
        std::string column = args[3];

        if(isNumber(line) && isNumber(column)){
            std::cout << "  > Spawning the specie of type " + args[1] +  " in the position: l:" + line + " c:" + column << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the animal command should contain the position and line arguments as integers and not characters" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the animal command must contain at least 1 argument <specie: c / o / l / g / m> or <specie: c / o / l / g / m> <line> <column>" << std::endl;
    }

}
void exec_command_kill(std::vector<std::string> args){
    std::cout << "  > Executing the kill command" << std::endl;
}
void exec_command_food(std::vector<std::string> args){
    std::cout << "  > Executing the food command" << std::endl;
}
void exec_command_feed(std::vector<std::string> args){
    std::cout << "  > Executing the feed command" << std::endl;
}
void exec_command_feedid(std::vector<std::string> args){
    std::cout << "  > Executing the feedid command" << std::endl;
}
void exec_command_nofood(std::vector<std::string> args){
    std::cout << "  > Executing the nofood command" << std::endl;
}
void exec_command_empty(std::vector<std::string> args){
    std::cout << "  > Executing the empty command" << std::endl;
}
void exec_command_see(std::vector<std::string> args){
    std::cout << "  > Executing the see command" << std::endl;
}

void exec_command_info(std::vector<std::string> args, Game* game){
    std::cout << "  > Executing the info command" << std::endl;
    if(args.size() == 2){
        if(isNumber(args[1])){
            bool found = false;
            int id = atoi(args[1].c_str());

            for (const auto &item: game->animals){
                if(item.id == id){
                    std::cout << "      [" + std::to_string(item.id) + "]" +  " " + item.identifier + " HP: " + std::to_string(item.health) << std::endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                for (const auto &item: game->foods){
                    if(item.id == id){
                        std::cout << "      [" + std::to_string(item.id) + "]" +  " " + item.identifier + " Toxicity: " + std::to_string(item.toxicity) + " Nutritive Value: " +
                                to_string(item.nutritiveValue)  << std::endl;
                        found = true;
                        break;
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

void exec_command_n(){
    std::cout << "  > Executing the n command" << std::endl;
}
void exec_command_n(std::vector<std::string> args){
    std::cout << "  > Executing the n command with args" << std::endl;
}
void exec_command_anim(Game* game){
    std::cout << "  > Executing the anim command" << std::endl;
    for (const auto &item: game->animals){
        std::cout << "      [" + std::to_string(item.id) + "]" +  " " + item.identifier + " HP: " + std::to_string(item.health) << std::endl;
    }
}
//TODO: required for the first meta
void exec_command_visanim(){
    std::cout << "  > Executing the visanim command" << std::endl;
}
void exec_command_store(std::vector<std::string> args){
    std::cout << "  > Executing the store command" << std::endl;
}
void exec_command_restore(std::vector<std::string> args){
    std::cout << "  > Executing the restore command" << std::endl;
}

void exec_command_load(std::vector<std::string> args, Game* game){
    std::cout << "  > Executing the load command" << std::endl;

    if(args.size() == 2){
        //read commands file
        std::vector<std::string> commands;
        FILE *f = NULL;

        std::string currentCommand;
        fstream newfile;
        newfile.open(args[1],ios::in); //open a file to perform read operation using file object
        if (newfile.is_open()){ //checking whether the file is open
            cout << "We have detected a " + args[1] + " file, executing.." << endl;
            string tp;
            while(getline(newfile, tp)){ //read data from file object and put it into string.
                commands.push_back(tp);
            }
            newfile.close(); //close the file object.
        }else{
            cout << "   > Couldn't find any file with the name " + args[1] << endl;
        }

        if(commands.size() > 0){
            std::cout << "============================| COMMANDS FROM FILE | ============================= " << std::endl;
            for (string cmd: commands){
                cout << "#Command from file: " + cmd << endl;
                executeCommand(cmd, game);
            }
            std::cout << "=======================| END OF COMMANDS FROM FILE | ========================== " << std::endl;
        }

    }else{
        std::cout << "  > Invalid command provided, the load command requires only one argument the file-name, example: load file-name.txt " << endl;
    }

}

void exec_command_slide(std::vector<std::string> args, Game* game){
    std::cout << "  > Executing the slide command" << std::endl;

    unordered_map<string,int> allowedDirections = {
            {"up",1},
            {"down", 2},
            {"left", 3},
            {"right", 4}
    };

    unordered_map<string,int> allowedSecondArgument = {
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
            std::cout << "  > Moved the natural reserve display correctly" << endl;
        }else{
            std::cout << "  > Please verify your arguments, remind that the second argument must be <lines/columns> and the first <direction: up/down/right/left>" << endl;
        }

    }else{
        std::cout << "  > Failed to execute the slide command, please follow the sintax: slide <direction: up/down/right/left> <lines/columns> " << std::endl;
    }
}


