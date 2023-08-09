#include <string>
#include <iostream>
#include "iterator.h"

int main() {
    std::string str {"aBaBsos00"};

    for (Str_Iterator it (str.begin()); it != str.end(); ++it) {
        std::cout << *it << " " << static_cast<int>(*it) << '\n';
    }

    std::cout << '\n';
}