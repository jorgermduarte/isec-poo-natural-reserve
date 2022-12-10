//
// Created by duarte on 10-12-2022.
//

#include <iostream>
#include "NCommand.h"
#include "../utils/utils.h"

//TODO: Implement the n command
void NCommand::execute() {
    if(args.size() == 1){
        std::cout << "  > Executing the n command" << std::endl;
    }else if (args.size() == 2){
        if(isNumber(args[1])){
            std::string times = args[1];
            std::cout << "  > Executing the n command times: " +  times << std::endl;
        }else{
            std::cout << "  > Sorry, we couldn't execute the n command, when passing arguments they should be numbers for the n command" << std::endl;
        }
    }else if(args.size() == 3){
        if(isNumber(args[1]) && isNumber(args[2])){
            std::string times = args[1];
            std::string sleep = args[2];
            std::cout << "  > Executing the n command times: " +  times + " with sleep cool down: " + sleep << std::endl;
        }else{
            std::cout << "  > Sorry, we couldn't execute the n command, when passing arguments they should be numbers for the n command" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the n command should contain, no args, 1 or 2 args, example: n, n<N>, n <N> <P>" << std::endl;
    }
}
