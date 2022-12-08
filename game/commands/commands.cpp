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

void exec_command_kill(std::vector<std::string> args){
    std::cout << "  > Executing the kill command" << std::endl;

    if (args.size() == 3){
        //kill entities at a given position args[1] and args[2]
        std::string line = args[1];
        std::string column = args[2];
        if (isNumber(line) && isNumber(column)) {
            std::cout << "  > killing the animal in the position: l: " + args[1] + " c:" + args[2] << std::endl;
        } else {
            std::cout << "  > Invalid command provided, the line and columns arguments must be integers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the kill command can be kill <line> <column>> " << std::endl;
    }
}

void exec_command_killid(std::vector<std::string> args){
    std::cout << "  > Executing the killid command" << std::endl;
    if(args.size()== 2){
        if(isNumber(args[1])){
            //kill an entity id on args[1];
            std::cout << "  > killing the animal with id: " + args[1] << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the id must be an integer" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the killid command should be be killid <id> " << std::endl;
    }
}

void exec_command_feed(std::vector<std::string> args){
    if(args.size() == 5){
        //line col, nutritive_value toxicity_points
        if(isNumber(args[1]) && isNumber(args[2]) && isNumber(args[3]) && isNumber(args[4])){
            string line = args[1];
            string col = args[2];
            string nutritivePoints = args[3];
            string toxicityPoints = args[4];
            std::cout << "  > Executing the feed command for line " + line + ", col "+ col + ", nutritive value: " + nutritivePoints + ", toxicity points: "+ toxicityPoints   << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the feed command arguments should be all numbers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the feed command must contain 4 arguments, example: feed <line> <column> <nutritive points> <toxicty points> " << std::endl;
    }
}

void exec_command_feedid(std::vector<std::string> args){
    if(args.size() == 4){
        //line col, nutritive_value toxicity_points
        if(isNumber(args[1]) && isNumber(args[2]) && isNumber(args[3])){
            string id = args[1];
            string nutritivePoints = args[2];
            string toxicityPoints = args[3];
            std::cout << "  > Executing the feedid command for id " + id + ", nutritive value: " + nutritivePoints + ", toxicity points: "+ toxicityPoints   << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the feedid command arguments should be all numbers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the feedid command must contain 3 arguments, example: feed <id> <nutritive points> <toxicty points> " << std::endl;
    }
}

void exec_command_nofood(std::vector<std::string> args){
    if(args.size() == 3){
        if(isNumber(args[1]) && isNumber(args[2])){
            string line = args[1];
            string column = args[2];
            std::cout << "  > Executing the nofood command for the line: " + line +" and column: " + column << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the nofood command arguments should be numbers" << endl;
        }
    }else if(args.size() == 2){
        if(isNumber(args[1])){
            string id = args[1];
            std::cout << "  > Executing the nofood command for the id: " + id << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the nofood command arguments should be numbers" << endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the nofood command must contain 2 arguments, example: nofood <ID>, or nofood <line> <column>" << std::endl;
    }
}

void exec_command_empty(std::vector<std::string> args){
    if(args.size() == 3){
        if(isNumber(args[1]) && isNumber(args[2])){
            string line = args[1];
            string column = args[2];
            std::cout << "  > Executing the empty command for line: " + line + " and column: " + column << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the empty command arguments should be numbers" << endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the empty command must contain only 2 arguments, example: empty <line> <column>" << std::endl;
    }
}

void exec_command_see(std::vector<std::string> args){
    if(args.size() == 3){
        if(isNumber(args[1]) && isNumber(args[2])) {
            string line = args[1];
            string column = args[2];
            std::cout << "  > Executing the see command for line: " + line + " and column: " + column << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the see command must contain only 2 arguments, example: see <line> <column>" << std::endl;
    }

}

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
    };

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
