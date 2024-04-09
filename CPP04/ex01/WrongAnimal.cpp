#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Wrong animal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << "Wrong animal copy constructor called" << std::endl;
	this->type = copy.type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong animal deconstructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& copy) {
	std::cout << "Wrong animal = operator called" << std::endl;
	this->type = copy.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong animals can make sounds" << std::endl;
}
