/* Michelle Bergin
 * DataStructures
 * Fall Midterm
 * Q2
 * push, pop, top, isEmpty
 * big-3
 * simple paren-matching program  
 */

#include <iostream>
#include "List.h"
#include <string>

using namespace std;
template<typename Object>
class myStack{
	public:
		myStack(){
			size = 0;
			mS = new List<Object> {};
		}
		~myStack(){
			delete mS;
		}
		myStack & operator=(const myStack &rhs){
			if(this != &rhs){
				size = rhs.size;
				mS = rhs.mS;
			}
		}
		void push(const Object &x){
			mS->push_front(x);
			size++;
		}
		void pop(){
			mS->pop_front();
			size--;
		}
		Object & top(){
			return mS->front();
		}
		bool isEmpty(){
			return size == 0;
		}
		int sizeOf(){
			return size;
		}
	private:
		int size;
		List<Object> *mS;
};

int main(){
	myStack<char> poop;
	string meow = "(meow)";
	string temp;
	for(int i = 0; i < meow.size();i++){
		if(meow[i] == ')'){
			while(!poop.isEmpty()){
				cout << poop.top();
				poop.pop();
			}
		} else {
			poop.push(meow[i]);
		}
		cout << endl;
	}
	return 0;
}
