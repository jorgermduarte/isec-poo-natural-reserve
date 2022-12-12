//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_SHEEP_H
#define POO_NATURAL_RESERVE_SHEEP_H

#include "Animal.h"

class Sheep : public Animal {
private:
    virtual void move();
    virtual void move(Position position);
    virtual void reproduce();
    virtual void eat(Food* food);
    virtual void fight(Animal* animal);
    virtual void verifications();
public:
    static int configMaxHP;
    static int configMaxIterations;
    Sheep();
    //TODO: this function will contain all the logic representing the instant
    virtual void do_iteration() override;
};


#endif //POO_NATURAL_RESERVE_SHEEP_H
