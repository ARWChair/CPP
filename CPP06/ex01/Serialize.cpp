#include "Serialize.hpp"

Serialize::Serialize() {
    std::cout << "Default constructor called" << std::endl;
}

Serialize::Serialize(const Serialize& copy) {
    if (this != &copy)
        *this = copy;
}

Serialize::~Serialize() {}

Serialize &Serialize::operator=(const Serialize& copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}

uintptr_t Serialize::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}