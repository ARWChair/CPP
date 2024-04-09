#ifndef INTERN_HPP
# define INTERN_HPP
# pragma once
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& copy);
        ~Intern();

        Intern &operator=(const Intern& copy);
        AForm *makeForm(std::string form_name, std::string target);
};

#endif
