//
// Created by yatabay on 11/21/23.
//

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("test");
    ScavTrap scav("wow");
    for (int i = 0; i < 11; i++)
        clap.attack("lol");
    clap.kill();
    clap.attack("lol");
    for (int i = 0; i < 11; i++) {
        scav.attack("cool");
    }
    scav.kill();
    scav.attack("cool");
    scav.guardGate();
    scav.guardGate();
}
