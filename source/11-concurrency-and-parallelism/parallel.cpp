#include <vector>
#include <algorithm>
#include <execution>



int main(int argc, char const *argv[])
{
    std::vector<int> vec ={3, 2, 1, 4, 5, 6, 10, 8, 9, 4};

    std::sort(vec.begin(), vec.end());                            // sequential as ever
    std::sort(std::execution::seq, vec.begin(), vec.end());       // sequential
    std::sort(std::execution::par, vec.begin(), vec.end());       // parallel
    std::sort(std::execution::par_unseq, vec.begin(), vec.end()); // parallel and vectorized
}