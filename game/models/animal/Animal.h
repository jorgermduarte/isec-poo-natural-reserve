//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_ANIMAL_H
#define POO_NATURAL_RESERVE_ANIMAL_H

#include <string>
#include "../Position.h"
#include "../Entity.h"

class Animal {
public:
    Animal();
    static int configMaxHP;
    static int configMaxIterations;
    int id;
    int maxHP;
    int currentHP;
    int currentIterations = 0;
    int maxIterations;
    char identifier;
    std::string identifierEmoji;
    Position position = {0,0};
    int weight;
    void feed(int nutritivePoints, int toxicityPoints);
    void display();
    void defineRandomPosition(int maxRow,int maxLine);
    void definePosition(int row, int line);
    void displayPosition();
    void setPosition(int row, int column);
    void setCurrentHP(int value);


    //TODO: this function will contain all the logic representing the instant
    virtual void triggerInstant();
    //TODO: this function should be implemented from the child classes implementing the logic when perceiving food and other animals
    virtual void perceive();
    //TODO: this function should be implemented by each child animal class
    virtual void move() ;
    //TODO: this function should be implemented by the child animals and verified if every animal have the reproduce function
    virtual void reproduce() ;
};

#endif //POO_NATURAL_RESERVE_ANIMAL_H
