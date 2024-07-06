#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <deque>
#include <list>
#include <sys/time.h>
#include <iomanip>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(std::string arg);

		template <typename Container>
		void FordJohnson(Container& container);
		void display();
	private:
		std::list<int> list;
		std::deque<int> deque;
		std::list<int> displayC;
		std::string arg;
		int amount;
		int check_and_add(std::string line);
		template <typename Container>
		void mergeExistingContainer(Container &container, Container reserve);
};

