#include <iomanip>
#include <iostream>
#include <cstring>

//if undefined then define
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class student {
  //variable declarations
 protected:
  int id;
  char fName[100];
  char lName[100];
  float gpa;
  //function declarations
 public:
  int getID();
  char* getfName();
  char* getlName();
  float getGPA();
  //constructor
  student(char _fName[100], char _lName[100], int _id, float _gpa);
};

#endif
