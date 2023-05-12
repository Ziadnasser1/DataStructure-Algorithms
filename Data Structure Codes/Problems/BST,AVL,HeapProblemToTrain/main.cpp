#include <iostream>
#include "BSTree.h"


int BstAvlMenu(){
    int choice = 0;
    cout<<"---------------------------------"<<endl;
    cout<<"Choose one of the following options"<<endl;
    cout<<"1. Add student"<<endl;
    cout<<"2. Remove student"<<endl;
    cout<<"3. Search student"<<endl;
    cout<<"4. Print all(sorted by id)"<<endl;
    cout<<"5. return to main menu"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}

int main() {

    BST bst;
    bst.buildFromDataFile("StudentsData.txt");
    bool isOk =true;

    while(isOk){
        int value = 0;
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
        cin>>value;

        switch (value) {
            case 1:{
                while(true){
                    int option = BstAvlMenu();
                    if(option == 1){
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
                    else if(option == 2){
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
                    else if(option == 3){
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
                    else if(option == 4){
                        bst.printAll();
                    }
                    else if(option == 5){
                        break;
                    }else{
                        cout<<"invalid option!"<<endl;
                    }
                }
                break;
            }//case 1
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


