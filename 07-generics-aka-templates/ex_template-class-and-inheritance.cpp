#include <iostream>
#include <typeinfo>

/*

# C++ template class and inheritance

When you define template class like example below.

*/

struct TYPE_1;
struct TYPE_2;

namespace v1
{
    // The class template with template parameter `T`.
    template <typename T>
    struct parent
    {
        void say_hello()
        {
            std::cout << "Using the *parent* class*." << "\n";
        }
    };

    // The specialized class template with template argument `TYPE_1`.
    template <>
    struct parent<TYPE_1>
    {
        void say_hello()
        {
            std::cout << "Using the *specialized parent class for TYPE_1*." << "\n";
        }
    };
}

/*

A compiler will use that template class for every class instation e.g
What is "problem" with template class specialisation is that you have to reimplement every method from originma template class.
It means a lot of code duplication!

*/


int main(int argc, char const *argv[])
{
    v1::parent<TYPE_1> p1;
    v1::parent<TYPE_2> p2;

    p1.say_hello();
    p2.say_hello();

    return 0;
}






