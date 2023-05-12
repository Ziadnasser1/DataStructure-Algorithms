//
// Created by Ziad Nasser on 2023-05-12.
//

#include <fstream>
#include "BSTree.h"

Node* BST::insert(Node*&  r, int id, const string& name, double GPA, const string& department) {
    if (r == nullptr) {
        Node* newNode = new Node(id, name, GPA, department);
        r = newNode;
        departmentCounts[department]++;
    } else if (id < r->id) {
        r->left = insert(r->left, id, name, GPA, department);
    } else if (id > r->id) {
        r->right = insert(r->right, id, name, GPA, department);
    }
    return r;
}


void BST::insert(int id, const string& name, double GPA, const string& department) {
    root = insert(root,id, name, GPA, department);
//    saveTofile("StudentsData.txt",true);
}

Node *BST::Search(Node *r, int id) {
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

bool BST::Search(int id) {
    Node* result = Search(root, id);
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
        findMin(root -> left);
}

Node *BST::findMax(Node *root) {
    if(root == nullptr)
        return nullptr;
    else if(root -> right == nullptr)
        return root;
    else
        findMax(root -> right);
}

Node* BST::Delete(Node* r, int id) {
    if (r == nullptr)
        return nullptr;
    else if (id < r->id)
        r->left = Delete(r->left, id);
    else if (id > r->id)
        r->right = Delete(r->right, id);
    else {
        if (r->left == nullptr && r->right == nullptr) { // Is leaf node
            departmentCounts[r->department]--; // Decrement the department count
            delete r;
            r = nullptr;
        } else if (r->left != nullptr && r->right == nullptr) { // Has one left child
            departmentCounts[r->department]--; // Decrement the department count
            Node* temp = r;
            r = r->left;
            delete temp;
        } else if (r->left == nullptr && r->right != nullptr) { // Has one right child
            departmentCounts[r->department]--; // Decrement the department count
            Node* temp = r;
            r = r->right;
            delete temp;
        } else { // Has two children
            Node* successor = findMin(r->right);
            r->id = successor->id;
            r->name = successor->name;
            r->GPA = successor->GPA;
            r->department = successor->department;
            r->right = Delete(r->right, successor->id);
        }
    }

    return r;
}


void BST::Delete(int id) {
    root = Delete(root, id);
//    saveTofile("StudentsData.txt",true);
}


void BST::preOrder(Node *r) {
    if(r == nullptr)
        return;
    cout << "[" << r->id << ", " << r->name << ", " << r->GPA << ", " << r->department << "]" << std::endl;
    preOrder(r->left);
    preOrder(r->right);
}
void BST::printAll() {
    preOrder(root);
    printDepartmentReport();
    cout << endl;
}
void BST::printDepartmentReport() {
    for (const auto& department : departmentCounts) {
        cout << department.first << " " << department.second << " Students" << endl;
    }
}

void BST::buildFromDataFile(const string& filename) {
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
        insert(root, id, name, GPA, department);
    }

    file.close();
}

void BST::printStudent(int id) {
    Node* student = Search(root, id);
    if (student != nullptr) {
        cout << "Student ID: " << student->id << std::endl;
        cout << "Name: " << student->name << std::endl;
        cout << "GPA: " << student->GPA << std::endl;
        cout << "Department: " << student->department << std::endl;
    }
}

//void BST::removeFromFile(string filename, int id) {
//    Node* nodeToRemove = Search(root, id);
//    root = Delete(root, id);
//    departmentCounts[nodeToRemove->department]--;
//    saveTofile(filename, true);
//}
//
//void BST::saveTofile(const string& filename, bool append) {
//    ofstream file;
//    if (append) {
//        file.open(filename, ios::app);
//    } else {
//        file.open(filename);
//    }
//
//    if (!file) {
//        cerr << "Error opening file: " << filename << endl;
//        return;
//    }
//    saveToFileHelper(root, file);
//
//    file.close();
//}
//
//void BST::saveToFileHelper(Node* node, ofstream& file) {
//    if (node == nullptr) {
//        return;
//    }
//
//    file << node->id << "\n";
//    file << node->name << "\n";
//    file << node->GPA << "\n";
//    file << node->department << "\n";
//
//    saveToFileHelper(node->left, file);
//    saveToFileHelper(node->right, file);
//}
//
