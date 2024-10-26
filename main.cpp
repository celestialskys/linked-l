#include <iostream>
#include<string>
#include "List.h"
#include "ListNode.h"

using namespace std;
bool validListType(int);
void inputMenu();
void typeInputMenu(const bool &);

int main()
{
    int type=0;

    do {
        cout << "Select Type of List\n"
            << "1 for singly linked list\n"
            << "2 for doubly linked list\n";
        cin >> type;
    } while(type!=1 && type!= 2);

    bool is_singly = type == 1 ? true : false;
    typeInputMenu(is_singly);

   return 0;
}

void inputMenu(){
    cout << "Where do you want to add your number?\n"
    << " 1 place at beginning\n"
    << " 2 place at end\n"
    << " 3 remove from beginning\n"
    << " 4 remove from end\n"
    << " 5 print current list backwards\n"
    << "9 to quit\n";
}

template<typename NODETYPE>
void makeList(const bool &circular){
    if(circular){
        List<NODETYPE, true> list;
        fillList(list);
    } else {
        List<NODETYPE, false> list;
        fillList(list);
    }
}

template< typename NODETYPE, bool isCircular>
void fillList(List<NODETYPE, isCircular> &list){
    NODETYPE value;
    int placement;
    do{
        inputMenu();
        cin >> placement;
        switch(placement){
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertFront(value);
                list.print();
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                list.print();
                break;
            case 3:
                list.removeFront();
                list.print();
                break;
            case 4:
                list.removeEnd();
                list.print();
                break;
            case 5:
                cout << "Your list forwards is: ";
                list.print();
                cout << endl;
                cout << "You list backwards is: ";
                list.printbackwards();
                cout << endl;

                break;
        }
    } while(placement !=9);
    cout << "Bye :) ";
}

void typeInputMenu(const bool &circular){
    int type;
    while(type!=1 && type!=2 && type!=3){
        cout << "What type of data do you want to add?\n"
            << " 1 for int\n"
            << " 2 for double\n";
        cin >> type;
        cout << endl;
    }
    switch (type)
    {
    case 1:
        makeList<int>(circular);
        break;
    case 2:
        makeList<double>(circular);
        break;
    }
}