#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Default Presidential form", 25, false, 5), target("default") {
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm(target + " presidential form", 25, false, 5), target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): target(copy.target + "_copy") {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	this->target = copy.getName();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

const std::string PresidentialPardonForm::getName() const {
	return target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	try {
		if (executor.getGrade() > this->getNeeded())
			throw Bureaucrat::GradeTooLowException();
		if (this->isSigned() == true)
			throw AForm::DoubleSignException();
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Cant execute function <execute>. " << e.what() << std::endl;
		throw Bureaucrat::BureaucratException();
	} catch (const AForm::DoubleSignException& e) {
		std::cerr << "Cant execute form. " << e.what() << std::endl;
		throw AForm::AFormException();
	}
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *f) {
	o	<< "\tName: " << f->getName() << std::endl
		<< "\tGrade: " << f->getGrade() << std::endl
		<< "\tNeeded: " << f->getNeeded() << std::endl
		<< "\tSigned: " << f->isSigned() << std::endl;
	return o;
}

