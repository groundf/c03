
#include <vector>
#include <algorithm>


// Naive implementation
// Iterate over first sequence unless we reach the end.
// Test the values and when they differs return false.
//
template <typename InpuIterator1, typename InputIterator2>
bool equal(InpuIterator1 first1, InpuIterator1 last1, InpuIterator2 first2)
{
    while(first1 != last1)
    {
        if ( !(*first1 == *first2) ) {
            return false;
        }
        ++first1; ++first2;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    return 0;
}
