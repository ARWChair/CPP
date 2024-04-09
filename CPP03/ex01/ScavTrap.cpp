//
// Created by yatabay on 11/22/23.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() { std::cout << "Default ScavTrap constructor called" << std::endl; }

ScavTrap::ScavTrap(std::string name, int hitPoints, int attackDamage, int energyPoints): guarding(false) {
    std::cout << "ScavTrap constructor called" << std::endl;
    setName(name);
    setHitPoints(hitPoints);
    setAttackDamage(attackDamage);
    setEnergyPoints(energyPoints);
    setObject("ScavTrap");
    this->dead = false;
}

ScavTrap::~ScavTrap() { std::cout << "Default ScavTrap destructor called" << std::endl; }

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
    std::cout << "ScavTrap = operator called" << std::endl;
    if (this != &copy) {
        this->name = copy.name;
        this->dead = copy.dead;
        this->attackDamage = copy.attackDamage;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
    }
    this->guarding = copy.guarding;
    return *this;
}

void ScavTrap::guardGate() {
    setGuarding(!isGuarding());
    if (isGuarding())
        std::cout << "ScavTrap " << getName() << " now guarding the gate" << std::endl;
    else
        std::cout << "ScavTrap " << getName() << " stopped guarding the gate" << std::endl;
}

void ScavTrap::setGuarding(bool state) { this->guarding = state; }

bool ScavTrap::isGuarding() const { return guarding; }
