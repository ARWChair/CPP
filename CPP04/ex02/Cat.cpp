#include "Cat.hpp"

Cat::Cat(): Animal() {
	std::cout << "Default cat constructor called" << std::endl;
	type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy) {
	std::cout << "Cat copy contructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
	this->type = copy.type;
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Cat = overload opperator called" << std::endl;
	this->brain = new Brain(*copy.brain);
	this->type = copy.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cats do miau" << std::endl;
}

std::string Cat::getType() const {
	return type;
}
