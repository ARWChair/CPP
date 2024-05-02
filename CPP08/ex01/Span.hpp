#ifndef SPAN_HPP
# define SPAN_HPP
# pragma once
# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <ctime>

class Span {
    private:
        std::vector<int> numbers;
        unsigned int max;
        int highest;
        int lowest;
        Span();
    public:
        Span(unsigned int N);
        Span(const Span& copy);
        ~Span();

        Span &operator=(const Span& copy);
        void addNumber(int num);
        void addNumber(int num, int range);
        int shortestSpan();
        int longestSpan();

        class allreadyExisting : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif