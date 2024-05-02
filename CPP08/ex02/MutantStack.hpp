#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# pragma once
# include <iostream>

template <typename T>
class MutantStack {
	private:
		T* container;
		int top;
		int elements;
	public:
		MutantStack();
		MutantStack(const MutantStack& copy);
		~MutantStack();

		MutantStack &operator=(const MutantStack& copy);
		void push(T value);
		void pop();
		int size();
		void reserve(int size);
		void display();
};

template <typename T>
MutantStack<T>::MutantStack(): elements(0), top(0) {
	container = new T[0]();
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) {
	this->container = new T[copy.top]();
	this->elements = copy.elements;
	this->top = copy.top;
	for (int i = 0; i < this->elements; i++) {
		this->container[i] = copy.container[i];
	}
}

template <typename T>
MutantStack<T>::~MutantStack() {
	if (container!= nullptr) {
		delete[] container;
	}
	container = nullptr;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& copy) {
	this->container = new T[copy.top]();
	this->elements = copy.elements;
	this->top = copy.top;
	for (int i = 0; i < this->elements; i++) {
		this->container[i] = copy.container[i];
	}
	return *this;
}

template <typename T>
void MutantStack<T>::reserve(int size) {
	T* temp = new T[top + size]();
	for (int i = 0; i < elements; i++) {
		temp[i] = container[i];
	}
	delete[] container;
	top += size;
	container = temp;
}

template <typename T>
void MutantStack<T>::push(T value) {
	T *temp;
	int i = 0;
	if (elements == top) {
		temp = new T[top + 1]();
		while (i < elements) {
			temp[i] = container[i];
			i++;
		}
		temp[i] = value;
		delete[] container;
		container = temp;
		top++;
	}
	else
		container[elements] = value;
	elements++;
}

template <typename T>
void MutantStack<T>::display() {
	for (int i = 0; i < elements; i++) {
		std::cout << container[i];
		if (i != elements - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

template <typename T>
void MutantStack<T>::pop() {
	elements--;
	container[elements] = 0;
}

template <typename T>
int MutantStack<T>::size() {
	return elements;
}

#endif