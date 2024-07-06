#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <iostream>
# include <string>
# include <algorithm>
# include <sstream>

class RPN {
	public:
		RPN();
		RPN(std::string numbers);

		class NumberOutOfRange: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class DivisionByZero: public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		std::stack<int> numbers;
		int arguments;
		int calc(std::string numbers);
};

#endif
