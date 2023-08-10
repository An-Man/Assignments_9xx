/* 
    Assignment 9.4.2
    
    Exercise 1.

    Create a class, and then a factory function (static member function) to
    create a class instance.  The function should return std::optional. 
    Create a way for the function to fail, and return a std::nullopt in case of failure.
    Then demonstrate both cases.
 */

#include <optional>
#include <vector>
#include <iostream>

class Tree {
    public:
        static std::optional<Tree> create_Tree(bool yes) {
            Tree tree;
            
            if (yes) {
                return tree;
            }
            return std::nullopt;
        }
};

int main() {

    std::vector<std::optional<Tree>> forest;
  
    forest.push_back(Tree::create_Tree(true));
    forest.push_back(Tree::create_Tree(false));

    std::cout << forest.size() << '\n';

    for (auto tree : forest) {
        if (!tree.has_value()) {
            std::cout << "Tree is null\n"; 
        } else {
            std::cout << "Tree has a value\n";
        }
    }
}