#include "Form.hpp"

Form::Form(): name("default"), needed(150), grade(150), sign(false) {
	std::cout << "Default form constructor called" << std::endl;
}

Form::Form(std::string name, int grade, bool sign, int needed)
: name(name), needed(needed), grade(grade), sign(false) {
	std::cout << "Form constructor called" << std::endl;
	checkGrade();
	checkNeeded();
	signForm(sign);
}

Form::Form(const Form &copy): name(copy.name + "_copy"), needed(copy.needed), grade(copy.grade) {
	std::cout << "Form copy constructor called" << std::endl;
	this->sign = copy.sign;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &copy) {
	std::cout << "Form = operator called" << std::endl;
	this->sign = copy.sign;
	return *this;
}

void Form::beSigned(Bureaucrat *b) {
	if (b->getGrade() > this->needed)
		throw GradeTooLowException();
	if (this->sign == true)
		throw DoubleSignException();
	this->sign = true;
}

void Form::signForm(bool value) {
	try {
		if (this->grade < this->needed)
			throw GradeLowerThanNeededException();
		if (this->grade < 1)
			throw GradeTooHighException();
		if (this->grade > 150)
			throw GradeTooLowException();
		this->sign = value;
	} catch (const GradeLowerThanNeededException& e) {
		std::cerr << e.what() << std::endl;
		throw FormException();
	} catch (const GradeTooLowException& e) {
		std::cerr << "Can't sign form. " << e.what() << std::endl;
		throw FormException();
	} catch (const GradeTooHighException &e) {
		std::cerr << "Can't sign form. " << e.what() << std::endl;
		throw FormException();
	}
}

void Form::checkGrade() {
	try {
		if (this->grade > 150)
			throw GradeTooLowException();
		else if (this->grade < 1)
			throw GradeTooHighException();
	} catch (const GradeTooLowException& e) {
		std::cerr << "Can't assign grade \"" << grade << "\" to \"" << getName() << "\". " << e.what() << std::endl;
		throw FormException();
	} catch (const GradeTooHighException& e) {
		std::cerr << "Can't assign grade \"" << grade << "\" to \"" << getName() << "\". " << e.what() << std::endl;
		throw FormException();
	}
}

void Form::checkNeeded() {
	try {
		if (this->needed > 150)
			throw GradeTooLowException();
		else if (this->needed < 1)
			throw GradeTooHighException();
	} catch (const GradeTooLowException& e) {
		std::cerr << "Can't assign needed \"" << grade << "\" to \"" << getName() << "\". " << e.what() << std::endl;
		throw FormException();
	} catch (const GradeTooHighException& e) {
		std::cerr << "Can't assign needed \"" << grade << "\" to \"" << getName() << "\". " << e.what() << std::endl;
		throw FormException();
	}
}

const std::string Form::getName() const {
	return this->name;
}

int Form::getNeeded() const {
	return this->needed;
}

int Form::getGrade() const {
	return this->grade;
}

int Form::isNeeded() const {
	return this->needed;
}

bool Form::isSigned() const {
	return this->sign;
}

const char *Form::DoubleSignException::what() const throw() {
	return "Form already signed";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char *Form::FormException::what() const throw() {
	return "";
}

const char *Form::GradeLowerThanNeededException::what() const throw() {
	return "Grade is lower than needed to sign the form.";
}

std::ostream &operator<<(std::ostream &o, Form *f) {
	o	<< "\tName: " << f->getName() << std::endl
		<< "\tGrade: " << f->getGrade() << std::endl
		<< "\tNeeded: " << f->getNeeded() << std::endl
		<< "\tSigned: " << f->isSigned() << std::endl;
	return o;
}
