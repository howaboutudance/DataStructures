#include "supervisor.h"
#include <iostream>

Supervisor::Supervisor(string theName, float thePayRate, string theDept) : Manager(theName, thePayRate, true){
    dept = theDept;
}
string Supervisor::getDept() const{
    return dept;
}
void Supervisor::setDept(string newDept){
    dept = newDept;
}
void Supervisor::setSalaried(bool newSalaried){
    (void)newSalaried;
    cout << "Supervisor salaried status cannot change." << endl;
}
