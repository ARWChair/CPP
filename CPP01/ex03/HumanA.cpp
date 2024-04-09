//
// Created by yatabay on 9/22/23.
//

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):
name(name),
weapon(weapon)
{}

void    HumanA::setWeapon(Weapon type) {
    this->weapon = type;
}

void    HumanA::setName(std::string name) {
    this->name = name;
}

Weapon  HumanA::getWeapon() {
    return weapon;
}

std::string HumanA::getName() {
    return name;
}

void    HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

