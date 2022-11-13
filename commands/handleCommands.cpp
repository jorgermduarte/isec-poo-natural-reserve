//
// Created by duarte on 10-11-2022.
//
#include <fstream>
#include "handleCommands.h"
#include "validateCommands.h"
#include "commands.h"

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
                exec_command_info(args);
                break;
            case 9:
                if(args.size() == 0)
                    exec_command_n();
                else
                    exec_command_n(args);
                break;
            case 10:
                exec_command_anim(game);
                break;
            case 11:
                exec_command_visanim();
                break;
            case 12:
                exec_command_store(args);
                break;
            case 13:
                exec_command_restore(args);
                break;
            case 14:
                exec_command_load(args);
                break;
            case 15:
                exec_command_slide(args);
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
    cout << " > Command: ";
    getline(cin, command);
    std::cout << "  > Command provided: " + command << std::endl;

    if(command != "exit") {
        if(!validateCommand(command)){
            cout << " # Please provide a valid command ..." << endl;
        }else{
            executeCommand(command,game);
        }
        initializeCommands(game);
    }
}

vector<string> readCommandsFile(){
    vector<string> commands;

    FILE *f = NULL;
    string fileName = "commands.txt";

    string currentCommand;
    fstream newfile;
    newfile.open(fileName,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        cout << "We have detected a commands.txt file, executing.." << endl;
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            commands.push_back(tp);
        }
        newfile.close(); //close the file object.
    }else{
        cout << " > Couldn't find any file with the name commands.txt" << endl;
    }

    return commands;
}

void handleCommands(Game* game){

    //read commands file
    std::vector<string> commandsInFile = readCommandsFile();
    if(commandsInFile.size() > 0){
        std::cout << "============================| COMMANDS FROM FILE | ============================= " << std::endl;
        for (string cmd: commandsInFile){
            cout << "#Command from file: " + cmd << endl;
            executeCommand(cmd, game);
        }
        std::cout << "=======================| END OF COMMANDS FROM FILE | ========================== " << std::endl;
    }

    std::cout << "================================| COMMANDS | ================================== " << std::endl;

    initializeCommands(game);
}
