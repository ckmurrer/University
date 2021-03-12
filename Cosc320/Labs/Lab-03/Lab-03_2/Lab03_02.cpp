/*
    Name: Cody Murrer
    Lab: 03-2 Binary Tree (find the max value in an integer Binary Tree)
    Class: 320-752
*/

#include <iostream>

#include "d_tnode.h"
#include "d_tnodel.h"
#include "max.h"

// taken from task one of the lab and changed char to int to accept integer values 
tnode<int> *buildIntTree(int n){
    tnode<int> *root, *b, *c, *d, *e, *f;
	switch(n)
	{
// structured based off of the way it was done in d_tnodel.h
// nodes 5 and 48 and 12 are leaf nodes
		case 0:
			d = new tnode<int> (5);
			e = new tnode<int> (48);
			f = new tnode<int> (12);
			b = new tnode<int> (40,d, (tnode<int> *)NULL);
			c = new tnode<int> (15,e, f);
			root = new tnode<int> (35,b, c);
			break;
	}
	return root;
}

int main(){
	tnode<int> *bt = buildIntTree(0);
// prints the tree and data from the max value
	std::cout<<"From the Integer Tree:"<<std::endl;
    displayTree(bt,0);
	std::cout<<"The max value is: "<<max(bt)<<std::endl;
	deleteTree(bt);
}