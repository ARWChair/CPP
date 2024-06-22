#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc <= 1) {
		std::cout << "Error: Invalid arg cound. please use ./PmergeMe Num1 Num2 Num3 Num4" << std::endl;
		return 1;
	}
	try {
		std::string sum;
		for (int i = 1; argv[i]; i++) {
			sum += argv[i];
			if (argv[i + 1])
				sum += " ";
		}
		PmergeMe merge(sum);
		// merge.display();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
