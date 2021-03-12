#include "SUList.h"
#include "payroll.h"

#include <iostream>

// default constructor
// @author Cody
template<class DataType>
SUList<DataType>::SUList(){
  head=nullptr;
  tail=nullptr;
}

// deconstructor
// @author Cody
template<class DataType>
SUList<DataType>::~SUList(){
  ListNode* temp = head;

  while(temp){

    temp = temp->next;
    delete head;
    head = temp;
  }
};

//@author Devin
// Copy constructor
template<class DataType>
SUList<DataType>::SUList(const SUList<DataType> &l){

if(l.head == nullptr){
  head = nullptr;
  tail = nullptr;
}

  head = new ListNode;
  head->data = l.head->data;
  head->prev = l.head->prev;

  ListNode* currList = l.head;
  ListNode* currCopy = head;

  currList = currList->next;

  while(currList != nullptr){
    ListNode* prev = currCopy;
    currCopy->next = new ListNode;
    currCopy = currCopy->next;
    currCopy->prev = prev;
    currCopy->data = currList->data;
    currList = currList->next;
  }
}

// @author Devin and Cody
//overloaded = operator for copy constructor
template<class DataType>
SUList<DataType>& SUList<DataType>::operator=(const SUList<DataType> &SUList){
  ListNode* temp = head;

  while(temp != nullptr){
    temp = temp->next;
    delete head;
    head = temp;
  }

  if(this != &SUList){
    if(head == nullptr){
      head = SUList.head;
      head->data = SUList.head->data;
    }

    ListNode* currList = SUList.head;
    ListNode* currCopy = head;


    currList = currList->next;

    while(currList != nullptr){
      ListNode* prev = currCopy;
      currCopy->next = currList;
      currCopy = currCopy->next;
      currCopy->prev = prev;
      currCopy->data = currList->data;
      currList = currList->next;
    }
  }
  return *this;
}

// @author Devin and Cody
// Puts on the front of the List
template<class DataType>
void SUList<DataType>::putFront(const DataType& p){
  ListNode* node = new ListNode;
  node->data=p;
  node->prev = nullptr;
  node->next = nullptr;

  if(head == nullptr){
    head = node;
    head->prev = node;
    tail = node;
    tail->prev = node;
    return;
  }

  node->next = head;
  head->prev = node;
  head = node;
}

//@author Devin and Cody
// Puts on back of linked list
template<class DataType>
void SUList<DataType>::putBack(const DataType& p){
  ListNode* nNode = new ListNode;
  nNode->data=p;
  nNode->prev = nullptr;
  nNode->next = nullptr;

  if(head == nullptr){
    head = nNode;
    head->prev = nNode;
    tail = nNode;
    tail->prev = nNode;
    return;
  }

  tail->next = nNode;
  nNode->prev = tail;
  tail = nNode;
};

//@author Devin and Cody
//removes the back of the list
template<class DataType>
DataType SUList<DataType>::getBack(){
  ListNode* back = tail;

  if(back == nullptr){
      std::cout<<"is empty\n";
      return back->data;
  }

  if(tail->prev != nullptr){
    tail = back->prev;
    tail->next = nullptr;
    delete back;
    return tail->data;
  }

  if(tail->next == nullptr){
    ListNode* temp = tail;
    tail = nullptr;
    return temp->data;
  }
}

//@author Devin and Cody
//removes from the front of the List
template<class DataType>
DataType SUList<DataType>::getFront(){
  ListNode* last = head;

  if(head == nullptr){
      std::cout<<"is empty\n";
      return head->data;
  }

  if(head->next != nullptr){
    head = head->next;
    head->prev = nullptr;
    delete last;
    return head->data;
  }

  if(head->next == nullptr){
    ListNode* temp = head;
    head = nullptr;
    return temp->data;
  }
}

//@author Devin and Cody
//overloaded << operator for prints
template<class DataType>
std::ostream& operator<<(std::ostream &oStream, SUList<DataType> &s){
  return s.display(oStream);
}

//@author Devin and Cody
//display for list
template<class DataType>
std::ostream& SUList<DataType>::display(std::ostream& oStream){
  ListNode* temp = head;
  while(temp != nullptr){
    oStream<<temp->data<<"\n";
    temp = temp->next;
  }
  return oStream;
}

//@author Devin and Cody
// contains function
template<class DataType>
bool SUList<DataType>::contains(const DataType &d){
  ListNode* temp = head;

  while(temp != NULL){
    if(d == temp->data){
      return true;
    }
    temp = temp->next;
  }
  return false;
}

// @author Cody
// gets the size of the list
template<class DataType>
int SUList<DataType>::size()const{
  ListNode* len = head;
  int size = 0;
  while(len != NULL){

    len = len->next;
    size++;
  }
  return size;
}
