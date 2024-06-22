#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

template <typename Container>
static std::string displayContainer(Container container) {
	std::string returning;
	int size = 0;
	for (typename Container::iterator it = container.begin(); it != container.end() && size < 5; ++it, size++) {
		returning += std::to_string(*it);
		returning += " ";
	}
	if (size == 5) {
		returning += "[...]";
	}
	return returning;
}

static long double addArtifialZero(long long seconds) {
	long double returning = seconds;
	returning /= 10000;
	return returning;
}

PmergeMe::PmergeMe(std::string arg) {
	bool number = false;
	std::size_t pos;
	struct timeval now, end;
	long long seconds;

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
	
	// ---------- TODO ----------- \\'
	std::istringstream argStream(arg);
	std::string line;
	while(argStream) {
		std::getline(argStream, line, (char)32);
		if (line.length() > 0)
			check_and_add(line);
	}
	list.pop_back();
	deque.pop_back();
	gettimeofday(&end, nullptr);
	FordJohnson(list);
	gettimeofday(&now, nullptr);
	seconds = now.tv_usec - end.tv_usec;
	gettimeofday(&end, nullptr);
	FordJohnson(deque);
	gettimeofday(&now, nullptr);
	std::cout << "Before:\t" + displayContainer(arg) << "\nAfter:\t" << displayContainer(list)
				<< "\nTime to process a range of\t" << list.size()
				<< " elements with std::list :  " << addArtifialZero(seconds) << " us" 
				<< "\nTime to process a range of\t" << deque.size()
				<< " elements with std::deque :  " << addArtifialZero(now.tv_usec - end.tv_usec) << " us" << std::endl;
	// ---------- TODO ----------- \\'
	// Fix Segfault ab 5: +1,+3,+1,+3,+1,+3,+1,+3,+1,+3,+1,+3,+1,+3 
	// Grund -> bei den werten wird das letzte array nciht behandelt
	// ungerade anzahl an arrays = crash
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

template <typename Container>
void PmergeMe::FordJohnson(Container& container) {
	int amount = getAmount(this->amount);
	Container shards[amount];
	int listModifierIndex = amount;

	preSort(shards, container, amount);
	while (listModifierIndex > 1) {
		for (int inner = 0; inner < listModifierIndex; inner += 2) {
			typename Container::iterator firstList = shards[inner].begin();
			while (shards[inner + 1].size() != 0) {
				typename Container::iterator secondList = shards[inner + 1].begin();
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
	container = shards[0];
}

void PmergeMe::check_and_add(std::string line) {
	std::stringstream ss(line);
	long long result;
	
	ss >> result;
	if (ss.fail())
		throw std::overflow_error("Error: Stringstream failed");
	else if (result > std::numeric_limits<int>::max())
		throw std::overflow_error("Error: number to big");
	else if (result < 0)
		throw std::overflow_error("Error: only positiv numbers allowed");
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
