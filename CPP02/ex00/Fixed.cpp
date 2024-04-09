//
// Created by yatabay on 11/3/23.
//

#include "Fixed.hpp"

const int	Fixed::fixedPoint = 8;

Fixed::Fixed(): fpValue(0) { std::cout << "Deafult constructor called" << std::endl; }

Fixed::Fixed(const Fixed &fpn) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fpn;
}

Fixed::~Fixed() {
    std::cout << "Default destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    std::cout << "Copy assignment function called" << std::endl;
    this->fpValue = copy.fpValue;
    return *this;
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    fpValue = raw;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return fpValue;
}

