/*
 * Michelle Bergin
 * Data Structures
 * Problem: 3.1
 * You are given a list, L, and another list, P, containing integers sorted in ascending order. 
 * The operation printLots(L,P) will print the elements in L that are in positions specified by P. 
 * For instance, if P = 1, 3, 4, 6, the elements in positions 1, 3, 4, and 6 in L are printed. 
 * Write the procedure printLots(L,P). You may use only the public STL container operations. 
 * What is the running time of your procedure?
 *
 * (Page 116). 
 */

#include <iostream>
#include "List.h"
#include <time.h>

using namespace std;
template <typename T>
void printLots(const List<T> &l, const List<int> & w){
	int counter = 0;
	for(List<int>::const_iterator it = w.begin(); it != w.end(); ++it){
		for(typename List<T>::const_iterator it2 = l.begin(); it2 != l.end(); ++it2){
			if(*it == counter){
				cout << *it2 << endl;
			}
			counter++;
		}
		counter = 0;
	}
}

int main(){
	List<int> L;
	List<int> P;
	for(int i = 0; i < 10; i++){
		L.push_back(i);
		P.push_back(i);
	}
	//printLots(L,P);
	
	List<string> S;
	S.push_back("IM A KITTY");
	S.push_back("NO I AM");
	S.push_back("STOP FIGHTING");
	S.push_back("why are you all talking in caps?");
	
	List<int> onlyAFew;
	onlyAFew.push_back(1);
	onlyAFew.push_back(4);
	onlyAFew.push_back(3);
	onlyAFew.push_back(2);
	onlyAFew.push_back(10);
	time_t t = clock();
	printLots(S,onlyAFew);
	t = clock() - t;
	cout << "This operation took " << (float)t / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}
