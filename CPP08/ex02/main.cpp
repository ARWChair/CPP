#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	mstack.reserve(20);
	mstack.push(10);
	mstack.push(10);
	mstack.push(20);
	mstack.push(706);
	mstack.push(708);
	mstack.push(704);
	mstack.push(703);
	mstack.push(702);
	mstack.push(701);
	mstack.push(706);
	mstack.push(730);
	mstack.push(702);
	mstack.push(700);
	mstack.push(705);
	mstack.reserve(10);
	mstack.push(475);
	mstack.push(270);
	mstack.push(970);
	mstack.push(370);
	mstack.push(170);
	mstack.push(470);
	mstack.push(670);
	mstack.push(470);
	mstack.push(870);
	mstack.push(370);
	mstack.push(170);
	mstack.push(270);
	mstack.push(790);
	mstack.push(780);
	mstack.push(760);
	mstack.push(750);
	mstack.push(720);
	mstack.push(700);
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
		std::cout << "Value: " << *it << std::endl;
	}
	mstack.pop();
	return 0;
}