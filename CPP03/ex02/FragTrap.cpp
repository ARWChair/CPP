//
// Created by yatabay on 11/22/23.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() { std::cout << "FragTrap default constructor called" << std::endl; }

FragTrap::FragTrap(std::string name, int hitPoints, int energyPoints, int attackDamage): highFives(0) {
    std::cout << "FragTrap constructor called" << std::endl;
    setName(name);
    setEnergyPoints(energyPoints);
    setAttackDamage(attackDamage);
    setHitPoints(hitPoints);
    setObject("FragTrap");
    this->dead = false;
}

FragTrap::~FragTrap() { std::cout << "FragTrap default destructor called" << std::endl; }

FragTrap &FragTrap::operator=(const FragTrap &copy) {
    std::cout << "Operator = called" << std::endl;
    if (this != &copy) {
        this->name = copy.name;
        this->dead = copy.dead;
        this->hitPoints = copy.hitPoints;
        this->attackDamage = copy.attackDamage;
        this->energyPoints = copy.energyPoints;
        this->highFives = copy.highFives;
    }
    return (*this);
}

void FragTrap::highFivesGuys(void) {
    int amount = getHighFives();
    setHighFives(++amount);
    std::cout << "High-fives: " << amount << std::endl;
}

void FragTrap::setHighFives(int amount) { this->highFives = amount; }

int FragTrap::getHighFives() const { return highFives; }
