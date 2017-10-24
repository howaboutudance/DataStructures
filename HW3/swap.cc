/*
 * Michelle Bergin
 * Data Structures
 * Problem: 3.2
 * Swap two adjacent elements by adjusting only the links (and not the data) using 
 * a. singly linked lists 
 * b. doubly linked lists
 *
 */
#include <iostream>
#include "List.h"
#include <forward_list> // For the singly linked list.

void swapSingly(const forward_list<int> &L){
	
}
void swapDoubly(List<int> &L){
	for(List<int>::iterator it = L.begin(); it != L.end(); it++){
		int nw = *it;
		*it = *it++;
		*it++;	
	}
}
int main(){
	List<int> sLL;
	sLL.push_back(444);
	sLL.push_back(42); // Common theme, 4 is my favorite number
	sLL.push_back(4);
	sLL.push_back(24);
	
	swapDoubly(sLL);
	for(List<int>::iterator it = sLL.begin(); it != sLL.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
