/*
 * Cody Murrer
 * Lab-2
 * Cosc-220
*/
#include "payroll.h"
#include "payrolllist.h"
using namespace std;

int main() {

  PayRollList workPls;

  workPls.insert("check",40.2,12.0);
  //workPls.insert("two",20.2,5.5);
  workPls.printPayChecks();
  return 0;
}
