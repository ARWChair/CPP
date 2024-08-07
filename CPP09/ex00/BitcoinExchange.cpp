#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string str) {
	std::fstream file(str.c_str());
	std::fstream db(std::string("data.csv").c_str());
	int lines = 0;

	if (!file.is_open())
		throw std::invalid_argument("Error: could not open file.");
	std::string line;
	while (std::getline(file, line)) {
		if (line.length() > 0) {
			this->file += line += '\n';
			lines++;
		}
	}
	if (this->file.length() == 0) {
		throw std::invalid_argument("File is empty");
	}
	file.close();
	line = "";
	while (std::getline(db, line)) {
		if (line.length() > 0) {
			this->dbFile += line += "\n";
		}
	}
	db.close();
	mapDB();
	this->file = mapString();
	std::cout << calculate(this->file, lines) << std::endl;
}


int BitcoinExchange::getDate(std::string line) {
	std::string date;
	std::size_t pos = 0;

	while (pos < line.length() && pos < 10) {
		date += line[pos];
		if (pos == 3 || pos == 6)
			pos++;
		pos++;
	}

	std::stringstream dateStream(date);
	int intDate = 0;
	dateStream >> intDate;
	std::map<int, long double>::iterator first = this->db.begin();
	if (intDate < first->first)
		return -1;
	return intDate;
}

long double BitcoinExchange::calcBtc(std::string line, int date) {
	std::map<int, long double>::iterator prevDate;
	std::string value;
	int pos = 10;

	pos += 3;
	while (line[pos] && line[pos] != '\n') {
		value += line[pos];
		pos++;
	}
	std::stringstream valueStream(value);
	long double ldValue = 0;
	valueStream >> ldValue;
	std::map<int, long double>::iterator first = this->db.begin();
	for (; first != db.end(); ++first) {
		if (date < first->first)
			break;
		prevDate = first;
	}
	ldValue *= prevDate->second;
	return ldValue;
}

static std::string replaceStr(std::string line, std::string find, std::string replace) {
	std::size_t pos;

	pos = line.find(find);
	line.replace(pos, find.length(), replace);
	return line;
}

static std::string to_string_remove_trailing_zeros(long double value) {
	std::string strValue;
	std::ostringstream convert;
	convert << value;
	strValue = convert.str();
	for (int index = strValue.length() - 1; index > 0; index--) {
		if (strValue[index] == '0')
			strValue[index] = 0;
	}
	return strValue;
} 

std::string BitcoinExchange::calculate(std::string file, int line) {
	std::string *lines = new std::string[line]();
	std::string returning;
	long double value;
	bool error;
	bool outOfBounds;
	int date;
	int pos = 0;

	for (std::size_t i = 0; i < file.length(); i++) {
		if (file[i] == '\n') {
			pos++;
			i++;
		}
		if (pos == line)
			break;
		lines[pos] += file[i];
	}
	pos = 0;
	while (pos < line) {
		error = false;
		outOfBounds = false;
		if (lines[pos].substr(0, 5) != "Error") {
			date = getDate(lines[pos]);
			if (date == -1)
				outOfBounds = true;
			value = calcBtc(lines[pos], date);
		} else {
			error = true;
		}
		if (error)
			returning += lines[pos];
		else if (outOfBounds)
			returning += "Error: date not found";
		else
			returning += replaceStr(lines[pos], " | ", " => ") + " = " + to_string_remove_trailing_zeros(value);
		if (pos < line - 1) {
			returning += "\n";
		}
		pos++;
	}
	delete[] lines;
	return returning;
}

void BitcoinExchange::convert(std::string date, std::string value) {
	std::string tempDate = "";
	for (int i = 0; i < 10; i++) {
		tempDate += date[i];
		if (i == 3 || i == 6)
			i++;
	}
	std::stringstream dateStream(tempDate);
	std::stringstream valueStream(value);
	int iDate = 0;
	long double ldValue = 0;
	dateStream >> iDate;
	valueStream >> ldValue;
	db.insert(std::make_pair(iDate, ldValue));
}

std::string BitcoinExchange::check_date(std::string line, std::size_t &pos, bool replace) {
	bool invalidDate = false;
	bool invalidDateLength = false;
	std::size_t posCopy = pos;
	std::string tempData;
	std::string correction;
	std::string data;
	int day = 0;
	int month = 0;
	int year = 0;

	for (; posCopy < line.length() && posCopy < 4 + pos; posCopy++) {
		if (!(line[posCopy] >= '0' && line[posCopy] <= '9'))
			break;
		tempData += line[posCopy];
	}
	if (posCopy != 4 + pos)
		return "Error: bad input => " + line;
	std::stringstream stream(tempData);
	stream >> year;
	if (year < 1000 || year > 9999) {
		invalidDate = true;
	}
	correction += year;
	data += tempData;
	if (line[posCopy] != '-')
		invalidDate = true;
	data += line[posCopy];
	posCopy++;
	tempData.clear();
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
	tempData.clear();
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
	data += tempData;
	if (replace) {
		std::map<int, long double>::iterator it = db.begin();
		if (year < it->first/ 10000) {
			std::istringstream lineStream(line);
			std::string innerLine;

			std::getline(lineStream, innerLine, (char)'|');
			tempData = "Error: bad input => " + innerLine;
			return tempData;
		}
	}
	//check here if date is lower than min of db
	if (invalidDate == false) {
		if (month == 2) {
			if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) {
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
	if ((invalidDate == true || invalidDateLength == true) && replace) {
		std::istringstream lineStream(line);
		std::string innerLine;

		std::getline(lineStream, innerLine, (char)'|');
		tempData = "Error: bad input => " + innerLine;
	}
	else if ((invalidDate == true || invalidDateLength == true) && replace == false) {
		throw InvalidDB();
	}
	else
		tempData = data;
	pos = posCopy;
	return tempData;
}

std::string BitcoinExchange::check_value(std::string line, std::size_t &pos, bool replace) {
	std::string returning = "";
	std::string tempData = "";
	std::size_t tempPos = pos;
	std::size_t end;
	bool minus = false;
	bool error = false;
	bool first = false;
	bool space = false;
	bool comma = false;
	int commas = 0;

	for (; tempPos < line.length(); tempPos++) {
		if (line[tempPos] != ' ')
			break;
	}
	pos = tempPos;
	for (int i = 0; tempPos < line.length(); tempPos++, i++) {
		if (i == 0 && line[tempPos] == '.')
			first = true;
		if (i != 0 && line[tempPos] == '.')
			commas++;
		if (i == 0 && line[tempPos] == '-')
			minus = true;
		if (i != 0 && line[tempPos] == '-')
			error = true;
		if (line[tempPos] == ',')
			commas += 2;
		tempData += line[tempPos];
	}
	tempPos = pos;
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
	pos = tempPos;
	if (commas > 1)
		comma = true;
	if (minus && replace)
		return "Error: not a positive number";
	if ((comma || first || space || error || tempPos != line.length()) && replace)
		return "Error: bad input => " + returning;
	long double number = 0;
	std::stringstream stream(returning);
	stream >> number;
	if ((number > 1000) && replace)
		return "Error: too large a number";
	if ((minus || comma || first || space || error || tempPos != line.length() || number > 2147483647) && replace == false)
		throw InvalidDB();
	return returning;
}

std::string BitcoinExchange::strip_line(std::string line) {
	std::string correction;
	std::string tempVal;
	std::size_t pos;

	for (pos = 0; pos < line.length(); pos++) {
		if (line[pos] != ' ')
			break;
	}
	if (pos == line.length())
		return "Error: bad input => " + line;
	correction += check_date(line, pos, true);
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
		tempVal += check_value(line, pos, true);
		if (tempVal.substr(0, 5) == "Error")
			correction = tempVal;
		else
			correction += tempVal;
	}
	return correction;
}

std::string BitcoinExchange::mapString() {
	std::string current;
	std::string newFile;

	for (std::size_t j = 0; j < file.length(); j++) {
		if (file[j] == '\n') {
			try {
				newFile += strip_line(current);
				if (j < file.length() - 1)
					newFile += "\n";
			} catch (const std::exception& e) {
				;
			}
			j++;
			current.clear();
		}
		current += (char)file[j];
	}
	return newFile;
}

std::string BitcoinExchange::strip_line_db(std::string line) {
	std::string correction = "";
	std::string value = "";
	std::string date = "";
	std::size_t pos = 0;

	for (; pos < line.length(); pos++) {
		if (line[pos] != ' ')
			break;
	}
	correction += check_date(line, pos, false);
	if (!(correction.find("Error:") != std::string::npos)) {
		for (; pos < line.length(); pos++)
			if (line[pos] != ' ')
				break;
		if (line[pos] != ',')
			throw InvalidDB();
		pos++;
		date = correction;
		correction += ",";
		value = check_value(line, pos, false);
		convert(date, value);
		correction += value;
	}
	return correction;
}

void BitcoinExchange::mapDB() {
	std::string current;
	std::string newFile;
	int currLine = 0;
	int nls = -1;

	for (std::size_t pos = 0; pos < dbFile.length(); pos++) {
		if (dbFile[pos] == '\n')
			nls++;
	}
	for (std::size_t j = 0; j < dbFile.length() && nls > 0; j++) {
		if (dbFile[j] == '\n') {
			nls--;
			newFile += strip_line_db(current);
			if (currLine < nls - 1)
				newFile += "\n";
			j++;
			current.clear();
			currLine++;
		}
		current += dbFile[j];
	}
}

const char *BitcoinExchange::InvalidDB::what() const throw() {
	return "Error in db file";
}
