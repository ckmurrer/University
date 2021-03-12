#include "Employee.h"

#include <iostream>


// Employee non-default constructor
Employee::Employee(std::string empName, double empRate){
  payRate = empRate;
  name = empName;
}

// regular pay for Employee
double Employee::pay(){
  return 0;
}

// prints the name and payrate
void Employee::print(){
  std::cout<<"Name: "<< name<<"\n"<<"Payrate: $"<<payRate<<"\n";
}


// Hourly class constructor
Hourly::Hourly(std::string empName, double empRate):Employee(empName,empRate){
  hoursWorked = 0;
}

// Hourly pay = hours*payRate
double Hourly::pay(){
  double total = hoursWorked*payRate;
  hoursWorked = 0;
  return total;
}

// sets the hours for hourly Employee
double Hourly::addHours(double hours){
  hoursWorked = hours;
}

// prints the name the payrate and the hours worked
void Hourly::print(){
  std::cout<<"Name: "<<name<<"\n"<<"Payrate: $"<<payRate<<" an hour"<<"\n"<<"Hours Worked: "<<hoursWorked<<"\n";
}


Executive::Executive(std::string empName, double empRate):Employee(empName,empRate){
  bonusPay = 0;
}
// sets Executive bonus pay
void Executive::setBonusPay(double x){
  bonusPay = x;
}

//
double Executive::pay(){
  double total = Employee::pay()+bonusPay;
  bonusPay = 0;
  return total;
}

// prints Executive bonus oay after calling Employee print
void Executive::print(){
  Employee::print();
  std::cout<<"Bonus Pay: $"<<bonusPay<<"\n";
}
