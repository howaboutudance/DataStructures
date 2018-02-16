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
	s2.insert(78);s2.insert(51);s2.insert(29);s2.insert(14);
    cout << "Added: 78, 51, 29, and 14 to s2" << endl;
    set<int> sNew;
    cout << "Inserting 15 into s and unioning s and s2" << endl;
    s.insert(15);
    s2.set_union(s);
    cout << "Here is what is now in s: " << endl;
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
    cout << "Here is what is in s2: " << endl;
    for(auto it = s2.begin(); it != s2.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
    cout << "Now intersecting s with s2 into sInter" << endl;
    set<int> * sInter = s2.set_inter(s);
    cout << "Here is what is now in sInter: " << endl;
    for(auto it2 = sInter->begin(); it2 != sInter->end(); it2++){
        cout << *it2 << ", ";
    }
    cout << endl;
    return 0;
}
