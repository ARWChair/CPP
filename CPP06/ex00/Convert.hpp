#ifndef CONVERT_HPP
# define CONVERT_HPP
# pragma once
# include <string>
# include <iostream>
# include <sstream>
# include <iomanip>
# include <cmath>

class Convert {
    private:
        std::string value;
    public:
        Convert();
        Convert(std::string value);
        Convert(const Convert& copy);
        ~Convert();

        Convert &operator=(const Convert& copy);
        void check_number();
        void convert_int();
        void convert_float(bool precission);
        void converter();
        void setValue(std::string value);
        std::string getValue();
};

#endif
