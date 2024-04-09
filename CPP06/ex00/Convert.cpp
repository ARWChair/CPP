#include "Convert.hpp"

Convert::Convert() {
    std::cout << "Default convert constructor called" << std::endl;
}

Convert::Convert(std::string value): value(value) {
    std::cout << "Convert constructor called" << std::endl;
    converter();
}

Convert::Convert(const Convert& copy) {
    std::cout << "Convert copy constructor called" << std::endl;
    this->value = copy.value;
}

Convert::~Convert() {
    std::cout << "Convert destructor called" << std::endl;
}

Convert &Convert::operator=(const Convert& copy) {
    std::cout << "Convert = operator called" << std::endl;
    this->value = copy.value;
    return *this;
}

void Convert::check_number() {
    bool valid = false;
    bool wrong = false;
    int ffffs = 0;
    int count = 0;
    int dots = 0;

    while (value[count]) {
        if (value[count] == '.')
            dots++;
        if (value[count] == 'f')
            ffffs++;
        if ((!(value[count] >= '0' && value[count] <= '9')) && value[count] != '.' && value[count] != 'f')
            wrong = true;
        count++;
    }
    if (dots > 1 || ffffs > 1)
        wrong = true;
    if (wrong == true) {
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl
                  << "float: nanf" << std::endl
                  << "double: nan" << std::endl;
        return;
    }
    valid = true;
    if (ffffs == 1 && value[count - 1] != 'f') {
        valid = false;
        return;
    } else if (ffffs == 1) {
        value.pop_back();
        count--;
    }
    if (dots == 0 && ffffs == 0) {
        convert_int();
        return;
    }
    if (dots == 1 && value[count - 1] == '.') {
        count++;
        value += "0";
        convert_float(true);
        return;
    } else if (dots == 1) {
        convert_float(false);
    }
    if (dots == 0) {
        value += ".0";
        count += 2;
        convert_float(true);
        return;
    }
}

void Convert::convert_int() {
    int val = std::stoi(value);

    if (val < 127 && val >= 32)
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << val << std::endl
              << "float: " << static_cast<float>(val) << ".0f" << std::endl
              << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void Convert::convert_float(bool precission) {
    double val = std::stod(value);

    if (val < 127 && val >= 32)
        std::cout << "char: " << static_cast<char>(val) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (precission == true) {
        std::cout << "int: " << static_cast<int>(val) << std::endl
                  << "float: " << static_cast<float>(val) << ".0f" << std::endl
                  << "double: " << val << ".0" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(val) << std::endl
                  << "float: " << static_cast<float>(val) << "f" << std::endl
                  << "double: " << val << std::endl;
    }
}

void Convert::converter() {
    int num;

    if (value.length() > 1) {
        check_number();
        return;
    }
    num = value.c_str()[0];
    if (num >= '0' && num <= '9')
        num -= 48;
    if (num >= 0 && num <= 9)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << (char)num << "'" << std::endl;
    std::cout << "int: " << (int)num << std::endl
              << "float: " << (float)num << ".0f" << std::endl
              << "double: " << (double)num << ".0" << std::endl;
}

void Convert::setValue(std::string value) {
    this->value = value;
}

std::string Convert::getValue() {
    return value;
}