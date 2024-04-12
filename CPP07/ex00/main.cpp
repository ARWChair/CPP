#include "whatever.hpp"

int main() {
    int a = 5;
    int b = 6;

    std::cout << "Before swap: " << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    swap<int>(&a, &b);
    std::cout << std::endl;
    std::cout << "After swap: " << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << std::endl;
    std::cout << "Min: " << min<int>(a, b) << std::endl; 
    std::cout << "Max: " << max<int>(a, b) << std::endl; 
}