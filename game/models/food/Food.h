//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_FOOD_H
#define POO_NATURAL_RESERVE_FOOD_H

#include <string>
#include <list>
#include "../Position.h"
#include "../Entity.h"

//TODO: verify if we can spawn food above food
//TODO: verify if lists belong to C++
//TODO: add the shared id to the Food
class Food {
private:
    virtual void reproduce() ;
    virtual void verifications() ;
public:
    static int configMaxIterations;
    int currentIterations = 0;
    int maxIterations;
    int id;
    char identifier;
    std::string identifierEmoji;
    Position position = {0,0};
    int nutritiveValue;
    int toxicity;
    std::list<int> smells;
    Food();
    void display();
    void defineRandomPosition(int maxRow,int maxLine);

    void definePosition(int row, int line);
    void isFoodAvailable();
    void incrementLifeTick();

    //TODO: this function will contain all the logic representing the instant
    virtual void do_iteration();

};


#endif //POO_NATURAL_RESERVE_FOOD_H
