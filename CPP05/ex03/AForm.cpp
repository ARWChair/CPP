#include "AForm.hpp"

AForm::AForm(): name("default"), needed(150), grade(150), sign(false) {
}

AForm::AForm(std::string name, int grade, bool sign, int needed)
: name(name), needed(needed), grade(grade), sign(false) {
	checkGrade();
	checkNeeded();
	signForm(sign);
}

AForm::AForm(const AForm &copy): name(copy.name + "_copy"), needed(copy.needed), grade(copy.grade) {
	this->sign = copy.sign;
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &copy) {
	std::cout << "AForm = operator called" << std::endl;
	this->sign = copy.sign;
	return *this;
}

void AForm::beSigned(Bureaucrat *b) {
	if (b->getGrade() > this->needed)
		throw GradeTooLowException();
	if (this->sign == true)
		throw DoubleSignException();
	this->sign = true;
}

void AForm::signForm(bool value) {
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
		throw AFormException();
	} catch (const GradeTooLowException& e) {
		std::cerr << "Can't sign AForm. " << e.what() << std::endl;
		throw AFormException();
	} catch (const GradeTooHighException &e) {
		std::cerr << "Can't sign AForm. " << e.what() << std::endl;
		throw AFormException();
	}
}

void AForm::checkGrade() {
	try {
		if (this->grade > 150)
			throw GradeTooLowException();
		else if (this->grade < 1)
			throw GradeTooHighException();
	} catch (const GradeTooLowException& e) {
		std::cerr << "Can't assign grade \"" << grade << "\" to \"" << getName() << "\". " << e.what() << std::endl;
		throw AFormException();
	} catch (const GradeTooHighException& e) {
		std::cerr << "Can't assign grade \"" << grade << "\" to \"" << getName() << "\". " << e.what() << std::endl;
		throw AFormException();
	}
}

void AForm::checkNeeded() {
	try {
		if (this->needed > 150)
			throw GradeTooLowException();
		else if (this->needed < 1)
			throw GradeTooHighException();
	} catch (const GradeTooLowException& e) {
		std::cerr << "Can't assign needed \"" << grade << "\" to \"" << getName() << "\". " << e.what() << std::endl;
		throw AFormException();
	} catch (const GradeTooHighException& e) {
		std::cerr << "Can't assign needed \"" << grade << "\" to \"" << getName() << "\". " << e.what() << std::endl;
		throw AFormException();
	}
}

const std::string AForm::getName() const {
	return this->name;
}

int AForm::getNeeded() const {
	return this->needed;
}

int AForm::getGrade() const {
	return this->grade;
}

int AForm::isNeeded() const {
	return this->needed;
}

bool AForm::isSigned() const {
	return this->sign;
}

const char *AForm::DoubleSignException::what() const throw() {
	return "AForm already signed";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char *AForm::AFormException::what() const throw() {
	return "";
}

const char *AForm::GradeLowerThanNeededException::what() const throw() {
	return "Grade is lower than needed to sign the AForm.";
}

std::ostream &operator<<(std::ostream &o, AForm *f) {
	o	<< "\tName: " << f->getName() << std::endl
		<< "\tGrade: " << f->getGrade() << std::endl
		<< "\tNeeded: " << f->getNeeded() << std::endl
		<< "\tSigned: " << f->isSigned() << std::endl;
	return o;
}
