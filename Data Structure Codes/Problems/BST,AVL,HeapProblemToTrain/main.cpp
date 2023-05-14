#include <iostream>
#include "BSTree.h"
#include "AVLTree.h"
#include "MaxHeap.h"
#include "MinHeap.h"

void MaxMinHeapMenu(bool isMax){
    if(isMax){
        MaxHeap maxHeap(10);
        maxHeap.loadDataFromFile("StudentsData.txt");
        int choice=0;
        cout<<"You are Using MaxHEap DataStructure to Use the following functions: "<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Choose one of the following options"<<endl;
        cout<<"1. Add student"<<endl;
        cout<<"2. Print all(sorted by gpa)"<<endl;
        cout<<"3. return to main menu"<<endl;
        cout<<"---------------------------------"<<endl;
        while(true){
            cout<<"Enter your choice: ";
            cin>>choice;
            cin.ignore();
            if(choice == 1){
                int id;
                double GPA;
                string name, department;
                cout<<"id: ";
                cout<<"id: ";
                cin>>id;
                cin.ignore();
                while(id < 1 || id > 100){
                    cout<<"please enter id in range 1-100: ";
                    cin>>id;
                    cin.ignore();
                }
                cout<<"name: ";
                getline(cin, name);
                cout<<"GPA: ";
                cin>>GPA;
                cin.ignore();
                cout<<"department: ";
                getline(cin, department);
                maxHeap.insertStudentMX(id,name,GPA,department);
                cout<<"The  student is added"<<endl;
            }else if(choice == 2){
                maxHeap.heapSort();
                maxHeap.printHeap();
                maxHeap.printDepartmentReport();
            }
            else if(choice == 3){
                break;
            }else{
                cout<<"invalid option!"<<endl;
            }
        }

    }else{
        MinHeap minHeap(10);
        minHeap.loadDataFromFile("StudentsData.txt");
        int choice=0;
        cout<<"You are Using MinHeap DataStructure to Use the following functions: "<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Choose one of the following options"<<endl;
        cout<<"1. Add student"<<endl;
        cout<<"2. Print all(sorted by gpa)"<<endl;
        cout<<"3. return to main menu"<<endl;
        cout<<"---------------------------------"<<endl;
        while(true){
            cout<<"Enter your choice: ";
            cin>>choice;
            cin.ignore();
            if(choice == 1){
                int id;
                double GPA;
                string name, department;
                cout<<"id: ";
                cin>>id;
                cin.ignore();
                while(id < 1 || id > 100){
                    cout<<"please enter id in range 1-100: ";
                    cin>>id;
                    cin.ignore();
                }
                cout<<"name: ";
                getline(cin, name);
                cout<<"GPA: ";
                cin>>GPA;
                cin.ignore();
                cout<<"department: ";
                getline(cin, department);
                minHeap.insertStudent(id,name,GPA,department);
                cout<<"The student is added"<<endl;
            }else if(choice == 2){
                minHeap.heapSort();
                minHeap.printHeap();
                minHeap.printDepartmentReport();
            }
            else if(choice == 3){
                break;
            }else{
                cout<<"invalid option!"<<endl;
            }
        }


    }
}

void BstAvlMenu(bool isBST){
    if(isBST){
        BST bst;
        bst.buildFromDataFile("StudentsData.txt");
        int choice = 0;
        cout<<"You are Using Binary Search Tree DataStructure to Use the following functions: "<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Choose one of the following options"<<endl;
        cout<<"1. Add student"<<endl;
        cout<<"2. Remove student"<<endl;
        cout<<"3. Search student"<<endl;
        cout<<"4. Print all(sorted by id)"<<endl;
        cout<<"5. return to main menu"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"---------------------------------"<<endl;

        while(true){
            cout<<"Enter your choice: ";
            cin>>choice;
            cin.ignore();
            if(choice == 1){
                int id;
                double GPA;
                string name, department;
                cout<<"id: ";
                cin>>id;
                cin.ignore();
                cout<<"name: ";
                getline(cin, name);
                cout<<"GPA: ";
                cin>>GPA;
                cin.ignore();
                cout<<"department: ";
                getline(cin, department);
                bst.insert(id,name,GPA,department);
                cout<<"The student is added"<<endl;
            }
            else if(choice == 2){
                int id;
                cout<<"id: ";
                cin>>id;
                if(bst.Search(id))
                    cout<<"Student is Found"<<endl;
                else {
                    cout << "Student is not Found" << endl;
                    break;
                }
                bst.printStudent(id);
                bst.Delete(id);
//                    bst.removeFromFile("StudentsData.txt",id);
                cout<<"Student is Deleted"<<endl;
            }
            else if(choice == 3){
                int id;
                cout<<"id: ";
                cin>>id;
                if(bst.Search(id))
                    cout<<"Student is Found"<<endl;
                else {
                    cout << "Student is not Found" << endl;
                    break;
                }
                bst.printStudent(id);
            }
            else if(choice == 4){
                bst.printAll();
            }
            else if(choice == 5){
                break;
            }else{
                cout<<"invalid option!"<<endl;
            }
        }
    }else{
        AVLTree avl;
        avl.buildFromDataFile("StudentsData.txt");
        int choice = 0;
        cout<<"You are Using AVL Tree DataStructure to Use the following functions: "<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Choose one of the following options"<<endl;
        cout<<"1. Add student"<<endl;
        cout<<"2. Remove student"<<endl;
        cout<<"3. Search student"<<endl;
        cout<<"4. Print all(sorted by id)"<<endl;
        cout<<"5. return to main menu"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"---------------------------------"<<endl;
        while(true){
            cout<<"Enter your choice: ";
            cin>>choice;
            cin.ignore();
            if(choice == 1){
                int id;
                double GPA;
                string name, department;
                cout<<"id: ";
                cin>>id;
                cin.ignore();
                cout<<"name: ";
                getline(cin, name);
                cout<<"GPA: ";
                cin>>GPA;
                cin.ignore();
                cout<<"department: ";
                getline(cin, department);
                avl.insert(id,name,GPA,department);
                cout<<"The student is added"<<endl;
            }
            else if(choice == 2){
                int id;
                cout<<"id: ";
                cin>>id;
                if(avl.Search(id))
                    cout<<"Student is Found"<<endl;
                else {
                    cout << "Student is not Found" << endl;
                    break;
                }
                avl.printStudent(id);
                avl.remove(id);
//                    bst.removeFromFile("StudentsData.txt",id);
                cout<<"Student is Deleted"<<endl;
            }
            else if(choice == 3){
                int id;
                cout<<"id: ";
                cin>>id;
                if(avl.Search(id))
                    cout<<"Student is Found"<<endl;
                else {
                    cout << "Student is not Found" << endl;
                    break;
                }
                avl.printStudent(id);
            }
            else if(choice == 4){
                avl.printAll();
            }
            else if(choice == 5){
                break;
            }else{
                cout<<"invalid option!"<<endl;
            }
        }

    }

}

int main() {
    bool isOk =true;

    while(isOk){
        cout<<"Main menu."<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Choose Data Structure"<<endl;
        cout<<"1. BST"<<endl;
        cout<<"2. AVL"<<endl;
        cout<<"3. Min Heap"<<endl;
        cout<<"4. Max Heap"<<endl;
        cout<<"5. Exit Program"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Enter your choice: ";

        int value = 0;
        cin>>value;
        switch (value) {
            case 1:{
                BstAvlMenu(true);
                break;
            }//case 1
            case 2:{
                BstAvlMenu(false);
                break;
            }//case 2
            case 3:{
                MaxMinHeapMenu(false);
                break;
            }//case 3
            case 4:{
                MaxMinHeapMenu(true);
                break;
            }
            case 5:{
                cout<<"Good bye!"<<endl;
                isOk = false;
                break;
            }//case 5
            default:
                isOk = false;
        }//switch
    }//while
}//main


