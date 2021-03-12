#ifndef PAYROLL_H
#define PAYROLL_H

#include<iostream>
using namespace std;
class PayRoll{
  private:
// data types passed into payroll.cpp
  double pay;
  string name;
  int hours;
  public:
    PayRoll(string n, int h, double p);// constructor

// getters
    string getName();
    double getPay();
    int getHours();

// setters
    void setName(string n);
    void setPay(double p);
    void setHours(int h);

// print function
    void printData();
};
#endif
