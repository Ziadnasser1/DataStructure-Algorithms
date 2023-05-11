#include "AVLTree.h"

int main() {
    AVLTree tree;

    tree.insert(5);
    tree.insert(4);
    tree.insert(7);
    tree.insert(8);

    std::cout << "Inorder traversal of the AVL tree: ";
    tree.printInorder(tree.getRoot());
    std::cout << std::endl;

    tree.remove(7);
//    tree.remove(5);

    std::cout << "Inorder traversal after removing 30: ";
    tree.printInorder(tree.getRoot());
    std::cout << std::endl;

    return 0;
}
