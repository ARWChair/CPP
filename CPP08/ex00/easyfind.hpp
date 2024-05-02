#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# pragma once

template <typename T>
void easyfind(T &container, int find) {
    typename T::iterator i;
    for (i = container.begin(); i != container.end(); i++) {
        if (*i == find)
            break;
    }
    if (i == container.end())
        throw std::out_of_range("Int not in container");
}

#endif
