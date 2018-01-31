#include <iostream>
#include <iomanip>
#include <list>
#include "bst2.h"
using namespace std;
void prnt(list<int> &lst){
	cout << "Below is my list of inorder traversal" << endl;
	for(list<int>::iterator it = lst.begin(); it != lst.end(); ++it){
	cout << *it << " ";
	}
	cout << endl;
}

int main(){
	bst<int> b;
	b.insert(32);
	b.insert(8);
	b.insert(7);
	b.insert(16);
	list<int> l;
	l = b.inOrder();
	prnt(l);
	return 0;
}
