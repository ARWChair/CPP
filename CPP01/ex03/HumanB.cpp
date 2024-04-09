//
// Created by yatabay on 9/22/23.
//

#include "HumanB.hpp"
HumanB::HumanB(std::string name):
name(name)
{ this->weapon = NULL; }

void    HumanB::setWeapon(Weapon &type) {
    this->weapon = &type;
}

void    HumanB::setName(std::string name) {
    this->name = name;
}

Weapon  HumanB::getWeapon() {
    return *weapon;
}

std::string HumanB::getName() {
    return name;
}

void    HumanB::attack() {
    if (this->weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack" << std::endl;
}

