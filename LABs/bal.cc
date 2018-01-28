#include <iostream>
#include <list>
#include "bst.h"
using namespace std;

void prnt(list<int> &ll){
	cout << "==========" << endl;
	cout << "Below is my list of inorder traversal" << endl;
	for(list<int>::iterator it = ll.begin(); it != ll.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	cout << "==========" << endl;
}

int main(){
	bst<int> b;
	list<int> l;
	int a[15] = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	for(int i = 0; i < 15; i ++)
		b.insert(a[i]);
	l = b.inOrder();
	prnt(l);
	cout << "Full Nodes (7): " << b.fullNodes() << endl;
	return 0;
}
