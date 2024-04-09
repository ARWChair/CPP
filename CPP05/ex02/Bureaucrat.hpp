#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "AForm.hpp"
# include <iostream>
# include <string>
# pragma once

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &copy);

		void executeForm(AForm const & form);
		void signForm(AForm &f);
		const std::string getName() const;
		void incGrade(int grade = 1);
		void decGrade(int grade = 1);
		void checkGrade(int grade);
		int getGrade() const;

		//Create exceptions
		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class BureaucratException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat *a);

#endif
