//
// Created by Ziad Nasser on 2023-05-14.
//

#include <sstream>
#include <fstream>
#include <limits>
#include "AVLTree.h"


int AVLTree::height(AVLTree::Node *node) {
    return node ? node->height: 0;
}

int AVLTree::balanceFactor(AVLTree::Node *node) {
    return (height(node -> right) - height(node->left));
}

void AVLTree::fixHeight(AVLTree::Node *node) {
    int heightLeft = height(node->left);
    int heightRight = height(node->right);
    node -> height = ((heightLeft > heightRight) ? heightLeft : heightRight) +1;
}

AVLTree::Node *AVLTree::rotateLeft(AVLTree::Node *node) {
    Node* tmp = node->right;
    node -> right = tmp -> left;
    tmp -> left = node;
    fixHeight(node);
    fixHeight(tmp);
    return tmp;
}

AVLTree::Node *AVLTree::rotateRight(AVLTree::Node *node) {
    Node* tmp = node->left;
    node->left = tmp -> right;
    tmp -> right = node;
    fixHeight(node);
    fixHeight(tmp);
    return tmp;
}

AVLTree::Node *AVLTree::balance(AVLTree::Node *node) {
    fixHeight(node);
    if(balanceFactor(node) == 2){
        if(balanceFactor(node -> right) < 0)
            node -> right = rotateRight(node -> right);
        return rotateLeft(node);
    }
    if(balanceFactor(node) == -2){
        if(balanceFactor(node ->left) >0)
            node-> left = rotateLeft(node -> left);
        return rotateRight(node);
    }
    return node;
}

AVLTree::Node* AVLTree::insert(AVLTree::Node* node, int sid, const string& sName, double sGPA, const string& sDepartment) {
    if (node == nullptr) {
        Node* newNode = new Node(sid, sName, sGPA, sDepartment);
        node = newNode;
        departmentCounts[sDepartment]++;
    }
    else if (sid < node->id)
        node->left = insert(node->left, sid, sName, sGPA, sDepartment);
    else if (sid > node->id)
        node->right = insert(node->right, sid, sName, sGPA, sDepartment);
    else {
        return node;
    }
    fixHeight(node);
    return balance(node);
}

void AVLTree::insert(int sid,const string& sName, double sGPA,const string& sDepartment) {
    root = insert(root, sid,sName,sGPA,sDepartment);
}

AVLTree::Node *AVLTree::findMin(AVLTree::Node *node) {
    return node->left ? findMin(node->left):node;
}

AVLTree::Node *AVLTree::removeMin(AVLTree::Node *node) {
    if(!node)
        return node->right;
    node -> left = removeMin(node->left);
    return balance(node);
}

AVLTree::Node *AVLTree::remove(AVLTree::Node *node, int id) {
    if(!node)
        return nullptr;
    if(id<node->id)
        node -> left = remove(node->left, id);
    else if(id > node-> id)
        node-> right = remove(node->right, id);
    else{
        Node* left = node->left;
        Node* right = node->right;
        delete node;
        if(!left)
            return right;
        if(!right)
            return left;
        Node* min = findMin(right);
        min-> right = removeMin(right);
        min->left = left ;
        return balance(min);
    }
    return balance(node);
}

void AVLTree::remove(int id) {
    root = remove(root,id);
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


AVLTree::Node *AVLTree::Search(AVLTree::Node *r, int id) {
    if(r== nullptr)
        return nullptr;
    else if(id == r->id){
        return r;
    }
    else if( id < r->id){
        return Search(r->left,id);
    }
    else{
        return Search(r->right,id);
    }
}

bool AVLTree::Search(int id) {
    Node* result = Search(root, id);
    if(result == nullptr)
        return false;
    else
        return true;

}



void AVLTree::buildFromDataFile(const string& filename) {
   ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename <<endl;
        return;
    }

    int numStudents;
    file >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        int id;
        string name;
        double GPA;
        string department;

        file >> id;
        file.ignore();
        getline(file, name);
        file >> GPA;
        file.ignore();
        getline(file, department);
        root = insert(root, id, name, GPA, department);
    }

    file.close();
}



void AVLTree::preOrder(Node *r) {
    if(r == nullptr)
        return;
    cout << "[" << r->id << ", " << r->name << ", " << r->GPA << ", " << r->department << "]" << std::endl;
    preOrder(r->left);
    preOrder(r->right);
}
void AVLTree::printAll() {
    preOrder(root);
    printDepartmentReport();
    cout << endl;
}
void AVLTree::printDepartmentReport() {
    for (const auto& department : departmentCounts) {
        cout << department.first << " " << department.second << " Students" << endl;
    }
}

void AVLTree::printStudent(int id) {
    Node* student = Search(root,id);
    if (student != nullptr) {
        cout << "Student ID: " << student->id << std::endl;
        cout << "Name: " << student->name << std::endl;
        cout << "GPA: " << student->GPA << std::endl;
        cout << "Department: " << student->department << std::endl;
    }
}

