/*
    Name: Cody Murrer
    Lab: 05 Binary Search Tree (create a binary search tree and keep track of the number of elements within from 0-6)
    Class: 320-752
*/
#include "d_random.h"
#include "d_stree.h"
#include "int.h"

#include <iostream>
#include <utility>
#include <stdio.h>
#include <time.h>

int main(){   
    stree<int> integerTree;

    integer intObj0(0),intObj1(1),intObj2(2),intObj3(3),intObj4(4),intObj5(5), intObj6(6);

    std::srand(time(NULL));
    for(int i=0; i<10000;i++){

        int ranInt(std::rand()%7);
        switch (ranInt)
        {
        case 0:
            intObj0.incCount();
            integerTree.insert(ranInt);
            break;
        case 1:
            intObj1.incCount();
            integerTree.insert(ranInt);
            break;
        case 2:
            intObj2.incCount();
            integerTree.insert(ranInt);
            break;
        case 3:
            intObj3.incCount();
            integerTree.insert(ranInt);
            break;
        case 4:
            intObj4.incCount();
            integerTree.insert(ranInt);
            break;
        case 5:
            intObj5.incCount();
            integerTree.insert(ranInt);
            break;
        case 6:
            intObj6.incCount();
            integerTree.insert(ranInt);
            break;
        
        default:
            
            break;
        }
    }

    std::cout<<"The values in the tree are: "<<std::endl;
    std::cout<<intObj0<<std::endl;
    std::cout<<intObj1<<std::endl;
    std::cout<<intObj2<<std::endl;
    std::cout<<intObj3<<std::endl;
    std::cout<<intObj4<<std::endl;
    std::cout<<intObj5<<std::endl;
    std::cout<<intObj6<<std::endl<<std::endl;
    std::cout<<"The tree used it: "<<std::endl;
    integerTree.displayTree(1);

}