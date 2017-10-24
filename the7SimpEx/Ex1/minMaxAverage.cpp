#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	int firstInt, secondInt, thirdInt, max, min;
	double average;

	// User input
	cout << "Enter first integer: ";
	cin >> firstInt;
	cout << "Enter second integer: ";
	cin >> secondInt;
	cout << "Enter last integer: ";
	cin >> thirdInt;

	// Find Max and Min
	max = firstInt;
	min = firstInt;

	if (secondInt > max) max = secondInt;
	if (thirdInt > max) max = thirdInt;

	if (secondInt < min) min = secondInt;
	if (thirdInt < min) min = thirdInt;
	
	// Get Average
	average = (firstInt + secondInt + thirdInt) / 3.0;

	// Print out end results
	cout << setprecision(2) << fixed;
	cout << "The average is: " << average << endl;
	cout << "The smallest is: " << min << endl;
	cout << "The largest is: " << max << endl;

	return 0;
}
