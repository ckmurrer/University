#include "payrolllist.h"
#include "payroll.h"

#include <iostream>

PayRollList::PayRollList(){

}

PayRollList::~PayRollList(){

}

void PayRollList::insert(string n, double h, double r){

  ListNode* nNode = new ListNode;
  PayRoll p(n,h,r);
  nNode->p=p;

  nNode->next = NULL;

  if(head!=NULL){
    head = nNode;
    return;
  }

  ListNode* temp = head;

  while(temp->next){
    temp=temp->next;
  }

  temp->next = nNode;

};

void PayRollList::insert(PayRoll p){
  insert(p.getName(),p.getHours(),p.getPay());
}

void PayRollList::printPayChecks(){
  ListNode* tempTwo = head;
  while(tempTwo!=NULL){
      cout<<"Name: "<<tempTwo->p.getName()<<"\n";
      cout<<"Hours Worked: "<<tempTwo->p.getHours()<<"\n";
      cout<<"Amount Paid: $"<<tempTwo->p.getPay()<<"\n";
      tempTwo= tempTwo->next;
  }
}
