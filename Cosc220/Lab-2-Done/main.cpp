/*
 * Cody Murrer
 * Lab-2
 * Cosc-220
*/
#include "payroll.h"
using namespace std;

int main() {
  string nameArr[7]={"Kevin", "Pam", "Jim", "Dwight", "Ryan", "Andy", "Toby"};// hard coded array for names
  double payRate[7] = {25.50,75.80,100.10,100.10,50.75,130.25,60.15};// hard coded array for rate
  int hourArr[7];// array to store hours worked
  string n;// passed through as name in the constructor
  int h;// passed through as hours in the constructor
  double p;// passed through as pay rate in constructor

  for (int i = 0; i < 7; i++) {//itterates an fills arrays then passes through constructor
    cout<<"\nHow many hours did "<<nameArr[i]<< " work: ";
    cin>>h;
    hourArr[i]=h;

    n = nameArr[i];
    h = hourArr[i];
    p = payRate[i];
    PayRoll p1(n,h,p);
  }
  return 0;
}
