#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>
# pragma once

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& copy);
		const std::string getName() const;
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *f);

#endif
