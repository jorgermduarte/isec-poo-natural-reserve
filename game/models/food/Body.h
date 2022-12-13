//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_BODY_H
#define POO_NATURAL_RESERVE_BODY_H


#include "Food.h"


class Body: public Food{
private:
    virtual void reproduce(Game* game) override;
    virtual void verifications(Game* game) override;
public:
    static int configMaxIterations;
    Body();
    virtual void do_iteration(Game* game) override;
};


#endif //POO_NATURAL_RESERVE_BODY_H
