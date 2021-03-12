#ifndef PAYROLL_H
#define PAYROLL_H

#include<iostream>

class PayRoll{
  private:
// data types passed into payroll.cpp
  double pay;
  std::string name;
  double hours;
  public:
    PayRoll();
    PayRoll(std::string n, double h, double p);// constructor

// getters
    std::string getName();
    double getPay();
    double getHours();

// setters
    void setName(std::string n);
    void setPay(double p);
    void setHours(double h);

    friend std::ostream& operator<<(std::ostream &oStream, PayRoll &p);
    std::ostream& display(std::ostream& oStream);
};
#endif
