#include "iter.hpp"

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Testing iter" << std::endl;
    iter(arr, 10, print_test);
}