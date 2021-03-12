/*
 * Cody Murrer
 * Lab-4/midterm
 * Cosc-220
 * I didnt turn in this as an original submission because i had troubles with the copy constructor
 * in this submission i spent so much time debugging the copy constructor i ran out of time to do the other items on the TODO list
*/
#include "payroll.h"
#include "payrolllist.h"
#include <fstream>
using namespace std;

int main() {
  string n;
  double h,p;

  PayRollList workPls;

  ifstream inFile;
  inFile.open("Pay.txt");
  if(!inFile){
    cout<<"File didnt open or there is no such file";
    exit(1);
  }
  while(inFile >>n>>h>>p){
    workPls.append(n,h,p);
  }
  inFile.close();

  PayRollList copPls(workPls);
  copPls.length();

  workPls.printPayChecks();
  cout<<"\n";
  cout<<"Copy Of The PayRoll List\n";
  copPls.printPayChecks();
  return 0;
}
