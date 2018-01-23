#include <iostream>
#include "AvlTree.h"

int main(){
	AvlTree<int> butts;
	butts.insert(5);
	butts.insert(3);
	butts.insert(7);
	butts.printTree();
	return 0;
}
