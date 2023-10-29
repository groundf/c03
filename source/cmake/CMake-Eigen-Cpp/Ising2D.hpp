#include <Eigen/Core>
#include <Eigen/Dense>

#include <cstddef> // size_t
#include <type_traits>

template <std::size_t N>


/// Ising model with defined dynamics.
class Ising2D {

  static_assert(N > 0, "N must >= 0.");

  public:

    constexpr explicit Ising2D<N>(Eigen::Matrix<int, N, N> const& matrix, const float& temperature)
      : spins_(matrix)
      , T_(temperature)
    { }

    ~Ising2D() = default;

    void evolve() const noexcept {
        // create copy of array
        // iterate over each spin
        // when energy > ... flip spins
    }

    void energy const noexcept {
        // calculate energy for current state.
    }

    // temperature
    // magnetization

    void print() const noexcept {
        std::cout << spins() << std::endl;
    }

    Eigen::Matrix<int, N, N> spins() const noexcept {
        return spins_;
    }

    // glauber

    // kawassaki

  private:
    // Temperature, Energy, Magnetization, Heat Capacity, Succeptibility.
    const float T;
    const float M;
    const float beta = 1.0/temperature_;
    Eigen::Matrix<int, N, N> spins_;

};


template <std::size_t N>
bool operator==(Ising2D<N> const& lhs, Ising2D<N> const& rhs) {
    return lhs.spins() == rhs.spins();
}

template <std::size_t N>
bool operator!=(Ising2D<N> const& lhs, Ising2D<N> const& rhs) {
    return !(lhs.spins() == rhs.spins());
}

namespace std {
    // hash() { }
}

// iostream { }