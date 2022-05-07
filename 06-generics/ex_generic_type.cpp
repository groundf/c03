/*

Vector type with generic numeric type.

Example:

    Vector<2, float> v{1, 2};

*/

#include <array>
#include <iostream>


template <typename T>
class Vector2 final
{
  public:

    constexpr Vector2(const T& x, const T& y) : values{x, y}  { }

    constexpr x() const noexcept { return values[0]; }
    constexpr y() const noexcept { return values[1]; }

  private:

    const std::array<T, 2> values;

};


int main(int argc, char const *argv[])
{
    Vector2<float> v{1, 2};

    std::cout << v.x() << ", " << v.y() << "\n";

    return 0;
}