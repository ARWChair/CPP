#include "Span.hpp"

Span::Span(): max(0), highest(-2147483648), lowest(2147483647) {}

Span::Span(unsigned int N): max(N), highest(-2147483648), lowest(2147483647) {
    numbers.reserve(N);
}

Span::Span(const Span& copy) {
    this->highest = copy.highest;
    this->lowest = copy.lowest;
    this->max = copy.max;
    this->numbers.reserve(this->max);
    for (std::vector<int>::const_iterator it = copy.numbers.begin(); it != copy.numbers.end(); it++) {
        this->numbers.push_back(*it); // Kopiert jedes Element von copy.numbers in this->numbers
    }
}

Span::~Span() {}

Span &Span::operator=(const Span& copy) {
    this->highest = copy.highest;
    this->lowest = copy.lowest;
    this->max = copy.max;
    this->numbers.reserve(this->max);
    for (std::vector<int>::const_iterator it = copy.numbers.begin(); it != copy.numbers.end(); it++) {
        this->numbers.push_back(*it); // Kopiert jedes Element von copy.numbers in this->numbers
    }
    return *this;
}

void Span::addNumber(int number) {
    if (numbers.size() == max)
        throw allreadyExisting();
    numbers.push_back(number);
    if (number < lowest)
        lowest = number;
    else if (number > highest)
        highest = number;
}

void Span::addNumber(int number, int range) {
    int amount = 0;
    for (std::vector<int>::iterator it = this->numbers.begin(); it != this->numbers.end(); it++, amount++);
    if (range + amount >= max + 1)
        throw allreadyExisting();
    for (int i = 0; i < range; i++) {
        addNumber(number);
    }
}

int Span::longestSpan() {
    return highest - lowest;
}

int Span::shortestSpan() {
    int distance = 0;
    int lowest = 0;
    bool first = true;
    std::sort(numbers.begin(), numbers.end());
    std::vector<int>::iterator it = numbers.begin();
    std::advance(it, 1);
    while (it != numbers.end()) {
        std::vector<int>::iterator prev = it;
        --prev;
        distance = *it - *prev;
        if (first) {
            lowest = distance;
            first = !first;
        }
        if (distance < lowest)
            lowest = distance;
        it++;
    }
    return lowest;
}

const char *Span::allreadyExisting::what() const throw() {
    return "Exceeding maximum size limit of container";
}