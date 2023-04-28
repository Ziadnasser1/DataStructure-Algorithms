#include <iostream>
#include "../../../Data Structure Codes/Lists/Single Linked List/SingleLinkedList.h"
#include "../../../Data Structure Codes/Lists/Single Linked List/SingleLinkedList.cpp"


using namespace std;

template <typename elementType>
void SingleLinkedList<elementType>::combineNodesBetweenZeros() {
    Node* current = first;
    elementType sum = 0;
    int index = 0;
    SingleLinkedList<elementType> result;
    while (current->next != nullptr) {
        if (current->next->item != 0) {
            sum += current->next->item;
            current = current->next;
        } else {
            if (sum != 0) {
                result.insertAtTail(sum);
            }
            sum = 0;
            current = current->next;
        }
    }
    //to modify the list with the result list
    first = result.getFirst();
    last = result.last;
    length = result.length;
}




int main() {
    SingleLinkedList<int> list;

    list.insertAtHead(0);
    list.insertAtTail(3);
    list.insertAtTail(1);
    list.insertAtTail(0);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(2);
    list.insertAtTail(0);
    list.insertAtTail(5);
    list.insertAtTail(2);
    list.insertAtTail(0);
    list.print();
    cout<<endl;
    list.combineNodesBetweenZeros();
    list.print();
    cout<<endl;
}
