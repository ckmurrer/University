#ifndef STUDENTDB_H
#define STUDENTDB_H

#include "student.h"
#include "course.h"

#include<stdio.h>
#include<iostream>

using namespace std;

class StudentDB{
  private:
    struct ListNode{
      Student s;
      ListNode* next;
    };
    ListNode* head;

  public:
    StudentDB();
    ~StudentDB();
    StudentDB(const Student &list);

    void create(string nam, string dob, string maj);
    void create(Student);

    void update();
    void remove();
    void search(string,string,string,string,char);
    
    void print();
};
#endif
