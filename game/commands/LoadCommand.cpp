//
// Created by duarte on 07-12-2022.
//

#include <iostream>
#include <fstream>
#include "LoadCommand.h"
#include "../models/commands/Command.h"

using namespace std;

void LoadCommand::execute() {
    std::cout << "  > Executing the load command" << std::endl;

    if(args.size() == 2){
        //read commands file
        std::vector<std::string> commands;
        FILE *f = NULL;

        std::string currentCommand;
        std::fstream newfile;
        newfile.open(args[1],std::ios::in); //open a file to perform read operation using file object
        newfile.ignore(3); // this is to prevent errors on the first line from the environments files
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
                Command::execute(cmd, game);
            }
            std::cout << "=======================| END OF COMMANDS FROM FILE | ========================== " << std::endl;
        }

    }else{
        std::cout << "  > Invalid command provided, the load command requires only one argument the file-name, example: load file-name.txt " << endl;
    }

}