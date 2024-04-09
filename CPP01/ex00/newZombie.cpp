//
// Created by yatabay on 9/22/23.
//

#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
    Zombie *zombie = new Zombie(name);
    zombie->announce();
    return zombie;
}

