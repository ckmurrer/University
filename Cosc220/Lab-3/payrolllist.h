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

    void insert(string n, double h, double p);
    void insert(PayRoll);
    void printPayChecks();
};
#endif
