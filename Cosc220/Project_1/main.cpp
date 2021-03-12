/*
  Cody Murrer
  Project-1
  10/13/2019
*/
#include "studentDB.h"
#include "student.h"
#include "course.h"

#include<sstream>
#include<string>
#include <fstream>
#include<iostream>

using namespace std;

int main(){
  string majorList;
  string test;
  char charAnswer,charCourse, charMajor;
  StudentDB data;

  cout<<"would you like to create a new student y/n: ";
  cin>>charAnswer;
  cin.ignore();

  while(charAnswer != 'y' && charAnswer != 'n'){
    cout<<"Your input of, "<<charAnswer<<" is not valid please use y or n";
    cout<<"\nwould you like to create a new student y/n: ";
    cin>>charAnswer;
    cin.ignore();
    if(charAnswer == 'y' && charAnswer == 'n')
      break;
  }

  while(charAnswer == 'y'){
    string nam,dob,maj;

    cout<<"Student Name: ";
    getline(cin,nam);
    cin.ignore();

    cout<<"\nStudent date Of Birth (month/day/year): ";
    getline(cin,dob);
    cin.ignore();

    ifstream inFile;
    inFile.open("Majors.txt");
    if(!inFile){
      cout<<"File didnt open or there is no such file";
      exit(1);
    }
    while(inFile >> majorList){
      cout<<majorList<<"\n";
    }
    inFile.close();

    cout<<"Here is a list of current majors\n";
    cout<<"\nDo you wish to add a major to the list y/n: ";
    cin>>charMajor;
    cin.ignore();


    while(charMajor != 'y' && charMajor != 'n'){
      cout<<"Your input of, "<<charMajor<<" is not valid please use y or n";
      cout<<"\nDo you wish to add a major to the list y/n: ";
      cin>>charMajor;
      cin.ignore();
      if(charMajor == 'y' && charMajor == 'n')
        break;
    }

    if(charMajor == 'y'){
      string newMajor;
      cout<<"\nWhat is the new Major: ";

      ofstream writeFile;
      writeFile.open("Majors.txt", ios::app);
      cin>>newMajor;
      writeFile<<newMajor<<"\n";
      writeFile.close();
    }

    cout<<"\nStudent Major: ";
    getline(cin,maj);
    cin.ignore();



    data.create(Student(nam,dob,maj));

    cout<<"\nDo you wish to create another student y/n: ";
    cin>>charAnswer;
    cin.ignore();

    while(charAnswer != 'y' && charAnswer != 'n'){
      cout<<"Your input of, "<<charAnswer<<" is not valid please use y or n";
      cout<<"\nDo you wish to create another student y/n: ";
      cin>>charAnswer;
      cin.ignore();
      if(charAnswer == 'y' && charAnswer == 'n')
        break;
    }
  }

  cout<<"Would you like to enter courses for a student y/n: ";
  cin>>charCourse;
  cin.ignore();

  while(charCourse != 'y'&& charCourse != 'n'){
    cout<<"Your input of, "<<charCourse<<" is not valid please use y or n";
    cout<<"\nWould you like to enter courses for a student y/n: ";
    cin>>charCourse;
    cin.ignore();
    if(charCourse == 'y' && charCourse == 'n')
      break;
  }
  if(charCourse == 'y'){
    cout<<"\nEnter the Students name: ";
    cin>>test;

    while(charCourse == 'y'){
      string con,dep,sem;
      char gra;
      cout<<"\nEnter a course: ";
      cin>>con;

      cout<<"\nWhat department is the course from: ";
      cin>>dep;

      cout<<"\nWhat semester was it taken in: ";
      cin>>sem;

      cout<<"\nWhat was the final letter grade: ";
      cin>>gra;

      data.search(test,con,dep,sem,gra);

      cout<<"\nDo you wish to enter another course y/n";
      cin>>charCourse;

      while(charCourse != 'y'&& charCourse != 'n'){
        cout<<"Your input of, "<<charCourse<<" is not valid please use y or n";
        cout<<"\nDo you wish to enter another class y/n";
        cin>>charCourse;
        cin.ignore();
        if(charCourse == 'y' && charCourse == 'n')
          break;
      }
    }
  }
  data.print();

  return 0;
}
