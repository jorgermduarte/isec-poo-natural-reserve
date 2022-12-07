//
// Created by duarte on 07-12-2022.
//

#include <unordered_map>
#include <iostream>
#include "Command.h"
#include "../../user_interface/userInterface.h"
#include "../../commands/commands.h"
#include "allowedCommands.h"
#include "../../commands/InfoCommand.h"
#include "../../commands/AnimCommand.h"
#include "../../commands/VisAnimCommand.h"
#include "../../commands/LoadCommand.h"
#include "../../commands/SlideCommand.h"

using namespace std;

// for string delimiter
// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

bool Command::validate(std::string &command) {
    // validate the arguments size
    bool validArgumentsSize = validateArgumentsSize(command);
    if(!validArgumentsSize){
        return false;
    }

    // retrieve the arguments
    vector<string> arguments = getArguments(command);

    //verify if the argument[0] (command type) exists on the map (allowed command)
    std::unordered_map<std::string,int>::const_iterator got = allowedCommands.find(arguments[0]);
    if(got == allowedCommands.end()){
        //we couldn't find any command available for the argument provided
        return false;
    }

    return true;
}

bool Command::validateArgumentsSize(std::string &command) {
    vector<string> args = split(command," ");
    if(args.size() > MAX_ARGUMENTS_SIZE) {
        return false;
    }else{
        return true;
    }
}

std::vector<std::string> Command::getArguments(std::string &command) {
    vector<string> args = split(command," ");
    return args;
}

void Command::execute(std::string &command, Game *game) {
    vector<string> args = getArguments(command);

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
                (new InfoCommand(game,args))->execute();
                break;
            case 9:
                exec_command_n(args);
                break;
            case 10:
                (new AnimCommand(game))->execute();
                break;
            case 11:
                (new VisAnimCommand(game))->execute();
                break;
            case 12:
                exec_command_store(args);
                break;
            case 13:
                exec_command_restore(args);
                break;
            case 14:
                (new LoadCommand(game,args))->execute();
                break;
            case 15:
                (new SlideCommand(game,args))->execute();
                break;
            case 16:
                exec_command_killid(args);
                break;
            default:
                break;
        }
    }else{
        std::cout << "   > Invalid command detected " << std::endl;
    }
}

void Command::handleCommands(Game *game) {
    std::string command;
    std::cout << "================================| COMMANDS | ================================== " << std::endl;
    cout << " > Command: ";
    getline(cin, command);
    std::cout << "  > Command provided: " + command << std::endl;

    if(command != "exit") {
        if(!validate(command)){
            cout << " # Please provide a valid command ..." << endl;
        }else{
            execute(command,game);
        }
        displayNaturalReserve(*game);
        displayAnimals(*game);
        handleCommands(game);
    }
}