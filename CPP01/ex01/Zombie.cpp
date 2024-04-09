//
// Created by yatabay on 9/22/23.
//

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) {
    setName(name);
}

Zombie::~Zombie() {
    std::cout << name << ": Got destroyed" << std::endl;
}

void    Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name) {
    this->name = name;
}

std::string Zombie::getName() {
    return name;
}

