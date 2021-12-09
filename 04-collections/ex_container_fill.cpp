/*
Shows how to fill container with values without loop with `std::fill()`
and also `std::array` with member function `fill()`
 */

#include <array> // std::array
#include <algorithm> // std::fill
#include <iostream>


int main(int argc, char const *argv[])
{
    std::array<float, 10> arr;

    // Array is not set to zero values!
    std::cout << "randomly set values: ";
    for (auto e : arr) {
        std::cout << e << " ";
    }
    std::cout << "\n";

    std::cout << "properly set values: ";
    std::fill(std::begin(arr), std::end(arr), -1);
    for (auto e : arr) {
        std::cout << e << " ";
    }
    std::cout << "\n";

    std::cout << "properly set values with `std::array::fill()`: ";
    arr.fill(1);
    for (auto e : arr) {
        std::cout << e << " ";
    }
    std::cout << "\n";


    return 0;
}