#ifndef HANOISTACK_H
#define HANOISTACK_H
#include <iostream>
using namespace std;

class HanoiStack{
  struct Disk{
    int diskSize;
    Disk* next;
  };
    Disk* head;

  private:
    friend HanoiStack operator+=(HanoiStack &start, HanoiStack &end);
    friend ostream& operator<<(ostream &oStream, HanoiStack &stack);
    int peek();
    bool empty(HanoiStack &stack);
  public:
    HanoiStack();
    ~HanoiStack();
    void push(int*);
    int& pop();
    ostream& display(ostream&);
    int winCondition();
};
#endif
