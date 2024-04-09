//
// Created by yatabay on 11/21/23.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage):object("ClapTrap"), dead(false) {
    std::cout << "ClapTrap constructor called" << std::endl;
    setName(name);
    setEnergyPoints(energyPoints);
    setHitPoints(hitPoints);
    setAttackDamage(attackDamage);
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    std::cout << "Copy ClapTrap constructor called" << std::endl;
    this->name = copy.name;
    this->dead = copy.dead;
    this->attackDamage = copy.attackDamage;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
}

ClapTrap::~ClapTrap() {
    std::cout << "Default ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "ClapTrap copy assigment operator called" << std::endl;
    this->name = copy.name;
    this->dead = copy.dead;
    this->attackDamage = copy.attackDamage;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (getEnergyPoints() <= 0 && !isDead()) {
        std::cout << "Cant attack " << target << ". " << getObject() << " " << getName() << " is out of energy" << std::endl;
        return;
    } else if (isDead()) {
        std::cout << "Cant attack " << target << ". " << getObject() << " " << getName() << " is dead" << std::endl;
        return;
    }
    std::cout << getObject() << " " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage" << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (isDead()) {
        std::cout << getObject() << " " << getName() << " cant take damage. He is already dead" << std::endl;
        return;
    }
    setHitPoints(getHitPoints() - amount);
    if (getHitPoints() <= 0)
        kill();
    if (isDead())
        std::cout << getObject() << " " << getName() << " died" << std::endl;
    else
        std::cout << getObject() << " " << getName() << " took " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (getEnergyPoints() <= 0 && !isDead()) {
        std::cout << getObject() << " " << getName() << " cant repair itself, because it is out of energy" << std::endl;
        return;
    } else if (isDead()) {
        std::cout << getObject() << " " << getName() << " cant repair itself. he is dead" << std::endl;
        return;
    }
    std::cout << getObject() << " " << getName() << " repaired itself " << amount << " times" << std::endl;
    setHitPoints(amount);
    setEnergyPoints(getEnergyPoints() - 1);
}

void ClapTrap::setHitPoints(int points) { this->hitPoints = points; }

void ClapTrap::setEnergyPoints(int points) { this->energyPoints = points; }

void ClapTrap::setAttackDamage(int damage) { this->attackDamage = damage; }

void ClapTrap::setName(std::string name) { this->name = name; }

void ClapTrap::setObject(std::string object) { this->object = object; }

void ClapTrap::kill() { this->dead = !dead; }

bool ClapTrap::isDead() const { return dead; }

std::string ClapTrap::getName() const { return name; }

std::string ClapTrap::getObject() const { return object; }

int ClapTrap::getEnergyPoints() const { return energyPoints; }

int ClapTrap::getHitPoints() const { return hitPoints; }

int ClapTrap::getAttackDamage() const { return attackDamage; }
