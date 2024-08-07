#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::string arg = "";
	for (int i = 0; argv[1][i]; i++)
		arg += argv[1][i];
	try {
		BitcoinExchange bitcoin(arg);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
