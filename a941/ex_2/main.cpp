#include <variant>
#include <vector>

#include "animal.h"

template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

using Animal = std::variant<
    Cow,
    Dog
>;

int main() {
    std::vector<Animal> animals;

    Dog dog("Doggie");
    Cow cow("Charlie");

    animals.push_back(dog);
    animals.push_back(cow);

    for (auto& animal : animals) {      // void visitor
        std::visit([](auto&& arg){ arg.make_sound(); }, animal);
        std::visit([](auto&& arg){ std::cout << arg.name << '\n'; }, animal);
        std::visit([](auto&& arg){ std::cout << std::boolalpha 
                                             << arg.is_fluffy() 
                                             << '\n'; }, animal);
    }

    for (auto& animal : animals) {      // type-matching visitor: 2 overloaded operator()'s
        std::visit(overloaded{          // with helper class "overloaded"
           [](Cow arg) { std::cout << arg.eats_grass() << '\n';},
           [](Dog arg) { std::cout << arg.eats_grass() << '\n';}
        }, animal);
    }
}