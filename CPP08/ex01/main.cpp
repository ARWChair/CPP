#include "Span.hpp"

int main()
{
    Span sp = Span(50);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(200, 45);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}