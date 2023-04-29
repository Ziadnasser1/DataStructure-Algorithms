#include <iostream>
#include "../../../Data Structure Codes/Lists/Single Linked List/SingleLinkedList.h"
#include "../../../Data Structure Codes/Lists/Single Linked List/SingleLinkedList.cpp"

template <typename elementType>
SingleLinkedList<elementType> mergeKLists(vector<SingleLinkedList<elementType>> lists) {

    SingleLinkedList<elementType> combinedList;
    for (int i = 0; i < lists.size(); i++) {
        auto current = lists[i].getFirst();
        while (current != nullptr) {
            combinedList.insertAtTail(current->item);
            current = current->next;
        }
    }

    int n = combinedList.SinglelinkedListSize();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (combinedList.retrieveAt(j) > combinedList.retrieveAt(j+1)) {
                elementType temp = combinedList.retrieveAt(j);
                combinedList.replaceAt(combinedList.retrieveAt(j+1), j);
                combinedList.replaceAt(temp, j+1);
            }
        }
    }

    return combinedList;
}

int main() {
// create three linked lists
    SingleLinkedList<int> list1;
    list1.insertAtTail(1);
    list1.insertAtTail(3);
    list1.insertAtTail(5);
    list1.insertAtTail(7);

    SingleLinkedList<int> list2;
    list2.insertAtTail(2);
    list2.insertAtTail(4);
    list2.insertAtTail(6);
    list2.insertAtTail(8);

    SingleLinkedList<int> list3;
    list3.insertAtTail(0);
    list3.insertAtTail(9);
    list3.insertAtTail(10);

    // create a vector of linked lists
    vector<SingleLinkedList<int>> lists = { list1, list2, list3 };

    // merge the linked lists and print the result
    SingleLinkedList<int> result = mergeKLists(lists);
    result.print();

}
