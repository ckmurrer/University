#include "SUStack.h"
#include "SUQueue.h"
#include "SUList.h"
#include "payroll.h"

#include "SUList.cpp"
#include "SUQueue.cpp"
#include "SUStack.cpp"

#include<iostream>

int main(){
  int tempBoi;
  PayRoll tempPayRollBoi;
  std::cout<<"\nSUList Int and Payroll Objects\n*********************************\n";
  SUList<int> suIntList;
  SUList<PayRoll> suPayRollList;

  std::cout<<"\nSU int list\n";
  suIntList.putFront(5);
  suIntList.putFront(9);
  suIntList.putFront(10);
  suIntList.putBack(10);
  suIntList.putBack(9);
  suIntList.putBack(5);
  suIntList.getBack();
  suIntList.getFront();
  std::cout<<suIntList;

  std::cout<<"\nSU payroll list\n";
  suPayRollList.putFront(PayRoll("John",20.2,5.0));
  suPayRollList.putFront(PayRoll("Joe",29.2,7.0));
  suPayRollList.putFront(PayRoll("Henry",15.2,1.0));
  suPayRollList.putBack(PayRoll("Jim",6.2,4.0));
  suPayRollList.putBack(PayRoll("Pam",5.2,9.0));
  suPayRollList.putBack(PayRoll("Dwight",12.2,3.0));
  suPayRollList.getBack();
  suPayRollList.getFront();
  std::cout<<suPayRollList;

  std::cout<<"\nSU int list copy\n";
  SUList<int> suListCopy(suIntList);
  std::cout<<suListCopy;

  std::cout<<"\nSUStack Int and Payroll Objects\n*********************************\n";

  SUStackList<int> suIntStackList;
  SUStackArr<int> suIntStackArr;
  SUStackList<PayRoll> suPayRollStackList;

  std::cout<<"\nSU int stack list\n";
  suIntStackList.push(9);
  suIntStackList.push(8);
  suIntStackList.push(1);
  suIntStackList.push(4);
  suIntStackList.push(9);
  suIntStackList.push(51);
  suIntStackList.pop(tempBoi);
  suIntStackList.pop(tempBoi);
  suIntStackList.printStack();

  std::cout<<"\nSU payroll stack list\n";
  suPayRollStackList.push(PayRoll("Angela",20.2,5.0));
  suPayRollStackList.push(PayRoll("Ryan",29.2,7.0));
  suPayRollStackList.push(PayRoll("Creed",15.2,1.0));
  suPayRollStackList.push(PayRoll("Jim",6.2,4.0));
  suPayRollStackList.push(PayRoll("Pam",5.2,9.0));
  suPayRollStackList.push(PayRoll("Dwight",12.2,3.0));
  suPayRollStackList.pop(tempPayRollBoi);
  suPayRollStackList.pop(tempPayRollBoi);
  suPayRollStackList.printStack();

  std::cout<<"\nSU int stack array\n";
  suIntStackArr.push(9);
  suIntStackArr.push(8);
  suIntStackArr.push(1);
  suIntStackArr.push(4);
  suIntStackArr.push(9);
  suIntStackArr.push(51);
  suIntStackArr.pop(tempBoi);
  suIntStackArr.pop(tempBoi);
  suIntStackArr.printStack();


  std::cout<<"\nSU int stack list copy\n";
  SUStackList<int> suStackListCopy(suIntStackList);
  suStackListCopy.pop(tempBoi);
  suStackListCopy.printStack();


  std::cout<<"\nSUQueue Int and Payroll Objects\n*********************************\n";

  SUQueueList<int> suIntQueueList;
  SUQueueArr<int> suIntQueueArr;
  SUQueueList<PayRoll> suPayRollQueueList;

  std::cout<<"\nSU int queue list\n";
  suIntQueueList.enqueue(9);
  suIntQueueList.enqueue(8);
  suIntQueueList.enqueue(1);
  suIntQueueList.enqueue(4);
  suIntQueueList.enqueue(9);
  suIntQueueList.enqueue(51);
  suIntQueueList.dequeue(tempBoi);
  suIntQueueList.dequeue(tempBoi);
  suIntQueueList.printQueue();

  std::cout<<"\nSU payroll queue list\n";
  suPayRollQueueList.enqueue(PayRoll("Angela",20.2,5.0));
  suPayRollQueueList.enqueue(PayRoll("Ryan",29.2,7.0));
  suPayRollQueueList.enqueue(PayRoll("Creed",15.2,1.0));
  suPayRollQueueList.enqueue(PayRoll("Jim",6.2,4.0));
  suPayRollQueueList.enqueue(PayRoll("Pam",5.2,9.0));
  suPayRollQueueList.enqueue(PayRoll("Dwight",12.2,3.0));
  suPayRollQueueList.dequeue(tempPayRollBoi);
  suPayRollQueueList.dequeue(tempPayRollBoi);
  suPayRollQueueList.printQueue();

  std::cout<<"\nSU int queue array\n";
  suIntQueueArr.enqueue(9);
  suIntQueueArr.enqueue(8);
  suIntQueueArr.enqueue(1);
  suIntQueueArr.enqueue(4);
  suIntQueueArr.enqueue(9);
  suIntQueueArr.enqueue(51);
  suIntQueueArr.dequeue(tempBoi);
  suIntQueueArr.dequeue(tempBoi);
  suIntQueueArr.printQueue();

  std::cout<<"\nSU int queue list copy\n";
  SUQueueList<int> suQueueListCopy;
  suQueueListCopy = suIntQueueList;
  suQueueListCopy.printQueue();
}
