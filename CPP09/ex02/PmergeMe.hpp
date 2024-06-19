#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <deque>
#include <list>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(std::string arg);

		void FJlist();
		void FJdeque();
	private:
		std::list<int> list;
		std::deque<int> deque;
		int amount;
		void check_and_add(std::string line);
		bool isSorted();
};
