//
// Created by yatabay on 9/27/23.
//

#include "File.hpp"

File::File() {}

void File::setFile(std::string file) {
    this->file = file;
}

std::string File::getInput() {
    std::string temp;

    std::ifstream input_file(file.c_str());
    if (!input_file) {
        std::cerr << "Could not open the file - '" << file << "'" << std::endl;
        return NULL;
    }

    std::ostringstream buffer;
    buffer << input_file.rdbuf();
    temp = buffer.str();
    return temp;
}

void File::replace(std::string to_find, std::string to_replace) {
    std::string temp;
    std::ofstream tfile;
    std::string replaced;
    size_t pos = 0;

    temp = getInput();
    if (temp.empty())
            return;
    while ((pos = temp.find(to_find, pos)) != std::string::npos) {
        temp.erase(pos, to_find.length());
        temp.insert(pos, to_replace);
        pos += to_replace.length();
    }
    replaced = file + ".replaced";
    tfile.open(replaced.c_str());
    tfile << temp;
}

std::string File::getFile() {
    return file;
}

