#ifndef ARRAY_HPP
# define ARRAY_HPP
# pragma once
# include <iostream>

template <typename T>
class Array {
	private:
		T *arr;
		unsigned int len;
	public:
		Array();
		Array(unsigned int len);
		Array(const T& copy);
		~Array();

		T& operator=(const T& copy);
		T& operator[](unsigned int size);
		int size() const;

		class IndexBoundException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
Array<T>::Array() {
	arr = new T();
}

template <typename T>
Array<T>::Array(unsigned int len): len(len) {
	arr = new T[len];
}

template <typename T>
Array<T>::Array(const T& copy) {
	if (arr != NULL)
		delete[] arr;
	this->len = copy.len;
	this->arr = new T[this->len];
	for (unsigned int i = 0; i < this->len; i++) {
		this->arr[i] = copy.arr[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete arr;
}

template <typename T>
T& Array<T>::operator=(const T& copy) {
	if (arr != NULL)
		delete[] arr;
	this->len = copy.len;
	this->arr = new T[this->len];
	for (unsigned int i = 0; i < this->len; i++) {
		this->arr[i] = copy.arr[i];
	}
	return this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= len)
		throw IndexBoundException();
	return arr[index];
}

template <typename T>
int Array<T>::size() const {
	return len;
}

template <typename T>
const char *Array<T>::IndexBoundException::what() const throw() {
	return "Index out of bounds";
}

#endif