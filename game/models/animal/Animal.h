//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_ANIMAL_H
#define POO_NATURAL_RESERVE_ANIMAL_H

#include <string>
#include <vector>
#include "../Position.h"
#include "../Entity.h"
#include "../food/Food.h"

class Animal {
private:
    virtual void move();
    virtual void move(Position position);
    virtual void reproduce();
    virtual void eat(Food* food);
    virtual void fight(Animal* animal);
    virtual void verifications();
public:
    Animal();
    static int configMaxHP;
    static int configMaxIterations;
    int id;
    int maxHP;
    int currentHP;
    int currentIterations = 0;
    int maxIterations;
    int hunger = 0;;
    int reprodutionCounter = 0;
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

    virtual void do_iteration();
};

#endif //POO_NATURAL_RESERVE_ANIMAL_H
