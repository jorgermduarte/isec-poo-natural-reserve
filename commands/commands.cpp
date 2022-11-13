//
// Created by duarte on 11-11-2022.
//
#include <iostream>
#include "commands.h"
#include "../game/game/Game.h"

void exec_command_animal(std::vector<std::string> args){
    std::cout << "  > Executing the animal command" << std::endl;
}
void exec_command_kill(std::vector<std::string> args){
    std::cout << "  > Executing the kill command" << std::endl;
}
void exec_command_food(std::vector<std::string> args){
    std::cout << "  > Executing the food command" << std::endl;
}
void exec_command_feed(std::vector<std::string> args){
    std::cout << "  > Executing the feed command" << std::endl;
}
void exec_command_feedid(std::vector<std::string> args){
    std::cout << "  > Executing the feedid command" << std::endl;
}
void exec_command_nofood(std::vector<std::string> args){
    std::cout << "  > Executing the nofood command" << std::endl;
}
void exec_command_empty(std::vector<std::string> args){
    std::cout << "  > Executing the empty command" << std::endl;
}
void exec_command_see(std::vector<std::string> args){
    std::cout << "  > Executing the see command" << std::endl;
}
void exec_command_info(std::vector<std::string> args){
    std::cout << "  > Executing the info command" << std::endl;
}
void exec_command_n(){
    std::cout << "  > Executing the n command" << std::endl;
}
void exec_command_n(std::vector<std::string> args){
    std::cout << "  > Executing the n command with args" << std::endl;
}
//TODO: required for the first meta
void exec_command_anim(){
    std::cout << "  > Executing the anim command" << std::endl;
}
//TODO: required for the first meta
void exec_command_visanim(){
    std::cout << "  > Executing the visanim command" << std::endl;
}
void exec_command_store(std::vector<std::string> args){
    std::cout << "  > Executing the store command" << std::endl;
}
void exec_command_restore(std::vector<std::string> args){
    std::cout << "  > Executing the restore command" << std::endl;
}
void exec_command_load(std::vector<std::string> args){
    std::cout << "  > Executing the load command" << std::endl;
}

//TODO: required for the first meta
void exec_command_slide(std::vector<std::string> args){
    std::cout << "  > Executing the slide command" << std::endl;
}
