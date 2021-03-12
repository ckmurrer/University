#ifndef COURSE_H
#define COURSE_H

#include<stdio.h>
#include<iostream>

using namespace std;

class Course{
  private:
    string courseName;
    string department;
    string semester;
    char grade;

  public:
    Course();
    Course(string con, string dep, string sem, char gra);

    void setCourseName(string con);
    string getCourseName();

    void setDepartment(string dep);
    string getDepartment();

    void setSemester(string sem);
    string getSemester();

    void setGrade(char gra);
    char getGrade();

};
#endif
