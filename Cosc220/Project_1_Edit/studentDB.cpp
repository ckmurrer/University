#include "studentDB.h"
#include "student.h"
#include "course.h"

#include <iostream>

StudentDB::StudentDB(){
  head = NULL;
}

StudentDB::~StudentDB(){
  ListNode* temp = head;

  while(temp){
    temp = temp->next;
    delete head;
    head = temp;
  }
};

void StudentDB::create(Student s){
  create(s.getName(), s.getDateOfBirth(), s.getMajor());
}

void StudentDB::create(string nam, string dob, string maj){
  Student s(nam,dob,maj);
  ListNode* testNode = new ListNode;

  testNode->s = s;

  testNode->next = NULL;

  if(head == NULL){
    head = testNode;
    return;
  }
  ListNode* temp = head;

  while(temp->next){
    temp = temp->next;
  }
  temp->next = testNode;
}

void StudentDB::search(string test, string con, string dep, string sem, char gra){
  ListNode* temp = head;
  while(temp){
    if(temp->s.getName().compare(test) == 0){
      temp->s.create(Course(con,dep,sem,gra));
    }
    temp = temp->next;
  }
  return;
}

void StudentDB::remove(){

}

void StudentDB::update(){

}

void StudentDB::print(){
  ListNode* temp = head;
  while(temp){
      cout<<"************************\n";
      cout<<"Name: "<<temp->s.getName()<<"\n";
      cout<<"DOB: "<<temp->s.getDateOfBirth()<<"\n";
      cout<<"Major: "<<temp->s.getMajor()<<"\n";
      temp->s.print();
      cout<<"************************\n";
      temp= temp->next;
  }
}
