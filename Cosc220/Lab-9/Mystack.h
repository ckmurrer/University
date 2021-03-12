#ifndef MYSTACK_H
#define MYSTACK_H

#include"payroll.h"
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>


template<class T>
class MyStack{

  private:
    struct Node{
      T data;
      Node* next;
    };
    Node* head;

  public:
    MyStack<T>();
    ~MyStack();
    MyStack(const MyStack&);
    MyStack operator=(const MyStack&);
    void push(T p);
    T pop();
    void pop(T&);
    T peek();
    int size();
    std::ostream& print(std::ostream& oStream);
    template<class W>
    friend std::ostream& operator<<(std::ostream &oStream, MyStack<W> &s);
};

#endif
