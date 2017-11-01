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

template <typename Object>
class myStack{
	public:
		myStack(){
			mS = new List<Object>;
			size = 0;
		}
		~myStack(){
			delete size;
			delete mS; // I actually don't know how to use a destructor. I think this is right...?
		}
		myStack & operator=(const Object &rhs){
			if(this != &rhs){
				size = rhs.size;
				*ms = *rhs.mS; // Shallow copy
			}
		}
		void push(Object &x){
			push_front(x);
			size++;
		}
		Object & pop(){
			Object &temp = ms->front();
			mS->popfront();
			size--;
			return temp;
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

/*
 * Simple Paren-matching program
 * I know this is all wrong, sorry.
 */

myStack<char> meow;
string cat = "(cat)";
int sizeM = cat.size();
/*
 * BIG O(N) I only run through 'n' characters. the rest is inconsequential compared to the possible 'n' chars.
 *
 */
for(int i = 0; i < sizeM; i ++){
	char top = cat[i];
	if(top == ")"){
		char prnt = meow.pop();
		if(prnt == "("){
			cout << prnt;
			continue;
		} else {
			cout << prnt;
		}
	}
	meow.push(top);
}
cout endl;
