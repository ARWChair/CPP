//
// Created by yatabay on 9/22/23.
//

#include "Zombie.hpp"

int main() {
    Zombie *zombies;
    int amount = 1;

    if (amount >= 1) {
        zombies = zombieHorde(amount, "alfred");
        if (!zombies)
            return -1;
        for (int i = 0; i < amount; i++)
            zombies[i].announce();
        delete[] zombies;
    } else
        std::cout << "Amount invalid {" << amount << "}" << std::endl;
    return 0;
}

