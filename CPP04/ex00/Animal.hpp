#ifndef ANIMAL_H
# define ANIMAL_H
# include <iostream>
# include <string>
# pragma once

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &copy);

		virtual std::string getType() const;
		virtual void makeSound() const;
};

#endif
