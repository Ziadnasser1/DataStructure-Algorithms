//
// Created by Ziad Nasser on 2023-05-06.
//

#include "BinarySearchTree.h"
#include <queue>

Node *BST::insert(Node* r, int item) {
    if(r == nullptr){
        Node* newNode = new Node(item);
        r = newNode;
    }
    else if(item < r->data){
        r-> left = insert(r->left, item);
    }else{
        r -> right = insert(r -> right, item);
    }
    return r;
}

void BST::insert(int item) {
    root = insert(root, item);
}

Node *BST::Search(Node *r, int key) {
    if(r == nullptr){
        return nullptr;
    }
    else if(key == r-> data){
        return r;
    }
    else if(key < r->data){
        return Search(r-> left, key);
    }
    else{
        return Search(r -> right, key);
    }
}

bool BST::Search(int key) {
    Node* result = Search(root, key);
    if(result == nullptr)
        return false;
    else
        return true;
}

Node *BST::findMin(Node *root) {
    if(root == nullptr)
        return nullptr;
    else if(root -> left == nullptr)
        return root;
    else
        return findMin(root -> left);
}

Node *BST::findMax(Node *root) {
    if (root == nullptr)
        return nullptr;
    else if(root -> right == nullptr)
        return root;
    else
        return findMax(root -> right);
}

Node *BST::Delete(Node *r, int key) {
    if(r == nullptr)
        return nullptr;
    else if(key < r -> data)
        r->left = Delete(r-> left, key);
    else if(key > r-> data)
        r-> right = Delete(r -> right, key);
    else{
        if(r -> left == nullptr && r -> right == nullptr){ // Is leaf node
            r= nullptr;
        }
        else if(r -> left != nullptr && r -> right == nullptr){ // Has one left child
            r -> data = r -> left ->data;
            delete r -> left;
            r -> left = nullptr;
        }
        else if(r -> left == nullptr && r -> right != nullptr){ // Has one right child
            r -> data = r -> right -> data;
            delete r -> right;
            r -> right = nullptr;
        }
        else{ // Has two child
            Node* Max = findMax(r -> left);
            r -> data = Max -> data;
            r -> left = Delete(r -> left, Max -> data);
        }
    }
    return r;
}

void BST::deleteByCopying(Node *&node) {
        if (node == nullptr)
            return;

        Node *prev, *tmp = node;

        if (node->right == nullptr)
            node = node->left;
        else if(node->left == nullptr)
            node = node->right;
        else{
            tmp = node->left;
            prev = node;
            while (tmp -> right != nullptr) {
                prev = tmp;
                tmp = tmp->right;
            }
            node->data = tmp->data;
            if (prev == node)
                prev->left = tmp->left;
            else prev->right = tmp->left;
            delete tmp;
        }
        if (node != nullptr && node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
    }


//print root left right
void BST::preOrder(Node *r) {
    if(r == nullptr)
        return;
    cout<<r->data<<" ";
    preOrder(r->left);
    preOrder(r->right);
}

//print left right root
void BST::postOrder(Node *r) {
    if(r == nullptr)
        return;
    postOrder(r->left);
    postOrder(r-> right);
    cout<<r->data<<" ";
}

//print left root right
void BST::inOrder(Node *r) {
    if(r == nullptr)
        return;
    inOrder(r->left);
    cout<<r->data<<" ";
    inOrder(r->right);
}

//(BFT) Breadth First Traversal
void BST::levelOrder(Node *r) {
    if (r == nullptr)
        return;

    queue<Node*> q;
    q.push(r);

    while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);

        q.pop();
    }
}
