#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	mstack.reserve(20);
	mstack.display();
	mstack.push(10);
	mstack.display();
	mstack.push(10);
	mstack.push(20);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.reserve(10);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.push(70);
	mstack.display();
	mstack.pop();
	mstack.display();
	return 0;
}