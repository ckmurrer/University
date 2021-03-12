/*
    Name: Cody Murrer
    Lab: 08 Priority Queue (use the object of the preqrec class to set the priority of the processes being pushed onto the priority queue) 
    Class: 320-752
*/
#include "d_pqueue.h"
#include "preqrec.h"

#include <stdio.h>
#include <time.h>
#include <iostream>

int main(){
// creates an object of the miniPQ class using the procReqRec class    
    miniPQ<procReqRec,less<procReqRec>> mpq;
// seeds the random number generator    
    std::srand(time(NULL)); 
 //  pushes the process A - J onto the priority queue
    mpq.push(procReqRec("Process A",std::rand() % 40));
    mpq.push(procReqRec("Process B",std::rand() % 40));
    mpq.push(procReqRec("Process C",std::rand() % 40));
    mpq.push(procReqRec("Process D",std::rand() % 40));
    mpq.push(procReqRec("Process E",std::rand() % 40));
    mpq.push(procReqRec("Process F",std::rand() % 40));
    mpq.push(procReqRec("Process G",std::rand() % 40));
    mpq.push(procReqRec("Process H",std::rand() % 40));
    mpq.push(procReqRec("Process I",std::rand() % 40));
    mpq.push(procReqRec("Process J",std::rand() % 40));
// prints the top of the priority queue and pops until empty
    while(!mpq.empty()){
        std::cout<<mpq.top();
        mpq.pop();
    }
}