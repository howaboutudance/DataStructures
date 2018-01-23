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

// Assuming there are no duplicates.
const List<int> unionator(const List<int> &L, const List<int> &R){
	List<int> N;
	bool duplicate = false;
	for(List<int>::const_iterator it = L.begin(); it != L.end(); it++){
		for(List<int>::iterator it3 = N.begin(); it3 != N.end(); it3++){
			if(*it == *it3){
				 duplicate = true;
			}
		}
		if(!duplicate)
			N.push_back(*it);
		duplicate = false;
	}
	for(List<int>::const_iterator it = R.begin(); it != R.end(); it++){
		for(List<int>::iterator it3 = N.begin(); it3 != N.end(); it3++){
			if(*it == *it3){
				duplicate = true;
			}
		}
		if(!duplicate)
			N.push_back(*it);
		duplicate = false;
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
	


	c = unionator(a,b);
	for(List<int>::const_iterator it = c.begin(); it != c.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
