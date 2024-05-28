#include "RPN.hpp"

int main(int argc, char **argv) {
	std::string args = "";
	for (int i = 1; argv[i]; i++) args += argv[i];
	try {
		RPN rpn(args);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	return 0;
}