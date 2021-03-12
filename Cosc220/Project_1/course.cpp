#include "course.h"

using namespace std;

Course::Course(){ // default constructor

}

Course::Course(string con, string dep, string sem, char gra){ // constructor
  this->setCourseName(con);
  this->setDepartment(dep);
  this->setSemester(sem);
  this->setGrade(gra);
}

void Course::setCourseName(string con){ // sets course name
  courseName = con;
}

string Course::getCourseName(){ // gets course name
  return courseName;
}

void Course::setDepartment(string dep){ // sets department
  department = dep;
}

string Course::getDepartment(){ // gets department
  return department;
}

void Course::setSemester(string sem){ // sets semester
  semester = sem;
}

string Course::getSemester(){ // gets semester
  return semester;
}

void Course::setGrade(char gra){ // sets grade
  grade = gra;
}

char Course::getGrade(){ // gets grade
  return grade;
}
