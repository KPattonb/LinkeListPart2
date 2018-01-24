#include "student.h"
#include "node.h"

int main() {
  bool running = true;

  while (running) {

    cout << "Create a List of Students." << endl;
    cout << "Enter a command:" << endl;
    cout << "ADD to enter a student in the list." << endl;
    cout << "PRINT to print the list of students." << endl;
    cout << "DELETE to remove a student from the list." << endl;
    cout << "AVERAGE to print the average GPA of the students." << endl;
    cout << "QUIT to quit the program." << endl;
  }
  
  return 0;
}
