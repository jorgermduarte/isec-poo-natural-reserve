//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_GRASS_H
#define POO_NATURAL_RESERVE_GRASS_H

#include "Food.h"

class Grass: public Food{
private:
    virtual void reproduce(Game* game) override;
    virtual void verifications(Game* game) override;
public:
    static int configMaxIterations;
    Grass();
    virtual void do_iteration(Game* game) override;
};


#endif //POO_NATURAL_RESERVE_GRASS_H
