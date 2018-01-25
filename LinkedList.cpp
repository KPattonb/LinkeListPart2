/*
Linked List Part 2
Allows user to create a linked list of students
User can add and delete students, print the list, average all the GPAs, and quit
Author: Kian Patton
Date: 11/24/18
 */

#include "student.h" //Include header files
#include "node.h"

char input[10];

//reads in user's command input and converts to uppercase
void readIn(char input[10]) {
  cin.getline(input, 10);
  for (int i = 0; i < strlen(input); i++) {
    input[i] = toupper(input[i]);
  }
}

//adds student to list
node* addStudent(char fName[100], char lName[100], int id, float gpa, node* &n) {
  if (n == NULL || id < n->getStudent()->getID()) {
    node* temp;
    student* s = new student(fName, lName, id, gpa);
    temp = new node(s);
    temp->setNext(n);
    n = temp;
    cout << endl << s->getfName() << " " << s->getlName() << " was added." << endl;
  }
  else {
    node* next = n->getNext();
    n->setNext(addStudent(fName, lName, id, gpa, next));
  }
  return n;
}

//prints list of students
void printList(node* n) {
  if (n != NULL) {
    cout << n->getStudent()->getfName() << " " << n->getStudent()->getlName() << " | ID: " << n->getStudent()->getID() << " | GPA: " << fixed << setprecision(2) << n->getStudent()->getGPA() << endl;
    printList(n->getNext());
  }
}

//deletes student from the list based on id number
node* deleteStudent(int id, node* &n) {
  if (n == NULL) {
    cout << "No student has this ID." << endl;
  }
  else {
    if (n->getStudent()->getID() == id) {
      node* temp;
      temp = n;
      cout << n->getStudent()->getfName() << " " << n->getStudent()->getlName() << " was deleted." << endl;
      n = n->getNext();
      delete temp;
    }
    else {
      node* next = n->getNext();
      n->setNext(deleteStudent(id, next));
    }
  }
  return n;
}

//averages the GPAs of all student in the list
void average(node* n) {
  double added = 0;
  int total = 0;
  double a = 0;

  if (n == NULL) {
    cout << endl << "List currently has no students." << endl;
  }
  else {
    while (n != NULL) {
      added += n->getStudent()->getGPA();
      total++;
      n = n->getNext();
    }
    a = added/total;
    cout << '\n' << "Average GPA: " << fixed << setprecision(2) << a << endl;
  }
}

//quit function
bool quit() {
  return false;
}

//main function
int main() {
  //variable declaration
  bool running = true;
  node* h = NULL;
  char command[10];

  while (running) {
    //user promts
    cout << '\n' << "Create a List of Students." << endl;
    cout << '\n' << "Enter a command. Type:" << endl;
    cout << "ADD to enter a student in the list." << endl;
    cout << "PRINT to print the list of students." << endl;
    cout << "DELETE to remove a student from the list." << endl;
    cout << "AVERAGE to print the average GPA of the students." << endl;
    cout << "QUIT to quit the program." << '\n' << endl;

    //checks for each command and calls for each function
    readIn(command);
    while (strcmp(command, "ADD") != 0 && strcmp(command, "PRINT") != 0 && strcmp(command, "DELETE") != 0 && strcmp(command, "AVERAGE") != 0 && strcmp(command, "QUIT") != 0) {
      cout << "Command is invalid. Please enter one of the listed commands." << endl;
      readIn(command);
    }

    if (strcmp(command, "ADD") == 0) {
      int id;
      float gpa;
      char* fName = new char[100];
      char* lName = new char[100];

      cout << "Input student's first name." << endl;
      cin >> fName;
      cin.ignore(100, '\n');
      cout << "Input student's last name." << endl;
      cin >> lName;
      cin.ignore(100, '\n');
      cout << "Input student's ID number." << endl;
      cin >> id;
      cin.ignore(100, '\n');
      cout << "Input student's GPA." << endl;
      cin >> gpa;
      cin.ignore(100, '\n');

      addStudent(fName, lName, id, gpa, h);
    }

    if (strcmp(command, "PRINT") == 0) {
      if (h == NULL) {
	cout << "List currently has no students." << endl;
      }
      else {
	cout << "Student List: " << '\n' << endl;
	printList(h);
      }
    }

    if (strcmp(command, "DELETE") == 0) {
      int id;
      if (h == NULL) {
	cout << "List currently has no students." << endl;
      }
      else {
	cout << "Input the ID of the student you would like to delete." << endl;
	cin >> id;
	cin.ignore(100, '\n');
	deleteStudent(id, h);
      }
    }

    if (strcmp(command, "AVERAGE") == 0) {
      average(h);
    }

    if (strcmp(command, "QUIT") == 0) {
      running = quit();
    }
    
  }
  return 0;
}
