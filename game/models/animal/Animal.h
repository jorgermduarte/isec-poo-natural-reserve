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

class Game;

class Animal {
private:
    virtual void move(Game* game);
    virtual void move(Game* game, Position position);
    virtual void reproduce(Game* game);
    virtual void eat(Game* game, Food* food);
    virtual void fight(Game* game, Animal* animal);
    virtual void verifications(Game* game);
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
    int progenitorId = -1;
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

    virtual void do_iteration(Game* game);
};

#endif //POO_NATURAL_RESERVE_ANIMAL_H
