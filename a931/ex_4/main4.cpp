// Assignment 9.3.1

/* 
    Exercise 4: Reimplement increment operator so that it moves to the next
    unicode codepoint instead of next byte.

    Exercise 5: Reimplement the dereferencing operator so it reads the 
    entire codepoint, and returns its value.

 */

#include <string>
#include <iostream>
#include "iterator.h"


int main() {
    std::string str {"🍍öa"};

    for (Str_Iterator it (str.begin()); it != str.end(); ++it) {
        std::cout << std::hex << static_cast<uint32_t>(*it) << '\n';
    }
}