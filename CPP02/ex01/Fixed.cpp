//
// Created by yannis on 11/8/23.
//

#include "Fixed.hpp"

const int Fixed::fixedPoint = 8;

Fixed::Fixed(): fpValue(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    this->fpValue = copy.fpValue;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    fpValue = value << fixedPoint;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    float temp = value * (1 << fixedPoint);
    setRawBits((int)roundf(temp));
}

Fixed::~Fixed() { std::cout << "Default destructor called" << std::endl; }

int Fixed::toInt() const {
    std::cout << "toInt function called" << std::endl;
    return fpValue >> fixedPoint;
}

float Fixed::toFloat() const {
    std::cout << "toFloat function called" << std::endl;
    float value = (float)this->getRawBits();
    value /= 1 << fixedPoint;
    return value;
}

void Fixed::setRawBits(int value) {
    std::cout << "setRawBits function called" << std::endl;
    this->fpValue = value;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits function called" << std::endl;
    return fpValue;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    std::cout << "Operator = called" << std::endl;
    this->fpValue = copy.fpValue;
    return *this;
}

std::ostream& operator<<(std::ostream &o, Fixed const &copy) {
    std::cout << "Operator << called" << std::endl;
    o << copy.toFloat();
    return o;
}

