#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <deque>
#include <list>
#include <sys/time.h>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(std::string arg);

		template <typename Container>
		void FordJohnson(Container& container);
		// void display();
	private:
		std::list<int> list;
		std::deque<int> deque;
		std::string arg;
		int amount;
		void check_and_add(std::string line);
		bool isSorted();
};

