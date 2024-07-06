#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

template <typename Container>
static std::string displayContainer(Container container) {
	typename Container::iterator it;
	std::string returning;
	int size = 0;

	for (it = container.begin(); it != container.end() && size < 4; ++it, size++) {
		std::ostringstream convert;
		convert << *it;
		returning += convert.str();
		returning += " ";
	}
	if (it != container.end()) {
		returning += "[...]";
	}
	return returning;
}

static long double addArtifialZero(unsigned int milliseconds) {
	long double returning = milliseconds;
	returning /= 100000;
	return returning;
}

PmergeMe::PmergeMe(std::string arg) {
	std::istringstream argStream(arg);
	std::string line;
	std::size_t pos;
	bool number = false;
	int val;

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
	this->arg = arg;
	while(argStream) {
		std::getline(argStream, line, (char)32);
		if (line.length() > 0) {
			val = check_and_add(line);
			displayC.push_back(val);
		}
	}
	displayC.pop_back();
}

void PmergeMe::display() {
	std::istringstream ListStream(arg);
	std::istringstream DequeStream(arg);
	struct timeval now, end;
	std::string line;
	unsigned int seconds;
	int val;

	gettimeofday(&end, 0);
	while(ListStream) {
		std::getline(ListStream, line, (char)32);
		if (line.length() > 0) {
			val = check_and_add(line);
			list.push_back(val);
			amount++;
		}
	}
	list.pop_back();
	FordJohnson(list);
	gettimeofday(&now, 0);
	seconds = now.tv_usec - end.tv_usec;
	gettimeofday(&end, 0);
	amount = -1;
	line.clear();
	while(DequeStream) {
		std::getline(DequeStream, line, (char)32);
		if (line.length() > 0) {
			val = check_and_add(line);
			deque.push_back(val);
			amount++;
		}
	}
	deque.pop_back();
	FordJohnson(deque);
	gettimeofday(&now, 0);
	std::cout << std::setprecision(6) << "Before:\t" + displayContainer(displayC) << "\nAfter:\t" << displayContainer(list)
				<< "\nTime to process a range of\t" << list.size()
				<< " elements with std::list :  " << std::fixed << addArtifialZero(seconds) << " us" 
				<< "\nTime to process a range of\t" << deque.size()
				<< " elements with std::deque :  " << addArtifialZero(now.tv_usec - end.tv_usec) << " us" << std::endl;
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
void PmergeMe::mergeExistingContainer(Container &container, Container reserve) {
	Container temp;

	typename Container::iterator ContainerIT = container.begin();
	typename Container::iterator ReserveIT = reserve.begin();
	while (!(ContainerIT == container.end() && ReserveIT == reserve.end())) {
		if (ContainerIT == container.end()) {
			temp.push_back(*ReserveIT);
			++ReserveIT;
		} else if (ReserveIT == reserve.end()) {
			temp.push_back(*ContainerIT);
			++ContainerIT;
		} else {
			if (*ContainerIT <= *ReserveIT) {
				temp.push_back(*ContainerIT);
				++ContainerIT;
			} else {
				temp.push_back(*ReserveIT);
				++ReserveIT;
			}
		}
	}
	container.clear();
	container = temp;
}

template <typename Container>
void PmergeMe::FordJohnson(Container& container) {
	int amount = getAmount(this->amount);
	Container *shards;
	Container reserve;
	Container fix;
	int listModifierIndex = amount;
	bool add_later = false;

	shards = new Container[amount]();
	if (!shards)
		throw std::bad_alloc();
	preSort(shards, container, amount);
	if (amount % 2 != 0 && amount > 2) {
		add_later = true;
		reserve = shards[amount - 1];
		listModifierIndex--;
	}
	while (listModifierIndex > 1) {
		for (int inner = 0; inner < listModifierIndex; inner += 2) {
			typename Container::iterator firstList = shards[inner].begin();
			typename Container::iterator secondList = shards[inner + 1].begin(); // to be rm'ed
			while (!(shards[inner + 1].size() + shards[inner].size() == fix.size())) {
				if (firstList == shards[inner].end()) {
					fix.push_back(*secondList);
					++secondList;
				} else if (secondList == shards[inner + 1].end()) {
					fix.push_back(*firstList);
					++firstList;
				} else {
					if (*firstList < *secondList) {
						fix.push_back(*firstList);
						++firstList;
					} else {
						fix.push_back(*secondList);
						++secondList;
					}
				}
			}
			shards[inner].clear();
			shards[inner + 1].clear();
			for (typename Container::iterator it = fix.begin(); it != fix.end(); ++it) {
				shards[inner].push_back(*it);
			}
			fix.clear();
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
	container.clear();
	container = shards[0];
	delete[] shards;
	if (add_later)
		mergeExistingContainer(container, reserve);
	
}

int PmergeMe::check_and_add(std::string line) {
	std::stringstream ss(line);
	int result;
	
	ss >> result;
	if (ss.fail())
		throw std::overflow_error("Error: Stringstream failed");
	else if (result > std::numeric_limits<int>::max())
		throw std::overflow_error("Error: number to big");
	else if (result < 0)
		throw std::overflow_error("Error: only positiv numbers allowed");
	return result;
}
