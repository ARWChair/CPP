#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string arg) {
	bool number = false;
	std::size_t pos;

	amount = -1;
	for (pos = 0; pos < arg.length(); pos++) {
		if (!((arg[pos] >= '0' && arg[pos] <= '9') || arg[pos] == 32 || arg[pos] == '-'))
			break;
		if (arg[pos] >= '0' && arg[pos] <= '9')
			number = true;
	}
	if (pos != arg.length())
		throw std::invalid_argument("Error: Invalid character found in argv");
	else if (!number)
		throw std::invalid_argument("Error: Cannot operate with empty string");
	
	std::istringstream argStream(arg);
	std::string line;
	while(argStream) {
		std::getline(argStream, line, (char)32);
		if (line.length() > 0)
			check_and_add(line);
	}
	list.pop_back();
	deque.pop_back();
	if (isSorted())
		return;
	FJlist();
	FJdeque();
	// Zeit erfassen
	// insertionsort für list machen
	// Zeit speichern
	// Zeit erfassen
	// insertionsort für deque machen
	// Zeit speichern
	// überfprüfen ob alles sortiert ist
	// Zeit mit der message ausprinten
}

static int getAmount(int amount) {
	int shift = 0;
	if (amount % 2 == 1)
		shift++;
	return (amount / 2) + shift;
}

template <typename Container>
void preSort(Container *shards, Container &base, int amount) {
	int listIndex = 0;
	int innerIndex = 0;
	int prev;

	for (typename Container::iterator it = base.begin(); it != base.end(); ++it) {
		if (innerIndex == 2) {
			listIndex++;
			innerIndex = 0;
		}
		shards[listIndex].push_back(*it);
		innerIndex++;
	}

	listIndex = 0;
	innerIndex = 0;
	for (int i = 0; i < amount; i++) {
		typename Container::iterator it = shards[i].begin();
		prev = *it;
		if (shards[i].size() == 2) {
			if (prev > *(++it)) {
				shards[i].pop_front();
				shards[i].push_back(prev);
			}
		}
	}
}

void PmergeMe::FJlist() {
	int amount = getAmount(this->amount);
	std::list<int> shards[amount];
	int listModifierIndex = amount;

	preSort(shards, list, amount);
	while (listModifierIndex > 1) {
		for (int inner = 0; inner < listModifierIndex; inner += 2) {
			std::list<int>::iterator firstList = shards[inner].begin();
			while (shards[inner + 1].size() != 0) {
				std::list<int>::iterator secondList = shards[inner + 1].begin();
				if (*secondList <= *firstList) {
					shards[inner].insert(firstList, *secondList);
					shards[inner + 1].pop_front();
				} else {
					++firstList;
				}
				if (firstList == shards[inner].end()) {
					shards[inner].insert(firstList, *secondList);
					shards[inner + 1].pop_front();
				}
			}
		}
		int del = 1;
		if (listModifierIndex % 2 != 0)
			listModifierIndex++;
		for (int inner = 1; inner < listModifierIndex; inner++, del += 2) {
			if (inner < listModifierIndex / 2)
				shards[inner] = shards[del + 1];
			else
				shards[inner].clear();
		}
		for (del = 0; del < listModifierIndex; del++) {
			if (shards[del].empty())
				break;
		}
		listModifierIndex = del;
	}
	list = shards[0];
}

void PmergeMe::FJdeque() {
	int amount = getAmount(this->amount);
	std::deque<int> shards[amount];
	int listModifierIndex = amount;

	preSort(shards, deque, amount);
	while (listModifierIndex > 1) {
		for (int inner = 0; inner < listModifierIndex; inner += 2) {
			std::deque<int>::iterator firstList = shards[inner].begin();
			while (shards[inner + 1].size() != 0) {
				std::deque<int>::iterator secondList = shards[inner + 1].begin();
				if (*secondList <= *firstList) {
					shards[inner].insert(firstList, *secondList);
					shards[inner + 1].pop_front();
				} else {
					++firstList;
				}
				if (firstList == shards[inner].end()) {
					shards[inner].insert(firstList, *secondList);
					shards[inner + 1].pop_front();
				}
			}
		}
		int del = 1;
		if (listModifierIndex % 2 != 0)
			listModifierIndex++;
		for (int inner = 1; inner < listModifierIndex; inner++, del += 2) {
			if (inner < listModifierIndex / 2)
				shards[inner] = shards[del + 1];
			else
				shards[inner].clear();
		}
		for (del = 0; del < listModifierIndex; del++) {
			if (shards[del].empty())
				break;
		}
		listModifierIndex = del;
	}
	deque = shards[0];
}

void PmergeMe::check_and_add(std::string line) {
	std::stringstream ss(line);
	long long result;
	
	ss >> result;
	if (ss.fail())
		throw std::overflow_error("Error: Stringstream failed");
	else if (result > std::numeric_limits<int>::max())
		throw std::overflow_error("Error: number to big");
	else if (result < std::numeric_limits<int>::min())
		throw std::overflow_error("Error: number to small");
	list.push_back(result);
	deque.push_back(result);
	amount++;
}

bool PmergeMe::isSorted() {
	bool sorted = true;
	int previous;
	int pos = 0;

	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it, pos++) {
		if (pos > 0 && previous > *it) {
			sorted = false;
			break;
		}
		previous = *it;
	}
	pos = 0;
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it, pos++) {
		if (pos > 0 && previous > *it) {
			sorted = false;
			break;
		}
		previous = *it;
	}
	return sorted;
}
