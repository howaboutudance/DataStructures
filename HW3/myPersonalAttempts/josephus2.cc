/* 
 * Michelle Bergin
 * Problem: 3.6
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
			name = new string{initialName};	
			eliminated = new bool{initialBool};
			position = new int{initialPosition};
		}
		~Player(){
			delete name;
			delete eliminated;
			delete position;
		}
		Player(const Player & rhs){
			name = new string{*rhs.name};
			eliminated = new bool{*rhs.eliminated};
			position = new int{*rhs.position};
		}
		Player & operator=(const Player &rhs){
			if(this != &rhs)
				*name = *rhs.name;
				*eliminated = *rhs.eliminated;
				*position = *rhs.position;
			return *this;
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
		string & read_name() const{
			return *name;
		}
		void write_name(string &n){
			*name = n;
		}
		friend ostream & operator<<(ostream &os, const Player &p){
			os << "Player, " << *p.name << " has won the game? "
        		<< boolalpha << !*p.eliminated
        		<< ". They were in position " << *p.position << ".";
			return os;
		}
	private:
		string *name;
		bool *eliminated;
		int *position;
};

Player hotPotatoe(List<Player> &l, int m){
	int potatoe = m;
	Player p;
	int count = l.size();
	while(count > 0){
		for(List<Player>::iterator it = l.begin(); it != l.end(); it++){
			p = *it;
			if(!p.read_eliminated()){
				if(potatoe == 0){
					p = *it;
					if(count == 1){
						count--;
					} else {
						p.write_eliminated();
						count--;
						potatoe = m;
					}
				} else {
					potatoe--;
				}
			}	
		}
	}
	return p;
}

int main(){
	List<Player> players;	
	int hops;
	cout << "How many hops?" << endl;
	cin >> hops;
		
	Player p("Meow Head",false,1);
	Player p2("Jerk Face",false,2);
	Player p3("Jibby Jub",false,3);
	Player p4("Waddya Know",false,4);
	Player p5("Cat Butt",false,5);
	Player p6("That one really weird guy",false,6);
	Player p7("Spekter the Cat",false,7);
	Player p8("Doodle Noodles",false,8);
	Player p9("Potaters the Kitten",false,9);
	players.push_back(p);
	players.push_back(p2);
	players.push_back(p3);
	players.push_back(p4);
	players.push_back(p5);
	players.push_back(p6);
	players.push_back(p7);
	players.push_back(p8);
	players.push_back(p9);
	
	cout << hotPotatoe(players, hops) << endl;
	return 0;
}
