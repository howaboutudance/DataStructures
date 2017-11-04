/* 
 * Write a program to convert an infix expression that 
 * includes (, ), +, -, *, and / to postfix.
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	stack<char> s;
	string st = "A B *";

	for(string::iterator it = st.begin(); it != st.end(); ++it){
		if(*it == ' ')
			continue;
		if((int)*it > 47 && (int)*it < 58){
			s.push(*it);
		}else{
			cout << s.top() << " ";
			s.pop();
			cout << s.top() << " ";
			s.pop();
			cout << *it << " ";
		}
	}

	return 0;
}
