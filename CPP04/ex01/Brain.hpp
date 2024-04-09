#ifndef BRAIN_H
# define BRAIN_H
# include <string>
# include <iostream>
# pragma once

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain &operator=(const Brain &copy);
};

#endif
