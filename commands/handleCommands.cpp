//
// Created by duarte on 10-11-2022.
//
#include "handleCommands.h"
#include "validateCommands.h"
#include "commands.h"

void executeCommand(std::string &command){
    vector<string> args = getCommandArguments(command);

    //verify if the argument[0] (command type) exists on the map (allowed command)
    std::unordered_map<std::string,int>::const_iterator got = allowedCommands.find(args[0]);
    if(got != allowedCommands.end()){
        //handling the execution of the different commands
        switch(got->second) {
            case 0: // this is the "food" case
                cout << "Executing the food function" << endl;
                break;
            case 1: // this is the "xpto" case
                cout << "Executing the xpto function" << endl;
                break;
            default:
                break;
        }
    }
}

void initializeCommands(){
    std::string command;
    cout << " > Command: ";
    getline(cin, command);
    std::cout << "  > Command provided: " + command << std::endl;

    if(command != "exit") {
        if(!validateCommand(command)){
            cout << " # Please provide a valid command ..." << endl;
        }else{
            executeCommand(command);
        }
        initializeCommands();
    }
}


void handleCommands(){
    std::cout << "================================| COMMANDS | ================================== " << std::endl;
    initializeCommands();
}
