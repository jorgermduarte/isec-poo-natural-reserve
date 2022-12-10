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
    }else{
        std::cout << "   > The restore command requires only 1 argument, example: restore <name>" << std::endl;
    }
}
