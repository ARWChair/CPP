//
// Created by yatabay on 9/22/23.
//

#ifndef CPP_WEAPON_H
#define CPP_WEAPON_H
#pragma once
#include <iostream>


class Weapon {
public:
    Weapon();
    Weapon(std::string type);
    void    setType(std::string type);
    std::string const &getType() const;
private:
    std::string type;
};


#endif //CPP_WEAPON_H
