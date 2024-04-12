#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# pragma once

template <typename T>
void iter(T *address, int length, void(*f)(T const&)) {
    for (int i = 0; i < length; i++) {
        f(address[i]);
    }
}

template <typename T>
void print_test(T& test) {
    std::cout << "LOL: " << test << std::endl;
}

#endif