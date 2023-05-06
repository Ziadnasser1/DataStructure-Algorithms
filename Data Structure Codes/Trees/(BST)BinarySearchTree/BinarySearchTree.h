//
// Created by Ziad Nasser on 2023-05-06.
//

#ifndef _BST_BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define _BST_BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int item){
        data =item;
        left = right = nullptr;
    }
};

class BST{
public:
    Node* root;
    BST(){root = nullptr;}

    Node* insert(Node* r, int item);
    void insert(int item);

    Node* Search(Node* r, int key);
    bool Search(int key);

    Node* findMin(Node* root);
    Node* findMax(Node* root);

    Node* Delete(Node* r , int key);
    void deleteByCopying(Node* &node);

    //traversing functions
    void preOrder(Node* r);
    void postOrder(Node* r);
    void inOrder(Node* r);
    void levelOrder(Node* r);
};


#endif //_BST_BINARYSEARCHTREE_BINARYSEARCHTREE_H
