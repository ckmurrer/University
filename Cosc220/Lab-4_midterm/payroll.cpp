#include "payroll.h"
#include "payrolllist.h"
using namespace std;

PayRoll::PayRoll(string n, double h, double p){
  this->setName(n);// passes n to setName
  this->setHours(h);// passes h to setHours
  this->setPay(p*h);// passes the total of rate * hours to set pay
//  printData();//calls print function
}
PayRoll::PayRoll(){}// default constructor

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

double PayRoll::getHours(){// gets the hours
return hours;
}
void PayRoll::setHours(double h){// sets the hours h
  hours = h;
}
