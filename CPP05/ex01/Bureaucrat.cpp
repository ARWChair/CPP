#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150) {
	std::cout << "Default bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): name(name), grade(150) {
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade): name("default"), grade(grade) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	checkGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.name + "_copy") {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->grade = copy.getGrade();
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	std::cout << "Bureaucrat = operator called" << std::endl;
	this->grade = copy.getGrade();
	return *this;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(this);
		std::cout << getName() << " signed <" << form.getName() << ">" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << getName() << " couldn't sign <" << form.getName() << "> because of: " << e.what() << std::endl;
		throw BureaucratException();
	}
}

const std::string Bureaucrat::getName() const {
	return name;
}

void Bureaucrat::incGrade(int grade) {
	try {
		if (this->grade - grade < 1)
			throw GradeTooHighException();
		this->grade -= grade;
	} catch (const GradeTooHighException& e) {
		std::cerr << "Cant increment grade of <" << getName() << ">. " << e.what() << std::endl;
		throw BureaucratException();
	}
}

void Bureaucrat::decGrade(int grade) {
	try {
		if (this->grade + grade > 150)
			throw GradeTooLowException();
		this->grade += grade;
	} catch (const GradeTooLowException& e) {
		std::cerr << "Cant decrement grade of <" << getName() << ">. " << e.what() << std::endl;
		throw BureaucratException();
	}
}

void Bureaucrat::checkGrade(int grade) {
	try {
		if (grade > 150)
			throw GradeTooLowException();
		else if (grade < 1)
			throw GradeTooHighException();
	} catch (const GradeTooLowException& e) {
		std::cerr << "Cant set grade of " << getName() << ". " << e.what() << std::endl;
		throw BureaucratException();
	} catch (const GradeTooHighException& e) {
		std::cerr << "Cant set grade of " << getName() << ". " << e.what() << std::endl;
		throw BureaucratException();
	}
}

int Bureaucrat::getGrade() const {
	return grade;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade to low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade to high";
}

const char *Bureaucrat::BureaucratException::what() const throw() {
	return "";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat *a) {
	o << a->getName() << ", bureaucrat grade " << a->getGrade() << ".";
	return o;
}
