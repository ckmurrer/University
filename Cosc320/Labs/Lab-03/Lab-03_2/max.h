/*
    Name: Cody Murrer
    Lab: 03-2 Binary Tree (find the max value in an integer Binary Tree)
    Class: 320-752
*/

#ifndef MAX_H
#define MAX_H

#include <iostream>

#include "d_tnodel.h"
#include "d_tnode.h"

class max{
    private:

    public:

};
// function to find the max number in an integer tree
template<typename T>
    int max(tnode <T> *t){
// creates a temp node at the start of root t        
        tnode<T> *temp = t;
// base case for the function that checks if temp is null or not        
        if(temp == NULL){
            return 0;
        }
// setting int values that recursivly goes through the tree
        int maxNumber = temp->nodeValue;
        int right = max(temp->right);
        int left = max(temp->left);
// data comnparisons and swaps for the right, max, and left integers        
        if(right>maxNumber){
            maxNumber = right;
        }
        if(left>right){
            maxNumber = left;
        } 
        return maxNumber;
    }
#endif