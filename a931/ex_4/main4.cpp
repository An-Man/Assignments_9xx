// Assignment 9.3.1

// Exercise 4-5

#include <string>
#include <iostream>
#include "iterator.h"


int main() {
    std::string str {"🍍öaaa"};

    for (Str_Iterator it (str.begin()); it != str.end(); ++it) {
        std::cout << std::hex << static_cast<uint32_t>(*it) << '\n';
    }
}