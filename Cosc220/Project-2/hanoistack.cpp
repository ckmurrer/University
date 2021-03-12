#include "hanoistack.h"
#include <iostream>
using namespace std;

// constructor
HanoiStack::HanoiStack(){
  int size = 0;
  head = nullptr;
}

// seg fault not sure why :( :(
HanoiStack::~HanoiStack(){
/*  Disk* temp = head;
  while(temp){
    temp = temp->next;
    delete head;
    head = temp;
  }*/
}

// pushes onto the stack
void HanoiStack::push(int* disk){
  Disk* node = new Disk;
  node->diskSize=*(disk);

  if(head == nullptr){
    head = node;
    return;
  }

  node->next = head;
  head = node;
}

// pops from the head of the stack
int& HanoiStack::pop(){
  Disk* now = head;
  Disk* last = head;

  if(now == nullptr){
      cout<<"The stack is empty\n";
      return now->diskSize;
  }

  if(head->next != nullptr){
    last = head;
    now = head->next;
    head = now;
    return last->diskSize;
  }

  if(head->next == nullptr){
    Disk* temp = head;
    head = nullptr;
    return temp->diskSize;
  }
}

// peeks the top of the stack
int HanoiStack::peek(){
  Disk* temp = head;
  return head->diskSize;
}

// checks if the stack is empty
bool HanoiStack::empty(HanoiStack &stack){
  if(head == nullptr){
    return true;
  }else{
    return false;
  }
}

// sets win condition
int HanoiStack::winCondition(){
  Disk* temp = head;
  int count = 0;

  while(temp){
    temp = temp->next;
    count++;
  }
  return count;
}

// overloaded += operator
HanoiStack operator+=(HanoiStack &start, HanoiStack &end){
  if(start.empty(start)==true && end.empty(end)==true){
    return end;
  }else if(start.empty(start)==true){
    return start;
  }else if(end.empty(end)==true){
    end.push(&start.pop());
  }else if(start.peek() > end.peek()){
    cout<<"Move could not be made chosen disk is larger.\n";
  }else{
    end.push(&start.pop());
  }
}

// overloaded << operator
ostream& operator<<(ostream &oStream, HanoiStack &stack){
  return stack.display(oStream);
}

// displays the stacks
ostream& HanoiStack::display(ostream& oStream){
  Disk* temp = head;
    while(temp){
      oStream<<" "<<temp->diskSize;
      temp= temp->next;
    }
    return oStream;
}
