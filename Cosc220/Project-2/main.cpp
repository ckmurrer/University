/*
  Cody Murrer
  Project-2
  11/3/19
*/
#include "hanoistack.h"
#include <iostream>
using namespace std;

// prints the optimal solution for the amount of disks user inputs
void optimalSolution(int disk, char start, char end, char other){
  if(disk >= 1){
    optimalSolution(disk-1,start,other,end);
    cout<<"Move disk "<<disk<<" from "<<start<<" to "<<end<<"\n";
    optimalSolution(disk-1,other,end,start);
  }
}

// data validation for choosing a stack
char validStack(char choice){
  choice = toupper(choice);
  if(choice == 'A'){
    return choice;
  }else if(choice == 'B'){
    return choice;
  }else if(choice == 'C'){
    return choice;
  }else if(choice == 'X'){
      return choice;
  }else{
    cout<<"invalid input no such stack exists choose between A,B,C: ";
    cin>>choice;
    return validStack(choice);
  }
}

// data validation for yes and no questions
char validYN(char yn){
  yn = toupper(yn);
  if(yn == 'Y'){
    return yn;
  }else if(yn == 'N'){
    return yn;
  }else{
    cout<<"Invalid input please choose y or n. ";
    cin>>yn;
    return validYN(yn);
  }
}

// data validation for seeing if the users desired number of disks
int validDisks(int* disk){
  if(*(disk) <= 1){
    system("clear");
    cout<<"The amount "<<*(disk)<<" is too small choose between 2-10: ";
    cin>>*(disk);
    return validDisks(disk);
  }else if(*(disk) > 10){
    cout<<"The amount "<<*(disk)<<" is too big choose between 2-10: ";
    cin>>*(disk);
    return validDisks(disk);
  }else{
    return *(disk);
  }
}

int main(){
  HanoiStack a;
  HanoiStack b;
  HanoiStack c;
  int x=0;
  char choice,opt;
  bool game;
  int counter = 0;
  // user input for number of disks
  cout<<"How many disks do you wish to use choose between 2-10: ";
  int diskNum;
  // amount of disks user wants to use also sets size of stack
  cin>>diskNum;
  int* disk = &diskNum;
  validDisks(disk);

  // ghetto way of filling the stack if it works it works
  if(x<1){
    int size = *(disk);
    for(int i=size ; i>0 ;i--){
      a.push(&size);
      size--;
    }
    x++;
  }

  // asks user if they want the optimal solution
  cout<<"do you wish to print the optimal solution for "<<diskNum<<" disks y/n. ";
  cin>>opt;
  validYN(opt);
  opt = toupper(opt);

  // yes and no if statements for choosing if they want to get the optimal solution
  if(opt == 'Y'){
    optimalSolution(diskNum, 'A', 'B','C');
    cout<<"Now would you like to start the game? ";
    cin>>opt;
    validYN(opt);
    opt = toupper(opt);
    if(opt == 'Y'){
      game = true;
    }else{
      game = false;
    }
  }else if(opt == 'N'){
    cout<<"Then would you like to start the game? ";
    cin>>opt;
    validYN(opt);
    opt = toupper(opt);
    if(opt == 'Y'){
      game = true;
    }else{
      game = false;
    }
  }

  // infinite game loop
  while(game == true){

    char select;
// clears console every time it loops
    system("clear");
// prints updated stacks every time it loops
    cout<<"Stack A: "<<a<<"\n\n"<<"Stack B: "<<b<<"\n\n"<<"Stack C: "<<c;
// condition to enter switch
    cout<<"\n\nWhere do you wish to take from A B C or X to quit: ";
    cin>>select;
    validStack(select);
    select = toupper(select);

    switch(select){

// a pole case
      case 'A':
        char move;
        cout<<"Where do you wish to move to: ";
        cin>> move;
        validStack(move);
        move = toupper(move);

        if(move == 'B'){
          a+=b;
        }else if(move == 'C'){
          a+=c;
        }
        break;

// b pole case
      case 'B':
        cout<<"Where do you wish to move to: ";
        cin>> move;
        validStack(move);
        move = toupper(move);
        if(move == 'A'){
          b+=a;
        }else if(move == 'C'){
          b+=c;
        }
        break;

// c pole case
      case 'C':
        cout<<"Where do you wish to move to: ";
        cin>> move;
        validStack(move);
        move = toupper(move);
        if(move == 'A'){
          c+=a;
        }else if(move == 'B'){
          c+=b;
        }
        break;

// exit case
      case 'X':
        char exit;
        cout<<"Are you sure you wish to leave? ";
        cin>>exit;
        validYN(exit);
        exit = toupper(exit);
        if(exit == 'Y'){
          cout<<"\nThanks for playing.\n";
          game = false;
        }else if(exit == 'N'){
          game = true;
      }
        break;
    }
// move counter
    counter++;

// win condition
    if(b.winCondition()==diskNum){
      system("clear");
      cout<<"Stack A: "<<a<<"\n\n"<<"Stack B: "<<b<<"\n\n"<<"Stack C: "<<c;
      cout<<"\nCongrats you won! You made " <<counter<<" moves\n";
      game = false;
    }else if(c.winCondition()==diskNum){
      system("clear");
      cout<<"Stack A: "<<a<<"\n\n"<<"Stack B: "<<b<<"\n\n"<<"Stack C: "<<c;
      cout<<"\nCongrats you won! You made " <<counter<<" moves\n";
      game = false;
    }
  }
  return 0;
}
