//
// Created by duarte on 11-11-2022.
//

#ifndef POO_NATURAL_RESERVE_SHEEP_H
#define POO_NATURAL_RESERVE_SHEEP_H

#include "Animal.h"

class Sheep : public Animal {
public:
    static int configMaxHP;
    Sheep();
    void reproduce() override;
    void move() override;
    void perceive() override;
    void triggerInstant() override;
};


#endif //POO_NATURAL_RESERVE_SHEEP_H
