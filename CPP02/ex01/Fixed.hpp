//
// Created by yannis on 11/8/23.
//

#ifndef CPP_FIXED_HPP
#define CPP_FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const Fixed& copy);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();
    Fixed& operator=(const Fixed& copy);
    float toFloat() const;
    int toInt() const;
    void setRawBits(int value);
    int getRawBits() const;
private:
    int fpValue;
    static const int fixedPoint;
};

std::ostream& operator<<(std::ostream &o, Fixed const &fixed);

#endif //CPP_FIXED_HPP

