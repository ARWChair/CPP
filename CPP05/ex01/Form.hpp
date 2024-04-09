#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# pragma once

class Bureaucrat;

class Form {
	private:
		const std::string name;
		const int needed;
		const int grade;
		bool sign;
	public:
		Form();
		Form(std::string name, int grade, bool sign, int needed);
		Form(const Form &copy);
		~Form();
		Form &operator=(const Form &copy);

		void beSigned(Bureaucrat *b);
		void signForm(bool value);
		void checkGrade();
		void checkNeeded();
		const std::string getName() const;
		int isNeeded() const;
		int getNeeded() const;
		int getGrade() const;
		bool isSigned() const;

		class DoubleSignException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeLowerThanNeededException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form *f);

#endif
