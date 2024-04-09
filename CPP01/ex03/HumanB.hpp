//
// Created by yatabay on 9/22/23.
//

#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP
#pragma once
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon *weapon;
public:
    HumanB(std::string name);
    void    setName(std::string name);
    void    setWeapon(Weapon &type);
    void    attack();
    Weapon getWeapon();
    std::string getName();
};


#endif //CPP_HUMANB_HPP
