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
    int currentLifetime;
    bool available;
public:
    int id;
    char identifier;
    std::string identifierEmoji;
    Position position = {0,0};
    int nutritiveValue;
    int toxicity;
    std::list<int> smells;
    int maxLifetime;
    Food();
    void isFoodAvailable();
    void incrementLifeTick();
    void defineRandomPosition(int maxRow,int maxLine);

};


#endif //POO_NATURAL_RESERVE_FOOD_H
