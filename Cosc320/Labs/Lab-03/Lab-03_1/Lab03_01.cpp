/*
    Name: Cody Murrer
    Lab: 03-1 Binary Tree (count interior nodes with one child)
    Class: 320-752
*/

#include <iostream>

#include "countOneChild.h"
#include "d_tnodel.h"
#include "d_tnode.h"

//used the structure of the buildTree function in d_tnodel.h
tnode<char> *build(int n){
    tnode<char> *root, *b, *c, *d, *e, *f, *g, *h, *i;
	switch(n)
	{
		// nodes d and g and f are leaf nodes
		case 0:
			g = new tnode<char> ('G');
			d = new tnode<char> ('D');
			e = new tnode<char> ('E',(tnode<char> *)NULL, g);
			f = new tnode<char> ('F');
			b = new tnode<char> ('B',d, (tnode<char> *)NULL);
			c = new tnode<char> ('C',e, f);
			root = new tnode<char> ('A',b, c);
			break;
	}
	return root;
}

int main(){
// sets a variable equal to the tree being built for later use in delete tree function	
	tnode<char> *bt = build(0);
    std::cout<<"from the tree: "<<std::endl;
// displays tree	
    displayTree(bt,0);
    std::cout<<"The number of Interior Nodes with one Child is: "<<countOneChild(bt)<<std::endl;
// gets rid of memory leaks	
	deleteTree(bt);
}