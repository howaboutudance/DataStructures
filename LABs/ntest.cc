#include <iostream>
#include <iomanip>
#include <list>
#include "bst.h"

using namespace std;

int main(){
	bst<int> b;
	cout << "Empty (true)? " << boolalpha << b.isEmpty() << endl;
	cout << "is 3 in tree (false)? " << boolalpha << b.search(3) << endl;
	b.insert(3);
	cout << "Empty (false)? " << boolalpha << b.isEmpty() << endl;
	return 0;
}
