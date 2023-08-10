#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Cow
{
    public:
        Cow(std::string str) : name(str) {}

        void make_sound() { std::cout << "Mooo\n"; }

        bool eats_grass() const { return true; }
        bool is_fluffy() const { return false; }
   
        std::string name;
};

class Dog
{
    public:
        Dog(std::string str) : name(str) {}

        void make_sound() { std::cout << "Barkka Barkka\n"; }

        bool eats_grass() const { return false; }
        bool is_fluffy() const { return true; }
    
        std::string name;
};

#endif