//
// Created by yatabay on 11/20/23.
//

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "b is " << b.toInt() << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

