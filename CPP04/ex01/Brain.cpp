#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; ideas->length(); i++)
		this->ideas[i] = copy.ideas[i];
}

Brain::~Brain() {
	std::cout << "Brain destrcutor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy) {
	std::cout << "Brain = operator called" << std::endl;
	for (int i = 0; ideas->length(); i++)
		this->ideas[i] = copy.ideas[i];
	return *this;
}
