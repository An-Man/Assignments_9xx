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