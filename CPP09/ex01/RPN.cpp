#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string numbers) {
	int i;
	int solution;

	for (i = 0; i < numbers.length(); i++) {
		if (!(numbers[i] >= '0' && numbers[i] <= '9')) {
			if (numbers[i] != 32 && numbers[i] != '+' && numbers[i] != '-' && numbers[i] != '*' && numbers[i] != '/')
				break;
			
		}
	}
	if (i != numbers.length())
		throw std::invalid_argument("Error: String contains invalid character");
	solution = calc(numbers);
	if (solution == -1)
		throw std::bad_alloc();
	std::cout << solution << std::endl;
}

RPN::RPN(const RPN& copy) {
	this->numbers = copy.numbers;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& copy) {
	this->numbers = copy.numbers;
	return *this;
}

static int argc_count(std::string numbers) {
	int i;
	int end = numbers.length();
	int amount = 0;
	int counted = 0;

	for (i = 0; i < numbers.length(); i++) {
		if (numbers[i] != ' ')
			break;
	}
	for (; end >= 0; end--) {
		if (numbers[end] != ' ')
			break;
	}
	for (; i < numbers.length() && i < end; i++) {
		counted = 0;
		if (numbers[i] >= '0' && numbers[i] <= '9') {
			for (; i < numbers.length(); i++) {
				if (!(numbers[i] >= '0' && numbers[i] <= '9')) {
					if (amount == 2147483647)
						throw std::out_of_range("Error: too many arguments");
					amount++;
					counted++;
					break;
				}
			}
		}
		if (numbers[i] == '+' || numbers[i] == '-' || numbers[i] == '*' || numbers[i] == '/') {
			for (; i < numbers.length(); i++) {
				if (numbers[i] == ' ') {
					break;
				}
				if (amount == 2147483647)
					throw std::out_of_range("Error: too many arguments");
				amount++;
				counted++;
			}
		}
		if (numbers[i] == ' ') {
			for (; i < numbers.length(); i++)
				if (numbers[i + 1] != ' ')
					break;
			if (counted == 0) {
				if (amount == 2147483647)
					throw std::out_of_range("Error: too many arguments");
				amount++;
			}
		}
	}
	return amount;
}

static std::string *convert_args(std::string numbers, int args) {
	std::string *arr;
	int i;
	int delim;
	int pos = 0;
	int end = numbers.length();
	int amount = 0;

	try {
		arr = new std::string[args]();
	} catch (const std::exception& e) {
		return nullptr;
	}
	for (i = 0; i < numbers.length(); i++) {
		if (numbers[i] != ' ')
			break;
	}
	for (; end >= 0; end--) {
		if (numbers[end] != ' ')
			break;
	}
	for (; i < numbers.length() && i < end; i++) {
		if (numbers[i] >= '0' && numbers[i] <= '9') {
			delim = i;
			for (; i < numbers.length(); i++) {
				if (!(numbers[i] >= '0' && numbers[i] <= '9')) {
					break;
				}
			}
			while (delim < i) {
				arr[pos] += numbers[delim];
				delim++;
			}
			pos++;
		}
		if (numbers[i] == '+' || numbers[i] == '-' || numbers[i] == '*' || numbers[i] == '/') {
			for (; i < numbers.length(); i++) {
				if (numbers[i] == ' ') {
					break;
				}
				if (amount == 2147483647) {
					delete[] arr;
					throw std::out_of_range("Error: too many arguments");
				}
				arr[pos++] += numbers[i];
			}
		}
		if (numbers[i] == ' ') {
			for (; i < numbers.length(); i++)
				if (numbers[i + 1] != ' ')
					break;
		}
	}
	return arr;
}

static void check_error(std::string *arr, int arguments) {
	int symbols = 0;
	int nums = 0;

	for (int i = 0; i < arguments; i++) {
		if (arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/")
			symbols++;
		else {
			nums++;
			if (i == arguments - 1)
				throw std::length_error("Error: Invalid syntax");
		}
	}
	if (symbols >= nums)
		throw std::out_of_range("Error. Not enough numbers");
}

int RPN::calc(std::string numbers) {
	std::string *arr;
	int tempNum;

	numbers += " ";
	arguments = argc_count(numbers);
	arr = convert_args(numbers, arguments);
	if (arr == nullptr)
		return -1;
	check_error(arr, arguments);
	for (int i = 0; i < arguments; i++) {
		if (arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/") {
				int second = this->numbers.top();
				this->numbers.pop();
				int first = this->numbers.top();
				this->numbers.pop();
			if (arr[i] == "+")
				this->numbers.push(first + second);
			if (arr[i] == "-")
				this->numbers.push(first - second);
			if (arr[i] == "*")
				this->numbers.push(first * second);
			if (arr[i] == "/")
				this->numbers.push(first / second);
		} else {
			std::stringstream stream(arr[i]);
			stream >> tempNum;
			this->numbers.push(tempNum);
		}
	}
	delete[] arr;
	if (this->numbers.size() != 1)
		throw std::length_error("Error: Too many numbers. Invalid syntax");
	return this->numbers.top();
}
