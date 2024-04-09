#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->type = copy.type;
}

Animal::~Animal() {
	std::cout << "Animal destroyed" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
	std::cout << "Animal = operator called" << std::endl;
	this->type = copy.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "I dont know what sound unknown animals make" << std::endl;
}

std::string Animal::getType() const {
	return type;
}
