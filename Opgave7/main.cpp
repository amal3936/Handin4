#include <iostream>
#include "Opgave7.cpp"

int main() {
    // Testprogram

    AVLTree tree;
    //Balanceret værdier
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(20);

    // værdier som ikke er balance
    //tree.insert(10);
    //tree.insert(5);
    //tree.insert(15);
    //tree.insert(3);
    //tree.insert(7);
    //tree.insert(12);
    //tree.insert(20);

    // Verificer om højdeoplysningerne i AVL-træet er balanceret
    if (tree.verifyHeight()) {
        std::cout << "Højdeoplysningerne i AVL-træet er balanceret" << std::endl;
    } else {
        std::cout << "Højdeoplysningerne i AVL-træet er ikke balanceret)." << std::endl;
    }

    return 0;
}