#include "Base.hpp"

int main() {
    Base *b[5];
    std::srand(0);
    for (int i = 0; i < 5; i++) {
        b[i] = generate();
        identify(b[i]);
        identify(*b[i]);
        std::cout << std::endl;
    }
    for (int i = 0; i < 5; i++)
        delete b[i];
}
