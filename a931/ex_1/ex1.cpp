/* Exercise 1

    Use iterator-based for loop to go through a string and print individual 
    characters.  What happens when there's a character outside of ASCII charset? 
    (try with e.g. emoji, åäö, etc.)

    Also print out the character as integers (to see the value of bytes beneath) */


#include <string>
#include <iostream>

int main() {
    std::string str {"ACAB1312Ö"};

    for (auto it = str.begin(); it < str.end(); ++it) {
        std::cout << *it << " " << static_cast<int>(*it) << '\n';
    }

    std::cout << '\n';
}

// the program prints
/* 

A 65
C 67
A 65
B 66
1 49
3 51
1 49
2 50
� -61
� -106

 */