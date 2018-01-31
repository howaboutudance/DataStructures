#include <iostream>
#include <iomanip>
#include <list>
#include "../butts/bst2.h"
#include "../butts/buttt.h"
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
	butt();
	bst<int> b;
	list<int> l;
	b.insert(5);
	b.insert(6);
	b.insert(10);
	b.insert(45);
	b.insert(2);
	b.insert(1);
	b.insert(0);
	b.insert(15);
	b.insert(14);
	b.insert(3);
	cout << "Full Nodes (2): " << b.fullNodes() << endl;
	cout << "nodes(10): " << b.numNodes() << endl;
	l = b.inOrder();
	prnt(l);
	int a = b.height();
	cout << "h (6): " << a << endl;
	b.remove(14);
	cout << "nodes(9): " << b.numNodes() << endl;
	l = b.inOrder();
	prnt(l);
	cout << "h (5): " << b.height() << endl;
	b.remove(15);
	l = b.inOrder();
	prnt(l);
	cout << "h (4): " << b.height() << endl;
	cout << "leaves (3): " << b.leaves() << endl;
	b.remove(0);
	b.remove(1);
	cout << "leaves (2): " << b.leaves() << endl;
	cout << "Full Nodes (1): " << b.fullNodes() << endl;
	
	return 0;
}
