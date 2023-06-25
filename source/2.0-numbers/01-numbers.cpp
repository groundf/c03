#include <limits>

#include <iostream>


auto main() -> int {

// integral types

    std::cout
    << "type\t│ lowest()\t│ min()\t\t│ max()\n"
    <<  "int\t|" << std::numeric_limits<int>::max() << std::numeric_limits<int>::max() << "\n";

// floating point types

    std::cout << std::numeric_limits<float>::min() << std::endl;
    std::cout << std::numeric_limits<float>::max() << std::endl;

}