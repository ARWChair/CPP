#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Form *f1;
	Form *f2;
	Form *f3;
	Form f4;
	Form f5;
	Form *f6;
	try {
		std::cout << "\t";
		f1 = new Form();
		std::cout << "\t";
		f2 = new Form("Ananas", 150, true, 150);
		std::cout << "\t";
		f3 = new Form(*f1);
		std::cout << "\t";
		f4 = *f1;
		std::cout << "\t";
		f5 = *f2;
		std::cout << "\t";
		f6 = new Form("High level", 20, false, 20);

	} catch (const std::exception& e) {
		;
	}
	std::cout << std::endl << std::endl << std::endl;


	std::cout << "Failed creation" << std::endl;
	Bureaucrat *berror;
	Form *ferror3;
	Form *ferror2;
	Form *ferror;
	try {
		std::cout << "\t";
		berror = new Bureaucrat("Error", 200);

	} catch (const std::exception& e) {
		;
	}
	try {
		std::cout << "\t";
		ferror = new Form("Error 1", 151, true, 151);
	} catch (const std::exception& e) {
		;
	}
	try {
		std::cout << "\t";
		ferror2 = new Form("Error 2", 151, true, 150);
	} catch (const std::exception& e) {
		;
	}
	try {
		std::cout << "\t";
		ferror3 = new Form("Error 3", 101, true, 100);
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

	std::cout << "Signing forms successfully" << std::endl << "\t";
	try {
		b1->signForm(*f1);
		std::cout << "\t";
		b2->signForm(*f3);
		std::cout << "\t";
		b3->signForm(f4);
	} catch (const std::exception& e) {
		;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Signing forms non-successfully (allready signed)" << std::endl << "\t";
	try {
		b1->signForm(*f2);
	} catch (const std::exception& e) {
		;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Signing forms non-successfully (Form grade to high)" << std::endl << "\t";
	try {
		b5->signForm(*f6);
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
	delete f6;
	delete ferror3;
}
