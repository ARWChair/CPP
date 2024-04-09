#ifndef ROBOTOMTREQUESTFORM_HPP
# define ROBOTOMTREQUESTFORM_HPP
# include <ctime>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# pragma once

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm& copy);
		const std::string getName() const;
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *f);

#endif
