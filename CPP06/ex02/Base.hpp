#ifndef BASE_HPP
# define BASE_HPP
# pragma once
# include <cstdlib>
# include <iostream>
# pragma once

class Base {
    public:
        virtual ~Base();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
