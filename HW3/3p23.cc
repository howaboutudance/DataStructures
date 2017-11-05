/* 
 * Write a program to convert an infix expression that 
 * includes (, ), +, -, *, and / to postfix.
 *
 * Notes for my self: 
 * 		if end paren - pop
 * 		if higher presidence - pop
 * 		else print numb
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool isHigher(char c){
	return c == '/' || c == '*' || c == '^';
}
void inToPost(string &s){
	stack<char> stck;
	for(int i = 0; i < s.size(); i++){
		if (s[i] == ' '){
				continue;
		} else if(((int)s[i] > 47 && (int)s[i] < 58) && (int)s[i] != 94){
			cout << s[i] << " ";
		} else if(s[i] == ')'){
			while(stck.top() != '('){
				cout << stck.top() << " ";
				stck.pop();
			}
			stck.pop();
		} else if(s[i] == '+' || s[i] == '-'){
			if(!stck.empty() && isHigher(stck.top())){
				while(!stck.empty() && stck.top() != '('){
					cout << stck.top() << " ";
					stck.pop();
				}
				stck.push(s[i]);
			} else {
				stck.push(s[i]);
			}
		} else if(s[i] == '/' || s[i] == '*'){
			if(!stck.empty() && stck.top() == '^'){
				while(!stck.empty() && stck.top() != '('){
					cout << stck.top() << " ";
					stck.pop();
				}
				stck.push(s[i]);
			} else {
				stck.push(s[i]);
			}
		} else {
			stck.push(s[i]);
		}
	}
	while(!stck.empty()){
		cout << stck.top() << " ";
		stck.pop();
	}
	cout << endl;
}

int main(){
	string st = "1 * 3";
	string st2 = "1 * 2 ^ 3 + 4";
	string st3 = "1 * (2 + 3 * 4) + 5";

	cout << st << " is the infix thingy" << endl;
	inToPost(st);

	cout << "\n" << st2 << " is the infix thingy" << endl;
	inToPost(st2);

	cout << "\n" << st3 << " is the infix thingy" << endl;
	inToPost(st3);

	return 0;
}
