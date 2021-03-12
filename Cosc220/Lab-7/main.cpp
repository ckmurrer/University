/*

Cody Murrer

Lab-7

*/
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

// prints the list in reverse order as it was added
Node* reversePrint(Node* head){
  if(head == nullptr){
    return head;
  }else{
    reversePrint(head->next);
    cout<<head->value<<"\n";
  }
}

Node* insertSorted(Node* head, int value){
  Node* newNode = new Node(value);

  if(head == NULL || head->value >= value ){
    newNode->next = head;
    head = newNode;
    return head;
  }
  if(head->next != NULL){
    if(head->next->value < value){
      return insertSorted(head->next,value);
    }
  }else{
    newNode->next = head->next;
    head->next = newNode;
  }
}

Node* remove(Node* head, int value){
  if(value < 1){
    return head;
  }
  if(head == nullptr){
    return NULL;
  }
  if(head->value == value){
    Node* temp = head->next;
    free(head);
    return temp;
  }
  head->next = remove(head->next , value);
  return head;
}

Node* appendList(Node* head, Node* head2){
  if(head == nullptr){
    return head;
  }
  if(head2 == nullptr){
    return head2;
  }
  if(head->next == nullptr){
    head->next = head2;
    return head;
  }else{
    return appendList(head->next, head2);
  }
}

Node* reverse(Node* head){
  if(head == nullptr){
    return head;
  }
}

// deletes the objects in the list to ensure no Memory Leaks
Node* deList(Node* head){
  if (head == nullptr){
    return head;
  }else{
    delete(head);
    deList(head->next);
  }
}

// program driver
int main(){

  Node* head = new Node;
  head -> value = 2;
  head -> next = nullptr;

  Node* nNode = new Node;
  nNode -> value = 5;
  head -> next = nNode;
  nNode -> next = nullptr;

  Node* nNodeTwo = new Node;
  nNodeTwo -> value = 15;
  nNode -> next = nNodeTwo;
  nNodeTwo -> next = nullptr;

  Node* head2 = new Node;
  head2->value = 18;
  head2->next = nullptr;

  Node* nN = new Node;
  nN -> value=20;
  head2 -> next = nN;
  nN -> next = nullptr;

  Node* nN2 = new Node;
  nN2 -> value = 22;
  nN -> next = nN2;
  nN2 -> next = nullptr;

  Node* head1 = new Node;
  head1 = appendList(head,head2);
  head1 = insertSorted(head,6);

  int len = length(head);
  cout<<"List Length is: "<<len<<"\n";
  Node* removedNode = remove(head, 20);
  cout<<"Regular print\n";
  print(head);
  cout<<"Reverse print\n";
  reversePrint(head);

  deList(head);
  deList(head1);
  deList(head2);

  return 0;
}
