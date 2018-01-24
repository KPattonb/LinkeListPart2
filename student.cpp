#include "student.h"

Student::Student(char _fName[100], char _lName[100], int _id, float _gpa) {

  strcpy(fName, _fName);
  strcpy(lName, _lName);
  id = _id;
  gpa = _gpa;

}

char* Student::getfName() {
  return fName;
}

char* Student::getlName() {
  return lName;
}

float Student::getGPA() {
  return gpa;
}

int Student::getID() {
  return id;
}
