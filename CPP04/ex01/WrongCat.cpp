#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "Wrong cat " << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) {
	std::cout << "Wrong cat copy constructor called" << std::endl;
	this->type = copy.type;
}

WrongCat::~WrongCat() {
	std::cout << "Wrong cat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& copy) {
	std::cout << "Wrong cat = operator called" << std::endl;
	this->type = copy.type;
	return *this;
}

std::string WrongCat::getType() const {
	return type;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong cats are stupid. They cant bark or miau" << std::endl;
}
