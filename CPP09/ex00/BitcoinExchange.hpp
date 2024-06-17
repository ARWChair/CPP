#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# pragma once
# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
#include <algorithm>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::string str);
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& copy);
		class InvalidDB: public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		std::map<int, long double> db;
		std::string file, dbFile;
		int lines;
		std::string mapString();
		std::string strip_line(std::string line);
		std::string strip_line_db(std::string line);
		std::string check_date(std::string line, int &pos, bool replace);
		std::string check_value(std::string line, int &pos, bool replace);
		std::string calculate(std::string file, int lines);
		long double calcBtc(std::string line, int date);
		int getDate(std::string line);
		void mapDB();
		void convert(std::string date, std::string value);
};

#endif
