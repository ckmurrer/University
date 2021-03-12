#include "SUQueue.h"
#include "payroll.h"

#include <iostream>

//@author Devin
//Default constructor
template<class DataType>
SUQueueList<DataType>::SUQueueList(){
  SUList<DataType> list;
}

//@author Devin and Cody
//Destructor
template<class DataType>
SUQueueList<DataType>::~SUQueueList(){

}

//@author Devin and Cody
//Overloaded operator
template<class DataType>
SUQueueList<DataType>& SUQueueList<DataType>::operator=(const SUQueueList<DataType> &q){
  list = q.list;
  return *this;
}

template<class DataType>
bool SUQueueList<DataType>::isEmpty()const{
  int t = list.size();
  if(t == 0){
    return 1;
  }
  return 0;
}

//@author Devin
//Copy Constructor
template<class DataType>
SUQueueList<DataType>::SUQueueList(const SUQueueList<DataType> &ql){
  list = ql.list;
}

//@author Cody & Devin
template<class DataType>
void SUQueueList<DataType>::enqueue(const DataType& t){
  list.putBack(t);
}

//@author Devin
//Puts element in the front of listCopy
template<class DataType>
void SUQueueList<DataType>::dequeue(DataType& t){
  t = list.getFront();
}

//@author Cody
//Prints list
template<class DataType>
void SUQueueList<DataType>::printQueue(){
 std::cout<<list;
}

//@author Devin
template<class DataType>
int SUQueueList<DataType>::size() const
{
  list.size();
}


//@author Cody & Devin
//default constructor for SUQueueArr
template<class DataType>
SUQueueArr<DataType>::SUQueueArr(){
  capacity = 10;
  front = 0;
  rear = 0;
  arr = new DataType[capacity];
}

//@author Cody & Devin
//queue array copy constructor
template<class DataType>
SUQueueArr<DataType>::SUQueueArr(const SUQueueArr<DataType> &sa){
  capacity = sa.capacity;
  rear = sa.rear;
  front = sa.front;
  arr = new DataType[capacity];
  for(int i = 0; i < capacity; i++){
    arr[i] = sa.arr[i];
  }
}

//@author Cody & Devin
// destructor for SUQueueArr
template<class DataType>
SUQueueArr<DataType>::~SUQueueArr(){
  delete [] arr;
}

//@author Cody & Devin
// uses capacity to check the size of the SUQueueArr
template<class DataType>
int SUQueueArr<DataType>::size()const{
  int size = 0;
  for(int i = front; i < rear; i++){
    size++;
  }
  return size;
}

//@author Cody & Devin
// uses top to see if the SUQueueArr is empty
template<class DataType>
bool SUQueueArr<DataType>::isEmpty()const{
  if(front == -1){
    return true;
  }
  return false;
}

//@author Cody & Devin
// pushes DataType elements onto the SUQueueArr using FILO order
template<class DataType>
void SUQueueArr<DataType>::enqueue(const DataType& p){
  if(capacity == rear){
    capacity++;
  }else{
    arr[rear] = p;
    rear++;
  }
}

//@author Cody & Devin
//removes first in from queue array
template<class DataType>
void SUQueueArr<DataType>::dequeue(DataType &p){
  if(front == rear){
    std::cout<<"Oof\n";
  }else{
    for(int i = 0; i < rear -1; i++){
      arr[i]=arr[i+1];
    }
    rear--;
  }
  return;
}

//@author Cody & Devin
// prints the SUQueueArr a for loop
template<class DataType>
void SUQueueArr<DataType>::printQueue()const{
  if(rear == front){
    std::cout<<"empty";
  }
  for(int i = front; i < rear; i++){
    std::cout<<arr[i];
    std::cout<<std::endl;
  }
}


//@author Cody & Devin
//Overloaded = operator copy constructor
template<class DataType>
SUQueueArr<DataType>& SUQueueArr<DataType>::operator=(const SUQueueArr<DataType> &SUQueueArr){
  delete[] arr;

  capacity = SUQueueArr.capacity;
  rear = SUQueueArr.rear;
  front = SUQueueArr.front;
  arr = new DataType[capacity];
  for(int i = 0; i < capacity; i++){
    arr[i] = SUQueueArr.arr[i];
  }
  return *this;
}
