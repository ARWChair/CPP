#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Default Robotomy form", 72, false, 45), target("default") {
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm(target + " robotomy form", 72, false, 45), target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): target(copy.target + "_copy") {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequest destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	std::cout << "RobotomyRequest = operator called" << std::endl;
	this->target = copy.getName();
	return *this;
}

const std::string RobotomyRequestForm::getName() const {
	return target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	int random;

	try {
		if (executor.getGrade() > this->getNeeded())
			throw Bureaucrat::GradeTooLowException();
		if (this->isSigned() == true)
			throw AForm::DoubleSignException();
		srand(time(NULL));
		random = rand();
		if (random % 2 == 0)
			std::cout << getName() << " was robotomized successfully" << std::endl;
		else
			std::cout << getName() << " failed robotomizing" << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Cant execute function <execute>. " << e.what() << std::endl;
		throw Bureaucrat::BureaucratException();
	} catch (const AForm::DoubleSignException& e) {
		std::cerr << "Cant execute form. " << e.what() << std::endl;
		throw AForm::AFormException();
	}
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *f) {
	o	<< "\tName: " << f->getName() << std::endl
		<< "\tGrade: " << f->getGrade() << std::endl
		<< "\tNeeded: " << f->getNeeded() << std::endl
		<< "\tSigned: " << f->isSigned() << std::endl;
	return o;
}
