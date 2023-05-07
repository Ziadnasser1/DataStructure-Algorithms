//
// Created by Ziad Nasser on 2023-05-07.
//

#include "AVLTree.h"

int AVLTree::height(AVLTree::Node *node) {
    return  node  ? node->height : 0;
}

int AVLTree::balanceFactor(AVLTree::Node *node) {
    return (height(node -> right) - height(node->left))+1;
}

void AVLTree::fixHeight(AVLTree::Node *node) {
    int heightLeft = height(node -> left);
    int heightRight = height(node -> right);
    node -> height = (heightLeft>heightRight ? heightLeft : heightRight ) + 1;

}

AVLTree::Node *AVLTree::rotateRight(AVLTree::Node *node) {
    Node* tmp = node -> left;
    node -> left = tmp-> right;
    tmp-> right = node;
    fixHeight(node);
    fixHeight(tmp);
    return tmp;
}

AVLTree::Node *AVLTree::rotateLeft(AVLTree::Node *node) {
    Node* tmp = node-> right;
    node -> right = tmp -> left;
    tmp -> left = node;
    fixHeight(node);
    fixHeight(tmp);
    return tmp;
}

AVLTree::Node *AVLTree::balance(AVLTree::Node *node) {
    fixHeight(node);
    if(balanceFactor(node)==2){
        if(balanceFactor(node->right)<0)
            node -> right = rotateRight(node->right);
        return rotateLeft(node);
    }
    if(balanceFactor(node)==-2){
        if(balanceFactor(node->left) >0)
            node -> left = rotateLeft(node -> left);
        return rotateRight(node);
    }
    return node;
}

AVLTree::Node *AVLTree::insert(AVLTree::Node *node, int data) {
    if(!node)
        return new Node(data);
    else if(data < node-> data)
        node->left = insert(node->left, data);
    else
        node -> right = insert(node->right, data);
    return balance(node);
}

AVLTree::Node *AVLTree::findMin(AVLTree::Node *node) {
    return node->left ? findMin(node->left): node;
}

AVLTree::Node *AVLTree::removeMin(AVLTree::Node *node) {
    if(!node->left)
        return node-> right;
    node-> left = removeMin(node->left);
    return balance(node);
}

AVLTree::Node *AVLTree::remove(AVLTree::Node *node, int data) {
    if(!node)
        return nullptr;
    if(data < node -> data)
        node -> left = remove(node->left,data);
    else if( data > node -> data)
        node -> right = remove(node->right, data);
    else{
        Node* left = node->left;
        Node* right = node->right;
        delete node;
        if(!right)
            return left;
        Node* min = findMin(right);
        min->right = removeMin(right);
        min-> left = left;
        return balance(min);
    }
    return balance(node);
}

void AVLTree::insert(int data) {
    root = insert(root,data);
}

void AVLTree::remove(int data) {
    root = remove(root, data);
}

void AVLTree::printInorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
}

void AVLTree::destroyTree(AVLTree::Node *node) {
        if (node == nullptr) {
            return;
        }
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
}


AVLTree::~AVLTree() {
    destroyTree(root);
}
