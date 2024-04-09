//
// Created by yatabay on 10/25/23.
//

#ifndef CPP_HARL_HPP
#define CPP_HARL_HPP

#include <iostream>

class Harl {
public:
    Harl();
    void complain(std::string level);
private:
    void debug();
    void info();
    void warning();
    void error();
};


#endif //CPP_HARL_HPP
