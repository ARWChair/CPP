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
		RPN(const RPN& copy);
		~RPN();

		RPN& operator=(const RPN& copy);

	private:
		std::stack<int> numbers;
		int arguments;
		int calc(std::string numbers);
};

#endif