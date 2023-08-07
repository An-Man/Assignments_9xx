// Assignment 9.1.1

/* 
    Exercise 2

    Use std::unordered_map<char, std::function<...>> to map a character to a function.
    Fill the map with operations '+', '-', '*' and '/'. Then read a line such as
    1 + 1 and parse the line to call the right function with the right parameters.
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <functional>
#include <unordered_map>
#include <sstream>
#include <cmath>

int add(int a, int b) {
    return (a + b);
}

int subtract(int a, int b) {
    return (a - b);
}

int multiply(int a, int b) {
    return (a * b);
}

double divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Cannot divide by 0");
    }
    return static_cast<double>(a) / static_cast<double>(b);
}

double power(int a, int b) {
    return std::pow(static_cast<double>(a), static_cast<double>(b));
}

int main()
{
    std::unordered_map<char, std::function<auto(int a, int b) -> double>> calc_map = {
        {'+', add},
        {'-', subtract},
        {'*', multiply},
        {'/', divide},
        {'^', power},
    };

    std::string line {"15 + 2"};
    std::string op {};
    std::string first_val {};
    std::string second_val {};

    std::istringstream iss(line);
    std::getline(iss, first_val, ' ');
    std::getline(iss, op, ' ');
    std::getline(iss, second_val);

    for (auto& n : calc_map) {
        if (op[0] == n.first) {
            std::cout << n.second(stoi(first_val), stoi(second_val)) << '\n';
        }
    }

    return 0;
}