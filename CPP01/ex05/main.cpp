//
// Created by yatabay on 10/25/23.
//

#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
        return 0;
    Harl h;
    h.complain(argv[1]);
    return 0;
}

