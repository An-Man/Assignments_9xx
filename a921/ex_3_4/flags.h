#ifndef FLAGS_H
#define FLAGS_H

#include <iostream>

constexpr static uint8_t IS_FUZZY            = 0b1;
constexpr static uint8_t IS_LARGE            = 0b10;
constexpr static uint8_t HAS_GOOGLY_EYES     = 0b100;
constexpr static uint8_t IS_CUTE             = 0b1000;
constexpr static uint8_t HAS_TEETH           = 0b10000;
constexpr static uint8_t IS_ABOUT_TO_EAT_YOU = 0b100000;
constexpr static uint8_t IS_FRIENDLY         = 0b1000000;
constexpr static uint8_t IS_SPIDER           = 0b10000000;

class Creature 
{   
    private:
    uint8_t flags {};

    public:
        Creature() {
            flags = 0b0110'0011;
        }

        Creature(uint8_t in_flag) {
            flags = in_flag;
        }

        void print_stats();

        void check_combinations();

        bool is_dangerous();

        bool is_bunny();
};

void Creature::print_stats() {
    std::cout << "This creature: \n";

    if (static_cast<bool>(flags & IS_FUZZY)) {
        std::cout << "-is fuzzy\n";
    }
    if (static_cast<bool>(flags & IS_LARGE)) {
        std::cout << "-is large\n";
    }
    if (static_cast<bool>(flags & HAS_GOOGLY_EYES)) {
        std::cout << "-has googly eyes\n";
    }
    if (static_cast<bool>(flags & IS_CUTE)) {
        std::cout << "-is cute\n";
    }
    if (static_cast<bool>(flags & HAS_TEETH)) {
        std::cout << "-has teeth\n";
    }
    if (static_cast<bool>(flags & IS_ABOUT_TO_EAT_YOU)) {
        std::cout << "-is about to eat you\n";
    }
    if (static_cast<bool>(flags & IS_FRIENDLY)) {
        std::cout << "-is friendly\n";
    }
    if (static_cast<bool>(flags & IS_SPIDER)) {
        std::cout << "-is a spider\n";
    }
}

void Creature::check_combinations() {
    if (is_dangerous()) {
        std::cout << "This creature IS dangerous!\n";
    } else {
        std::cout << "This creature is not dangerous.\n";
    }

    if (is_bunny()) {
        std::cout << "This creature is a bunny.\n";
    } else {
        std::cout << "This creature is not a bunny.\n";
    }

    if (is_dangerous() && is_bunny()) {
        std::cout << "This creature is the Killer Rabbit Of "
                  << "Caerbannog!!! AAAAAARGH!\n";
    }
    
}

bool Creature::is_dangerous() {
    return (static_cast<bool>(flags & HAS_TEETH) && (flags & IS_ABOUT_TO_EAT_YOU));
}

bool Creature::is_bunny() {
    return (static_cast<bool>(flags & IS_FUZZY) && (flags & IS_CUTE) && !(flags & IS_SPIDER));
}


#endif