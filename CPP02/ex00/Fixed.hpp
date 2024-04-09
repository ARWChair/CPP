//
// Created by yatabay on 11/3/23.
//

#ifndef CPP_FIXED_HPP
#define CPP_FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const Fixed &fpn);
    ~Fixed();
    Fixed& operator=(const Fixed& copy);
    void setRawBits(int const raw);
    int getRawBits() const;
private:
    int fpValue;
    static const int fixedPoint;
};


#endif //CPP_FIXED_HPP

