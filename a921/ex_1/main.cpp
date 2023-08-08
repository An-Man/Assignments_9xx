// Exercise 1
// Create a function to check if nth bit is set in an value.

#include <cstdint>
#include <iostream>

template <typename T>
bool is_set_bit(const T& value, int N) {

    return value & (1 << (N - 1)); 
}

int main() {
    uint8_t value5 = 5;
    uint8_t value2 = 2;
    std::cout << std::boolalpha << is_set_bit(value5, 1) << '\n';
    std::cout << std::boolalpha << is_set_bit(value5, 2) << '\n';
    std::cout << std::boolalpha << is_set_bit(value5, 3) << '\n';
    std::cout << std::boolalpha << is_set_bit(value5, 4) << '\n';

    std::cout << std::boolalpha << is_set_bit(value2, 1) << '\n';
    std::cout << std::boolalpha << is_set_bit(value2, 2) << '\n';
    std::cout << std::boolalpha << is_set_bit(value2, 3) << '\n';
}
