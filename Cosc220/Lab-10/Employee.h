#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee{
  protected:
    double payRate;
    std::string name;

  public:
    Employee(std::string empName, double empRate);

  virtual  double pay();
  virtual  void print();
};

class Hourly:public Employee{
  public:
    double hoursWorked;

    Hourly(std::string empName, double empRate);

    double addHours(double hours);
    double pay() override;
    void print() override;
};

class Executive: public Employee{
  private:
    double bonusPay;
  public:
    Executive(std::string empName, double empRate);
    void setBonusPay(double bp);
    double pay() override;
    void print() override;
};

#endif
