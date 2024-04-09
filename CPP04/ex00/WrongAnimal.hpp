#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H
# include <iostream>
# include <string>
# pragma once

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal& copy);

		virtual std::string getType() const;
		void makeSound() const;
};

#endif
