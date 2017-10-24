#include <iostream>
#include "IntCell.h"
using namespace std;

int main(){
	
	IntCell arr1[6];
	IntCell *arr2[6];

	int arrSize = sizeof(arr1) / sizeof(arr1[0]);

	for (int i = 0; i < arrSize; i++){
		arr1[i].write(i);
	}
	
	for (int i = 0; i < arrSize; i++){
		arr2[i] = &arr1[i];
	}
	
	cout << "Setting arr1[0] = 42" << endl;
	arr1[0].write(42);
	cout << "Read arr1[0]: " << arr1[0].read() << endl;	
	cout << "Now lets change only arr2[0] = 43 " << endl;
	arr2[0]->write(43);
	cout << "Read arr1[0]: " << arr1[0].read() << endl;

	return 0;
}
