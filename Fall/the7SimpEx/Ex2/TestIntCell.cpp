#include <iostream>
#include "IntCell.h"
using namespace std;

/**
 * Testing my Int Cell to:
 * 		add two IntCells
 * 		add an intCell and an int returning a new intCell
 * 		add an intCell and a int modifying the state of the intCell
 * 		do the same for subtract
 */
int main(){
	IntCell m;
	IntCell cat;

	m.write(5);
	cat.write(8);
	IntCell catNew = cat.addToNew(4);

	cout << "Cell contents: " << m.read() << " and " << cat.read() << endl;
	cout << "Cells added: " << m.add(cat) << endl;
	cout << "New Cat cell :3 : " << catNew.read() << endl;

	catNew.addTo(53);

	cout << "Added 53 to cat : " << catNew.read() << endl;

	catNew.subTo(53);

	cout << "Minused 53 to cat : " << catNew.read() << endl;

	cout << "Adding 2 IntCells together: " << m.add(cat) << endl;
	
	return 0;
}
