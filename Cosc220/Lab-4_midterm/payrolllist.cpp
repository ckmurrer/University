#include "payrolllist.h"
#include "payroll.h"

#include <iostream>
using namespace std;

// default constructor
PayRollList::PayRollList(){
  head=NULL;
}

// deconstructor
PayRollList::~PayRollList(){
  ListNode* temp = head;

  while(temp){
    temp = temp->next;
    delete head;
    head = temp;
  }
};

void PayRollList::append(PayRoll p){
  append(p.getName(),p.getHours(),p.getPay());
}

// Copy constructor
// one issue it coppies jimmy twice every time i try to fix it
// i get a seg fault
PayRollList::PayRollList(const PayRollList &list){
  ListNode* cNode = new ListNode;

  head = cNode;

  head->p = list.head->p;

  ListNode* begList = list.head;

  ListNode* copList = head;

  while(begList != NULL){
    copList-> next = new ListNode;
    copList = copList-> next;
    copList-> p = begList-> p;
    begList = begList-> next;
  }
}

// creates linked list
void PayRollList::append(string n, double h, double r){
  ListNode* nNode = new ListNode;
  PayRoll p(n,h,r);
  nNode->p=p;

  nNode->next = NULL;

  if(head == NULL){
    head = nNode;
    return;
  }

  ListNode* temp = head;

  while(temp->next){
    temp=temp->next;
  }

  temp->next = nNode;
};

// gets the size of the list currently getting the copy lists size
// called in main
int PayRollList::length(){
  ListNode* len = head;
  int size = 0;
  while(len != NULL){

    len = len->next;
    size++;
  }
  return size;
}

// Idk what to do
PayRoll* PayRollList::operator[](int){

}

// TODO
void PayRollList::remove(int ){


}

// TODO
void PayRollList::assign(int , PayRoll){

}

void PayRollList::insert(int , PayRoll){

}

void PayRollList::printPayChecks(){
  ListNode* temp = head;
  while(temp){
      cout<<"************************\n";
      cout<<"Name: "<<temp->p.getName()<<"\n";
      cout<<"Hours Worked: "<<temp->p.getHours()<<"\n";
      cout<<"Amount Paid: $"<<temp->p.getPay()<<"\n";
      cout<<"************************\n";
      temp= temp->next;
  }
}
