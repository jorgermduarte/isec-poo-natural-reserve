//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_WOLF_H
#define POO_NATURAL_RESERVE_WOLF_H


#include "Animal.h"

class Wolf: public Animal {
public:
    static int configMaxHP;
    static int configMaxIterations;
    Wolf();
    void reproduce() override;
    void move() override;
    void perceive() override;
    void triggerInstant() override;
};


#endif //POO_NATURAL_RESERVE_WOLF_H
