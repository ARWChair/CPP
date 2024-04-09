#include "Bureaucrat.hpp"

int main() {
	std::cout << "Success creating" << std::endl;
	Bureaucrat *b1 = new Bureaucrat();
	std::cout << "\t";
	Bureaucrat *b2 = new Bureaucrat("B2");
	std::cout << "\t";
	Bureaucrat *b3 = new Bureaucrat("B3", 120);
	std::cout << "\t";
	Bureaucrat *b4 = new Bureaucrat("B4", 1);
	std::cout << "\t";
	Bureaucrat *b5 = new Bureaucrat(*b2);
	std::cout << "\t";
	Bureaucrat b6 = *b3;
	std::cout << std::endl << std::endl;

	std::cout << "Failed creation" << std::endl;
	std::cout << "\t";
	Bureaucrat *error;
	try {
		error = new Bureaucrat("Error", 200);
		std::cout << "\t";
	} catch (const std::exception& e) {
		std::cerr << "Error creating bureaucrat" << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Names and Grades:" << std::endl;
	std::cout << "\t" << b1 << std::endl;
	std::cout << "\t" << b2 << std::endl;
	std::cout << "\t" << b3 << std::endl;
	std::cout << "\t" << b4 << std::endl;
	std::cout << "\t" << b5 << std::endl;
	std::cout << "\t" << &b6 << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Try decrementing" << std::endl;
	try {
		b1->decGrade();
		b2->decGrade();
		b3->decGrade();
		b4->decGrade();
		b5->decGrade();
		b6.decGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Try incrementing" << std::endl;
	try {
		b1->incGrade();
		b2->incGrade();
		b3->incGrade();
		b4->incGrade();
		b5->incGrade();
		b6.incGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Try decrementing with 500" << std::endl;
	try {
		b1->decGrade(500);
		b2->decGrade(500);
		b3->decGrade(500);
		b4->decGrade(500);
		b5->decGrade(500);
		b6.decGrade(500);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Try incrementing with 500" << std::endl;
	try {
		b1->incGrade(500);
		b2->incGrade(500);
		b3->incGrade(500);
		b4->incGrade(500);
		b5->incGrade(500);
		b6.incGrade(500);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	delete b1;
	delete b2;
	delete b3;
	delete b4;
	delete b5;
}
