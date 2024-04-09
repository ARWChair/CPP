#ifndef CAT_H
# define CAT_H
# include "Animal.hpp"
# pragma once

class Cat: public Animal {
	private:
		std::string type;
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		void makeSound() const;
		Cat &operator=(const Cat &copy);
		std::string getType() const;
};

#endif
