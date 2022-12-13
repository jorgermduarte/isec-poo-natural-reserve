//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_CARROT_H
#define POO_NATURAL_RESERVE_CARROT_H


#include "Food.h"

class Carrot: public Food{
private:
    virtual void reproduce(Game* game) override;
    virtual void verifications(Game* game) override;
public:
    static int configMaxIterations;
    Carrot();
    virtual void do_iteration(Game* game) override;
};


#endif //POO_NATURAL_RESERVE_CARROT_H
