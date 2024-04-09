//
// Created by yatabay on 9/27/23.
//

#ifndef CPP_FILE_HPP
#define CPP_FILE_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iosfwd>

class File {
private:
    std::string file;
public:
    File(void);
    void    setFile(std::string file);
    void    replace(std::string replace, std::string find);
    std::string getInput();
    std::string getFile();
};


#endif //CPP_FILE_HPP

