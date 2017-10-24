/* 
 * Michelle Bergin
 * Problem: 3.6
 * The Josephus problem is the following game: N people, numbered 1 to N, are sitting in a circle. 
 * Starting at person 1, a hot potato is passed. After M passes, the person holding the hot potato 
 * is eliminated, the circle closes ranks, and the game continues with the person who was sitting 
 * after the eliminated person picking up the hot potato. The last remaining person wins. 
 * Thus, if M = 0 and N = 5, players are eliminated in order, and player 5 wins. 
 * If M = 1 and N = 5, the order of elimination is 2, 4, 1, 5. 
 *
 * a. Write a program to solve the Josephus problem for general values of M and N. 
 * Try to make your program as efficient as possible. 
 * Make sure you dispose of cells. 
 */

#include <iostream>
#include "List.h"
#include <time.h>
#include <string>

/*
 * I wanted a way to eliminate a player yet not destroy an original List. 
 * What if the list is 100,000's of people? It just doesn't seem logical. 
 * Plus I can practice using a class 
 */

class Player{
	public:
		explicit Player(string initialName = "Mx Androgenous", bool initialBool = false, int initialPosition = 0){
			
			
			eliminated = new bool{initialBool};
			position = new int{initialPosition};
		}
		~Player(){
			delete eliminated;
			delete position;
		}
		Player(const Player & rhs){
			eliminated = new bool{*rhs.eliminated};
			position = new int{*rhs.position};
		}
		int read_position() const{
			return *position;
		}
		void write_position(int x){
			*position = x;
		}
		bool read_eliminated() const{
			return *eliminated;
		}
		void write_eliminated(){
			*eliminated = true;
		}
		void write_eliminated(bool status){
			*eliminated = status;
		}
	private:
		string *name;
		bool *eliminated;
		int *position;
};

Player & hotPotatoe(Link<Player> temp){
	
}

int main(){

	return 0;
}
