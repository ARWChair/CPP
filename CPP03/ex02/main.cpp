//
// Created by yatabay on 11/21/23.
//

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap clap("test");
    ScavTrap scav("wow");
    FragTrap frag("null");
    for (int i = 0; i < 11; i++)
        clap.attack("lol");
    clap.kill();
    clap.attack("lol");
    std::cout << std::endl;
    for (int i = 0; i < 11; i++) {
        scav.attack("cool");
    }
    scav.kill();
    scav.attack("cool");
    std::cout << std::endl;
    std::cout << std::endl;
    scav.guardGate();
    scav.guardGate();
    std::cout << std::endl;
    frag.attack("nil");
    frag.highFivesGuys();
    frag.highFivesGuys();
}
