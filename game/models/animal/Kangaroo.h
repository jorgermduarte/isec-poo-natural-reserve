//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_KANGAROO_H
#define POO_NATURAL_RESERVE_KANGAROO_H


#include "Animal.h"

class Kangaroo : public Animal {
private:
private:
    virtual void move(Game* game) override;
    virtual void move(Game* game,Position position) override;
    virtual void reproduce(Game* game) override;
    virtual void eat(Game* game,Food* food) override;
    virtual void fight(Game* game,Animal* animal) override;
    virtual void verifications(Game* game) override;
    bool onMarsupial = false;
    int onMarsupialInstants = 0;
public:
    static int configMaxHP;
    static int configMaxIterations;
    Kangaroo();
    //TODO: this function will contain all the logic representing the instant
    virtual void do_iteration(Game* game) override;
};

#endif //POO_NATURAL_RESERVE_KANGAROO_H
