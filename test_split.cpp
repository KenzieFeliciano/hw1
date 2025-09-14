/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    //create a linked list (2, 3, 4, 5)
    Node* head = new Node(2, nullptr);
    head->next = new Node(3, nullptr);
    head->next->next = new Node(4, nullptr);
    head->next->next->next = new Node(5, nullptr);

    //print the list
    cout << "Original list: " << endl;
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;

    //split the list. odds and evens start as nullptr
    Node* odds = nullptr;
    Node* evens = nullptr;
    split(head, odds, evens);
    head = nullptr; // so theres no dangling pointer
    cout << "Updated lists: " << endl;

    // first evens list
    cout << "Evens: ";
    curr = evens;
    while(curr != nullptr){
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;

    // now odds list
    cout << "Odds: ";
    curr = odds;
    while (curr != nullptr){
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;

    // clean up the memory
    while(odds != nullptr){
        Node* temp = odds;
        odds = odds-> next;
        delete temp;
    }

    while(evens != nullptr){
        Node* temp = evens;
        evens = evens->next;
        delete temp;
    }
    return 0;
}
