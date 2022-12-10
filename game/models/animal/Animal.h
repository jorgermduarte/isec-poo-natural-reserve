//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_ANIMAL_H
#define POO_NATURAL_RESERVE_ANIMAL_H

#include <string>
#include "../Position.h"
#include "../Entity.h"

class Animal {
private:
    virtual void perception();
    virtual void move() ;
    virtual void reproduce() ;
    virtual void eat() ;
    virtual void fight() ;
    virtual void verifications() ;
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
    virtual void do_iteration();
};

#endif //POO_NATURAL_RESERVE_ANIMAL_H
