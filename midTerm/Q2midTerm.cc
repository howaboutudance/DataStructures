/* Michelle Bergin
 * DataStructures
 * Fall Midterm
 * Q2
 * push, pop, top, isEmpty
 * big-3
 * simple paren-matching program  
 * 
 * SOOOO..... This isn't perfect but it works.. kinda. It doesnt recreate my string
 * But it does match parens... :/ Thanks for all your help as well :D !!!!
 * Also I re added my template. I really enjoy using templates... :3
 */

#include <iostream>
#include "List.h"
#include <string>

using namespace std;
template<typename Object>
class myStack{
	public:
		myStack(){
			mS = new List<Object> {};
		}
		~myStack(){
			delete mS;
		}
		myStack & operator=(const myStack &rhs){
			if(this != &rhs){
				mS->sizeOf() = rhs.sizeOf();
				mS = rhs.mS;
			}
		}
		void push(const Object &x){
			mS->push_front(x);
		}
		void pop(){
			mS->pop_front();
		}
		Object & top(){
			return mS->front();
		}
		bool isEmpty(){
			return mS->empty();
		}
		int sizeOf(){
			return mS->size();
		}
	private:
		List<Object> *mS;
};

void parenMatch(string &s){
	myStack<char> stck;

	for(char c : s){
		if(c == '('){
			stck.push(c);
		} else {
			while(!stck.isEmpty()){
				cout << stck.top();
				stck.pop();
			}
			cout << c;
		}
	}
	cout << endl;
}

int main(){
	myStack<char> p;
	string meow = "()(())";
	string crazyMeow = "(()((()()))(())())";

	cout << meow << " is the parens" << endl;
	parenMatch(meow);

	cout << "\n" << crazyMeow << " is the crazy parens" << endl;
	parenMatch(crazyMeow);

	return 0;
}
