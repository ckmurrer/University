/*
    Name: Cody Murrer
    Lab: 04 Espression Tree (take the infix expression and make a tree out of it)
    Class: 320-752
*/

#include "d_except.h"
#include "d_expsym.h"
#include "d_tnode.h"
#include "d_tnodel.h"
#include "inf2pstf.h"

#include <iostream>

tnode<char> *buildExpTree(const string& exp)
{
	// newnode is the address of the root of subtrees we build
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	// subtrees go into and off the stack
	stack<tnode<char> *> s;
	int i = 0;

	// loop until i reaches the end of the string
	while(i != exp.length())
	{
		// skip blanks and tabs in the expression
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		// if the expression has trailing whitespace, we could
		// be at the end of the string
		if (i == exp.length())
			break;

		// extract the current token and increment i
		token = exp[i];
		i++;
		// see if the token is an operator or an operand
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// current token is an operator. pop two subtrees off
			// the stack.
			rptr = s.top();
			s.pop();
			lptr = s.top();
			s.pop();
		
			// create a new subtree with token as root and subtees
			// lptr and rptr and push it onto the stack
			newnode = new tnode<char>(token,lptr,rptr);
			s.push(newnode);
		}
		else // must be an operand
		{
			// create a leaf node and push it onto the stack
			newnode = new tnode<char>(token);
			s.push(newnode);
		}
	}
	// if the expression was not empty, the root of the expression
	// tree is on the top of the stack
	if (!s.empty())
		return s.top();
	else
		return NULL;
}

void prefixOutput(tnode<char> *exp, const string& separator){
    // the recursive scan terminates on a empty subtree
    if (exp != NULL){
        cout << exp->nodeValue << separator;
        prefixOutput(exp->left, separator);
        prefixOutput(exp->right, separator);
   }
}

int main(){
    infix2Postfix iftp("((a+b)*c)/(d-e)");
    string b = iftp.postfix();

    tnode<char> *et = buildExpTree(b);
    displayTree(et,0);
    
    std::cout<<"The Prefix order is: ";
    prefixOutput(et," ");
    std::cout<<std::endl;

    std::cout<<"The Postfix order is: ";
    postorderOutput(et," ");
    std::cout<<std::endl;

    deleteTree(et);
}