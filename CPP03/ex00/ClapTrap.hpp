//
// Created by yatabay on 11/21/23.
//

#ifndef CPP_CLAPTRAP_HPP
#define CPP_CLAPTRAP_HPP
#pragma once

#include <iostream>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(std::string name, int hitPoints = 10, int energyPoints = 10, int attackDamage = 0);
    ClapTrap(const ClapTrap& copy);
    ~ClapTrap();
    ClapTrap& operator=(ClapTrap const& copy);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void setHitPoints(int points);
    void setEnergyPoints(int points);
    void setAttackDamage(int damage);
    void setName(std::string name);
    void kill();
    bool isDead() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;
    std::string getName() const;
private:
    std::string name;
    int hitPoints, energyPoints, attackDamage;
    bool dead;
};


#endif //CPP_CLAPTRAP_HPP
