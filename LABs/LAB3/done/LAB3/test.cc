#include <iostream>
#include <iomanip>
#include <list>
#include "bst.h"
using namespace std;
void prnt(list<int> &butts){
	cout << "Below is my list of inorder traversal" << endl;
	for(list<int>::iterator it = butts.begin(); it != butts.end(); ++it){
	cout << *it << " ";
	}
	cout << endl;
}

int main(){
	bst<int> test;
	//test.findMin();
	cout << "Is Empty(yes): " << boolalpha << test.isEmpty() << endl;
	cout << "Is 3 in my tree(no): " << test.search(3) << endl;
	test.insert(3);
	cout << "Is Empty(no): " << boolalpha << test.isEmpty() << endl;
	cout << "Is 3 in my tree(yes): " << test.search(3) << endl;
	test.insert(5);
	test.insert(32);
	test.insert(8);
	test.insert(7);
	test.insert(16);
	list<int> testL;
	testL = test.inOrder();
	prnt(testL);
	list<int> butts;
	test.insert(9);
	butts = test.inOrder();
	prnt(butts);
	test.remove(9);
	cout << "Removed 9: " << endl;
	cout << boolalpha << test.isEmpty() << endl;
	list<int> lb;
	lb = test.inOrder();
	prnt(lb);
	cout << "is 16: " << test.search(16) << endl;
	test.insert(9);
	test.remove(3);
	list<int> lb2;
	lb2 = test.inOrder();
	prnt(lb2);

	return 0;
}
