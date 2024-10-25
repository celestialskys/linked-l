#include <iostream>
#include<string>
#include "List.h"
#include "ListNode.h"

using namespace std;

int main()
{
//     List<int, false> intList;
//     intList.insertFront(4);
//     intList.insertEnd(40);
//     intList.insertFront(12);
//     intList.removeFront();
//     intList.insertEnd(33);
//     intList.removeEnd();
//     cout << "print:  ";
//     intList.print();
//     cout << "Backwards" << "\n";
//     intList.printbackwards();

    List<int, true> circularIntList;
    circularIntList.insertFront(33);
    circularIntList.insertEnd(12);
    circularIntList.insertEnd(1);
    // circularIntList.removeEnd();
    circularIntList.print();

    circularIntList.insertFront(3);
    circularIntList.print();

    circularIntList.insertFront(99);
    circularIntList.print();

    circularIntList.removeFront();
    circularIntList.print();
    cout << "Backwards \n";
    circularIntList.printbackwards();
    return 0;
}

