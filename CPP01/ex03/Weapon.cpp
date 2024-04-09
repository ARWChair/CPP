//
// Created by yatabay on 9/22/23.
//

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) {
    setType(type);
}

void    Weapon::setType(std::string type) {
    this->type = type;
}

std::string const &Weapon::getType() const {
    return this->type;
}
