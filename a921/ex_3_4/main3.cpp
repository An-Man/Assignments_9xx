#include "flags.h"
#include <iostream>

/* 
    Exercise 3

    Create a set of flags for 8 different options. You may make the options
    up yourself or use the given ones.
    Create a function to print out set options given a set of flags in 
    human-readable form. You can use a type of your own or uint8_t directly.

    Exercise 4

    Create another function to check for certain combinations of the set flags,
    and print out something special for those. 
*/

int main() 
{
    Creature one;               // with default flags

    one.print_stats();
    one.check_combinations();

    Creature two {0b1111'1101};

    two.print_stats();
    two.check_combinations();

    Creature three {0b0111'1111};

    three.print_stats();
    three.check_combinations();
}