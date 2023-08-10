/* 
    Assignment 9.4.2
    
    Exercise 2.

    Again, create a class with a factory function.  The function should return
    std::expected.  Create a way for the function to fail, and test out and 
    demonstrate both outcomes.
*/

#include <optional>
#include <vector>
#include <iostream>
#include <expected>

enum class Error
{
    faulty_tree,
};

class Tree {
    public:
        static std::expected<Tree, Error> create_Tree(bool yes) {
            Tree tree;
            
            if (yes) {
                return tree;
            }
            return std::unexpected{Error::faulty_tree};
        }
};

int main() {

    std::vector<std::expected<Tree, Error>> forest;
  
    forest.push_back(Tree::create_Tree(true));
    forest.push_back(Tree::create_Tree(false));

    for (auto tree : forest) {
        if (!tree.has_value()) {
            switch (tree.error()) {
                case Error::faulty_tree:
                    std::cout << "This tree is faulty\n";
            }
        } else {
            std::cout << "Tree is fine\n";
        }
    }
}