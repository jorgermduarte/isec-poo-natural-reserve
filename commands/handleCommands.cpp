//
// Created by duarte on 10-11-2022.
//
#include <fstream>
#include "handleCommands.h"
#include "validateCommands.h"
#include "commands.h"
#include "../userInterface/useInterface.h"

void executeCommand(std::string &command,Game* game){
    vector<string> args = getCommandArguments(command);
    //displayStringsList(args);

    //verify if the argument[0] (command type) exists on the map (allowed command)
    std::unordered_map<std::string,int>::const_iterator got = allowedCommands.find(args[0]);
    if(got != allowedCommands.end()){
        //handling the execution of the different commands
        switch(got->second) {
            case 0: // this is the "animal" case
                exec_command_animal(args);
                break;
            case 1: // this is the "kill" case
                exec_command_kill(args);
                break;
            case 2:
                exec_command_food(args);
                break;
            case 3:
                exec_command_feed(args);
                break;
            case 4:
                exec_command_feedid(args);
                break;
            case 5:
                exec_command_nofood(args);
                break;
            case 6:
                exec_command_empty(args);
                break;
            case 7:
                exec_command_see(args);
                break;
            case 8:
                exec_command_info(args,game);
                break;
            case 9:
                exec_command_n(args);
                break;
            case 10:
                exec_command_anim(game);
                break;
            case 11:
                exec_command_visanim(game);
                break;
            case 12:
                exec_command_store(args);
                break;
            case 13:
                exec_command_restore(args);
                break;
            case 14:
                exec_command_load(args,game);
                break;
            case 15:
                exec_command_slide(args,game);
                break;
            case 16:
                exec_command_killid(args);
                break;
            default:
                break;
        }
    }else{
        cout << "   > Invalid command detected " << endl;
    }
}

void initializeCommands(Game* game){
    std::string command;
    std::cout << "================================| COMMANDS | ================================== " << std::endl;
    cout << " > Command: ";
    getline(cin, command);
    std::cout << "  > Command provided: " + command << std::endl;

    if(command != "exit") {
        if(!validateCommand(command)){
            cout << " # Please provide a valid command ..." << endl;
        }else{
            executeCommand(command,game);
        }
        displayNaturalReserve(*game);
        displayAnimals(*game);
        initializeCommands(game);
    }
}

void handleCommands(Game* game){
    initializeCommands(game);
}
