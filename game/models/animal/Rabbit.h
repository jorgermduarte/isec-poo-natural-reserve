//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_RABBIT_H
#define POO_NATURAL_RESERVE_RABBIT_H

#include "Animal.h"

class Rabbit: public Animal {
private:
    virtual void perception() override;
    virtual void move() override;
    virtual void reproduce()  override;
    virtual void eat()  override;
    virtual void fight()  override;
    virtual void verifications()  override;
public:
    static int configMaxHP;
    static int configMaxIterations;
    Rabbit();
    //TODO: this function will contain all the logic representing the instant
    virtual void do_iteration() override;
};


#endif //POO_NATURAL_RESERVE_RABBIT_H
