cmake_minimum_required(VERSION 3.23)
project(poo_natural_reserve)

set(CMAKE_CXX_STANDARD 14)

add_executable(poo_natural_reserve main.cpp userInterface/useInterface.cpp userInterface/useInterface.h commands/validateCommands.cpp commands/validateCommands.h services/GameService.cpp services/GameService.h commands/handleCommands.h commands/handleCommands.cpp game/food/Food.cpp game/food/Food.h game/food/Grass.cpp game/food/Grass.h game/enums/Smell.cpp game/enums/Smell.h game/Position.cpp game/Position.h game/animal/Animal.cpp game/animal/Animal.h game/animal/Rabbit.cpp game/animal/Rabbit.h game/game/MatrixCell.cpp game/game/MatrixCell.h game/game/MatrixSize.cpp game/game/MatrixSize.h game/game/GameConfiguration.cpp game/game/GameConfiguration.h game/game/Game.cpp game/game/Game.h game/animal/Sheep.cpp game/animal/Sheep.h commands/commands.h commands/commands.cpp)
