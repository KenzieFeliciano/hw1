#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;




    //testing push_back

    // 1) empty
    list.push_back("A");
    cout << "After pushing back A to empty list: back = " << list.back() << ", size = " << list.size() << endl;

    // 2) not empty and space at no space at tail
    for(int i = 0; i < ARRSIZE; i++)
    {
        list.push_back("B");
    }
    list.push_back("C");
    cout << "After pushing back C with no space at tail: back = " << list.back() << ", size = " << list.size() << endl;

    // 3) not empty and there's space at tail
    list.pop_back();
    list.push_back("C");
    cout << "After popping and pushing back C with space at tail: back = " << list.back() << ", size = " << list.size() << endl;

    //checking if new nodes created
    cout << "Number of nodes in the list: " << list.nodeCount() << endl << endl;






    //testing push_front
    list.clear();
    cout << "Reseting for push_front tests. Size = " << list.size() << endl;

    // 1) empty
    list.push_front("A");
    cout << "After pushing front A to empty list: front = " << list.front() << ", size = " << list.size() << endl;

    // 2) not empty and no space at head
    for(int i = 0; i < ARRSIZE; i++)
    {
        list.push_front("B");
    }
    list.push_front("C");
    cout << "After pushing front C with no space at head: front = " << list.front() << ", size = " << list.size() << endl;


    // 3) not empty and space at head
    list.pop_front();
    list.push_front("C");
    cout << "After popping and pushing front C with space at head: front = " << list.front() << ", size = " << list.size() << endl;
    //checking new nodes were created
    cout << "Number of nodes in the list: " << list.nodeCount() << endl << endl;





    //testing pop_front
    list.clear();
    cout << "Reseting for pop_front tests. Size = " << list.size() << endl;

    // 1) empty
    list.pop_front();
    cout << "After pop_front on empty: size = " << list.size() << endl;

    // 2) not empty and only 1 element
    list.push_back("Success");
    list.pop_front();
    cout << "After pop_front on not empty and 1 element: size = " << list.size() << endl;

    // 3) not empty and > 1 element
    list.push_back("Is");
    list.push_back(" Mine");
    list.pop_front();
    cout << "After pop_front with two elements: front = " << list.front() << ", size = " << list.size() << endl << endl;




    //testing pop_back
    list.clear();
    cout << "Reseting for pop_back tests. Size = " << list.size() << endl;

    // 1) empty
    list.pop_back();
    cout << "After pop_back on empty: size = " << list.size() << endl;

    // 2) not empty and only 1 element
    list.push_front("Success");
    list.pop_back();
    cout << "After pop_back on not empty and 1 element: size = " << list.size() << endl;

    // 3) not empty and > 1 element
    list.push_front("Is");
    list.push_front(" Mine");
    list.pop_back();
    cout << "After pop_back with two elements: front = " << list.front() << ", size = " << list.size() << endl << endl;


    // testing front/back on empty list
    list.clear();
    if(list.empty())
    {
        cout << "front on empty: " << list.front() << endl;
        cout << "back on empty: " << list.back() << endl;
    }


    //test get/set
    list.push_back("Success");
    list.push_back("IsMine");
    cout << "get index 1: " << list.get(1) << endl;
    list.set(1, "IsTrulyMine");
    cout << "After set index 1: " << list.get(1) << endl << endl;

    return 0;
    

    

 






    


    

}
