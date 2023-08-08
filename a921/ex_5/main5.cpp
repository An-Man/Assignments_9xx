/* 
    Exercise 5

    Create a program, where you let user input a string (either read it from 
    command line or use I/O functions, it doesn't matter as long as the string is
    given by the end-user)  You may assign a max size for the string.

    Go through bytes in the string, and for each character of the string, mark
    the bit set if the character represents a comma.

    Print out the resulting bits.

*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

template <typename T>   
void print_bits(const T& value) {
    using decay_type = std::decay_t<T>;

    std::cout << "0b";

    for (int i = sizeof(decay_type) * 8 - 1; i >= 0; --i)
        std::cout << ((value & (1 << i)) ? 1 : 0);

    std::cout << '\n';
}

int main(int argc, char* argv[])
{
    std::vector<std::string> args;      // store cmd line args
    for (int i = 0; i < argc; ++i) {
        args.push_back(argv[i]);
    }

    if (args.size() < 2) {
        throw std::runtime_error("Error: Enter a string of max 8 chars as an argument\n");
    }
    
    std::string str {args[1]};

    if (str.size() > 8) {
        throw std::runtime_error("Maximum string size is 8 chars");
    }

    uint8_t mask {};

    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == ',') {
            mask |= (1 << i); 
        }    
    }

    print_bits(mask);
}