#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"
#include <string>
using namespace std;

class Manager : public Employee{
    public:
        Manager(string theName, 
            float thePayRate, 
            bool isSalaried);

        bool getSalaried() const;
        float pay(float hoursWorked) const;
        void setSalaried(bool newSalaried);
    protected:
        bool salaried;
};
#endif
