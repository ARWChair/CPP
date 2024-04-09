#ifndef DOG_H
# define DOG_H
# include "Animal.hpp"
# pragma once

class Dog: public Animal {
	private:
		std::string type;
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		void makeSound() const;
		Dog &operator=(const Dog &copy);
		std::string getType() const;
};

#endif
