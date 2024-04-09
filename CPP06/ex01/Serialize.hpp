#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP
# include <iostream>
# include <stdint.h>
# pragma once

typedef struct Data {
    int first;
    int second;
};


class Serialize {
    private:
        Serialize();
    public:
        Serialize(const Serialize& copy);
        ~Serialize();

        Serialize &operator=(const Serialize& copy);
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif