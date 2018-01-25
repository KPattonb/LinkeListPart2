#include "student.h"

//constructor
student::student(char _fName[100], char _lName[100], int _id, float _gpa) {

  strcpy(fName, _fName);
  strcpy(lName, _lName);
  id = _id;
  gpa = _gpa;

}

//returns first name
char* student::getfName() {
  return fName;
}
//returns last name
char* student::getlName() {
  return lName;
}
//returns gpa
float student::getGPA() {
  return gpa;
}
//returns id
int student::getID() {
  return id;
}
