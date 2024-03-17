#include <iostream>
#include <algorithm>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    TreeNode* root;
    // beregner højden af et undertræ, der har den givne node som rod
    // Hvis den givne node er nullptr (dvs. et tomt træ), returneres -1.
    // Ellers returneres den maksimale højde af venstre og højre undertræer, plus 1 (roden).
    int getHeight(TreeNode* node) {
        if (node == nullptr) return -1;
        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    // Kontrollerer om et undertræ er balanceret.
    // Det sammenligner højden af venstre og højre undertræer og sikrer, at forskellen i højde er højst 1.
    // Hvis undertræet ikke er balanceret, returnerer metoden -2, ellers returneres højden af undertræet.

    int checkBalance(TreeNode* node) {
        if (node == nullptr) return -1;

        int leftHeight = checkBalance(node->left);
        int rightHeight = checkBalance(node->right);

        if (leftHeight == -2 || rightHeight == -2 || abs(leftHeight - rightHeight) > 1)
            return -2; // ikke balanceret

        return std::max(leftHeight, rightHeight) + 1;
    }

public:
    // Konstruktør for AVLTree-klassen.
    // Initialiserer roden til nullptr, da træet starter tomt.
    AVLTree() : root(nullptr) {}

    // Returnerer true, hvis højdeoplysningerne er balanceret
    // Returnerer false, hvis træet ikke er balanceret
    bool verifyHeight() {
        return checkBalance(root) != -2;
    }

    // Metode til at indsætte en ny værdi i træet
    void insert(int value) {
        root = insertRecursive(root, value);
    }

private:
    TreeNode* insertRecursive(TreeNode* node, int value) {
        // Hvis den aktuelle node er nullptr, oprettes en ny node med den givne værdi.
        if (node == nullptr) return new TreeNode(value);

        // Sammenlign den nye værdi med værdien i den aktuelle node
        // Indsæt den nye værdi i det passende undertræ baseret på sammenligningen
        if (value < node->data)
            node->left = insertRecursive(node->left, value); // Indsæt til venstre subtræ
        else if (value > node->data)
            node->right = insertRecursive(node->right, value); // Indsæt til højre subtræ.

        return node; // Returnerer den aktuelle node efter indsættelsen eller uændret, hvis værdien allerede eksisterer
    }
};


