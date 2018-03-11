#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee{
    public:
        Employee(string theName, float thePayRate);
        string getName() const;
        float getPayRate() const;
        float pay(float hoursWorked) const;
        void setName(string newName);
        void setPayRate(float newPayRate);
    protected:
        string name;
        float payRate;
};
#endif
