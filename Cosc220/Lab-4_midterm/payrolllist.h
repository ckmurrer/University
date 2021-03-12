#ifndef PAYROLLLIST_H
#define PAYROLLLIST_H

#include "payroll.h"
#include<stdio.h>
#include<iostream>

class PayRollList{
  private:
    struct ListNode{
      PayRoll p;
      ListNode* next;
    };

    ListNode* head;

  public:
    PayRollList();
    ~PayRollList();
    PayRollList(const PayRollList &list);

    int length();
    PayRoll* operator[](int);

    void remove(int);
    void assign(int, PayRoll);
    void insert(int, PayRoll);

    void append(string n, double h, double p);
    void append(PayRoll);
    void printPayChecks();
};
#endif
