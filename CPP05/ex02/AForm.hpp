#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# pragma once

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		const int needed;
		const int grade;
		bool sign;
	public:
		AForm();
		AForm(std::string name, int grade, bool sign, int needed);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(const AForm &copy);

		virtual void execute(Bureaucrat const &executor) const = 0;
		void beSigned(Bureaucrat *b);
		void signForm(bool value);
		void checkGrade();
		void checkNeeded();
		virtual const std::string getName() const;
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

		class AFormException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, AForm *f);

#endif
