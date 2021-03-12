/*
    Name: Cody Murrer
    Lab: 02 (Binary search lab)
    Class: 320-752
*/
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "binSearch.h"

int binSearch::search(int *arr, int left, int right, int x){
// *arr is the array
//  left is the start of the array
//  right is the end of the array
//  x is the element searching for
    
    int sumFailCom=0, successTotal=0;
//  while loop that itterates until left is less than or equal to the right    
    while(left<=right){
//      finds the middle of the array and checks if it is there      
        int middle = left + (right-left)/2;
        if(arr[middle]==x){
            successTotal++;
//          returns when there is a successful search            
            return successTotal;
        }
//      checks if the middle element is smaller or bigger than x        
        if(arr[middle] < x){
            left = middle +1;
        }else{
            right = middle -1;
        }
        sumFailCom++;
    }
// returns the amount of failed comparisons         
   return sumFailCom;
}

void binSearch::sort(int *arr, int n){
    
    int j = n-1;
//  intial for loop that runs each itteration for the sort
    for(int i = 0; i < j; i++,j--){
//      sets and initializes needed variables to i
        int small = arr[i];
        int big = arr[i];
        int arrMin = i;
        int arrMax = i;
      
//      loop to find the min or max values in each pass      
        for(int k = i; k <= j; k++){
            if(arr[k] > big){
                arrMax = k;
                big = arr[k];
            }else if(arr[k] < small){
                arrMin = k;
                small = arr[k];
            }
        }
//      swaps the element where i is with the min
        std::swap(arr[i], arr[arrMin]);
//      checks is the min is the same as the big and if so swaps them
        if(arr[arrMin] == big){
            std::swap(arr[j], arr[arrMin]);
        }else{
            std::swap(arr[j], arr[arrMax]);
        }
    }    
}

int main(){
    binSearch bs;
    int successTotal = 0, sumFailCom = 0;
//  creates the array of random ints up to 10000 and gets it size
    int arr[10000];
    std::srand(time(NULL));
    for(int i = 0; i<10000;i++){
        arr[i] = std::rand() % 10000;
    }
    int size = *(&arr+1)-arr;
//  calls the sort function to sort the array    
    bs.sort(arr,size);

    int left = 0;
//  sets a random number to itterate through the for loop 
    int ran = std::rand() % 10000;
    for(int j = 0; j<ran; j++){
//      sets the random target value each time the loop itterates        
        int x = std::rand()%10000;
//      calls and gets the return of the search function        
        int result = bs.search(arr,left,size-1,x);
//      checks if it was a successful search or a failed search        
        if(result==1){
            successTotal++;
        }else{
            sumFailCom = sumFailCom + result;
        }
    }
//  prints for the data used in the operation to find the empirical result    
    std::cout<<"Random Value: "<<ran<<std::endl;
    std::cout<<"Total successful searches: "<<successTotal<<std::endl;
    std::cout<<"Total failed comparisons: "<<sumFailCom<<std::endl;
    std::cout<<"Empirical Result: "<<sumFailCom/(ran-successTotal)<<std::endl;
}