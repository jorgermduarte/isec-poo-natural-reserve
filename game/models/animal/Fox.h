//
// Created by duarte on 07-12-2022.
//

#ifndef POO_NATURAL_RESERVE_FOX_H
#define POO_NATURAL_RESERVE_FOX_H


#include "Animal.h"

class Fox: public Animal{
public:
    static int configMaxHP;
    Fox();
    void reproduce() override;
    void move() override;
    void perceive() override;
    void triggerInstant() override;
};


#endif //POO_NATURAL_RESERVE_FOX_H
