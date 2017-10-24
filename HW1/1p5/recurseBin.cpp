#include <iostream>
using namespace std;

/** 
 * Using recursion to find the number of 1's after converting a numb to binary.
 */

int recurse(int n){
	//base case
	if(n == 0){
		return n;
	} else if (n % 2 == 0){
		recurse(n / 2);
	} else {
		return recurse(n / 2) + 1;
	}
}

int main(){

	int entered;

	cout << "Enter an integer: " << endl;
	cin >> entered;

	cout << "There are " << recurse(entered) << " binary 1's" << endl;

	return 0;
}
