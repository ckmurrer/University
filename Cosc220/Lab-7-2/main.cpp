#include <iostream>
using namespace std;

// creates the Node struct to be used to make the list
struct Node{
  int value;
  Node* next;

  Node(){
    value = 0;
    next = nullptr;
  }

  Node(int n){
    value = n;
    next = nullptr;
  }
};

// gets the length of the list when called
int length(struct Node* head){
  if(head == nullptr){
      return 0;
  }else{
    return 1+length(head->next);
  }
}

// prints the list in order as it was added
Node* print(Node* head){
  if(head == nullptr){
    return head;
  }else{
    cout<<head->value<<endl;
    return print(head->next);
  }
}

// prints the list in reverse order as it was addeddddd
Node* reversePrint(Node* head){
  if(head == nullptr){
    return head;
  }else{
    reversePrint(head->next);
    cout<<head->value<<"\n";
    return head;
  }
}

Node* insertSorted(Node* head,int value){
  if(head == NULL || head->value >= value){
    Node* nNode = new Node(value);
    nNode->next = head;
    return nNode;
  }

  if(head->next != NULL){
    if(head->next->value < value){
      insertSorted(head->next,value);
      return head;
    }else{
       Node* nNode = new Node(value);
       nNode->next = head->next;
       head->next = nNode;
       return head;
     }
  }else{
    Node* nNode = new Node(value);
    head->next = nNode;
    return head;
  }
  return head;
}

Node* remove(Node*& head, int value){
    Node* last = head;

    if(head == nullptr)
    {
      return head;
    }
    if(head->value == value){
      head = head->next;
      last->next = nullptr;
      return last;
    } else {
      return nullptr;
    }
    if(head->next->value == value){
      last = head->next;
      head->next = head->next->next;
      last->next = nullptr;
      return last;
    }
    else{
      return remove(head->next,value);
    }
  }

Node* appendList(Node* head, Node* head2){
  if(head == nullptr){
    return head2;
  }
  if(head2 == nullptr){
    return head;
  }
  if(head->next == nullptr){
    head->next = head2;
    return head;
  }else{
    appendList(head->next, head2);
    return head;
  }
}

Node* reverse(Node* head){

  if(head == nullptr){
    return head;
  }
  if(head->next == nullptr){
    return head;
  }
    Node* tail = reverse(head->next);
    head->next->next = head;
    head ->next = nullptr;

    return tail;
}

// deletes the objects in the list to ensure no Memory Leaks

Node* deList(Node* head){
  Node* temp = head;

  if (head == nullptr){
    return head;
  }else{
    temp = head->next;
    delete head;
    return deList(temp);
  }
}

// program driver
int main(){

  Node* head = new Node(2);
  head -> next = nullptr;

  head -> next = new Node(5);

  head ->next->next = new Node(15);

  Node* head1 = new Node(10);

  head = appendList(head,head1);
  head1=nullptr;

  int len = length(head);
  cout<<"List Length is: "<<len<<"\n";

  Node* removedNode = remove(head, 2);

  cout<<"Regular print\n";
  print(head);

  cout<<"Reverse print\n";
  reversePrint(head);

  head = reverse(head);
  cout<<"Reverse List\n";
  print(head);

  deList(head);
  deList(head1);
  deList(removedNode);

  return 0;
}
