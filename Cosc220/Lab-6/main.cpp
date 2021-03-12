#include <iostream>
#include <stdio.h>
#include <time.h>
#include <chrono>
using namespace std;

void printArr(string name,int count, string sort){
  cout<<"*****"<<sort<<"*****\n";
  cout<<name<<"\n";
  cout<<"Times swapped: "<<count<<"\n";
  cout<<"Time taken to sort: \n";
}

void isSorted(int arr[], int size, string name){
  for(int i=0; i<size;i++){
    if(arr[i]>arr[i+1]){
      cout<<name<" is not sorted correctly\n";
      break;
    }else{
      cout<<name<<" is sorted correctly\n";
      break;
    }
  }
}

void BUBBLESORT(int arr[], int size,string name){
  string sort = "Bubble_Sort";
  int count=0;
  bool swapped;
  swapped = true;
  while(swapped){
    swapped = false;

    for(int i=0; i<size-1; i++){

      if(arr[i] > arr[i+1]){
        int temp;
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        swapped = true;
      }
      count ++;
    }
  }
  printArr(name,count,sort);
  isSorted(arr,size,name);
}

void SELECTIONSORT(int arr[], int size, string name){
  string sort = "Selection_Sort";
  int count = 0;
  int min;
  for(int i=0; i<size-1; i++){
     min = i;
     count++;
    for(int j=i+i; j<size; j++){
      if(arr[j]<arr[min]){
        min = j;
        int temp;
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
      }
    }
  }
  printArr(name,count,sort);
}

void INSERTIONSORT(int arr[], int size,string name){
  string sort = "Insertion_Sort";
  int count = 0;
  for(int i=0; i<size-1; i++){
    count++;
    int j=i;
    while(j>0 && arr[j]<arr[j-1]){
      int temp;
      temp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = temp;
    }
  }
  printArr(name,count,sort);
}

int main(){
  srand(time(NULL));
  string name;
  int asSize;
  int deSize;
  int bigBoi;
  cout<<"How many elements for the Ascending list; ";
  cin>>asSize;
  cout<<"How many elements for the Descending list: ";
  cin>>deSize;
  cout<<"How many elements for the Random list: ";
  cin>>bigBoi;

  int asArray[asSize];
  int deArray[deSize];
  int *bigArray = new int[bigBoi];

// Ascending array
  for(int i=0; i<asSize; i++){
    asArray[i] = i;
  }
  name = "Ascending";
  auto start = chrono::system_clock::now();
  BUBBLESORT(asArray,asSize,name);
  auto end = chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  time_t end_time = chrono::system_clock::to_time_t(end);
  cout<<"Finished at "<<ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";

  auto start1 = chrono::system_clock::now();
  INSERTIONSORT(asArray,asSize,name);
  auto end1 = chrono::system_clock::now();
  chrono::duration<double> elapsed1_seconds = end1-start1;
  time_t end1_time = chrono::system_clock::to_time_t(end1);
  cout<<"Finished at "<<ctime(&end1_time)<<"elapsed time: "<<elapsed1_seconds.count()<<"s\n";

  auto start2 = chrono::system_clock::now();
  SELECTIONSORT(asArray,asSize,name);
  auto end2 = chrono::system_clock::now();
  chrono::duration<double> elapsed2_seconds = end2-start2;
  time_t end2_time = chrono::system_clock::to_time_t(end2);
  cout<<"Finished at "<<ctime(&end2_time)<<"elapsed time: "<<elapsed2_seconds.count()<<"s\n";

// Descending array
  for(int i=deSize; i>=0; i--){
    deArray[i] = i;
  }
  name = "Descending";
  auto start3 = chrono::system_clock::now();
  BUBBLESORT(deArray,deSize,name);
  auto end3 = chrono::system_clock::now();
  chrono::duration<double> elapsed3_seconds = end3-start3;
  time_t end3_time = chrono::system_clock::to_time_t(end3);
  cout<<"Finished at "<<ctime(&end3_time)<<"elapsed time: "<<elapsed3_seconds.count()<<"s\n";

  auto start4 = chrono::system_clock::now();
  INSERTIONSORT(deArray,deSize,name);
  auto end4 = chrono::system_clock::now();
  chrono::duration<double> elapsed4_seconds = end4-start4;
  time_t end4_time = chrono::system_clock::to_time_t(end4);
  cout<<"Finished at "<<ctime(&end4_time)<<"elapsed time: "<<elapsed4_seconds.count()<<"s\n";

  auto start5 = chrono::system_clock::now();
  SELECTIONSORT(deArray,deSize,name);
  auto end5 = chrono::system_clock::now();
  chrono::duration<double> elapsed5_seconds = end5-start5;
  time_t end5_time = chrono::system_clock::to_time_t(end5);
  cout<<"Finished at "<<ctime(&end5_time)<<"elapsed time: "<<elapsed5_seconds.count()<<"s\n";

// Dynamic random array
  for(int i=bigBoi; i>=0; i--){
    *(bigArray+i)=rand()%(bigBoi+1);
  }
  name = "Random";
  auto start6 = chrono::system_clock::now();
  BUBBLESORT(bigArray,bigBoi,name);
  auto end6 = chrono::system_clock::now();
  chrono::duration<double> elapsed6_seconds = end6-start6;
  time_t end6_time = chrono::system_clock::to_time_t(end6);
  cout<<"Finished at "<<ctime(&end6_time)<<"elapsed time: "<<elapsed6_seconds.count()<<"s\n";

  auto start7 = chrono::system_clock::now();
  INSERTIONSORT(bigArray,bigBoi,name);
  auto end7 = chrono::system_clock::now();
  chrono::duration<double> elapsed7_seconds = end7-start7;
  time_t end7_time = chrono::system_clock::to_time_t(end7);
  cout<<"Finished at "<<ctime(&end7_time)<<"elapsed time: "<<elapsed7_seconds.count()<<"s\n";

  auto start8 = chrono::system_clock::now();
  SELECTIONSORT(bigArray,bigBoi,name);
  auto end8 = chrono::system_clock::now();
  chrono::duration<double> elapsed8_seconds = end8-start8;
  time_t end8_time = chrono::system_clock::to_time_t(end8);
  cout<<"Finished at "<<ctime(&end8_time)<<"elapsed time: "<<elapsed8_seconds.count()<<"s\n";
  delete[] bigArray;
  return 0;
}
