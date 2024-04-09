//
// Created by yatabay on 11/22/23.
//

#ifndef CPP_SCAVTRAP_HPP
#define CPP_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
    ScavTrap();
    ScavTrap(std::string name, int hitPoints = 100, int attackDamage = 50, int energyPoints = 20);
    ScavTrap(const ScavTrap& copy);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& copy);
    void guardGate();
    void setGuarding(bool state);
    bool isGuarding() const;
private:
    bool guarding;
};


#endif //CPP_SCAVTRAP_HPP
