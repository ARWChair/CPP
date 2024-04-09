//
// Created by yatabay on 9/22/23.
//

#ifndef CPP_HUMANA_H
#define CPP_HUMANA_H
#pragma once
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon &weapon;
public:
    HumanA(std::string name, Weapon &type);
    void    setName(std::string name);
    void    setWeapon(Weapon type);
    void    attack();
    Weapon getWeapon();
    std::string getName();
};


#endif //CPP_HUMANA_H
