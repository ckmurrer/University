/*
 * Cody Murrer
 *  Lab-9
 * Cosc-220
 */
#include "payroll.h"
#include "Mystack.h"
#include "Mystack.cpp"

#include<iostream>

int main(int argc, char** argv) {
  std::string n;
  double h,p;

MyStack<PayRoll> the;
MyStack<PayRoll> It;
MyStack<PayRoll> Is;
MyStack<PayRoll> One_am;


the.push(PayRoll("F",2.0,6.3));
std::cout<<"List one\n";
std::cout<<the;

It.push(PayRoll("I",20.0,3.3));
Is.push(PayRoll("Wanna",9.0,8.3));
One_am.push(PayRoll("Sleep",2.0,1.3));

std::cout<<It;
std::cout<<Is;
std::cout<<One_am;



std::cout<<"Copy of the first list\n";
MyStack<PayRoll> cop(the);
std::cout<<cop;


  return 0;
}
