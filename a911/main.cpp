// Assignment 9.1.1

/* 
    Exercise 1

    Create a table of functions (std::vector is fine).  Then read user input
    from command line, standard input or a file (your choice), where user 
    determines which function in the array to call.
 */

#include <iostream>
#include <functional>
#include <vector>
#include <cctype>
#include <stdexcept>

void print_lowercase(std::string str) {
    for (auto c : str) {
        std::cout << static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    std::cout << '\n';
}

void print_uppercase(std::string str) {
    for (auto c : str) {
        std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }
    std::cout << '\n';
}

void print_ascii(std::string str) {
    for (auto c : str) {
        std::cout << static_cast<int>(c) << " ";
    }
    std::cout << '\n';
}

int main(int argc, char* argv[])
{
    std::vector<std::string> args;      // store cmd line args
    for (int i = 0; i < argc; ++i) {
        args.push_back(argv[i]);
    }

    if (args.size() < 3) {
        throw std::runtime_error("Enter two arguments after program call:\n"
        "a string followed by --lower, --upper or --ascii");
    }

    // store functions using std::function
    std::vector<std::function<void(std::string)>> printers = {
        print_lowercase,
        print_uppercase,
        print_ascii
    };                              

    std::string input_str {args[1]};    // take second argument as input string

    if (args[2] == "--lower") {
        printers[0](input_str);
    } else if (args[2] == "--upper") {
        printers[1](input_str);
    } else if (args[2] == "--ascii") {
        printers[2](input_str);
    } else {
        throw std::runtime_error("Invalid argument");
    }

    return 0;
}