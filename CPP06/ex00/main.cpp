#include "Convert.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;
    std::string temp = argv[1];
    Convert con(temp);
}
