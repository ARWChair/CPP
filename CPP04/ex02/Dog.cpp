#include "Dog.hpp"

Dog::Dog(): Animal() {
	std::cout << "Default dog constructor called" << std::endl;
	type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog copy contructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
	this->type = copy.type;
}

Dog::~Dog() {
	std::cout << "Dog destroyed" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog = overload opperator called" << std::endl;
	this->brain = new Brain(*copy.brain);
	this->type = copy.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dogs do bark" << std::endl;
}

std::string Dog::getType() const {
	return type;
}
