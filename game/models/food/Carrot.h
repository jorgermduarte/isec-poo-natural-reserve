//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_CARROT_H
#define POO_NATURAL_RESERVE_CARROT_H


#include "Food.h"

class Carrot: public Food{
private:
    virtual void reproduce() ;
    virtual void verifications() ;
public:
    static int configMaxIterations;
    Carrot();
    //TODO: this function will contain all the logic representing the instant
    virtual void do_iteration() override;
};


#endif //POO_NATURAL_RESERVE_CARROT_H
