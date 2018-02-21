#include <iostream>
#include "bst2.h"

int main(){
    bst<int> b;
    cout << "Inserting 6 items" << endl;
    b.insert(4); b.insert(2); b.insert(1); b.insert(3);
    b.insert(5);b.insert(6);
    cout << "Number of Nodes (6): " << b.numNodes() << endl;
    cout << "Number of leaves (3): " << b.leaves() << endl;
    return 0;
}
