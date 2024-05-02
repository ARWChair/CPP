#include "easyfind.hpp"
#include <vector>
#include <stdexcept>

int main() {
    std::vector<int> test = {1, 2, 3, 4, 5, 6, 7};
    try {
        easyfind(test, 2);
        easyfind(test, 4);
        easyfind(test, 9);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << "Every value in container" << std::endl;
    return 0;
}