#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# pragma once
# include <iostream>

template <typename T>
class MutantStack {
	private:
		static T* container;
		static int top;
		static int elements;
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

		class iterator {
			private:
				T* address;
				int index;
			public:
				iterator();
				iterator(const iterator& copy);
				~iterator();

				iterator &operator=(const iterator& copy);
				iterator &operator++();
				iterator operator++(int);
				iterator &operator--();
				iterator operator--(int);
				T& operator*();
				bool operator==(const iterator& other) const;
				bool operator!=(const iterator& other) const;
		};
		typename MutantStack<T>::iterator begin();
		typename MutantStack<T>::iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() {
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

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
       return iterator(container);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return iterator(container + elements);
}

template <typename T>
MutantStack<T>::iterator::iterator() {
	index = 0;
	address = new T[0]();
}

template <typename T>
MutantStack<T>::iterator::iterator(const iterator& copy) {
	this->index = copy.index;
	this->address = new T[copy.address]();
}

template <typename T>
MutantStack<T>::iterator::~iterator() {}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(const iterator& copy) {
	this->index = copy.index;
	this->address = new T[copy.address]();
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++() {
	// ++index
	if (address != nullptr) {
		index++;
		if (index < elements)
			address = container[index];
		else
			address = nullptr;
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int) {
	// index++
	iterator temp = *this
	++(*this);
	return temp;
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--() {
	// ++index
	if (address != nullptr && index > 0) {
		index--;
		if (index >= 0)
			address = container[index];
		else
			address = nullptr;
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int) {
	// index++
	iterator temp = *this
	--(*this);
	return temp;
}

template <typename T>
T& MutantStack<T>::iterator::operator*() {
    if (address!= nullptr) 
        return *address;
}

template <typename T>
bool MutantStack<T>::iterator::operator==(const iterator& other) const {
    return address == other.address && index == other.index;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator& other) const {
    return!(*this == other);
}


#endif