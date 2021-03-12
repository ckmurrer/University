#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int partition(int arr[], int start, int end){
  // referenced the textbook in chapter 20
  int p,pI,mid;
  mid = (start+end)/2;
  swap(arr[start],arr[mid]);
  pI = start;
  p = arr[start];

  for(int i = start+1; i<=end; i++){
    if(arr[i]<p){
      pI++;
      swap(arr[pI],arr[i]);
    }
  }
  swap(arr[start], arr[pI]);
  return pI;
}

// swaps the index of the passed values
void swap(int &val1, int &val2){
  int temp = val1;
  val1 = val2;
  val2 = temp;
}

// quick sort
void quicksort(int arr[], int start, int end){
  int p;
  if(start<end){
    p = partition(arr,start,end);
    quicksort(arr,start,p-1);
    quicksort(arr,p+1,end);
  }
}

int assign(){
  srand(time(NULL));
  int size = 30;
  int bigArray[size];
  cout<<"Random Array: ";
  for(int i=0; i<size; i++){
    bigArray[i]=rand()%(size+1);
    cout<<bigArray[i]<<" ";
  }
  cout<<"\n";
  quicksort(bigArray,0,size-1);
  cout<<"Sorted Random Array: ";
  for(int i=0; i<size; i++){
    cout<<bigArray[i]<<" ";
  }
  cout<<"\n";
}

int main(){
  int arr[] = {10,5,20,15,30,90};
  int arr2[] = {91,82,93,54,55,60,84};
  int arr3[] = {6,5,4,3,2,1};

  assign();
  cout<<"Array 1: ";
  for(int i = 0; i<6; i++){
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
  cout<<"Array 2: ";
  for(int i = 0; i<6; i++){
    cout<<arr2[i]<<" ";
  }
  cout<<"\n";
  cout<<"Array 3: ";
  for(int i = 0; i<6; i++){
    cout<<arr3[i]<<" ";
  }
  cout<<"\n";
  quicksort(arr,0,6-1);
  quicksort(arr2,0,6-1);
  quicksort(arr3,0,6-1);

  cout<<"Sorted Array 1: ";
  for(int i = 0; i<6; i++){
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
  cout<<"Sorted Array 2: ";
  for(int i = 0; i<6; i++){
    cout<<arr2[i]<<" ";
  }
  cout<<"\n";
  cout<<"Sorted Array 3: ";
  for(int i = 0; i<6; i++){
    cout<<arr3[i]<<" ";
  }
  cout<<"\n";

}
