#include "Serialize.hpp"

int main(void) {
	Data *d = new Data();
	
	std::cout << "Data before modification: " << d << std::endl;
	uintptr_t ptr = serialize(d);
	Data *dataptr = deserialize(ptr);
	std::cout << "Data after modification: " << dataptr << std::endl;

	delete d;
}
