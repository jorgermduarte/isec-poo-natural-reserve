#include "DefaultCommand.h"
#include "iostream"

DefaultCommand::DefaultCommand(Game *game) {
    this->game = game;
}

DefaultCommand::DefaultCommand(Game *game, std::vector<std::string> args) {
    this->game = game;
    this->args = args;
}

void DefaultCommand::execute() {
    std::cout << "Invalid command. Please provide a valid command." << std::endl;
}