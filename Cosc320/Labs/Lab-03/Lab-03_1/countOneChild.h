/*
    Name: Cody Murrer
    Lab: 03-1 Binary Tree (count interior nodes with one child)
    Class: 320-752
*/

#ifndef COUNTONECHILD_H
#define COUNTONECHILD_H

#include <iostream>

#include "d_tnodel.h"
#include "d_tnode.h"

class countOneChild{
    private:

    public:

};

    template<typename T>
    int countOneChild(tnode<T> *t){        
        int level = 0, column = 0;
        int interior = 0;
// checking if there is a tree
        if(t == NULL||t->left == NULL && t->right == NULL){
            return 0;
        }else{
// used some logic from display function in the d_tnodel.h file to put the tree into a queue            
            tnodeShadow *nRoot = buildShadowTree(t, level, column);
            tnodeShadow *temp;
            queue<tnodeShadow *> plsWork;
            plsWork.push(nRoot);

// while loop that will continue to run until the queue is empty
            while(!plsWork.empty()){
// setting a temp variable to the front of the queue                
                temp = plsWork.front();
                plsWork.pop();

// checking tree to see if there is a single node with one child to itterate interior by one
                if(temp->left &&!temp->right || !temp->left && temp->right){
                    interior++;
                }
// checks to see when temp is pointing left it is not pointing to null and if not pushes it into the queue               
                if(temp->left != NULL){
                    plsWork.push(temp->left);
                }
// checks to see when temp is pointing right it is not pointing to null and if not pushes it into the queue
                if(temp->right != NULL){
                    plsWork.push(temp->right);
                } 
            }
// deletes the shadow tree used to make the queue            
            deleteShadowTree(nRoot);
        }
        return interior;
    }
#endif