/*
---
category: C++ exercise
---

# Find a median of two sortred arrays 

## Problem

Mějme zadaná dvě uspořádáná pole. Najděte medián spojených polí
s časouvou složitostí O(log(N)), kde N je součet délek obou polí.

### Examples

```input
in: {1, 6, 8}, {0, 1, 2, 2, 9} => {0, 1, 1, 2, 2, 6, 8, 9}
```

```output

```

## Solutions

*/

#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>

int main(void) {

    // Create two sorted arrays.
    constexpr std::array<int, 3> array1 = {1, 6, 8};       
    constexpr std::array<int, 5> array2 = {0, 1, 2, 3, 9};

    std::cout << "\narray1: ";
    
    /*/The range based for loop./*/ 
    for (const auto& i : array1 ) {
        std::cout << i << " ";
    }

    std::cout << "\narray2: ";

  
    for (const auto& i : array2 ) {
        std::cout << i << " ";
    }

    // Merge arrays and sort in-place.
    std::array<int, array1.size() + array2.size()> merged;
    std::copy(array1.begin(), array1.end(), merged.begin());
    std::copy(array2.begin(), array2.end(), merged.begin() + array1.size());
    std::sort(std::begin(merged), std::end(merged));
    
    std::cout << "\nmerged: ";
    for (const auto& i : merged) {
        std::cout << i << " ";
    }
    
//### 1. 
//Nejdříve správné řešení, ketré ale nesplňuje podmínku na časovou složitost.

    
}