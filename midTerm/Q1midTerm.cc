/*
 * Michelle Bergin
 * DataStructures
 * Q 1 revised
 */

#include <iostream>
#include "List.h"
void reverse(List<int> &l){
	int counter = l.size();
	int place = counter;
	int temp1 = l.back();
	int temp2;
	cout << temp1 << endl;
	for(int i = 0; i < l.size(); i++){
		for(List<int>::iterator it = l.begin(); it != l.end(); it++){
			if(((l.size()) - place) == i){
				temp2 = *it;
				*it = temp1;
				cout << temp1 << " :t1 t2: " << temp2 << " + " << *it << endl;
			}
			if(place == counter){
				cout << "p==c " << temp1 << " " << temp2 << endl;
				temp1 = *it;
				*it = temp2;
			}
		}
		place++;
		counter--;
	}

}
int main(){
	List<int> l;
	for(int i = 0; i < 10; i ++){
		l.push_back(i);
	}
	for(List<int>::iterator it = l.begin(); it != l.end(); it++){
		cout << *it << endl;
	}
	reverse(l);
	for(List<int>::iterator it = l.begin(); it != l.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
