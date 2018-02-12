#include <iostream>
#include <iomanip>
#include <list>
#include "set.h"
using namespace std;

int main(){
	set<int> s;
	set<int> s2;
	s.insert(4);s.insert(8);s.insert(1);s.insert(9);s.insert(10);
	s2.insert(8);s2.insert(1);s2.insert(9);s2.insert(10);
	cout << "Inserted 4, 8, 1, 9, 10" << endl;
	cout << "Size of our set: " << s.size() << endl;
	s.remove(4);
	cout << "removed 4" << endl;
	cout << "Size of our set: " << s.size() << endl;
	cout << "Is s == s2: " << boolalpha << (s == s2) << endl;
	cout << "Adding 42 to s2" << endl; s2.insert(42);
	cout << "Is s == s2: " << boolalpha << (s == s2) << endl;
	return 0;
}
