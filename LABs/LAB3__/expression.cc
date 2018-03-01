#include <iostream>
#include "expr.h"
using namespace std;
int main(){
	ExTree a{4};
	ExTree b{42};
	ExTree c{'+', a, b};
	ExTree d{'/', b, a};
	cout << c.eval() << endl;
    cout << d.eval() << endl;
	d.prnt();
	return 0;	
}
