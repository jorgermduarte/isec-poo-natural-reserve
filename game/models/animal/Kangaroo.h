//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_KANGAROO_H
#define POO_NATURAL_RESERVE_KANGAROO_H


#include "Animal.h"

class Kangaroo : public Animal {
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
    Kangaroo();
    //TODO: this function will contain all the logic representing the instant
    virtual void do_iteration() override;
};

#endif //POO_NATURAL_RESERVE_KANGAROO_H
