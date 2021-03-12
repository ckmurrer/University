#include "payroll.h"
#include "Mystack.h"

#include<iostream>
#include<stdio.h>
#include<string>


//Default constructor
template<class T>
MyStack<T>::MyStack(){
  head = nullptr;
}

//Destructor
template<class T>
MyStack<T>::~MyStack(){
  Node* temp = head;
    while (temp) {
      temp = temp->next;
      delete head;
      head = temp;
    }
}

//Copy constructor
template<class T>
MyStack<T>::MyStack(const MyStack &stack){

    head = new Node;
    head->data = stack.head->data;

  Node* currStack = stack.head;
  Node* currCopy = head;

  currStack = currStack->next;

  while(currStack != nullptr){
    currCopy->next = new Node;
    currCopy = currCopy->next;
    currCopy->data = currStack->data;
    currStack = currStack->next;
  }
}

//Overloaded operator
template<class T>
MyStack<T> MyStack<T>::operator=(const MyStack &stack){
  Node* temp = head;
    while (temp) {
      temp = temp->next;
      delete head;
      head = temp;
    }

if(this != &stack){
  if(head == nullptr){
      head = new Node;
      head->data = stack.head->data;
  }

    Node* currStack = stack.head;
    Node* currCopy = head;

    currStack = currStack->next;

    while(currStack != nullptr){
      currCopy->next = new Node;
      currCopy = currCopy->next;
      currCopy->data = currStack->data;
      currStack = currStack->next;
    }
 }
    return *this;
}

template<class T>
T MyStack<T>::peek(){
  T data;
  Node* temp = head;
  return data;
}

//Inserts nodes into linkedlist
template<class T>
void MyStack<T>::push(T p){
  Node* nNode = new Node;
  nNode->data = p;
  nNode->next = nullptr;

   //Makes sure theres a head if not it makes one
  if(head == nullptr){
    nNode->next = head;
    head = nNode;
    return;
  }

  Node* curr = head;
  //loops through list and makes a nNode after head
  while(curr->next != nullptr){
      curr = curr->next;
  }
    nNode->next = curr->next;
    curr->next = nNode;
}

//Removes the last node inserted into the list
template<class T>
T MyStack<T>::pop(){
  Node* curr = head;
  Node* prev = head;
  T p;

  if(curr ==  nullptr){
    std::cout << "Empty";
    return p;
  }

  while(curr->next != nullptr){
    prev = curr;
    curr = curr->next;

  }
  p = curr->data;
  delete curr;
  prev->next = nullptr;
  return p;
}

template<class T>
void MyStack<T>::pop(T &p){
  p = pop();
}

template<class T>
std::ostream& operator<<(std::ostream &oStream,MyStack<T> &stack){
  return stack.print(oStream);
}

//Prints list
template<class T>
std::ostream& MyStack<T>::print(std::ostream& oStream){
  Node* temp = head;
  while(temp){
      oStream<<"************************\n";
      oStream<<"Name: "<<temp->data.getName()<<"\n";
      oStream<<"Hours Worked: "<<temp->data.getHours()<<"\n";
      oStream<<"Amount Paid: $"<<temp->data.getPay()<<"\n";
      oStream<<"************************\n";
      temp= temp->next;
  }
  return oStream;
}
