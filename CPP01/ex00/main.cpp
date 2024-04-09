//
// Created by yatabay on 9/22/23.
//

#include "Zombie.hpp"

int main() {
    std::string name = "Foo";
    Zombie zombie(name);
    zombie.announce();
    Zombie *zombie2;
    zombie2 = newZombie(name + "2");
    delete zombie2;
    return 0;
}

