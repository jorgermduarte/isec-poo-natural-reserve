//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_RABBIT_H
#define POO_NATURAL_RESERVE_RABBIT_H

#include "Animal.h"

class Rabbit: public Animal {
private:
    virtual void move(Game* game) override;
    virtual void move(Game* game,Position position) override;
    virtual void reproduce(Game* game)  override;
    virtual void eat(Game* game, Food* food)  override;
    virtual void fight(Game* game, Animal* animal)  override;
    virtual void verifications(Game* game)  override;
public:
    static int configMaxHP;
    static int configMaxIterations;
    Rabbit();
    //TODO: this function will contain all the logic representing the instant
    virtual void do_iteration(Game* game) override;
};


#endif //POO_NATURAL_RESERVE_RABBIT_H
