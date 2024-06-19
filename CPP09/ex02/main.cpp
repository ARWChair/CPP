#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc <= 1 || argc > 2) {
		std::cout << "Error: Invalid arg cound. please use ./PmergeMe \"Num1 Num2 Num3 Num4\"" << std::endl;
		return 1;
	}
	try {
		PmergeMe merge(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}