/*
    Name: Cody Murrer
    Lab: 01 (double ended selection sort)
    Class: 320-752
*/
#include <iostream>
#include "deSelsort.h"

void deSelsort::sort(int *arr, int n){
    
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
//      loop that prints the array each pass of the sort
        for(int l = 0; l<n; l++){
            std::cout<<arr[l]<<" ";
        }
        std::cout<<std::endl;
    }    
}

int main(){
//  creates the array and gets it size
    int arr[]= {13,5,2,25,47,17,8,21};
    int size = *(&arr+1)-arr;

//prints out unsorted the array
    std::cout<<"The unsorted values are:"<<std::endl;
    for(int k=0; k<size; k++){
        std::cout<<arr[k]<<" ";
    }
    std::cout<<std::endl<<"The unsorted values in each pass to fully sorted are:"<<std::endl;

// creates an object of the deSelsort class and passes the array and size into the double ended selection sort    
    deSelsort dSS;
    dSS.sort(arr,size);
}