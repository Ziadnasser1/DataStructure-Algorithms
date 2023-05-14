//
// Created by Ziad Nasser on 2023-05-14.
//

#ifndef BST_AVL_HEAPPROBLEMTOTRAIN_AVLTREE_H
#define BST_AVL_HEAPPROBLEMTOTRAIN_AVLTREE_H

#include <iostream>
#include <unordered_map>

using namespace std;
class AVLTree{
private:
    struct Node{
        int id;
        string name;
        double GPA;
        string department;
        int height;
        Node* left;
        Node* right;
        Node(int sID,const string& sName,double sGPA,const string& sDepartment){
            id = sID;
            name = sName;
            GPA = sGPA;
            department = sDepartment;
            height = 1;
            left = right = nullptr;
        }
    };

    int height(Node* node);
    int balanceFactor(Node* node);
    void fixHeight(Node* node);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* balance(Node* node);
    Node* insert(Node* node,int sid,const string& sName, double sGPA,const string& sDepartment);
    Node* findMin(Node* node);
    Node* removeMin(Node* node);
    Node* remove(Node* node, int id);
    Node* Search(Node* r,int id);

    void destroyTree(Node* node);

public:
    unordered_map<string,int> departmentCounts;
    Node* root;

    AVLTree() {
        root = nullptr;
        departmentCounts.clear();
    }
    ~AVLTree();
    void insert(int sid,const string& sName, double sGPA,const string& sDepartment);
    void remove(int sID);
    bool Search(int id);


    void preOrder(Node* r);
    void printAll();
    void printDepartmentReport();
    void printStudent(int id);

    void buildFromDataFile(const string& filename);

    Node* getRoot(){
        return root;
    }
};


#endif //BST_AVL_HEAPPROBLEMTOTRAIN_AVLTREE_H
