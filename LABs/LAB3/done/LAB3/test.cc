#include <iostream>
#include <iomanip>
#include <list>
#include "bst2.h"
using namespace std;
void prnt(list<int> *butts){
	cout << "Below is my list of inorder traversal" << endl;
	for(list<int>::iterator it = butts->begin(); it != butts->end(); ++it){
	cout << *it << " ";
	}
	cout << endl;
}

int main(){
	bst<int> b;
	list<int> *l;
	cout << "Is Empty(yes): " << boolalpha << b.isEmpty() << endl;
	cout << "Insert 8" << endl; b.insert(8);
	cout << "Is Empty(no): " << boolalpha << b.isEmpty() << endl;
	b.insert(4);b.insert(5);b.insert(6);b.insert(300);
	cout << "Inserted 4, 5, 6, and 300" << endl;
	cout << "The minimum: " << b.findMin() << endl;
	cout << "The max: " << b.findMax() << endl;
	cout << "The height: " << b.height() << endl;
	l = b.inOrder();
	prnt(l);
	b.remove(5);
	cout << "Removed 5" << endl;
	l = b.inOrder();
	prnt(l);
	cout << "The height: " << b.height() << endl;
	for(bst<int>::const_iterator it = b.begin(); it != b.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
