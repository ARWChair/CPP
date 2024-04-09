#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "Success creating" << std::endl;
	std::cout << "\t";
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
	std::cout << std::endl << std::endl << std::endl;

	ShrubberyCreationForm *f1;
	try {
		std::cout << "\t";
		f1 = new ShrubberyCreationForm();
	} catch (const std::exception& e) {
		;
	}
	try {
		std::cout << "\t";
		b1->executeForm(*f1);
	} catch (const std::exception& e) {
		;
	}

	RobotomyRequestForm *f2;
	try {
		std::cout << "\t";
		f2 = new RobotomyRequestForm();
	} catch (const std::exception& e) {
		;
	}
	try {
		std::cout << "\t";
		b4->executeForm(*f2);
		f2->signForm(false);
		std::cout << "\t";
		b1->executeForm(*f2);
	} catch (const std::exception& e) {
		;
	}

	PresidentialPardonForm *f3;
	try {
		std::cout << "\t";
		f3 = new PresidentialPardonForm();
	} catch (const std::exception& e) {
		;
	}
	try {
		std::cout << "\t";
		b4->executeForm(*f3);
	} catch (const std::exception& e) {
		;
	}

	std::cout << "Failed creation" << std::endl;
	Bureaucrat *berror;
	try {
		std::cout << "\t";
		berror = new Bureaucrat("Error", 200);

	} catch (const std::exception& e) {
		;
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
		;
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
		;
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
		;
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
		;
	}
	std::cout << std::endl << std::endl;

	delete b1;
	delete b2;
	delete b3;
	delete b4;
	delete b5;
	delete f1;
	delete f2;
	delete f3;






	Intern *i = new Intern();
	AForm *test;
	try {
		test = i->makeForm("RobotomyRequestForm", "Wow");
	} catch (const std::exception& e) {
		;
	}
	delete test;
	delete i;
}
