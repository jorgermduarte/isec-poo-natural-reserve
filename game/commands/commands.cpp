//
// Created by duarte on 11-11-2022.
//
#include <iostream>
#include "commands.h"
#include "../utils/utils.h"
#include "../models/commands/Command.h"
#include "../models/commands/allowedTypes.h"
#include "../models/commands/allowedCommands.h"

using namespace std;

void exec_command_n(std::vector<std::string> args){
    if(args.size() == 1){
        std::cout << "  > Executing the n command" << std::endl;
    }else if (args.size() == 2){
        if(isNumber(args[1])){
            string times = args[1];
            std::cout << "  > Executing the n command times: " +  times << std::endl;
        }else{
            std::cout << "  > Sorry, we couldn't execute the n command, when passing arguments they should be numbers for the n command" << std::endl;
        }
    }else if(args.size() == 3){
        if(isNumber(args[1]) && isNumber(args[2])){
            string times = args[1];
            string sleep = args[2];
            std::cout << "  > Executing the n command times: " +  times + " with sleep cool down: " + sleep << std::endl;
        }else{
            std::cout << "  > Sorry, we couldn't execute the n command, when passing arguments they should be numbers for the n command" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the n command should contain, no args, 1 or 2 args, example: n, n<N>, n <N> <P>" << std::endl;
    }
}

void exec_command_store(std::vector<std::string> args){
    if(args.size() == 2){
        string filename = args[1];
        std::cout << "  > Executing the store command with the name: " + filename << std::endl;
    }else{
        cout << "   > The store command requires only 1 argument, example: store <name>" << endl;
    }
}

void exec_command_restore(std::vector<std::string> args){
    if(args.size() == 2){
        string filename = args[1];
        std::cout << "  > Executing the restore command with the name: " + filename << std::endl;
    }else{
        cout << "   > The restore command requires only 1 argument, example: restore <name>" << endl;
    }
}
