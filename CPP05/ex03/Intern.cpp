#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Default intern constructor called" << std::endl;
}

Intern::Intern(const Intern& copy) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern& copy) {
    std::cout << "Intern = operator called" << std::endl;
    if (this != &copy)
        *this = copy;
    return *this;
}

static AForm *makeShrub(std::string target) {
    ShrubberyCreationForm *shrub = new ShrubberyCreationForm(target);
    return shrub;
}

static AForm *makePresi(std::string target) {
    PresidentialPardonForm *presi = new PresidentialPardonForm(target);
    return presi;
}

static AForm *makeRoboti(std::string target) {
    RobotomyRequestForm *roboti = new RobotomyRequestForm(target);
    return roboti;
}

AForm *Intern::makeForm(std::string form_name, std::string target) {
    AForm *(*forms[])(const std::string target) = {&makeShrub, &makePresi, &makeRoboti};
    std::string names[] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};

    for (int i = 0; i < 3; i++) {
        if (form_name == names[i]) {
            std::cout << "Intern creates " << form_name << std::endl;
            return (forms[i](target));
        }
    }
    std::cout << "Intern cannot create form. Form \"" << form_name << "\" doesn't exist." << std::endl;
    return (NULL);
}
