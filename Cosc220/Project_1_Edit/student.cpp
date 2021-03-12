/*
  student.cpp
*/

#include "student.h"
#include "course.h"

Student::Student(){ // default constructor

}

Student::Student(string nam, string dob, string maj){ // constructor
  head = NULL;
  this->setName(nam);
  this->setDateOfBirth(dob);
  this->setMajor(maj);
}

void Student::create(Course c){
  create(c.getCourseName(),c.getDepartment(), c.getSemester(), c.getGrade());
}

void Student::create(string con, string dep, string sem, char gra){
  ListNode* newNode = new ListNode;
  Course c(con,dep,sem,gra);
  newNode->c = c;

  newNode->next = NULL;

  if(head == NULL){
    newNode->next = head;
    head = newNode;
    return;
  }
  ListNode* temp = head;

  while(temp->next){
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void Student::setName(string nam){ // sets students name
  name = nam;
}

string Student::getName(){ // gets students name
  return name;
}

void Student::setDateOfBirth(string dob){ // sets students date of birth
  dateOfBirth = dob;
}

string Student::getDateOfBirth(){ // gets students date of birth
  return dateOfBirth;
}

void Student::setMajor(string maj){ // sets students major
  major = maj;
}

string Student::getMajor(){ // gets students major
  return major;
}

void Student::print(){
  ListNode* temp = head;
  while(temp != NULL){
      cout<<"\nCourse Name: "<<temp->c.getCourseName()<<"\n";
      cout<<"Department: "<<temp->c.getDepartment()<<"\n";
      cout<<"Semester: "<<temp->c.getSemester()<<"\n";
      cout<<"Grade: "<<temp->c.getGrade()<<"\n";
      cout<<"************************\n";
      temp= temp->next;
  }
}
