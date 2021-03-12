#include "SUStack.h"
#include "payroll.h"
#include "SUList.h"
#include <iostream>

//@author Devin
//Default constructor
template<class DataType>
SUStackList<DataType>::SUStackList(){
  SUList<DataType> list;
}

//@author Devin
//Destructor
template<class DataType>
SUStackList<DataType>::~SUStackList(){

}

template<class DataType>
bool SUStackList<DataType>::isEmpty()const{
  int t = list.size();
  if(t == 0){
    return 1;
  }
  return 0;
}

//@author Devin
//Overloaded operator
template<class DataType>
SUStackList<DataType>& SUStackList<DataType>::operator=(const SUStackList<DataType> &s){
  list = s.list;
  return *this;
}

//@author Devin
//Copy Constructor
template<class DataType>
SUStackList<DataType>::SUStackList(const SUStackList<DataType> &l){
  list = l.list;
}

//@author Cody & Devin
template<class DataType>
void SUStackList<DataType>::push(const DataType& t){
  list.putFront(t);
}

//@author Devin
//Puts element in the front of listCopy
template<class DataType>
void SUStackList<DataType>::pop(DataType& t){
  t = list.getFront();
}

//@author Cody
//Prints list
template<class DataType>
void SUStackList<DataType>::printStack(){
  std::cout<<list;
}

//@author Devin and Cody
template<class DataType>
int SUStackList<DataType>::size() const
{
  list.size();
}

//@author Cody & Devin
// default constructor for SUStackArr
template<class DataType>
SUStackArr<DataType>::SUStackArr(){
  capacity = 10;
  top = -1;
  arr = new DataType[capacity];
}

//@author Cody & Devin
//copy constructor for stack array
template<class DataType>
SUStackArr<DataType>::SUStackArr(const SUStackArr<DataType> &sa){
  capacity = sa.capacity;
  top = sa.top;
  arr = new DataType[capacity];

  for(int i = 0; i <capacity; i++){
    arr[i] = sa.arr[i];
  }
}

//@author Cody & Devin
// destructor for SUStackArr
template<class DataType>
SUStackArr<DataType>::~SUStackArr(){
  delete [] arr;
}

//@author Cody & Devin
// uses capacity to check the size of the SUStackArr
template<class DataType>
int SUStackArr<DataType>::size()const{
  int size = 0;
  for(int i = 0; i < top+1; i++){
    size ++;
  }
  return size;
}

//@author Cody & Devin
// uses top to see if the SUStackArr is empty
template<class DataType>
bool SUStackArr<DataType>::isEmpty()const{
  if(top == -1){
    return true;
  }
  return false;
}

//@author Cody & Devin
// pushes DataType elements onto the SUStackArr using FILO order
template<class DataType>
void SUStackArr<DataType>::push(const DataType& p){
  if(top < capacity -1){
    arr[++top] = p;
  }else{
    std::cout<<"Overflow";
  }
}

//@author Cody & Devin
//pops from array stack
template<class DataType>
void SUStackArr<DataType>::pop(DataType &p){
  if(top>0){
    capacity--;
    p = arr[top];
    top--;
  }
}

//@author Cody & Devin
//overloaded << operator for prints
template<class DataType>
std::ostream& operator<<(std::ostream &oStream, SUStackArr<DataType> &s){
  return s.display(oStream);
}
template<class DataType>
std::ostream& SUStackArr<DataType>::display(std::ostream& oStream){
  for(int i = top; i >=0; i--){
      std::cout<<arr[i];
      std::cout<<std::endl;
  }
  return oStream;
}

//@author Cody & Devin
// prints the SUStackArr top down using a for loop
template<class DataType>
void SUStackArr<DataType>::printStack()const{
  for(int i = top; i >=0; i--){
      std::cout<<arr[i];
      std::cout<<std::endl;
  }
}

//@author Cody & Devin
//overloaded = operator for copy constructor
template<class DataType>
SUStackArr<DataType>& SUStackArr<DataType>::operator=(const SUStackArr<DataType> &SUStackArr){
  delete [] arr;

  capacity = SUStackArr.capacity;
  top = SUStackArr.top;
  arr = new DataType[capacity];

  for(int i = 0; i <capacity; i++){
    arr[i] = SUStackArr.arr[i];
  }
  return *this;
}
