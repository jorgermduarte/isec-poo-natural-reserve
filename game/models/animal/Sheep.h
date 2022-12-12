//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_SHEEP_H
#define POO_NATURAL_RESERVE_SHEEP_H

#include "Animal.h"

class Sheep : public Animal {
private:
    virtual void move(Game* game) override;
    virtual void move(Game* game,Position position) override;
    virtual void reproduce(Game* game) override;
    virtual void eat(Game* game, Food* food) override;
    virtual void fight(Game* game,Animal* animal) override;
    virtual void verifications(Game* game) override;
public:
    static int configMaxHP;
    static int configMaxIterations;
    Sheep();
    virtual void do_iteration(Game* game) override;
};


#endif //POO_NATURAL_RESERVE_SHEEP_H
