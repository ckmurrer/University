#include "payroll.h"
using namespace std;

PayRoll::PayRoll(string n, int h, double p){
  this->setName(n);// passes n to setName
  this->setHours(h);// passes h to setHours
  this->setPay(p*h);// passes the total of rate * hours to set pay
  printData();//calls print function
}

string PayRoll::getName(){// gets name
  return name;
}
void PayRoll::setName(string n){// sets the name n
  name = n;
}

double PayRoll::getPay(){// gets pay
  return pay;
}
void PayRoll::setPay(double p){// sets the pay rate p*h
  pay = p;
}

int PayRoll::getHours(){// gets the hours
return hours;
}
void PayRoll::setHours(int h){// sets the hours h
  hours = h;
}

void PayRoll::printData(){// void class that is called within the constructor function to print the getters data
  cout<<"Name: "<<getName()<<"\n";
  cout<<"Hours Worked: "<<getHours()<<"\n";
  cout<<"Amount Paid: $"<<getPay()<<"\n";
  return;
}
