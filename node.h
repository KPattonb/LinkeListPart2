#ifndef NODE_H
#define NODE_H

#include "student.h" //Include.

class node{
 protected: //Declare variables.
  node* n;
  student* s;
 public: //Declare functions.
  node(student*);
  ~node();
  node* getNext();
  student* getStudent();
  void setNext(node*);
};
#endif
