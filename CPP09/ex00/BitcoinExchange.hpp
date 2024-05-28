#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# pragma once
# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::string str);
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& copy);
	private:
		std::map<int, long double> input;
		std::map<int, long double> db;
		std::string file;
		int lines;
		std::string mapString();
		std::string strip_line(std::string line);
		std::string check_date(std::string line, int *pos);
		std::string check_value(std::string correction, std::string line, int *pos);
		void convert();
};

#endif
