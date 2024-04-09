//
// Created by yatabay on 9/27/23.
//

#include "File.hpp"

int main(int argc, char **argv) {
    if (argc < 4) {
        std::cout << "Not enough arguments in functioncall. Please use: ./file [Filename] [to-find] [to-replace]" << std::endl;
        return 1;
    }
    File file;
    file.setFile(argv[1]);
    file.replace(argv[2], argv[3]);
}

