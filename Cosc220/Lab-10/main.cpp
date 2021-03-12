#include "Employee.h"
#include <iostream>

int main(){

    Employee emp("Joe",30.2);
    Hourly hour("John",20.0);
    Executive exec("BigCheif",900.0);

    std::cout<<"\nExecutive\n";
    exec.setBonusPay(950.0);
    exec.print();
    exec.pay();

    std::cout<<"\nHourly Worker\n";
    hour.addHours(40);
    hour.print();
    hour.pay();

    std::cout<<"\nBase Employee\n";
    emp.print();
    emp.pay();

    std::cout<<"\nEmployee Array\n";

    Employee *empArr[5];

    Hourly test("Boi",15.0);
    Hourly test2("Bill",9.2);
    Hourly test3("Bobby",6.2);
    test.addHours(15);
    test2.addHours(17);
    test3.addHours(20);
    Executive bigBossMan("CEO",600.0);
    Executive smallBossMan("VP",300.0);
    bigBossMan.setBonusPay(200.0);
    smallBossMan.setBonusPay(100.0);

    empArr[0] = &test;
    empArr[1] = &test2;
    empArr[2] = &test3;
    empArr[3] = &bigBossMan;
    empArr[4] = &smallBossMan;

    for(int i = 0; i<5; i++){

      empArr[i]->print();
      empArr[i]->pay();
      std::cout<<"\n";
      //delete[] empArr[count];
    }

}
