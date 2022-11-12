//
// Created by duarte on 10-11-2022.
//

#include "Rabbit.h"

Rabbit::Rabbit() {
    this->identifier = "\U0001f407";
    this->maxLifetime = 20;
    this->health = 20;
    this->weight = rand() % 4 + 1;
}


//TODO: verify the tick inspection and implement it
/*
void Rabbit::tickInspection() {
    //for every tick, the hunger of the animal increases by one
    if(this->hunger < 10){
        this->hunger++;
    } else if(this->hunger > 20)
    {
        this->health = this->health - 2;
        //TODO: implement the wings movement that the animal receives apparently
        // the animal moves 1-4 positions each time
    }else {
        this->health--;
        //TODO: implement the wings movement that the animal receives apparently
        // the animal moves 1-3 positions each time
    }

}
*/