#ifndef SUSTACK_H
#define SUSTACK_H

#include "SUList.h"
#include <iostream>

template <class DataType>
class SUStackList{

  private:
    SUList<DataType> list;

  public:
    SUStackList();                   // Constructor
    SUStackList(const SUStackList &); // Copy Constructor
    ~SUStackList();                  // Destructor
    int size() const;               // get the number of elements in the stack
    bool isEmpty() const;           // Check if the stack is empty
    void push(const DataType&);     // Pushes an object onto the stack
    void pop(DataType&);            // Pop an object off the stack and store it
    void printStack();        // Prints the stack from the top, down
    SUStackList<DataType>& operator=(const SUStackList<DataType>&); // Assignment operator
};

template <class DataType>
class SUStackArr{
  private:
    DataType* arr;        // The array of items
    int capacity;   // The size of the current array
    int top;        // The location of the top element

  public:
    SUStackArr();                   // Constructor
    SUStackArr(const SUStackArr &); // Copy Constructor
    ~SUStackArr();                  // Destructor
    int size() const;               // get the number of elements in the stack
    bool isEmpty() const;           // Check if the stack is empty
    void push(const DataType&);     // Pushes an object onto the stack
    void pop(DataType&);            // Pop an object off the stack and store it
    void printStack() const;        // Prints the stack from the top, down
    SUStackArr<DataType>& operator=(const SUStackArr<DataType>&); // Assignment operator

    template<class f>
    friend std::ostream& operator<<(std::ostream &oStream, SUStackArr<f> &s);

    std::ostream& display(std::ostream& oStream);
};
#endif
