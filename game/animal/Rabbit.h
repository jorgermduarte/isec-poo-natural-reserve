//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_RABBIT_H
#define POO_NATURAL_RESERVE_RABBIT_H


#include "Animal.h"

class Rabbit: public Animal {
public:
    Rabbit();
    void reproduce() override;
    void move() override;
    void perceive() override;
    void triggerInstant() override;
};


#endif //POO_NATURAL_RESERVE_RABBIT_H
