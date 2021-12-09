/*
  Examples for concepts.
 */


template<typename T>
requires true 
struct T { };


template<typename T>
requires false struct F { };


int main()
{
    // static_assert(__cplusplus >= 201500);    // check compiled with --std=c++1z
    // static_assert(__cpp_concepts >= 201500); // check compiled with -fconcepts
    T<int>(); // success
    F<int>(); // failure
}
