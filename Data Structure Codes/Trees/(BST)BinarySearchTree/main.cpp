#include "BinarySearchTree.h"

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrder(tree.root);
    cout << endl;

    cout << "Level-order traversal: ";
    tree.levelOrder(tree.root);
    cout << endl;

    int key = 60;
    cout << "Search for key " << key << ": ";
    if (tree.Search(key)) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }
    Node* maxNode = tree.findMax(tree.root);
    Node* minNode = tree.findMin(tree.root);
    cout << "Minimum value: " << minNode -> data << endl;
    cout << "Maximum value: " << maxNode -> data << endl;

    key = 30;
    tree.Delete(tree.root, key);
    cout << "In-order traversal after deleting " << key << ": ";
    tree.inOrder(tree.root);
    cout << endl;


    tree.deleteByCopying(tree.root);

    cout << "Inorder traversal after deletion 50(root) by copying: ";
    tree.inOrder(tree.root);
    cout << endl;
    return 0;
}
