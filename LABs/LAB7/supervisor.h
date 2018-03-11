#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "manager.h"
#include <string>
using namespace std;

class Supervisor : public Manager{
    public:
        Supervisor(string theName, float thePayRate, string theDept);
        string getDept() const;
        void setDept(string newDept);
        void setSalaried(bool newSalaried);
    private:
        string dept;
};
#endif
