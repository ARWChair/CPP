//
// Created by yatabay on 11/13/23.
//

#ifndef CPP_FIXED_HPP
#define CPP_FIXED_HPP
#pragma once

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed();
    Fixed(const Fixed& copy);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed(void);
    int toInt() const;
    float toFloat() const;
    void setRawBits(int value);
    int getRawBits() const;
    Fixed& operator=(const Fixed& copy);
    int operator<(Fixed const &copy) const;
    int operator>(Fixed const &copy) const;
    int operator>=(Fixed const &copy) const;
    int operator<=(Fixed const &copy) const;
    int operator==(Fixed const &copy) const;
    int operator!=(Fixed const &copy) const;
    Fixed operator++(int);
    Fixed& operator++(void);
    Fixed operator--(int);
    Fixed& operator--(void);
    Fixed operator-(Fixed const &second) const;
    Fixed operator+(Fixed const &second) const;
    Fixed operator*(Fixed const &second) const;
    Fixed operator/(Fixed const &second) const;
    static const Fixed& max(const Fixed &a, const Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
private:
    static const int fixedPoint;
    int fpValue;
};

std::ostream& operator<<(std::ostream &o, Fixed const &b);

#endif //CPP_FIXED_HPP

