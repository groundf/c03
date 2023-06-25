#include <iostream>
#include <random>
#include <cstddef>

#include <Eigen/Core>
#include <Eigen/Dense>

#include "Ising2D.hpp"


int main()
{
    constexpr std::size_t N = 10;

    Eigen::Matrix<int, N, N> spins;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            spins(i, j) = 0;
        }
    }

    Ising2D<N> model(spins);

    model.print();

    return 0;
}