/* 
    Assignment 9.4.1

    Exercise 1
    In exercise 6.1.2 we created a tagged union of our own.  
    Reimplement the same using a std::variant instead. Use full
    name instead of the initial this time around.
*/

#include <iostream>
#include <variant>

using Entity = std::variant<
    int,
    std::string,
    float
>;

int main()
{
    Entity robot = 9;
    Entity alien = 6.67f;
    Entity human = "Sarah";
    std::cout << std::get<int>(robot) << '\n'; // print value

    alien = std::get<int>(robot);              // this is ok, implicit conversion
    std::cout << std::get<int>(alien) << '\n';

    robot = std::get<float>(alien);            // this throws bad_variant_access

    return 0;
}