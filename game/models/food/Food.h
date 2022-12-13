//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_FOOD_H
#define POO_NATURAL_RESERVE_FOOD_H

#include <string>
#include <list>
#include "../Position.h"
#include "../Entity.h"

class Game;
class Food {
private:
    virtual void reproduce(Game* game);
    virtual void verifications(Game* game);
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
    //TODO: this function will contain all the logic representing the instant
    virtual void do_iteration(Game* game);

};


#endif //POO_NATURAL_RESERVE_FOOD_H
