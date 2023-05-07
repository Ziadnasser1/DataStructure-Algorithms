//
// Created by Ziad Nasser on 2023-05-07.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H
#include <iostream>
class AVLTree{
private:
    struct Node{
        int data;
        int height;
        Node* left;
        Node* right;
        Node(int value){
            data = value;
            height = 1;
            left = right = nullptr;
        }
    };
    Node* root;

    int height(Node* node);
    int balanceFactor(Node* node);
    void fixHeight(Node* node);
    Node* rotateRight(Node*node);
    Node* rotateLeft(Node*node);
    Node* balance(Node* node);
    Node* insert(Node* node, int data);
    Node* findMin(Node* node);
    Node* removeMin(Node* node);
    Node* remove(Node* node, int data);
    void destroyTree(Node* node);
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree();
    void insert(int data);
    void remove(int data);
    void printInorder(Node* node);
        Node* getRoot(){
        return root;
    }

};

#endif //AVLTREE_AVLTREE_H
