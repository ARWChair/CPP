#ifndef WRONGCAT_H
# define WRONGCAT_H
# include "WrongAnimal.hpp"
# pragma once

class WrongCat: public WrongAnimal {
	private:
		std::string type;
	public:
		WrongCat();
		WrongCat(const WrongCat& copy);
		~WrongCat();
		WrongCat &operator=(const WrongCat& copy);

		std::string getType() const;
		void makeSound() const;
};

#endif
