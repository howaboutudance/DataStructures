/*
 * Michelle Bergin
 * Problem: 3.6
 */

#include <iostream>
#include "List.h"
int josephus(List<int> &l, int m){
	int potatoe = m;
	int winner;
	while(!l.empty()){
		for(List<int>::iterator it = l.begin(); it != l.end(); it++){
			if(potatoe == 0){
				winner = *it;
				l.erase(it);
				potatoe = m;
			} else {
				potatoe--;
			}
		}
	}
	return winner;
}
int main(){
	int N, M;
	cout << "How many players?" << endl;
	cin >> N;
	cout << "Hop size?" << endl;
	cin >> M;

	List<int> players;
	for(int i = 1; i <= N; i++){	
		players.push_back(i);
	}
	cout << "Player number " << josephus(players, M) << " won a cookie." << endl;
	return 0;
}
