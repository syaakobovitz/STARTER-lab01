// intlist.cpp
// Implements class IntList
// Shay Yaakobovitz, 1/13

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head= nullptr;
    tail= nullptr;
    Node* curr= source.head;
    while(curr){
        push_back(curr->info);
        curr= curr->next;
    }


    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr= head;
    Node* temp;
    while( curr){
        temp= curr->next;
        delete curr;
        curr= temp;
    }
    head= nullptr;
    tail= nullptr;
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    int sum=0; 
    Node* curr= head;
    while(curr){
        sum+= curr->info;
        curr=curr->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
   // return 0;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    if(head==nullptr){
        return false;
    }
    Node* curr= head;
    bool check= false;
    while(curr){
        if(curr->info == value){
            check= true;
        }
        curr= curr->next;
    }
    return check; // REPLACE THIS NON-SOLUTION
    \
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if( head== nullptr){
        return 0; 
    }
    int max= head->info;
    Node* curr= head;
    while(curr){
        if(curr->info> max){
            max= curr->info;
        }
        curr=curr->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
    
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(head==nullptr){
        return 0; 
    }
    int size= count();
    int value = sum();

    return double(value)/size; // REPLACE THIS NON-SOLUTION

    
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode= new Node;
    newNode->info= value;
    newNode->next= head;
    head= newNode;
   
}

// append value at end of list
void IntList::push_back(int value) {
     Node* newNode = new Node;
    newNode->info= value;
    newNode->next= nullptr;
    if(head== nullptr){
        head= newNode;
        tail= newNode;
    }else{
        tail->next= newNode;
        tail=newNode;
    }
    
    
 
}

// return count of values
int IntList::count() const {
    int count=0; 
    Node* curr= head;
    while(curr){
        count++;
        curr=curr->next; 
    }
    return count; 
    return 0;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if( this == & source){
        return *this;
    }
    Node* curr= head;
    Node* temp;
    while( curr){
        temp= curr->next;
        delete curr;
        curr= temp;
    }
    head= nullptr;
    tail= nullptr;

   
    Node* other= source.head;
    while(other){
        push_back(other->info);
        other= other->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head=nullptr;
    tail=nullptr;
    
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

