//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_GRASS_H
#define POO_NATURAL_RESERVE_GRASS_H

#include "Food.h"

class Grass: public Food{
private:
    virtual void reproduce() ;
    virtual void verifications() ;
public:
    static int configMaxIterations;
    Grass();
    //TODO: this function will contain all the logic representing the instant
    virtual void do_iteration() override;
};


#endif //POO_NATURAL_RESERVE_GRASS_H
