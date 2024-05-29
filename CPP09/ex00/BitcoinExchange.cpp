#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string str) {
	std::fstream file(str);
	std::fstream db(std::string("data.csv"));

	if (!file.is_open())
		throw std::invalid_argument("Error: could not open file.");
	std::string line;
	int newLine = 0;
	while (std::getline(file, line)) {
		this->file += line += "\n";
	}
	line = "";
	while (std::getline(db, line)) {
		this->dbFile += line += "\n";
	}
	// this->file = mapString();
	this->dbFile = mapDB();
	// convert();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	this->input = copy.input;
	this->db = copy.db;
	this->file = copy.file;
	this->dbFile = copy.dbFile;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	this->input = copy.input;
	this->db = copy.db;
	this->file = copy.file;
	this->dbFile = copy.dbFile;
	return *this;
}

void BitcoinExchange::convert() {
	std::string line;
	std::string date;
	int index = 0;
	int pos;

	while (file[index]) {
		line += file[index];
		if (file[index + 1] == '\n' || file[index + 1] == '\0') {
			for (pos = 0; pos < 10; pos++) {
				date += line[pos];
				if (pos == 3 || pos == 6)
					pos++;
			}
			if (line.substr(0, 4) == "Erro") {
				input.insert(std::make_pair(-1, 0));
			} else {
				std::stringstream dStream(date);
				std::stringstream lStream(line.substr(13, line.length() - 13));
				int iDate = 0;
				long double lValue = 0;
				dStream >> iDate;
				lStream >> lValue;
				input.insert(std::make_pair(iDate, lValue));
				std::cout << iDate << " " << lValue << std::endl;
			}
			date = "";
			line = "";
			index++;
		}
		index++;
	}
	std::cout << std::endl;
	for (std::map<int, long double>::iterator it = input.begin(); it != input.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}
}

std::string BitcoinExchange::check_date(std::string line, int *pos, bool replace) {
	bool invalidDate = false;
	bool invalidDateLength = false;
	int posCopy = *pos;
	std::string tempData = "";
	std::string correction = "";
	std::string data = "";
	int day, month, year;

	for (; posCopy < line.length() && posCopy < 4 + *pos; posCopy++) {
		if (!(line[posCopy] >= '0' && line[posCopy] <= '9'))
			break;
		tempData += line[posCopy];
	}
	if (posCopy != 4 + *pos)
		invalidDateLength = true;
	std::stringstream stream(tempData);
	stream >> year;
	if (year < 2009 || year > 2022) {
		invalidDate = true;
	}
	correction += year;
	data += tempData;
	if (line[posCopy] != '-')
		invalidDate = true;
	data += line[posCopy];
	posCopy++;
	tempData = "";
	if ((line[posCopy] >= '0' && line[posCopy] <= '9') && (line[posCopy + 1] >= '0' && line[posCopy + 1] <= '9')) {
		tempData += line[posCopy];
		posCopy++;
		tempData += line[posCopy];
		posCopy++;
	} else if ((line[posCopy] >= '0' && line[posCopy] <= '9') && (!(line[posCopy + 1] >= '0' && line[posCopy + 1] <= '9'))) {
		tempData += line[posCopy];
		invalidDateLength = true;
		posCopy++;
	} else if (!(line[posCopy] >= '0' && line[posCopy] <= '9')) {
		invalidDate = true;
		posCopy++;
	}
	std::stringstream monthStream(tempData);
	monthStream >> month;
	if (month < 1 || month > 12)
		invalidDate = true;
	correction += "-";
	correction += tempData;
	data += tempData;
	tempData = "";
	if (line[posCopy] != '-')
		invalidDate = true;
	data += line[posCopy];
	posCopy++;
	if ((line[posCopy] >= '0' && line[posCopy] <= '9') && (line[posCopy + 1] >= '0' && line[posCopy + 1] <= '9')) {
		tempData += line[posCopy];
		posCopy++;
		tempData += line[posCopy];
		posCopy++;
	} else if ((line[posCopy] >= '0' && line[posCopy] <= '9') && (!(line[posCopy + 1] >= '0' && line[posCopy + 1] <= '9'))) {
		tempData += line[posCopy];
		invalidDateLength = true;
		posCopy++;
	} else if (!(line[posCopy] >= '0' && line[posCopy] <= '9')) {
		invalidDate = true;
		posCopy++;
	}
	std::stringstream dayStream(tempData);
	dayStream >> day;
	if (year == 2022 && month >= 3) {
		if (month == 3) {
			if (day > 29)
				invalidDate = true;
		} else if (month > 3)
			invalidDate = true;
	}
	data += tempData;
	if (invalidDate == false) {
		if (month == 2) {
			if (year == 2012 || year == 2016 || year == 2020) {
				if (day > 29 || day < 0)
					invalidDate = true;
			} else {
				if (day > 28 || day < 0)
					invalidDate = true;
			}
		} else if (month < 8) {
			if (month % 2 == 0) {
				if (day > 30 || day < 0)
					invalidDate = true;
			} else {
				if (day > 31 || day < 0)
					invalidDate = true;
			}
		} else if (month >= 8) {
			if (month % 2 != 0) {
				if (day > 30 || day < 0)
					invalidDate = true;
			} else {
				if (day > 31 || day < 0)
					invalidDate = true;
			}
		}
	}
	if ((invalidDate == true || invalidDateLength == true) && replace)
		tempData = "Error: bad input => " + data;
	else if ((invalidDate == true || invalidDateLength == true) && replace == false) {
		// std::cout << invalidDate << " " << invalidDateLength << std::endl;
		throw InvalidDB();
	}
	else
		tempData = data;
	*pos = posCopy;
	return tempData;
}

std::string BitcoinExchange::check_value(std::string correction, std::string line, int *pos, bool replace) {
	std::string returning = "";
	std::string tempData = "";
	bool minus = false;
	bool error = false;
	bool first = false;
	bool space = false;
	bool comma = false;
	int tempPos = *pos;
	int spaces = 0;
	int commas = 0;
	int end;

	for (; tempPos < line.length(); tempPos++) {
		if (line[tempPos] != ' ')
			break;
	}
	*pos = tempPos;
	for (int i = 0; tempPos < line.length(); tempPos++, i++) {
		if (i == 0 && line[tempPos] == '.')
			first = true;
		if (i != 0 && line[tempPos] == '.')
			commas++;
		if (i == 0 && line[tempPos] == '-')
			minus = true;
		if (i != 0 && line[tempPos] == '-')
			error = true;
		tempData += line[tempPos];
	}
	tempPos = *pos;
	for (end = line.length() - 1; end >= 0; end--) {
		if (line[end] != ' ')
			break;
	}
	for (; tempPos < line.length() && tempPos <= end; tempPos++) {
		if (line[tempPos] == ' ')
			space = true;
		returning += line[tempPos];
	}
	for (; tempPos < line.length(); tempPos++);
	*pos = tempPos;
	if (commas > 1)
		comma = true;
	if (minus && replace)
		return "Error: not a positive number";
	if ((comma || first || space || error || tempPos != line.length()) && replace)
		return "Error: bad input => " + returning;
	long double number = 0;
	std::stringstream stream(returning);
	stream >> number;
	if ((number > 2147483647) && replace)
		return "Error: too large a number";
	if ((minus || comma || first || space || error || tempPos != line.length() || number > 2147483647) && replace == false)
		throw InvalidDB();
	returning = correction + returning;
	return returning;
}

std::string BitcoinExchange::strip_line(std::string line) {
	std::string correction = "";
	int pos = 0;

	for (; pos < line.length(); pos++) {
		if (line[pos] != ' ')
			break;
	}
	correction += check_date(line, &pos, true);
	if (!(correction.find("Error:") != std::string::npos)) {
		for (; pos < line.length(); pos++)
			if (line[pos] != ' ')
				break;
		if (line[pos] != '|') {
			correction = "Error: bad input => " + correction;
			return correction;
		}
		pos++;
		correction += " | ";
		correction = check_value(correction, line, &pos, true);
	}
	return correction;
}

std::string BitcoinExchange::mapString() {
	std::string current = "";
	std::string newFile = "";
	int currLine = 0;

	for (int i = 0; i < file.length(); i++) {
		for (int j = i; j < file.length(); j++, i++) {
			if (file[j] == '\n' && currLine < this->lines) {
				try {
					newFile += strip_line(current);
					if (currLine < this->lines - 1)
						newFile += "\n";
				} catch (const std::exception& e) {
					;
				}
				j++;
				current = "";
				currLine++;
			}
			current += file[j];
		}
	}
	return newFile;
}

std::string BitcoinExchange::strip_line_db(std::string line) {
	std::string correction = "";
	int pos = 0;

	for (; pos < line.length(); pos++) {
		if (line[pos] != ' ')
			break;
	}
	correction += check_date(line, &pos, false);
	std::cout << correction << std::endl;
	if (!(correction.find("Error:") != std::string::npos)) {
		for (; pos < line.length(); pos++)
			if (line[pos] != ' ')
				break;
		if (line[pos] != ',') {
			correction = "Error: bad input => " + correction;
			return correction;
		}
		pos++;
		correction += ",";
		correction = check_value(correction, line, &pos, false);
	}
	return correction;
}

std::string BitcoinExchange::mapDB() {
	std::string current = "";
	std::string newFile = "";
	int currLine = 0;
	int nls = -1;
	for (int pos = 0; pos < dbFile.length(); pos++) {
		if (dbFile[pos] == '\n')
			nls++;
	}
	std::cout << nls << std::endl;
	for (int i = 0; i < dbFile.length(); i++) {
		for (int j = i; j < dbFile.length() && nls > 0; j++, i++) {
			if (currLine > 0) {
				if (dbFile[j] == '\n' && currLine < this->lines) {
					nls--;
					std::cout << nls << std::endl;
					newFile += strip_line_db(current);
					if (currLine < this->lines - 1)
						newFile += "\n";
					j++;
					current = "";
					currLine++;
				}
				current += dbFile[j];
			} else {
				if (dbFile[j] == '\n')
					currLine++;
			}
		}
	}
	return newFile;
}

const char *BitcoinExchange::InvalidDB::what() const throw() {
	return "Error in db file";
}
