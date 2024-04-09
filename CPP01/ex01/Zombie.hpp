//
// Created by yatabay on 9/22/23.
//

#ifndef CPP_ZOMBIE_H
#define CPP_ZOMBIE_H
#include <iostream>
#pragma once

class Zombie {
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void    announce(void);
    void    setName(std::string);
    std::string getName();
private:
    std::string name;
};

Zombie  *zombieHorde(int N, std::string name);

#endif //CPP_ZOMBIE_H
