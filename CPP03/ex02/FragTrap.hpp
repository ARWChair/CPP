//
// Created by yatabay on 11/22/23.
//

#ifndef CPP_FRAGTRAP_HPP
#define CPP_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
public:
    FragTrap();
    FragTrap(std::string name, int hitPoints = 100, int energyPoints = 100, int attackDamage = 30);
    FragTrap(FragTrap const &copy);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& copy);
    void highFivesGuys(void);
    void setHighFives(int amount);
    int getHighFives() const;
private:
    int highFives;
};


#endif //CPP_FRAGTRAP_HPP
