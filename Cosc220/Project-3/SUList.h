#ifndef SULIST_H
#define SULIST_H

#include <iostream>

template <class DataType>
class SUList{
  private:
    struct ListNode{     // The nodes of the list
      DataType data;      // The data stored in the node
      ListNode* next;     // The next node in the list
      ListNode* prev;
    };
    ListNode* head;      // The front of the list
    ListNode* tail;      // The last node of the list

  public:
    SUList();                      // Default ctor
    SUList(const SUList&);         // Copy ctor
    ~SUList();                     // Destructor
    DataType getFront();           // Remove & return the front
    DataType getBack();            // Remove & return the back
    void putFront(const DataType&);// Add to the front
    void putBack(const DataType&); // Add to the back
    int size() const;              // Returns the number of elements
    bool contains(const DataType&);// Tests for membership
    SUList<DataType>& operator=(const SUList<DataType>&); // Overloaded assignment

    template<class f>
    friend std::ostream& operator<<(std::ostream &oStream, SUList<f> &s);

    std::ostream& display(std::ostream& oStream);
  };
#endif
