#ifndef PAYROLL_H
#define PAYROLL_H

#include<iostream>
using namespace std;
class PayRoll{
  private:
// data types passed into payroll.cpp
  double pay;
  string name;
  double hours;
  public:
    PayRoll();
    PayRoll(string n, double h, double p);// constructor

// getters
    string getName();
    double getPay();
    double getHours();

// setters
    void setName(string n);
    void setPay(double p);
    void setHours(double h);

// print function
    void printData();
};
#endif
