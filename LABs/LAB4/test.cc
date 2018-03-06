#include "HashTable.cc"
#include "Employee.cc"
#include <iostream>
using namespace std;

int main() {
	HashTable<Employee> h1;
	Employee e1("abc", 10, 1);
	Employee e2("def", 11, 2);
	Employee e3("ghi", 12, 3);
	Employee e4("jkl", 13, 4);
    cout << "Set up for Hash (jkl): " << e4.hash() << endl;
	h1.insert(e1);
	h1.insert(e2);
	h1.insert(e3);

/*	if (h1.contains(e1))
		std::cout << "E1 is in table" << std::endl;
	else
		std::cout << "E1 is not in table" << std::endl;
	if (h1.contains(e4))
		std::cout << "E4 is in table" << std::endl;
	else
		std::cout << "E4 is not in table" << std::endl;

	h1.remove(e1);
	if (h1.contains(e1))
		std::cout << "E1 is in table" << std::endl;
	else
		std::cout << "E1 is not in table" << std::endl;
*/
}
