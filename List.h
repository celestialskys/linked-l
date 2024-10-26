#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
using namespace std;

template< typename NODETYPE, bool isCircular>
class List
{
    public:
        List();
        ~List();
        void insertFront( const NODETYPE &);
        void insertEnd(const NODETYPE &);
        bool removeFront();
        bool removeEnd();
        bool isEmpty() const;
        void print() const;
        void printbackwards() const;
    private:
        ListNode< NODETYPE > *firstPtr;
        ListNode< NODETYPE > *lastPtr;
        bool circularFlag;
        ListNode< NODETYPE > *newNode( const NODETYPE &);
};

template< typename NODETYPE, bool isCircular>
List<NODETYPE, isCircular>::List()
   : firstPtr(0), lastPtr(0), circularFlag(isCircular)
{
}

template< typename NODETYPE, bool isCircular>
List<NODETYPE, isCircular>::~List()
{
    if (!isEmpty()){
        ListNode<NODETYPE> *currentPtr = firstPtr;
        ListNode<NODETYPE> *tempPtr;

        while(!isEmpty())
        {
            removeEnd();
        }
    }
}

template< typename NODETYPE, bool isCircular>
void List<NODETYPE, isCircular>::insertFront(const NODETYPE &value){
    ListNode< NODETYPE > *newPtr = newNode(value);

    if (isEmpty()){
        firstPtr = lastPtr = newPtr;
        if(circularFlag){
            newPtr->nextPtr = newPtr;
            newPtr->prevPtr = newPtr;
        }
    } else{
        if(circularFlag){
            newPtr->prevPtr = lastPtr;
            lastPtr->nextPtr = newPtr;
        }
        newPtr->nextPtr = firstPtr;
        firstPtr->prevPtr = newPtr;
        firstPtr = newPtr;
    }
}

template< typename NODETYPE, bool isCircular>
void List<NODETYPE, isCircular>::insertEnd(const NODETYPE &value){
    ListNode< NODETYPE > *newPtr = newNode(value);

    if(isEmpty()){
        firstPtr = lastPtr = newPtr;
        if(circularFlag){
            newPtr->nextPtr = newPtr;
            newPtr->prevPtr = newPtr;
        }
    }else{
        if(circularFlag){
            newPtr->nextPtr = firstPtr;
        }
        lastPtr -> nextPtr = newPtr;
        newPtr->prevPtr = lastPtr;
        lastPtr = newPtr;
    }
}


template< typename NODETYPE, bool isCircular>
bool List<NODETYPE, isCircular>::removeFront(){
    if(isEmpty()){
        return false;
    } else {
        ListNode<NODETYPE> *tempPtr = firstPtr;
        if (firstPtr == lastPtr){
            firstPtr = lastPtr = 0;
        } else{
            if(circularFlag){
                ListNode<NODETYPE> *secondPtr = firstPtr->nextPtr;
                secondPtr->prevPtr=lastPtr;
                lastPtr->nextPtr = secondPtr;

            } else {
                firstPtr->nextPtr->prevPtr=0;
            }
            firstPtr = firstPtr->nextPtr;
        }
        delete tempPtr;
        return true;
    }
}
template< typename NODETYPE, bool isCircular>
bool List<NODETYPE, isCircular>::removeEnd(){
    

    ListNode<NODETYPE> *tempPtr = lastPtr;
    if (isEmpty()){
        return false;
    }else{
        if(firstPtr == lastPtr){
            firstPtr = lastPtr = 0;
        }else{
            ListNode<NODETYPE> *secondLastPtr = lastPtr;
             if(circularFlag){
                secondLastPtr = secondLastPtr->prevPtr;
                secondLastPtr->nextPtr = firstPtr;
             } else{
                secondLastPtr = firstPtr;
                while( secondLastPtr->nextPtr !=lastPtr){
                    secondLastPtr = secondLastPtr->nextPtr;
                }
                secondLastPtr->nextPtr = 0;
             }
            lastPtr = secondLastPtr;
        }
        delete tempPtr;
        return true;
    }
}


template< typename NODETYPE, bool isCircular>
bool List<NODETYPE, isCircular>::isEmpty() const{
    return firstPtr == 0;
}

template< typename NODETYPE, bool isCircular>
ListNode<NODETYPE> *List<NODETYPE, isCircular>::newNode(const NODETYPE &value){
    return new ListNode<NODETYPE>(value);
}

template< typename NODETYPE, bool isCircular>
void List<NODETYPE, isCircular>::print() const {
    if(!isEmpty()){
        ListNode<NODETYPE> *currPtr = firstPtr;
        do {
            cout << currPtr->data << " ";
            currPtr = currPtr->nextPtr;
        } while((currPtr != 0) && (currPtr != firstPtr));
    } else{
        cout <<"Empty\n\n";
    }
    cout << endl;
    return;
}

template< typename NODETYPE, bool isCircular>
void List<NODETYPE, isCircular>::printbackwards() const {
    if(!isEmpty()){
        ListNode<NODETYPE> *currPtr = lastPtr;
        do {
            cout << currPtr->data << " ";
            currPtr = currPtr->prevPtr;
        } while((currPtr != 0) && (currPtr!= lastPtr));
    } else {
        cout << "Empty \n\n";
    }
    cout << endl;
}
#endif