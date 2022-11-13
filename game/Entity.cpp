//
// Created by duarte on 13-11-2022.
//

#include "Entity.h"

//static
int Entity::id = 0;

int Entity::defineNewId() {
    Entity::id = Entity::id + 1;
    return Entity::id;
}
