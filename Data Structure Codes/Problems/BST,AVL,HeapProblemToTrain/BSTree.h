//
// Created by Ziad Nasser on 2023-05-12.
//

#ifndef BST_AVL_HEAPPROBLEMTOTRAIN_BSTREE_H
#define BST_AVL_HEAPPROBLEMTOTRAIN_BSTREE_H
#include <iostream>
#include <unordered_map>
#include <utility>
#include <set>

using namespace std;

class Node{
public:
    int id;
    string name;
    double GPA;
    string department;
    Node* left;
    Node* right;

    Node(int id, string name,double GPA,string department ){
        this->id = id;
        this->name = std::move(name);
        this->GPA = GPA;
        this->department = std::move(department);
        left = right = nullptr;
    }
};

class BST{
public:
    Node* root;
    unordered_map<string,int> departmentCounts;

    BST(){
        root = nullptr;
        departmentCounts.clear();
    }

    Node* insert(Node*& r,  int id, const string& name, double GPA, const string& department);
    void insert(int id,const string& name, double GPA, const string& department);

    Node* Search(Node* r, int id);
    bool Search(int id);

    Node* findMin(Node* root);
    Node* findMax(Node* root);

    Node* Delete(Node* r, int id);
    void Delete(int id);

    void preOrder(Node* r);
    void printAll();
    void printDepartmentReport();
    void printStudent(int id);

    void buildFromDataFile(const string& filename);
//    void saveTofile(const string& fileName, bool append);
//    void saveToFileHelper(Node* node, ofstream& file);
//    void removeFromFile(string filename, int id);

};


#endif //BST_AVL_HEAPPROBLEMTOTRAIN_BSTREE_H
