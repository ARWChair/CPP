#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	const WrongAnimal* wrongA = new WrongAnimal();
	const WrongCat* wrongC = new WrongCat();
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << wrongC->getType() << " " << std::endl;
	std::cout << wrongA->getType() << " " << std::endl;
	wrongA->makeSound();
	wrongC->makeSound();
	delete wrongA;
	delete wrongC;
	delete meta;
	delete j;
	delete i;
	return 0;
}
