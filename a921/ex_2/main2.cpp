/*
    Exercise 2
    Create a template function to swap byte order of the value it is
    given, regardless of its size.  It should work at least for unsigned
    integer types.  Use static_assert with the type_traits header to make
    sure only integral types are accepted.
*/

#include <cstdint>
#include <iostream>
#include <type_traits>
#include <bit>
#include <array>
#include <algorithm>
#include <string>
#include <vector>

template <typename T>
void swap_byte_order(T& value) {

    static_assert(std::is_integral_v<T>, "must be integral type");

    auto ptr = reinterpret_cast<std::uint8_t*>(&value); // pointer to byte

    std::vector<std::uint8_t> source (sizeof(T));       // vector for bytes

    for (int i = 0; i < sizeof(T); ++i) {               // fill vector from value
        source[i] = ptr[i];
    }

    std::vector<std::uint8_t> dest (sizeof(T));         // vector for reverse order

    std::reverse_copy(source.begin(), source.end(), dest.begin());

    for (int i = 0; i < sizeof(T); ++i) {               // reverse order of bytes 
        ptr[i] = dest[i];                               // in original value
    }
}

// print function to check result
template <typename T>   
void print_bits(const T& value) {
    using decay_type = std::decay_t<T>;

    std::cout << "0b";

    for (int i = sizeof(decay_type) * 8 - 1; i >= 0; --i)
        std::cout << ((value & (1 << i)) ? 1 : 0);

    std::cout << '\n';
}

int main() {

    uint16_t value {752};
    uint32_t value32 {721};

    // std::string v {"sdff"};   
    // swap_byte_order(v);         // will not compile as not integral

    print_bits(value);
    print_bits(value32);

    swap_byte_order(value);
    swap_byte_order(value32);

    print_bits(value);
    print_bits(value32);
}