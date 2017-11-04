/*
 * Michelle Bergin
 * Problem 3.5
 *
 * Given two sorted lists, L1 and L2, write a procedure 
 * to compute L1 ∪ L2 using only the basic list operations.
 */

#include <iostream>
#include "List.h"
using namespace std;

const List<int> removeDuplicates(List<int> &L){
	for(List<int>::iterator it = L.begin(); it != L.end(); it++){
		for(List<int>::iterator it2 = L.begin(); it2 != L.end(); it2++){
			if(*it == *it2){
				//*it.erase;
			}
		}
	}
	return L;
}

const List<int> unionator(const List<int> &L, const List<int> &R){
	List<int> N;
	for(List<int>::const_iterator it = L.begin(); it != L.end(); it++){
		N.push_back(*it);
	}
	for(List<int>::const_iterator it = R.begin(); it != R.end(); it++){
		N.push_back(*it);
	}

	return N;
}

int main(){
	List<int> a;
	List<int> b;
	List<int> c;
	for(int i = 0; i < 10; i++){
		a.push_back(i);
		if(i % 2 == 0)
			b.push_back(i);
	}
	b.push_back(44);
	b.push_back(2);

	cout << "Below is our 'a' list before" << endl;
	for(List<int>::const_iterator it = a.begin(); it != a.end(); it++){
		cout << *it << ", ";
	}
	cout << "\n" << endl;

	cout << "Below is our 'b' list before" << endl;
	for(List<int>::const_iterator it = b.begin(); it != b.end(); it++){
		cout << *it << ", ";
	}
	cout << "\n" << endl;

	c = unionator(a,b);

	cout << "Below is our 'c' unioned list" << endl;
	for(List<int>::const_iterator it = c.begin(); it != c.end(); it++){
		cout << *it << ", ";
	}
	cout << "\n" << endl;

	return 0;
}
