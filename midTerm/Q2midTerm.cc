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

int main(){
	myStack<char> poop;
	string meow = "(arf)((meow)cat)";
	char temp;
	for(int i = meow.size() - 1; i >= 0;i--){
		if(meow[i] == '('){
			cout << meow[i];
			temp = poop.top();
			while(temp != ')'){
				cout << temp;
				poop.pop();
				temp = poop.top();
			}
			cout << temp;
			poop.pop();
		} else {
			poop.push(meow[i]);
		}
	}
	cout << endl;
	return 0;
}
