/* 
    Assignment 9.1.2

    Exercise 1a: Create a template class that takes an arbitrary function 
    as its template parameter.  Use the constructor to deduce the template
    types so user doesn't have to provide them.

    Exercise 1b: Save the information about function return type (via using)
    and function arity (number of arguments) in the class.  
    (This requires you to template the return type and function parameters separately)

    Exercise 1c: Create a function to test your class with.
    Use decltype to print out infomation contained without 
    manually entering the template parameters.
*/

#include "template.h"
#include <iostream>
#include <type_traits>
#include <typeinfo>

int sum(int a, int b) {
    return a + b;
}

void example2() {
    // empty
}

int main() {

    Caller c(sum);
    Caller d(example2);

    decltype(c)::return_type num = 6; // just a check, int can be assigned
        
    std::cout << std::boolalpha;
    std::cout << std::is_void_v<decltype(c)::return_type> << '\n';  // false
    std::cout << std::is_void_v<decltype(d)::return_type> << '\n';  // true

    // next 2 lines from Karri :D
    std::cout << "Return type: " << typeid(typename decltype(c)::return_type).name() << '\n';
    std::cout << "Return type: " << typeid(typename decltype(d)::return_type).name() << '\n';

    std::cout << decltype(c)::arg_count << '\n';    // prints 2
    std::cout << decltype(d)::arg_count << '\n';    // prints 0

}