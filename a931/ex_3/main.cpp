/* 
    Assignment 9.3.1
    Exercise 3:
    Create a type that wraps a pointer of type std::string::pointer.  This will be our starting
    point of our iterator.  Then, at first, implement a simple increment and dereference 
    operators and conversion constructors from std::string::iterator.

    Try to iterate through elements of std::string with your own iterator, and verify that
    the functionality at this point is equivalent to the std::string::iterator.
 */

#include <string>
#include <iostream>
#include "iterator.h"

int main() {
    std::string str {"aBaBsos00"};

    for (Str_Iterator it (str.begin()); it != str.end(); ++it) {
        std::cout << *it << " " << static_cast<int>(*it) << '\n';
    }

    std::cout << '\n';
}