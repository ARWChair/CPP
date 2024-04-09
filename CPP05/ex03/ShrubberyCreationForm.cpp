#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Default Shrubby form", 145, false, 137), target("default") {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm(target + " shrubby form", 145, false, 137), target(target) {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): target(copy.target + "_copy") {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	std::cout << "Shrubbery = operator called" << std::endl;
	this->target = copy.target;
	return *this;
}

const std::string ShrubberyCreationForm::getName() const {
	return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	try {
		if (executor.getGrade() > this->getNeeded())
			throw Bureaucrat::GradeTooLowException();
		if (this->isSigned() == true)
			throw AForm::DoubleSignException();
		std::ofstream outfile((this->getName() + "_shrubbery").c_str());
		for (int i = 0; i < 3; i++) {
			outfile << "            .        +          .      .          ." << std::endl <<
			"     .            _        .                    ." << std::endl <<
			"  ,              /;-._,-.____        ,-----.__" << std::endl <<
			" ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl <<
			"  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl <<
			"                      ,    `./  \\:. `.   )==-'  ." << std::endl <<
			"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl <<
			".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl <<
			"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl <<
			"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl <<
			"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl <<
			"              \\:  `  X` _| _,\\/'   .-'" << std::endl <<
			".               \":._:`\\____  /:'  /      .           ." << std::endl <<
			"                    \\::.  :\\/:'  /              +" << std::endl <<
			"   .                 `.:.  /:'  }      ." << std::endl <<
			"           .           ):_(:;   \\           ." << std::endl <<
			"                      /:. _/ ,  |" << std::endl <<
			"                   . (|::.     ,`                  ." << std::endl <<
			"     .                |::.    {\\" << std::endl <<
			"                      |::.\\  \\ `." << std::endl <<
			"                      |:::(\\    |" << std::endl <<
			"              O       |:::/{ }  |                  (o" << std::endl <<
			"               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl <<
			"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl <<
			"dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~" << std::endl << std::endl << std::endl;
		}
		outfile.close();
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Cant execute function <execute>. " << e.what() << std::endl;
		throw Bureaucrat::BureaucratException();
	} catch (const AForm::DoubleSignException& e) {
		std::cerr << "Cant execute form. " << e.what() << std::endl;
		throw AForm::AFormException();
	}
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *f) {
	o	<< "\tName: " << f->getName() << std::endl
		<< "\tGrade: " << f->getGrade() << std::endl
		<< "\tNeeded: " << f->getNeeded() << std::endl
		<< "\tSigned: " << f->isSigned() << std::endl;
	return o;
}

