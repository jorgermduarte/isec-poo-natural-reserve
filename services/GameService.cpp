//
// Created by duarte on 10-11-2022.
//

#include <limits>
#include <fstream>
#include "../commands/handleCommands.h"
#include "../userInterface/useInterface.h"
#include "GameService.h"
#include "../game/animal/Rabbit.h"
#include "../game/animal/Sheep.h"
#include "../game/food/Grass.h"
#include "../commands/validateCommands.h"
#include "../utils/utils.h"

void GameService::defineNaturalReserveConfiguration() {
    int length = 0;
    int height = 0;
    bool failedValidations = false;

    cout << "Please provide the length of the natural reserve, value between 5-500" << endl;
    cout << "Length: ";
    cin >> length;

    if(!std::cin.good())
        failedValidations = true;

    if(!failedValidations){
        cout << "Please provide the height of the natural reserve, value between 5-500" << endl;
        cout << "Height: ";
        cin >> height;
    }

    if(!std::cin.good())
       failedValidations = true;

    if(failedValidations){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << " > Something went wrong defining the values of the natural reserve" << endl;
        cout << " > Please provide them again..." << endl;
        this->defineNaturalReserveConfiguration();
    }else{
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

        this->game.configuration.setMatrixSize(height,length);
        this->game.configuration.displayMatrixSize();
    }
}

void GameService::initializeMatrix() {
    int x,y;
    for( x = 0; x < this->game.configuration.size.cols; x++){
        vector<MatrixCell> col = {};
        for(y = 0; y < this->game.configuration.size.rows; y++){
            col.push_back(MatrixCell(x,y));
            //cout << " > created cell -> x:" + to_string(x) + " y: " + to_string(y) << endl;
        }
        this->game.matrix.push_back(col);
    }
    //cout << " > num rows configured: " + to_string(this->game.matrixGetNumRows()) + " cols: " + to_string(this->game.matrixGetNumColumns()) << endl;
}

void GameService::readConstantsFile() {
    std::vector<std::string> commands;
    FILE *f = NULL;

    std::string currentCommand;
    fstream newfile;
    string fileName = "constantes.txt";

    newfile.open(fileName,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        std::cout << "============================| CONSTANTS  -  FILE | ============================ " << std::endl;

        cout << "We have detected the a configuration file, executing.." << endl;
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            commands.push_back(tp);
        }
        newfile.close(); //close the file object.
    }

    if(commands.size() > 0){

        //do something with the commands from the file
        for (string item: commands){

            if(item.size() > 1){
                cout << "   > executing configuration setting: " + item << endl;
                vector<string> args = getCommandArguments(item);

                if(args.size() >= 2){
                    //handling definitions for animals
                    if(args[0] == "SSheep"){
                        if(isNumber(args[1])){
                            Sheep::maxHP = stoi(args[1]);
                        }else{
                            cout << "   > Invalid second parameter detected for the sheep configuration" << endl;
                        }
                    }
                    //handling definitions for animals
                    if(args[0] == "SRabbit"){
                        if(isNumber(args[1])){
                            Rabbit::maxHP = stoi(args[1]);
                        }else{
                            cout << "   > Invalid second parameter detected for the sheep configuration" << endl;
                        }
                    }
                }else{
                    cout << "   > line detected with ony with one argument" << endl;
                }
            }else{
                cout << "   > empty line configuration detected " << endl;
            }
        }

        std::cout << "==========================| END OF CONSTANTS FILE | =========================== " << std::endl;

    }
}

void GameService::initialize() {
    std::cout << "           \U0001f334 \U0001f334 \U0001f334 Welcome to the natural reserve \U0001f334 \U0001f334 \U0001f334 " << std::endl;
    std::cout << "========================================================================" << std::endl;
    this->defineNaturalReserveConfiguration();
    //set the matrix with the default values
    this->initializeMatrix();

    readConstantsFile();

    //TODO: remove the rabbit test ( test purposes)
    Rabbit rabbit = {};
    Sheep sheep = {};
    Grass grass = {};
    grass.defineRandomPosition(this->game.configuration.size.rows,this->game.configuration.size.cols);
    rabbit.defineRandomPosition(this->game.configuration.size.rows,this->game.configuration.size.cols);
    sheep.defineRandomPosition(this->game.configuration.size.rows,this->game.configuration.size.cols);

    this->game.addAnimal(rabbit);
    this->game.addAnimal(sheep);
    this->game.addFood(grass);

    displayNaturalReserve(this->game);
    displayAnimals(this->game);
    handleCommands(&this->game);
}
