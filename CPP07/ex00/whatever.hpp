#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>
# pragma once

template <typename T>
void swap(T *val1, T *val2) {
    T temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

template <typename T>
T min(T &val1, T &val2) {
    if (val1 < val2)
        return val1;
    return val2;
}

template <typename T>
T max(T &val1, T &val2) {
    if (val1 > val2)
        return val1;
    return val2;
}

#endif