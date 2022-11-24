//
// Created by duarte on 11-11-2022.
//
#include <iostream>
#include <fstream>
#include "commands.h"
#include "../utils/utils.h"
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

void exec_command_food(std::vector<std::string> args){
    std::cout << "  > Executing the food command" << std::endl;
    bool validFood = false;
    if ( args.size() == 2 ) {
        for( const auto &item : allowedFoodTypes){
            if(args[1]== item) {
                validFood = true;
                std::cout << "Spawning " + item + " in a random position "<< std::endl;
            }
        }
        if(validFood == false){
            std::cout << " Please insert valid a type of food" << std::endl;
        }
    }
    else if(args.size() == 4) {
        for (const auto &item: allowedFoodTypes) {
            if (args[1] == item) {
                validFood = true;
                if (isNumber(args[2]) && isNumber(args[3])) {
                    std::cout << "  > Spawning " + args[1] + " in the position: l: " + args[2] + " c:" + args[3]  << std::endl;
                }
            }
        }
        if (validFood == false) {
            std::cout << " Please insert valid a type of food or integer values on the line/column" << std::endl;
        }
    }else{
        std::cout << " Food command should look like: (food <tipo: r / t / b / a> <linha> <coluna>  or (food <tipo: r / t / b / a>)" << std::endl;
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

void exec_command_info(std::vector<std::string> args, Game* game){
    std::cout << "  > Executing the info command" << std::endl;
    if(args.size() == 2){
        if(isNumber(args[1])){
            bool found = false;
            int id = atoi(args[1].c_str());

            for (const auto &item: game->animals){
                if(item.id == id){
                    std::cout << "      [" + std::to_string(item.id) + "]" +  " " + item.identifierEmoji + "Current HP: " + std::to_string(item.currentHP) + ", MAX HP: " + std::to_string(item.maxHP) << std::endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                for (const auto &item: game->foods){
                    if(item.id == id){
                        std::cout << "      [" + std::to_string(item.id) + "]" +  " " + item.identifierEmoji + " Toxicity: " + std::to_string(item.toxicity) + " Nutritive Value: " +
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

void exec_command_anim(Game* game){
    std::cout << "  > Executing the anim command" << std::endl;
    for (const auto &item: game->animals){
        std::cout << "      [" + std::to_string(item.id) + "]" +  " " + item.identifierEmoji + "Current HP: " + std::to_string(item.currentHP) + ", MAX HP: " + std::to_string(item.maxHP) << std::endl;
    }
}

void exec_command_visanim(Game* game){
    std::cout << "  > Executing the visanim command" << std::endl;
    int defaultPresentationCols = game->configuration.size.cols * DISPLAY_AREA_PERCENTAGE;
    int defaultPresentationRows = game->configuration.size.rows * DISPLAY_AREA_PERCENTAGE;

    int currentMaxCols = defaultPresentationCols + game->configuration.screenPosition.column - 1;
    int currentMaxRows = defaultPresentationRows + game->configuration.screenPosition.row - 1;
    int minCols = game->configuration.screenPosition.column;
    int minRows = game->configuration.screenPosition.row;

    //cout << to_string(currentMaxCols) << " - " << to_string(currentMaxRows) << " - min _> " << to_string(minCols) + " . " << to_string(minRows) << endl;

    for (const auto &item: game->animals){
        if(
                item.position.row >= minRows && item.position.column >= minCols
                && item.position.row <= currentMaxRows && item.position.column <= currentMaxCols
                ){
            std::cout << "      [" + std::to_string(item.id) + "]" +  " " + item.identifierEmoji + "Current HP: " + std::to_string(item.currentHP) + ", MAX HP: " + std::to_string(item.maxHP) << std::endl;
        }
    }
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


