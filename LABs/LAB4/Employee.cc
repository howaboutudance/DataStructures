#include <string>
using namespace std;

class Employee{
    public:
        explicit Employee(string n, double s,  int sr) : name(n), salary(s), seniority(sr) {}
        const string & getName() const{ 
            return name;
        }
        bool operator==(const Employee & rhs) const{
            return getName() == rhs.getName();
        }
        bool operator!=(const Employee & rhs) const{
            return !(*this == rhs);
        } 
        int hash() const{
            return hash(this->getName());
        }

    private:
        string name;
        double salary;
        int seniority;

        int hash(const string & s) const{
            int hsh = 0;
            for(int i = 0; i < s.size(); i++){
                hsh += s[i];
            }
            return hsh;
        }
};
