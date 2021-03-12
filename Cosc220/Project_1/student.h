#ifndef STUDENT_H
#define STUDENT_H

#include "course.h"

#include<stdio.h>
#include<iostream>

using namespace std;

class Student{
  struct ListNode{
    Course c;
    ListNode* next;
  };
  ListNode* head;

  private:
    string name;
    string dateOfBirth;
    string major;

  public:
    Student();
    Student(string nam, string dob, string maj);

    void setName(string nam);
    string getName();

    void setDateOfBirth(string dob);
    string getDateOfBirth();

    void setMajor(string maj);
    string getMajor();

    void create(Course);
    void create(string, string, string, char);

    void print();
};
#endif
